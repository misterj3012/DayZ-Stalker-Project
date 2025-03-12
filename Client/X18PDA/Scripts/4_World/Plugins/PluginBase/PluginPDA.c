class PluginPDA : PluginBase
{
	string m_configDir;
	ref PDAMenu m_PDAMenu;
	ref array<ref PluginPDA_Conversation> m_contacts;
	ref array<string> m_onlineContacts;
	ref map<string, ref array<ref PluginPDAComment>> m_comments;
	string m_Name;
	string m_UndercoverName;
	string m_serverEnvTemp;
	bool m_enableGlobalChat;
	const string contactsBinFilename = "contacts.bin";
	const string optionsBinFilename = "options.bin";
	string m_faction_chatName = "";
	ref array<ref Param2<string, string>> m_globalMessages;
	ref array<ref Param2<string, string>> m_factionMessages;
	ref PluginPDAConfig m_options;
	void PluginPDA()
	{
		m_contacts = new array<ref PluginPDA_Conversation>();
		m_comments = new map<string, ref array<ref PluginPDAComment>>();
		m_onlineContacts = new array<string>();
		m_globalMessages = new array<ref Param2<string, string>>;
		m_factionMessages = new array<ref Param2<string, string>>;
		m_options = new PluginPDAConfig();
		m_configDir = ProfilePath + "PDA/";
	}
	void ~PluginPDA()
	{
		SaveOptionsConfig();
	}
	override void OnInit()
	{
		MakeDirectory(ProfilePath);
		MakeDirectory(m_configDir);
		if (!FileExist(m_configDir + contactsBinFilename)) {
			SaveOptionsConfig();
			SaveContactsConfig();
		}
		else {
			LoadOptionsConfig();
			LoadContactsConfig();
		}
	}
	void SaveOptionsConfig()
	{
		BinaryFileLoader<ref PluginPDAConfig>.BinarySaveFile(m_configDir + optionsBinFilename, m_options);
	}
	void LoadOptionsConfig()
	{
		BinaryFileLoader<ref PluginPDAConfig>.BinaryLoadFile(m_configDir + optionsBinFilename, m_options);
	}
	void SaveContactsConfig()
	{
		BinaryFileLoader<ref array<ref PluginPDA_Conversation>>.BinarySaveFile(m_configDir + contactsBinFilename, m_contacts);
	}
	void LoadContactsConfig()
	{
		BinaryFileLoader<ref array<ref PluginPDA_Conversation>>.BinaryLoadFile(m_configDir + contactsBinFilename, m_contacts);
	}
	void SaveCommentsConfig(string uid)
	{
		if (m_comments.Contains(uid))
		{
			ref array<ref PluginPDAComment> comments = m_comments[uid];
			while (comments.Count() > 100)
			{
				comments.RemoveOrdered(0);
			}
			BinaryFileLoader<ref array<ref PluginPDAComment>>.BinarySaveFile(m_configDir + uid + ".bin", comments);
		}
	}
	void LoadCommentsConfig(string uid)
	{
		string fileName = m_configDir + uid + ".bin";
		if (FileExist(fileName))
		{
			ref array<ref PluginPDAComment> result = new array<ref PluginPDAComment>();
			BinaryFileLoader<ref array<ref PluginPDAComment>>.BinaryLoadFile(fileName, result);
			m_comments[uid] = result;
		}
	}
	ref array<ref PluginPDAComment> GetComments(string uid)
	{
		if (!m_comments.Contains(uid))
			LoadCommentsConfig(uid);
		if (!m_comments.Contains(uid))
			m_comments[uid] = new array<ref PluginPDAComment>();
		return m_comments[uid];
	}
	void AddComment(string contactId, string senderId, string message)
	{
		if (contactId.Length() > 0)
		{
			ref array<ref PluginPDAComment> comments = GetComments(contactId);
			ref PluginPDAComment comment = new PluginPDAComment();
			comment.m_UID = senderId;
			comment.m_Message = message;
			comments.Insert(comment);
			SaveCommentsConfig(contactId);
			ref PluginPDA_Conversation contact = FindContact(contactId);
			if (contact != null)
			{
				contact.m_Unreaded = contact.m_Unreaded + 1;
				SaveContactsConfig();
			}
			if (IsOpen())
				m_PDAMenu.m_sendMessageStatus = 2;
		}
		else
		{
			if (IsOpen())
				m_PDAMenu.m_sendMessageStatus = 0;
			ref array<string> request = new array<string>();
			for (int i = 0; i < m_contacts.Count(); i++)
			{
				request.Insert(m_contacts[i].m_UID);
			}
			GetRPCManager().SendRPC("X18PDA", "CheckContacts", new Param1< ref array<string> >(request), true);
		}
	}
	bool IsOpen()
	{
		return m_PDAMenu && m_PDAMenu.m_Active;
	}
	void Open()
	{
		if (IsOpen())
			Close();
		if (GetGame().GetUIManager().GetMenu() != NULL)
			return;
		m_PDAMenu = new PDAMenu;
		m_PDAMenu.Init();
		GetGame().GetUIManager().ShowScriptedMenu(m_PDAMenu, NULL);
	}
	ref PluginPDA_Conversation FindContact(string uid)
	{
		for (int i = 0; i < m_contacts.Count(); i++)
		{
			ref PluginPDA_Conversation item = m_contacts[i];
			if (item.m_UID == uid)
				return item;
		}
		return null;
	}
	void AddContact(string uid, string name)
	{
		if (uid.Length() > 0 && name.Length() > 0)
		{
			if (FindContact(uid) == null)
			{
				ref PluginPDA_Conversation conv = new PluginPDA_Conversation();
				conv.m_UID = uid;
				conv.m_Name = name;
				conv.m_Unreaded = 0;
				conv.m_IsBanned = false;
				m_contacts.Insert(conv);
				m_onlineContacts.Insert(uid);
				SaveContactsConfig();
			}
		}
		if (IsOpen())
			m_PDAMenu.m_addContactStatus = 2;
	}
	void RemoveContact(string uid)
	{
		ref PluginPDA_Conversation contactToDelete = FindContact(uid);
		if (contactToDelete == null)
			return;
		m_contacts.RemoveItem(contactToDelete);
		SaveContactsConfig();
		if (m_comments.Contains(uid))
			m_comments.Remove(uid);
		string fileName = m_configDir + uid + ".bin";
		if (FileExist(fileName))
			DeleteFile(fileName);
	}
	void RenameContact(string uid, string newName)
	{
		ref PluginPDA_Conversation contactToRename = FindContact(uid);
		if (contactToRename == null)
			return;
		contactToRename.m_Name = newName;
		SaveContactsConfig();
	}
	void BanUnbanContact(string uid)
	{
		ref PluginPDA_Conversation contactToRename = FindContact(uid);
		if (contactToRename == null)
			return;
		contactToRename.m_IsBanned = !contactToRename.m_IsBanned;
		SaveContactsConfig();
	}
	void Close()
	{
		if (m_PDAMenu)
			m_PDAMenu.m_Active = false;
	}
	void EnableFactionManagement(ref array<ref FactionMember> members, ref array<string> ranks, string infoText)
	{
		if (m_PDAMenu)
			m_PDAMenu.EnableFactionManagement(members, ranks, infoText);
	}
	void FactionMembersGPSLocation(ref array<PlayerBase> players)
	{
		if (m_PDAMenu)
			m_PDAMenu.FactionMembersGPSLocation(players);
	}
}
class PluginPDA_Conversation
{
	string m_UID;
	string m_Name;
	int m_Unreaded;
	bool m_IsBanned;
	void PluginPDA_Conversation()
	{}
}
class PluginPDAComment
{
	string m_UID;
	string m_Message;
	void PluginPDAComment()
	{}
}
class PluginPDAConfig
{
	bool m_Muted;
	bool m_ShareGPS;
	bool m_Undercover;
	void PluginPDAConfig()
	{}
}