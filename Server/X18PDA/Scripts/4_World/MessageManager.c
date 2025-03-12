static ref MessageManager g_MessageManager;
static MessageManager GetMessageManager()
{
	if (!g_MessageManager)
		g_MessageManager = new MessageManager();
	return g_MessageManager;
}
class MessageManager
{
	protected RestApi m_RestApi;
	protected RestContext m_RestContext;
	protected static ref JsonSerializer m_Serializer = new JsonSerializer;
	ref array<PDAMessageRest> t_PDAMessagesRestArray = new array<PDAMessageRest>;
	string m_RestUrl = GetDayZGame().GetX18Config().HostURL + GetDayZGame().GetX18Config().ScriptsPath;
	string m_ImageUrl = GetDayZGame().GetX18Config().HostURL + GetDayZGame().GetX18Config().LogosPath;
	string m_DiscordMessagePath = GetDayZGame().GetX18Config().DiscordPath + "DiscordMessage.json";
	protected ref PluginPDALogic m_PluginPDA;
	private float m_MessageDelayTimer = 0.0;
	protected float m_MessageDelay = 5.0;
	void MessageManager()
	{
		if (!m_RestApi)
			m_RestApi = CreateRestApi();
		if (m_RestApi && !m_RestContext)
			m_RestContext = m_RestApi.GetRestContext(m_RestUrl);
		if (!m_PluginPDA)
			m_PluginPDA = PluginPDALogic.Cast(GetPlugin(PluginPDALogic));
		if (GetDayZGame().GetX18Config().HostURL == "http:			m_ImageUrl = "http:		if (m_PluginPDA)
			m_MessageDelay = m_PluginPDA.GetPDAConfig().TimeToCheckForMessages;
	}
	void ~MessageManager()
	{
		if (m_RestApi)
			DestroyRestApi();
	}
	void _CheckForMessages(float deltaTime)
	{
		if (m_RestContext)
		{
			if (m_MessageDelayTimer >= m_MessageDelay)
				thread CheckForMessages();
			m_MessageDelayTimer += deltaTime;
		}
	}
	void CheckForMessages()
	{
		if (m_RestContext)
		{
			PDAReadRestCallback cbx1 = new PDAReadRestCallback;
			m_RestContext.GET(cbx1, "index.php?Table=PDAMessages&GetMessages=unsend");
			for (int i = 0; i < t_PDAMessagesRestArray.Count(); ++i)
			{
				PDAMessageRest m_Message = t_PDAMessagesRestArray.Get(i);
				t_PDAMessagesRestArray.Remove(i);

				string formattedFaction = EnumTools.EnumToString(EFactions, m_Message.faction);
				formattedFaction.Replace("_", " ");

				string formattedSender;
				if (m_Message.showfaction && !m_Message.undercover && m_Message.faction != -1)
				{
					if (m_Message.rank != "" && m_Message.showrank)
						formattedSender = "[" + formattedFaction + "][" + m_Message.rank + "] " + m_Message.username;
					else
						formattedSender = "[" + formattedFaction + "] " + m_Message.username;
				}
				else if (m_Message.undercover && m_Message.faction != -1)
				{
					formattedSender = "[Loner] " + m_Message.username;
				}
				else if (m_Message.faction == -1)
				{
					if (m_Message.rank != "" && m_Message.showrank)
						formattedSender = "[" + m_Message.externalfaction + "][" + m_Message.rank + "] " + m_Message.username;
					else
						formattedSender = "[" + m_Message.externalfaction + "] " + m_Message.username;
				}

				ref DiscordMessage m_DiscordMessage;
				JsonFileLoader<DiscordMessage>.JsonLoadFile(m_DiscordMessagePath, m_DiscordMessage);

				string formattedUsername = m_DiscordMessage.username;
				formattedUsername.Replace("USERNAME", formattedSender);
				m_DiscordMessage.username = formattedUsername;

				string formattedAvatar = m_DiscordMessage.avatar_url;
				formattedAvatar.Replace("AVATARURL", m_ImageUrl + "PDA.png");
				m_DiscordMessage.avatar_url = formattedAvatar;

				foreach(ref DiscordMessageEmbeds globalEmbeds : m_DiscordMessage.embeds)
				{
					foreach(ref DiscordMessageEmbedsFields globalFields : globalEmbeds.fields)
					{
						string formattedMessageTitle = globalFields.name;
						formattedMessageTitle.Replace("MESSAGETITLE", "Nachricht");
						globalFields.name = formattedMessageTitle;

						string formattedString = globalFields.value;
						formattedString.Replace("MESSAGE", m_Message.message);
						globalFields.value = formattedString;
					}

					string formattedThumbnail = globalEmbeds.thumbnail.url;
					string formattedGlobalFaction;
					if (m_Message.faction != -1)
						formattedGlobalFaction = EnumTools.EnumToString(EFactions, m_Message.faction);
					else
						formattedGlobalFaction = m_Message.externalfaction;
					formattedGlobalFaction.Replace(" ", "_");
					if (m_Message.showfaction && !m_Message.undercover)
						formattedThumbnail.Replace("THUMBNAILURL", m_ImageUrl + "" + formattedGlobalFaction + ".png");
					else
						formattedThumbnail.Replace("THUMBNAILURL", m_ImageUrl + "Loner.png");

					globalEmbeds.thumbnail.url = formattedThumbnail;
				}
				if (m_Message.type == 0)
				{
					if (m_PluginPDA.GetPDAConfig().GlobalChatDiscord && m_PluginPDA.GetPDAConfig().GlobalChatDiscordWebhook != "")
					{
						GetDiscordHook().SetAlias("GlobalChat", m_PluginPDA.GetPDAConfig().GlobalChatDiscordWebhook);
						GetDiscordHook().SendEmbed("GlobalChat", m_DiscordMessage);
					}
					GetRPCManager().SendRPC("X18PDA", "SendGlobalMessage", new Param2< string, string >(formattedSender, m_Message.message), true);
				}
				else
				{
					ref PDAFactionConfig m_Faction;
					if (!m_PluginPDA.FindFactionByFactionID(m_Message.faction, m_Faction))
						return;
					ref array<PlayerIdentity> identities = new array<PlayerIdentity>();
					GetGame().GetPlayerIndentities(identities);
					foreach(ref PlayerIdentity identity : identities)
					{
						foreach(ref FactionMember member : m_Faction.Members)
						{
							if (identity.GetPlainId() == member.UID)
								GetRPCManager().SendRPC("X18PDA", "SendFactionMessage", new Param2< string, string >(formattedSender, m_Message.message), true, identity);
						}
					}
					if (m_Faction.DiscordWebhook != "DiscordWebHook")
					{
						GetDiscordHook().SetAlias(m_Faction.Name, m_Faction.DiscordWebhook);
						GetDiscordHook().SendEmbed(m_Faction.Name, m_DiscordMessage);
					}
				}
			}
			m_MessageDelayTimer = 0.0;
		}
	}
	void _InsertMessage(Param5<int, bool, string, string, bool> data1, Param5<int, bool, string, string, bool> data2)
	{
		thread InsertMessage(data1, data2);
	}
	void InsertMessage(Param5<int, bool, string, string, bool> data1, Param5<int, bool, string, string, bool> data2)
	{
		if (m_RestContext)
		{
			protected ref PDAMessageInsertRestRequest m_PDAMessageInsertRequest = new PDAMessageInsertRestRequest();
			m_PDAMessageInsertRequest.Table = "PDAMessages";
			m_PDAMessageInsertRequest.Type = "Insert";
			protected ref PDAMessageRest m_PDAMessagesRest = new PDAMessageRest();
			m_PDAMessagesRest.type = data1.param1;
			m_PDAMessagesRest.undercover = data1.param2;
			m_PDAMessagesRest.steamid = data1.param3;
			m_PDAMessagesRest.username = data1.param4;
			m_PDAMessagesRest.showfaction = data1.param5;
			m_PDAMessagesRest.faction = data2.param1;
			m_PDAMessagesRest.externalfaction = "";
			m_PDAMessagesRest.showrank = data2.param2;
			m_PDAMessagesRest.rank = data2.param3;
			m_PDAMessagesRest.message = data2.param4;
			m_PDAMessagesRest.status = data2.param5;
			m_PDAMessageInsertRequest.Message = m_PDAMessagesRest;
			string jsonString = JsonFileLoader<PDAMessageInsertRestRequest>.JsonMakeData(m_PDAMessageInsertRequest);
			PDAWriteRestCallback cbx1 = new PDAWriteRestCallback;
			m_RestContext.SetHeader("application/json");
			m_RestContext.POST(cbx1, "index.php", jsonString);
		}
	}
	void AddMessage(PDAMessageRest message)
	{
		if (message)
		{
			t_PDAMessagesRestArray.Insert(message);
			PrintLog("AddMessage: " + message.id);
		}
	}
	RestContext GetRestContext()
	{
		if (!m_RestContext)
			m_RestContext = m_RestApi.GetRestContext(m_RestUrl);
		return m_RestContext;
	}
}
class PDAReadRestCallback : RestCallback
{
	protected static ref JsonSerializer m_Serializer = new JsonSerializer;
	override void OnError(int errorCode)
	{
		PrintLog(" !!! OnError() errorcode= " + errorCode);
	};
	override void OnTimeout()
	{
		PrintLog(" !!! OnTimeout() ");
	};
	override void OnSuccess(string data, int dataSize)
	{
		if (g_MessageManager && dataSize > 0)
		{
			string error;
			protected ref array<PDAMessageRest> m_PDAMessagesRestArray = new array<PDAMessageRest>;
			m_Serializer.ReadFromString(m_PDAMessagesRestArray, data, error);
			if (!error && m_PDAMessagesRestArray.Count() >= 1)
			{
				foreach(ref PDAMessageRest m_Message : m_PDAMessagesRestArray)
				{
					g_MessageManager.AddMessage(m_Message);
					protected ref PDAMessageUpdateRestRequest m_PDAMessageUpdateRequest = new PDAMessageUpdateRestRequest();
					m_PDAMessageUpdateRequest.Table = "PDAMessages";
					m_PDAMessageUpdateRequest.Type = "Update";
					m_PDAMessageUpdateRequest.UpdateMessage = m_Message.id;
					m_PDAMessageUpdateRequest.MessageStatus = "send";
					string jsonString = JsonFileLoader<PDAMessageUpdateRestRequest>.JsonMakeData(m_PDAMessageUpdateRequest);
					PDAWriteRestCallback cbx1 = new PDAWriteRestCallback;
					g_MessageManager.GetRestContext().SetHeader("application/json");
					g_MessageManager.GetRestContext().POST(cbx1, "index.php", jsonString);
				}
			}
		}
	};
	override void OnFileCreated(string fileName, int dataSize)
	{
		PrintLog(" !!! OnFileCreated() file=" + fileName + " size=" + dataSize);
	};
};
class PDAWriteRestCallback : RestCallback
{
	override void OnError(int errorCode)
	{
		PrintLog(" !!! OnError() errorcode= " + errorCode);
	};
	override void OnTimeout()
	{
		PrintLog(" !!! OnTimeout() ");
	};
	override void OnSuccess(string data, int dataSize)
	{
		if (g_MessageManager && dataSize > 0)
		{
			PrintLog("PDAWriteRestCallback: " + data);
		}
	};
	override void OnFileCreated(string fileName, int dataSize)
	{
		PrintLog(" !!! OnFileCreated() file=" + fileName + " size=" + dataSize);
	};
};