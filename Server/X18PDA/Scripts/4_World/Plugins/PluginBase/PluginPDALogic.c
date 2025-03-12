modded class PluginPDALogic
{
	ref PDAServerConfig m_serverConfig;
	ref DiscordMessage m_DiscordMessage;

	string m_PDAConfig = GetDayZGame().GetX18Config().ProfilePath + "PDAConfig.json";
	string m_FactionConfig = GetDayZGame().GetX18Config().ProfilePath + "Factions.json";

	string m_FactionsPath = GetDayZGame().GetX18Config().ProfilePath + "Factions/";

	protected float m_UpdaterInterval;

	protected ref Timer m_Timer;

	override void OnInit()
	{
		super.OnInit();
		if (!FileExist(m_PDAConfig))
		{
			m_serverConfig = new PDAServerConfig();
			JsonFileLoader<ref PDAServerConfig>.JsonSaveFile(m_PDAConfig, m_serverConfig);
		}
		else
			JsonFileLoader<ref PDAServerConfig>.JsonLoadFile(m_PDAConfig, m_serverConfig);


		if (!FileExist(m_FactionsPath))
			MakeDirectory(m_FactionsPath);

		int count = EnumTools.GetEnumSize(EFactions);
		int value;

		for (int i = 0; i < count; i++)
		{
			string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, i) + ".json";
			if (!FileExist(m_FactionPath))
			{
				ref PDAFactionConfig m_FactionsNewConfig = new PDAFactionConfig();
				m_FactionsNewConfig.ID = i;
				m_FactionsNewConfig.Name = EnumTools.EnumToString(EFactions, i);
				m_FactionsNewConfig.MaxMembers = 25;

				m_FactionsNewConfig.FactionPublic = true;
				m_FactionsNewConfig.RanksPublic = false;

				m_FactionsNewConfig.Ranks = new array<string>();
				m_FactionsNewConfig.Ranks.Insert("Rookie");
				m_FactionsNewConfig.Ranks.Insert("Experienced");
				m_FactionsNewConfig.Ranks.Insert("Veteran");
				m_FactionsNewConfig.Ranks.Insert("Expert");

				m_FactionsNewConfig.LoadoutItem = new array<string>();
				m_FactionsNewConfig.LoadoutItem.Insert("FS_ITEM_BANDAGE");
				m_FactionsNewConfig.LoadoutItem.Insert("FS_ITEM_WATERbootle");
				m_FactionsNewConfig.LoadoutItem.Insert("FS_ITEM_SNICKERS");

				m_FactionsNewConfig.LoadoutHeadgear = new array<string>();
				m_FactionsNewConfig.LoadoutHeadgear.Insert("Booniehat_Black");
				m_FactionsNewConfig.LoadoutHeadgear.Insert("Booniehat_Blue");
				m_FactionsNewConfig.LoadoutHeadgear.Insert("Booniehat_DPM");
				m_FactionsNewConfig.LoadoutHeadgear.Insert("Booniehat_Dubok");

				m_FactionsNewConfig.LoadoutBody = new array<string>();
				m_FactionsNewConfig.LoadoutBody.Insert("Sweater_Gray");
				m_FactionsNewConfig.LoadoutBody.Insert("Sweater_Blue");
				m_FactionsNewConfig.LoadoutBody.Insert("Sweater_Green");
				m_FactionsNewConfig.LoadoutBody.Insert("Sweater_Red");

				m_FactionsNewConfig.LoadoutGloves = new array<string>();
				m_FactionsNewConfig.LoadoutGloves.Insert("WorkingGloves_Black");
				m_FactionsNewConfig.LoadoutGloves.Insert("WorkingGloves_Beige");
				m_FactionsNewConfig.LoadoutGloves.Insert("WorkingGloves_Brown");
				m_FactionsNewConfig.LoadoutGloves.Insert("WorkingGloves_Yellow");

				m_FactionsNewConfig.LoadoutLegs = new array<string>();
				m_FactionsNewConfig.LoadoutLegs.Insert("Jeans_Black");
				m_FactionsNewConfig.LoadoutLegs.Insert("Jeans_Blue");
				m_FactionsNewConfig.LoadoutLegs.Insert("Jeans_Brown");
				m_FactionsNewConfig.LoadoutLegs.Insert("Jeans_Green");

				m_FactionsNewConfig.LoadoutFeet = new array<string>();
				m_FactionsNewConfig.LoadoutFeet.Insert("AthleticShoes_Blue");
				m_FactionsNewConfig.LoadoutFeet.Insert("AthleticShoes_Black");
				m_FactionsNewConfig.LoadoutFeet.Insert("AthleticShoes_Brown");
				m_FactionsNewConfig.LoadoutFeet.Insert("AthleticShoes_Green");

				m_FactionsNewConfig.LoadoutWeapon = new array<string>();
				m_FactionsNewConfig.LoadoutWeapon.Insert("CombatKnife");
				m_FactionsNewConfig.LoadoutWeapon.Insert("HuntingKnife");
				m_FactionsNewConfig.LoadoutWeapon.Insert("KitchenKnife");
				m_FactionsNewConfig.LoadoutWeapon.Insert("SteakKnife");
				m_FactionsNewConfig.LoadoutWeapon.Insert("StoneKnife");
				m_FactionsNewConfig.LoadoutWeapon.Insert("Hammer");

				m_FactionsNewConfig.Leaders = new array<string>();
				m_FactionsNewConfig.Leaders.Insert("Leader Steam ID");

				m_FactionsNewConfig.Members = new array<ref FactionMember>();

				m_FactionsNewConfig.DiscordWebhook = "DiscordWebHook";

				JsonFileLoader<ref PDAFactionConfig>.JsonSaveFile(m_FactionPath, m_FactionsNewConfig);
			}
		}
	}

	override void SendGlobalMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			Param2< bool, string > serverData;
			if (!ctx.Read(serverData))
				return;

			if (!sender)
				return;

			if (!m_serverConfig.EnableGlobalChat)
				return;

			ref PDAFactionConfig faction = FindFactionByMember(sender.GetPlainId());

			foreach(ref FactionMember member : faction.Members)
			{
				if (sender.GetPlainId() == member.UID)
				{
					if (serverData.param1 && member.UndercoverName != "")
						GetMessageManager()._InsertMessage(new Param5<int, bool, string, string, bool>(0, serverData.param1, sender.GetPlainId(), member.UndercoverName, faction.FactionPublic), new Param5<int, bool, string, string, bool>(faction.ID, faction.RanksPublic, faction.Ranks.Get(member.Rank), serverData.param2, false));
					else
						GetMessageManager()._InsertMessage(new Param5<int, bool, string, string, bool>(0, serverData.param1, sender.GetPlainId(), sender.GetName(), faction.FactionPublic), new Param5<int, bool, string, string, bool>(faction.ID, faction.RanksPublic, faction.Ranks.Get(member.Rank), serverData.param2, false));
				}
			}
		}
	}

	override void SendFactionMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			Param1< string > serverData;
			if (!ctx.Read(serverData))
				return;

			if (!sender)
				return;

			ref PDAFactionConfig faction = FindFactionByMember(sender.GetPlainId());
			if (!faction)
				return;

			foreach(ref FactionMember member : faction.Members)
			{
				if (sender.GetPlainId() == member.UID)
					GetMessageManager()._InsertMessage(new Param5<int, bool, string, string, bool>(1, false, sender.GetPlainId(), sender.GetName(), faction.FactionPublic), new Param5<int, bool, string, string, bool>(faction.ID, faction.RanksPublic, faction.Ranks.Get(member.Rank), serverData.param1, false));
			}
		}
	}

	override void SendMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			Param2< string, string > serverData;
			if (!ctx.Read(serverData))
				return;

			string senderId = sender.GetPlainId();
			string senderName = sender.GetName();
			ref array<Man> players = new array<Man>();
			GetGame().GetPlayers(players);
			for (int q = 0; q < players.Count(); q++)
			{
				ref PlayerBase player = PlayerBase.Cast(players[q]);
				if (player)
				{
					ref PlayerIdentity identity = player.GetIdentity();
					string identityId = identity.GetPlainId();
					if (serverData.param1 == identityId)
					{
						if (player.HasWorkingItem("X18_PDA"))
						{
							string identityName = identity.GetName();
							GetRPCManager().SendRPC("X18PDA", "SendMessage", new Param4< string, string, string, string >(identityId, senderName, senderId, serverData.param2), true, sender);

							if (!(senderId == identityId))
								GetRPCManager().SendRPC("X18PDA", "SendMessage", new Param4< string, string, string, string >(senderId, senderName, senderId, serverData.param2), true, identity);
							return;
						}
					}
				}
			}
			GetRPCManager().SendRPC("X18PDA", "SendMessage", new Param4< string, string, string, string >("", "", "", ""), true, sender);
		}
	}

	override void CheckContacts(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			Param1< array<string> > serverData;
			if (!ctx.Read(serverData))
				return;

			ref array<string> request = new array<string>();
			request.Copy(serverData.param1);

			ref array<Man> players = new array<Man>();
			GetGame().GetPlayers(players);

			ref array<string> result = new array<string>();
			for (int i = 0; i < request.Count(); i++)
			{
				string uid = request[i];
				for (int q = 0; q < players.Count(); q++)
				{
					ref PlayerBase player = PlayerBase.Cast(players[q]);
					if (player)
					{
						ref PlayerIdentity identity = player.GetIdentity();
						string identityId = identity.GetPlainId();
						if (uid == identityId && player.HasWorkingItem("X18_PDA"))
							result.Insert(uid);
					}
				}
			}

			CheckContactsResponse(sender, result);
		}
	}

	void CheckContactsResponse(ref PlayerIdentity sender, ref array<string> contacts)
	{
		ref PDAFactionConfig leadedFaction = FindFactionByLeader(sender);
		ref array<ref FactionMember> factionMembers = null;
		ref array<string> factionRanks = null;
		string infoText = "";
		bool useFactionManagenemt = false;

		if (leadedFaction)
		{
			factionMembers = leadedFaction.Members;
			factionRanks = leadedFaction.Ranks;
			infoText = leadedFaction.Name + "(" + leadedFaction.Members.Count() + "/" + leadedFaction.MaxMembers + ")";
			useFactionManagenemt = true;
		}

		string factionChatName = "";
		ref PDAFactionConfig memberFaction = FindFactionByMember(sender.GetPlainId());
		if (memberFaction)
		{
			factionChatName = memberFaction.Name;
			factionChatName.Replace("_", " ");
		}

		GetRPCManager().SendRPC("X18PDA", "CheckContacts", new Param6< ref array<string>, bool, ref array<ref FactionMember>, ref array<string>, string, string>(contacts, useFactionManagenemt, factionMembers, factionRanks, infoText, factionChatName), true, sender);
	}

	override void GetVisualUserName(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			if (!sender)
				return;

			string m_UndercoverName = "";

			ref PDAFactionConfig faction = FindFactionByMember(sender.GetPlainId());
			if (faction)
			{
				foreach(ref FactionMember member : faction.Members)
				{
					if (sender.GetPlainId() == member.UID)
						m_UndercoverName = member.UndercoverName;
				}
			}
			ref array<Man> players = new array<Man>();
			GetGame().GetPlayers(players);

			ref array<string> result = new array<string>();
			for (int q = 0; q < players.Count(); q++)
			{
				ref PlayerBase player = PlayerBase.Cast(players[q]);
				if (player)
				{
					ref PlayerIdentity identity = player.GetIdentity();
					if (sender.GetPlainId() == identity.GetPlainId())
					{
						player.SetFaction(faction.ID);
						break;
					}
				}
			}
			GetRPCManager().SendRPC("X18PDA", "GetVisualUserName", new Param3<string, string, bool>(sender.GetName(), m_UndercoverName, m_serverConfig.EnableGlobalChat), true, sender);
		}
	}

	override void GetPlayerPositions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			if (!sender)
				return;

			ref PDAFactionConfig memberFaction = FindFactionByMember(sender.GetPlainId());
			if (memberFaction)
			{
				ref array<PlayerBase> m_DummyPlayers = new array<PlayerBase>;
				if (memberFaction.ID != EFactions.Loner)
				{
					ref array<Man> players = new array<Man>();
					GetGame().GetPlayers(players);

					for (int i = 0; i < players.Count(); ++i)
					{
						PlayerBase player = PlayerBase.Cast(players[i]);
						if (!player)
							break;
						if (!player.HasWorkingItem("X18_PDA"))
							break;
						if (!player.HasGPSEnabled())
							break;

					}
				}
				if (m_DummyPlayers.Count() >= 1)
					GetRPCManager().SendRPC("X18PDA", "GetPlayerPositions", new Param1< ref array<PlayerBase> >(m_DummyPlayers), true, sender);
			}
		}
	}

	override void AddContact(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			Param1< string > serverData;
			if (!ctx.Read(serverData))
				return;
			string requestName = serverData.param1;

			ref array<Man> players = new array<Man>();
			GetGame().GetPlayers(players);
			for (int i = 0; i < players.Count(); i++)
			{
				PlayerBase player = PlayerBase.Cast(players[i]);
				if (player)
				{
					PlayerIdentity identity = player.GetIdentity();
					string contactPlainId = identity.GetPlainId();
					string contactSteamId = identity.GetPlainId();
					string contactName = identity.GetName();
					if ((contactPlainId == requestName) || (contactName == requestName))
					{
						if (sender.GetPlainId() != contactSteamId)
						{
							GetRPCManager().SendRPC("X18PDA", "AddContact", new Param2<string, string>(contactSteamId, contactName), true, sender);
							return;
						}
					}
				}
			}

			GetRPCManager().SendRPC("X18PDA", "AddContact", new Param2<string, string>("", ""), true, sender);
		}
	}

	void SetUndercoverStatus(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server && sender)
		{
			Param2< PlayerBase, bool > serverData;
			if (!ctx.Read(serverData))
				return;

			PlayerBase m_Player;
			if (Class.CastTo(m_Player, serverData.param1))
				m_Player.SetUndercoverStatus(serverData.param2);
		}
	}

	void SetGPSStatus(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server && sender)
		{
			Param2< PlayerBase, bool > serverData;
			if (!ctx.Read(serverData))
				return;

			PlayerBase m_Player;
			if (Class.CastTo(m_Player, serverData.param1))
				m_Player.SetGPSStatus(serverData.param2);
		}
	}

	PDAFactionConfig FindFactionByLeader(PlayerIdentity identity)
	{
		ref PDAFactionConfig m_FactionConfig;
		int count = EnumTools.GetEnumSize(EFactions);
		int value;

		for (int i = 0; i < count; i++)
		{
			string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, i) + ".json";
			if (FileExist(m_FactionPath))
			{
				JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
				foreach(string leader : m_FactionConfig.Leaders)
				{
					string identityId = identity.GetPlainId();
					if (leader == identityId)
						return m_FactionConfig;
				}
			}
		}
		return null;
	}
	bool  FindFactionByFactionID(int factionId, out ref PDAFactionConfig factionResult)
	{
		ref PDAFactionConfig m_FactionConfig;
		string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, factionId) + ".json";
		if (FileExist(m_FactionPath))
		{
			JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
			factionResult = m_FactionConfig;
			return true;
		}
		return false;
	}
	PDAFactionConfig FindFactionByMember(string uid)
	{
		ref PDAFactionConfig m_FactionConfig;
		int count = EnumTools.GetEnumSize(EFactions);
		int value;

		for (int i = 0; i < count; i++)
		{
			string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, i) + ".json";
			if (FileExist(m_FactionPath))
			{
				JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
				foreach(FactionMember member : m_FactionConfig.Members)
				{
					if (uid == member.UID)
						return m_FactionConfig;
				}
			}
		}
		return null;
	}
	bool FindFactionMember(PlayerIdentity identity, out ref PDAFactionConfig m_Faction)
	{
		int count = EnumTools.GetEnumSize(EFactions);
		int value;
		string m_FactionPath;

		ref PDAFactionConfig m_FactionConfig;

		for (int i = 0; i < count; i++)
		{
			m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, i) + ".json";
			if (FileExist(m_FactionPath))
			{
				JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
				foreach(ref FactionMember member : m_FactionConfig.Members)
				{
					if (identity.GetPlainId() == member.UID)
					{
						m_Faction = m_FactionConfig;
						return true;
					}
				}
			}
		}

		m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, EFactions.Loner) + ".json";
		if (FileExist(m_FactionPath))
		{
			JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
			ref FactionMember newMember = new FactionMember();
			newMember.UID = identity.GetPlainId();
			newMember.Name = identity.GetName();
			newMember.LastLogin = JMDate.Now(false).ToString("DD-MM-YYYY hh:mm:ss");
			m_FactionConfig.Members.Insert(newMember);
			JsonFileLoader<ref PDAFactionConfig>.JsonSaveFile(m_FactionPath, m_FactionConfig);
			m_Faction = m_FactionConfig;
			return true;
		}
		return false;
	}
	void UpdatePlayerData(PlayerIdentity identity, int factionID)
	{
		ref PDAFactionConfig m_FactionConfig;
		string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, factionID) + ".json";
		if (FileExist(m_FactionPath))
		{
			JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
			foreach(ref FactionMember member : m_FactionConfig.Members)
			{
				if (identity.GetPlainId() == member.UID)
				{
					member.Name = identity.GetName();
					member.LastLogin = JMDate.Now(false).ToString("DD-MM-YYYY hh:mm:ss");
					JsonFileLoader<ref PDAFactionConfig>.JsonSaveFile(m_FactionPath, m_FactionConfig);
					return;
				}
			}
		}
	}
	void UpdatePlayerStatus(PlayerIdentity identity, int factionID, bool status)
	{
		ref PDAFactionConfig m_FactionConfig;
		string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, factionID) + ".json";
		if (FileExist(m_FactionPath))
		{
			JsonFileLoader<ref PDAFactionConfig>.JsonLoadFile(m_FactionPath, m_FactionConfig);
			foreach(ref FactionMember member : m_FactionConfig.Members)
			{
				if (identity.GetPlainId() == member.UID)
				{
					member.Online = status;
					JsonFileLoader<ref PDAFactionConfig>.JsonSaveFile(m_FactionPath, m_FactionConfig);
					return;
				}
			}
		}
	}
	override void FactionCommand(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Server)
		{
			if (sender == null)
				return;

			Param3< int, string, string > serverData;
			if (!ctx.Read(serverData))
				return;

			int action = serverData.param1;
			string fid = serverData.param2;
			ref PDAFactionConfig faction = FindFactionByLeader(sender);

			if (faction == null)
				return;

			if (action == 0)
			{
				if (faction.Members.Count() >= faction.MaxMembers)
					return;

				ref array<PlayerIdentity> identities = new array<PlayerIdentity>;
				GetGame().GetPlayerIndentities(identities);
				ref PlayerIdentity newMemberIdentity = null;

				foreach(ref PlayerIdentity identity : identities)
				{
					string fvalue = identity.GetName();
					if (fvalue == fid)
					{
						newMemberIdentity = identity;
						break;
					}

					fvalue = identity.GetPlainId();
					if (fvalue == fid)
					{
						newMemberIdentity = identity;
						break;
					}
				}

				if (newMemberIdentity == null)
					return;

				ref PDAFactionConfig m_GetOldUserFaction = FindFactionByMember(newMemberIdentity.GetPlainId());
				if (m_GetOldUserFaction.ID == EFactions.Loner)
				{
					int memberOldId = -1;
					for (int h = 0; h < m_GetOldUserFaction.Members.Count(); h++)
					{
						if (m_GetOldUserFaction.Members.Get(h).UID == newMemberIdentity.GetPlainId())
						{
							memberOldId = h;
							break;
						}
					}

					if (memberOldId < 0)
						return;
					m_GetOldUserFaction.Members.Remove(memberOldId);
					m_GetOldUserFaction = null;
				}

				if (m_GetOldUserFaction != null)
					return;

				ref FactionMember newMember = new FactionMember();
				newMember.UID = newMemberIdentity.GetPlainId();
				newMember.Name = newMemberIdentity.GetName();

				faction.Members.Insert(newMember);
			}
			else if (action == 1)
			{
				int memberId = -1;
				for (int i = 0; i < faction.Members.Count(); i++)
				{
					if (faction.Members.Get(i).UID == fid)
					{
						memberId = i;
						break;
					}
				}

				if (memberId < 0)
					return;
				faction.Members.Remove(memberId);
			}

			string m_FactionPath = m_FactionsPath + "/" + EnumTools.EnumToString(EFactions, faction.ID) + ".json";
			JsonFileLoader<ref PDAFactionConfig>.JsonSaveFile(m_FactionPath, faction);
			CheckContactsResponse(sender, null);
		}
	}
	PDAServerConfig GetPDAConfig()
	{
		if (m_serverConfig)
			return m_serverConfig;

		JsonFileLoader<ref PDAServerConfig>.JsonLoadFile(m_PDAConfig, m_serverConfig);
		return m_serverConfig;
	}
}

class PDAFactionsConfig
{
	ref array<ref PDAFactionConfig> Factions;
}

class PDAFactionConfig
{
	int ID;
	string Name;
	int MaxMembers;
	vector Spawn;
	bool FactionPublic;
	bool RanksPublic;
	ref array<string> Ranks;
	ref array<string> LoadoutShoulder;
	ref array<string> LoadoutMelee;
	ref array<string> LoadoutVest;
	ref array<string> LoadoutBody;
	ref array<string> LoadoutHips;
	ref array<string> LoadoutLegs;
	ref array<string> LoadoutBack;
	ref array<string> LoadoutHeadgear;
	ref array<string> LoadoutMask;
	ref array<string> LoadoutEyewear;
	ref array<string> LoadoutGloves;
	ref array<string> LoadoutFeet;
	ref array<string> LoadoutArmband;
	ref array<string> LoadoutWeapon;
	ref array<string> LoadoutItem;
	ref array<string> Leaders;
	ref array<ref FactionMember> Members;
	string DiscordWebhook;
}

class PDAServerConfig
{
	float TimeToCheckForMessages = 1.0;
	bool EnableGlobalChat = false;
	bool GlobalChatDiscord = false;
	string GlobalChatDiscordWebhook = "";
}