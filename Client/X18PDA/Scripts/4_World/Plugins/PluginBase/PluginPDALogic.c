class PluginPDALogic : PluginBase
{
	EffectSound effect;
	void PluginPDALogic()
	{}
	void ~PluginPDALogic()
	{}
	override void OnInit()
	{
		GetRPCManager().AddRPC("X18PDA", "GetVisualUserName", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "AddContact", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "CheckContacts", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "GetPlayerPositions", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "SendMessage", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "SendGlobalMessage", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "SendFactionMessage", this, SingleplayerExecutionType.Both);
		//GetRPCManager().AddRPC("X18PDA", "SendGroupMessage", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "FactionCommand", this, SingleplayerExecutionType.Both);
		//GetRPCManager().AddRPC("X18PDA", "GroupCommand", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "SetUndercoverStatus", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("X18PDA", "SetGPSStatus", this, SingleplayerExecutionType.Both);
	}
	void SendGlobalMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && m_PluginPDA.m_enableGlobalChat)
			{
				Param2< string, string> clientData;
				if (!ctx.Read(clientData))
					return;
				m_PluginPDA.m_globalMessages.Insert(clientData);
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				if (player && player.HasWorkingItem("X18_PDA"))
				{
					if (!m_PluginPDA.m_options.m_Muted)
						GetGame().GetPlayer().PlaySoundSet(effect, "PDA_GlobalMessage_SoundSet", 0, 0);
					if (m_PluginPDA.IsOpen())
						m_PluginPDA.m_PDAMenu.m_sendMessageStatus = 2;
				}
			}
		}
	}
	void SendMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param4< string, string, string, string > clientData;
			if (!ctx.Read(clientData))
				return;
			string contactId = clientData.param1;
			string contactName = clientData.param2;
			string userSenderId = clientData.param3;
			string message = clientData.param4;
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
			{
				ref PluginPDA_Conversation msgContact = m_PluginPDA.FindContact(contactId);
				if (msgContact == null)
				{
					m_PluginPDA.AddContact(contactId, contactName);
					msgContact = m_PluginPDA.FindContact(contactId);
				}
				if (!msgContact.m_IsBanned)
				{
					if (userSenderId == contactId && !m_PluginPDA.m_options.m_Muted)
						GetGame().GetPlayer().PlaySoundSet(effect, "PDA_PrivateMessage_SoundSet", 0, 0);
					m_PluginPDA.AddComment(contactId, userSenderId, message);
				}
			}
		}
	}
	/*void SendGroupMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			PluginPDA m_PluginPDA;
			Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
			if (m_PluginPDA)
			{
				Param2< string, string > clientData;
				if (!ctx.Read(clientData))
					return;
				m_PluginPDA.m_groupMessages.Insert(clientData);
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				if (player && player.HasWorkingItem("X18_PDA"))
				{
					if (!m_PluginPDA.m_options.m_Muted)
						GetGame().GetPlayer().PlaySoundSet(effect, "PDA_GlobalMessage_SoundSet", 0, 0);
					if (m_PluginPDA.IsOpen())
						m_PluginPDA.m_PDAMenu.m_sendMessageStatus = 2;
				}
			}
		}
	}*/
	void SendFactionMessage(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
			{
				Param2< string, string > clientData;
				if (!ctx.Read(clientData))
					return;
				m_PluginPDA.m_factionMessages.Insert(clientData);
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				if (player && player.HasWorkingItem("X18_PDA"))
				{
					if (!m_PluginPDA.m_options.m_Muted)
						GetGame().GetPlayer().PlaySoundSet(effect, "PDA_FactionMessage_SoundSet", 0, 0);
					if (m_PluginPDA.IsOpen())
						m_PluginPDA.m_PDAMenu.m_sendMessageStatus = 2;
				}
			}
		}
	}
	void CheckContacts(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param6< ref array<string>, bool, ref array<ref FactionMember>, ref array<string>, string, string> clientData;
			if (!ctx.Read(clientData))
				return;
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
			{
				if (clientData.param1)
				{
					m_PluginPDA.m_onlineContacts.Clear();
					m_PluginPDA.m_onlineContacts.Copy(clientData.param1);
				}
				if (clientData.param6 != m_PluginPDA.m_faction_chatName)
				{
					m_PluginPDA.m_faction_chatName = clientData.param6;
					m_PluginPDA.m_factionMessages.Clear();
				}
				if (m_PluginPDA.IsOpen())
				{
					if (clientData.param2)
						m_PluginPDA.EnableFactionManagement(clientData.param3, clientData.param4, clientData.param5);
					m_PluginPDA.m_PDAMenu.m_Dirty = true;
				}
			}
		}
	}
	void GetPlayerPositions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param1< ref array<PlayerBase> > clientData;
			if (!ctx.Read(clientData))
				return;

			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
			{
				if (clientData.param1)
					m_PluginPDA.FactionMembersGPSLocation(clientData.param1);
			}
		}
	}
	void GetVisualUserName(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param3<string, string, bool> clientData;
			if (!ctx.Read(clientData))
				return;
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
			{
				m_PluginPDA.m_Name = clientData.param1;
				m_PluginPDA.m_UndercoverName = clientData.param2;
				m_PluginPDA.m_enableGlobalChat = clientData.param3;
			}
		}
	}
	void AddContact(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param2< string, string > clientData;
			if (!ctx.Read(clientData))
				return;
			PluginPDA m_PluginPDA;
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && m_PluginPDA.IsOpen())
				m_PluginPDA.AddContact(clientData.param1, clientData.param2);
		}
	}
	void FactionCommand(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{}
	/*void GroupCommand(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{}*/
};
class FactionMember
{
	bool Online;
	string UID;
	string Name;
	string UndercoverName;
	int Rank;
	string LastLogin;
};
/*class GroupMember
{
	string UID;
	string Name;
};*/