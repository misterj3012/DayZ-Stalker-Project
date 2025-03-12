class PDAMenu : UIScriptedMenu
{
	bool m_Active = false;
	bool m_Dirty = false;
	bool m_Opened = false;
	ref TextListboxWidget m_contactList;
	ref TextWidget m_yourNameText;
	ref TextWidget m_clockText;
	ref TextWidget m_dateText;
	ref TextWidget m_tempText;
	ref EditBoxWidget m_addContactTxt;
	ref ButtonWidget m_addContactBtn;
	ref ButtonWidget m_deleteContactBtn;
	ref TextListboxWidget m_chat;
	ref EditBoxWidget m_message;
	ref ButtonWidget m_send;
	ref TextWidget m_callibrationText;
	ref ButtonWidget m_mute_btn;
	ref ButtonWidget m_sharegps_btn;
	ref ButtonWidget m_undercover_btn;
	ref ButtonWidget m_rename_btn;
	ref ButtonWidget m_ban_btn;
	private int	  m_OrigYear;
	private int	  m_OrigMonth;
	private int	  m_OrigDay;
	private int	  m_OrigHour;
	private int	  m_OrigMinute;
	ref TextListboxWidget m_factionMembersList;
	ref ButtonWidget m_faction_add_btn;
	ref ButtonWidget m_faction_del_btn;
	ref EditBoxWidget m_faction_input;
	ref TextWidget m_faction_help_text;
	ref ImageWidget m_page_msg;
	ref ImageWidget m_page_map;
	ref ImageWidget m_page_faction;
	ref ButtonWidget m_page_msg_btn;
	ref ButtonWidget m_page_map_btn;
	ref ButtonWidget m_page_faction_btn;
	ref MapWidget m_map;
	const int m_contactMaxLength = 32;
	const int m_messageMaxLength = 196;
	float m_addContactTimeout = 0;
	bool m_addContactStatus = 0;
	float m_sendMessageTimeout = 0;
	bool m_sendMessageStatus = 0;
	int m_lastSelectedContact = -1;
	bool m_externalSendEvent = false;
	bool m_sendFuncEnabled = true;
	int m_selectedPage = 0;
	bool m_updateFactionManagement = false;
	ref array<ref FactionMember> m_faction_members = null;
	ref array<PlayerBase> m_faction_players = null;
	ref array<string> m_faction_ranks = null;
	string m_faction_info = "";
	int m_FactionColor;
	PlayerBase m_Player;
	PluginPDA m_PluginPDA;
	void PDAMenu()
	{}
	void ~PDAMenu()
	{
		if (m_faction_members)
			delete m_faction_members;
		if (m_faction_players)
			delete m_faction_players;
		if (m_faction_ranks)
			delete m_faction_ranks;
		m_Player = PlayerBase.Cast(m_Player);
		m_Player.GetInputController().SetDisabled(false);
	}
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18PDA/Data/Layouts/PDAMenu.layout");
		m_contactList = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("contact_list"));
		m_yourNameText = TextWidget.Cast(layoutRoot.FindAnyWidget("your_name_text"));
		m_clockText = TextWidget.Cast(layoutRoot.FindAnyWidget("clock_text"));
		m_dateText = TextWidget.Cast(layoutRoot.FindAnyWidget("date_text"));
		m_tempText = TextWidget.Cast(layoutRoot.FindAnyWidget("temp_text"));
		m_addContactTxt = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("add_contact_txt"));
		m_addContactBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("add_contact_btn"));
		m_deleteContactBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("delete_contact_btn"));
		m_chat = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("messages_txt"));
		m_message = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("send_msg_txt"));
		m_send = ButtonWidget.Cast(layoutRoot.FindAnyWidget("send_msg_btn"));
		m_callibrationText = TextWidget.Cast(layoutRoot.FindAnyWidget("callibration_txt"));
		m_mute_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("mute_btn"));
		m_sharegps_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("sharegps_btn"));
		m_undercover_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("undercover_btn"));
		m_rename_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("rename_contact_btn"));
		m_ban_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ban_contact_btn"));
		m_map = MapWidget.Cast(layoutRoot.FindAnyWidget("MapWidgetX"));
		m_factionMembersList = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("FactionMembers"));
		m_faction_add_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("AddMemberBtnX"));
		m_faction_del_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("DelMemberBtn"));
		m_faction_input = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("TextMemberId"));
		m_faction_help_text = TextWidget.Cast(layoutRoot.FindAnyWidget("FactionHelpText"));
		m_page_msg = ImageWidget.Cast(layoutRoot.FindAnyWidget("PagePDA"));
		m_page_map = ImageWidget.Cast(layoutRoot.FindAnyWidget("PageMap"));
		m_page_faction = ImageWidget.Cast(layoutRoot.FindAnyWidget("PageFactions"));
		m_page_msg_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("pagemsg_btn"));
		m_page_map_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("pagemap_btn"));
		m_page_faction_btn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("pagefaction_btn"));
		m_Player = PlayerBase.Cast(m_Player);
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		ref array<string> request = new array<string>();
		for (int i = 0; i < m_PluginPDA.m_contacts.Count(); i++)
		{
			request.Insert(m_PluginPDA.m_contacts[i].m_UID);
		}
		if (!m_Active)
		{
			GetRPCManager().SendRPC("X18PDA", "GetVisualUserName", NULL, true);
			GetRPCManager().SendRPC("X18PDA", "CheckContacts", new Param1< ref array<string> >(request), true);
			GetRPCManager().SendRPC("X18PDA", "GetPlayerPositions", NULL, true);
			m_yourNameText.SetText("#pda_loading");
			m_message.Enable(false);
			m_send.Enable(false);
			m_sendFuncEnabled = false;
		}
		m_Active = true;
		return layoutRoot;
	}
	void FactionMembersGPSLocation(ref array<PlayerBase> players)
	{
		m_faction_players = players;
	}
	void EnableFactionManagement(ref array<ref FactionMember> members, ref array<string> ranks, string infoText)
	{
		m_faction_members = members;
		m_faction_ranks = ranks;
		m_faction_info = infoText;
		m_updateFactionManagement = true;
	}
	/*void EnableGroupManagement(ref array<ref GroupMember> members, string infoText)
	{
		m_group_members = members;
		m_group_info = infoText;
		m_updateGroupManagement = true;
	}*/
	void SelectPdaPage(int id)
	{
		if (m_selectedPage == id)
			return;
		m_selectedPage = id;
		m_page_msg.Show(false);
		m_page_map.Show(false);
		//m_page_group.Show(false);
		m_page_faction.Show(false);
		switch (id)
		{
		case 0:
			m_page_msg.Show(true);
			break;
		case 1:
			m_map.ClearUserMarks();
			m_map.AddUserMark(m_Player.GetPosition(), "", ARGB(255, 0, 125, 255), "Noosphere\\X18PDA\\Data\\Model\\Data\\Map_PlayerMarker.paa");
			MoveMapToPlayer(m_Player.GetPosition());
			foreach(ref PlayerBase factionPlayer : m_faction_players)
			{
				if (factionPlayer != m_Player)
					m_map.AddUserMark(factionPlayer.GetPosition(), factionPlayer.GetIdentity().GetName(), m_FactionColor, "Noosphere\\X18PDA\\Data\\Model\\Data\\Map_PlayerMarker.paa");
			}
			m_page_map.Show(true);
			break;
		case 2:
			//m_page_group.Show(true);
			break;
		case 3:
			m_faction_add_btn.Show(false);
			m_page_faction.Show(true);
			break;
		}
	}
	void FillContactsList()
	{
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		int itemId;
		int rowShift = 0;
		int selectedRow = m_lastSelectedContact;
		m_contactList.ClearItems();
		if (m_PluginPDA.m_enableGlobalChat)
		{
			rowShift = rowShift + 1;
			itemId = m_contactList.AddItem("#pda_global_chat", NULL, 0);
			m_contactList.SetItem(itemId, "", NULL, 1);
			m_contactList.SetItemColor(itemId, 0, ARGBF(1, 0.0, 0.529, 0.858));
		}
		if (m_PluginPDA.m_faction_chatName.Length() > 0)
		{
			switch (m_PluginPDA.m_faction_chatName)
			{
			case "Militär":
				m_FactionColor = ARGB(255, 120, 155, 120);
				break;
			case "Clear Sky":
				m_FactionColor = ARGB(255, 120, 200, 205);
				break;
			case "ISG":
				m_FactionColor = ARGB(255, 205, 105, 5);
				break;
			case "Freedom":
				m_FactionColor = ARGB(255, 30, 155, 105);
				break;
			case "Duty":
				m_FactionColor = ARGB(255, 160, 30, 30);
				break;
			case "Bratya":
				m_FactionColor = ARGB(255, 95, 60, 20);
				break;
			case "Sin":
				m_FactionColor = ARGB(255, 135, 80, 135);
				break;
			case "Mercenaries":
				m_FactionColor = ARGB(255, 55, 110, 160);
				break;

			default:
				m_FactionColor = ARGB(255, 205, 205, 105);
				break;
			}

			rowShift = rowShift + 1;
			itemId = m_contactList.AddItem(m_PluginPDA.m_faction_chatName, NULL, 0);
			m_contactList.SetItem(itemId, "", NULL, 1);
			m_contactList.SetItemColor(itemId, 0, m_FactionColor);
		}
		/*if (m_PluginPDA.m_group_chatName.Length() > 0)
		{
			rowShift = rowShift + 1;
			itemId = m_contactList.AddItem(m_PluginPDA.m_group_chatName, NULL, 0);
			m_contactList.SetItem(itemId, "", NULL, 1);
			m_contactList.SetItemColor(itemId, 0, ARGBF(1, 0.0, 0.529, 0.858));
		}*/
		for (int i = 0; i < m_PluginPDA.m_contacts.Count(); i++)
		{
			ref PluginPDA_Conversation contact = m_PluginPDA.m_contacts[i];
			itemId = m_contactList.AddItem(contact.m_Name, NULL, 0);
			m_contactList.SetItem(itemId, "" + contact.m_Unreaded, NULL, 1);
			if (contact.m_IsBanned)
				m_contactList.SetItemColor(itemId, 0, ARGBF(1, 0.8, 0.02, 0.02));
			else if (m_PluginPDA.m_onlineContacts.Find(contact.m_UID) != -1)
				m_contactList.SetItemColor(itemId, 0, ARGBF(1, 0.2, 0.8, 0.02));
			else
				m_contactList.SetItemColor(itemId, 0, ARGBF(1, 0.7, 0.7, 0.7));
		}
		if (selectedRow >= 0 && selectedRow < m_PluginPDA.m_contacts.Count() + rowShift)
		{
			m_lastSelectedContact = selectedRow;
			m_contactList.SelectRow(selectedRow);
			SelectConversation(selectedRow);
		}
		else if (m_PluginPDA.m_contacts.Count() + rowShift > 0)
		{
			m_lastSelectedContact = 0;
			m_contactList.SelectRow(0);
			SelectConversation(0);
		}
		else
		{
			m_lastSelectedContact = -1;
			m_contactList.SelectRow(-1);
			SelectConversation(-1);
		}
	}
	void SelectConversation(int id)
	{
		int rowShift = 0;
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		ref array<ref Param2<string, string>> confMessages = null;
		if (m_PluginPDA.m_enableGlobalChat)
		{
			if (id == rowShift)
				confMessages = m_PluginPDA.m_globalMessages;
			rowShift = rowShift + 1;
		}
		if (m_PluginPDA.m_faction_chatName.Length() > 0)
		{
			if (id == rowShift)
				confMessages = m_PluginPDA.m_factionMessages;
			rowShift = rowShift + 1;
		}
		/*if (m_PluginPDA.m_group_chatName.Length() > 0)
		{
			if (id == rowShift)
				confMessages = m_PluginPDA.m_group_chatName;
			rowShift = rowShift + 1;
		}*/
		if ((id < 0) || (id >= m_PluginPDA.m_contacts.Count() + rowShift))
		{
			m_chat.ClearItems();
			m_message.Enable(false);
			m_send.Enable(false);
			m_sendFuncEnabled = false;
			return;
		}
		m_chat.ClearItems();
		float chatWidth;
		float chatHeight;
		m_chat.GetScreenSize(chatWidth, chatHeight);
		int chatLineMaxSize = (int)(chatWidth * 0.70) - 50;
		int chatLinesCount = -1;
		string autor;
		int color;
		int itemId;
		int addedLinesCount = 0;
		string chatMessage;
		bool isLineFinished;
		string chatLine;
		int i = 0;
		int q = 0;
		int textWidthCalibration;
		int textHeightCalibration;
		if (confMessages)
		{
			for (i = 0; i < confMessages.Count(); i++)
			{
				ref Param2<string, string> commentGlob = confMessages[i];
				autor = commentGlob.param1;
				itemId = m_chat.AddItem(autor, NULL, 0);
				addedLinesCount = 0;
				chatMessage = commentGlob.param2;
				while (chatMessage.LengthUtf8() > 0)
				{
					isLineFinished = false;
					chatLine = "";
					for (q = 0; q < chatMessage.LengthUtf8() && !isLineFinished; q++)
					{
						chatLine = chatLine + chatMessage.SubstringUtf8(q, 1);
						m_callibrationText.SetText(chatLine);
						m_callibrationText.GetTextSize(textWidthCalibration, textHeightCalibration);
						if (textWidthCalibration >= chatLineMaxSize)
							isLineFinished = true;
					}
					if (addedLinesCount == 0)
						m_chat.SetItem(itemId, chatLine, NULL, 1);
					else
						m_chat.AddItem(chatLine, NULL, 1);
					chatMessage = chatMessage.SubstringUtf8(chatLine.LengthUtf8(), chatMessage.LengthUtf8() - chatLine.LengthUtf8());
					addedLinesCount = addedLinesCount + 1;
					chatLinesCount = chatLinesCount + 1;
				}
			}
			m_callibrationText.SetText("");
			m_chat.SelectRow(chatLinesCount);
			m_chat.EnsureVisible(chatLinesCount);
			m_message.Enable(true);
			m_send.Enable(true);
			m_sendFuncEnabled = true;
		}
		else
		{
			ref PluginPDA_Conversation contact = m_PluginPDA.m_contacts[id - rowShift];
			ref array<ref PluginPDAComment> comments = m_PluginPDA.GetComments(contact.m_UID);
			for (i = 0; i < comments.Count(); i++)
			{
				ref PluginPDAComment comment = comments[i];
				if (comment.m_UID == GetGame().GetUserManager().GetTitleInitiator().GetUid())
				{
					ref array <ref SyncPlayer > PlayersInfoListServer = ClientData.m_PlayerList.m_PlayerList;
					foreach(ref SyncPlayer player : PlayersInfoListServer)
					{
						if (player.m_UID == comment.m_UID)
							autor = player.m_PlayerName;
						break;
					}
					color = ARGBF(1, 0.2, 0.8, 0.2);
				}
				else
				{
					autor = contact.m_Name;
					color = ARGBF(1, 0.976, 1, 0.298);
				}
				itemId = m_chat.AddItem(autor, NULL, 0);
				m_chat.SetItemColor(itemId, 0, color);
				addedLinesCount = 0;
				chatMessage = comment.m_Message;
				while (chatMessage.LengthUtf8() > 0)
				{
					isLineFinished = false;
					chatLine = "";
					for (q = 0; q < chatMessage.LengthUtf8() && !isLineFinished; q++)
					{
						chatLine = chatLine + chatMessage.SubstringUtf8(q, 1);
						m_callibrationText.SetText(chatLine);
						m_callibrationText.GetTextSize(textWidthCalibration, textHeightCalibration);
						if (textWidthCalibration >= chatLineMaxSize)
							isLineFinished = true;
					}
					if (addedLinesCount == 0)
						m_chat.SetItem(itemId, chatLine, NULL, 1);
					else
						m_chat.AddItem(chatLine, NULL, 1);
					chatMessage = chatMessage.SubstringUtf8(chatLine.LengthUtf8(), chatMessage.LengthUtf8() - chatLine.LengthUtf8());
					addedLinesCount = addedLinesCount + 1;
					chatLinesCount = chatLinesCount + 1;
				}
			}
			m_callibrationText.SetText("");
			m_chat.SelectRow(chatLinesCount);
			m_chat.EnsureVisible(chatLinesCount);
			if ((m_PluginPDA.m_onlineContacts.Find(contact.m_UID) == -1) || (contact.m_IsBanned))
			{
				m_message.Enable(false);
				m_send.Enable(false);
				m_sendFuncEnabled = false;
			}
			else
			{
				m_message.Enable(true);
				m_send.Enable(true);
				m_sendFuncEnabled = true;
			}
			if (contact.m_Unreaded > 0)
			{
				contact.m_Unreaded = 0;
				m_contactList.SetItem(id, "" + contact.m_Unreaded, NULL, 1);
				m_PluginPDA.SaveContactsConfig();
			}
		}
	}
	override void Update(float timeslice)
	{
		super.Update(timeslice);
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		if (m_externalSendEvent)
		{
			SendMessageEvent();
			m_externalSendEvent = false;
		}
		if (m_addContactStatus == 2)
		{
			UpdateUndercoverButton();
			UpdateShareGPSButton();
			UpdateMutedButton();
			FillContactsList();
			m_addContactStatus = 0;
		}
		if (m_sendMessageStatus == 2)
		{
			UpdateUndercoverButton();
			UpdateShareGPSButton();
			UpdateMutedButton();
			FillContactsList();
			m_sendMessageStatus = 0;
		}
		if (m_lastSelectedContact != m_contactList.GetSelectedRow())
		{
			m_lastSelectedContact = m_contactList.GetSelectedRow();
			SelectConversation(m_lastSelectedContact);
		}
		if (m_addContactTimeout > 0 || m_addContactStatus != 0)
		{
			m_addContactTimeout = m_addContactTimeout - timeslice;
			m_addContactBtn.Enable(false);
		}
		else
			m_addContactBtn.Enable(true);
		if (m_sendMessageTimeout > 0 || m_sendMessageStatus != 0)
		{
			m_sendMessageTimeout = m_sendMessageTimeout - timeslice;
			m_send.Enable(false);
		}
		else
			m_send.Enable(true);
		if (m_Dirty)
		{
			UpdateUndercoverButton();
			UpdateShareGPSButton();
			UpdateMutedButton();
			FillContactsList();
			m_Dirty = false;
		}
		if (m_Opened)
		{

			GetGame().GetWorld().GetDate(m_OrigYear, m_OrigMonth, m_OrigDay, m_OrigHour, m_OrigMinute);
			string timeText = m_OrigHour.ToStringLen(2) + ":" + m_OrigMinute.ToStringLen(2);
			string dateText = m_OrigMonth.ToStringLen(2) + "/" + m_OrigYear.ToStringLen(2);
			m_clockText.SetText(timeText);
			m_dateText.SetText(dateText);
			m_tempText.SetText(m_Player.GetTemperatureAroundPlayer().ToString() + " °C");
		}
		if (m_updateFactionManagement)
		{
			ref array<Man> v_Players = new array<Man>;
			GetGame().GetPlayers(v_Players);

			m_updateFactionManagement = false;
			m_faction_help_text.SetText(m_faction_info);
			m_factionMembersList.ClearItems();
			foreach(ref FactionMember member : m_faction_members)
			{
				string m_MemberStatus;
				int color;
				if (member.Online)
				{
					m_MemberStatus = "Online";
					color = ARGB(255, 127, 255, 0);
				}
				else
				{
					m_MemberStatus = "Offline";
					color = ARGB(255, 255, 0, 0);
				}

				int pos = m_factionMembersList.AddItem(m_MemberStatus, null, 0);
				m_factionMembersList.SetItem(pos, member.UID, null, 1);
				m_factionMembersList.SetItem(pos, member.Name, null, 2);
				m_factionMembersList.SetItem(pos, m_faction_ranks.Get(member.Rank), null, 3);
				m_factionMembersList.SetItem(pos, member.LastLogin, null, 4);
				m_factionMembersList.SetItemColor(pos, 0, color);
			}
			m_page_faction_btn.Show(true);
		}
		/*if (m_updateGroupManagement)
		{
			m_updateGroupManagement = false;
			m_group_help_text.SetText(m_group_info);
			m_groupMembersList.ClearItems();
			foreach (ref GroupMember member : m_group_members)
			{
				int pos = m_groupMembersList.AddItem(member.UID, null, 0);
				m_groupMembersList.SetItem(pos, member.Name, null, 1);
			}
			m_page_group_btn.Show(true);
		}*/
		if (!m_Active)
			GetGame().GetUIManager().Back();
	}
	override void OnShow()
	{
		super.OnShow();
		PPEffects.SetBlurMenu(0.5);
		SetFocus(NULL);
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		m_Player.GetInputController().SetDisabled(true);
		m_Player.GetActionManager().EnableActions(false);
		GetGame().GetInput().ChangeGameFocus(1);
		GetGame().GetUIManager().ShowUICursor(true);
		m_Opened = true;

		UpdateUndercoverButton();
		UpdateShareGPSButton();
		UpdateMutedButton();

		/*if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			SEffectManager.PlaySound("PDA_Welcome_SoundSet", m_Player.GetPosition());*/
	}
	override void OnHide()
	{
		super.OnHide();
		PPEffects.SetBlurMenu(0);
		SetFocus(NULL);
		m_Player.GetInputController().SetDisabled(false);
		m_Player.GetActionManager().EnableActions(true);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetUIManager().ShowUICursor(false);
		m_Opened = false;
		Close();
	}
	override bool OnKeyPress(Widget w, int x, int y, int key)
	{
		string boxText;
		if (w.GetName() == m_addContactTxt.GetName())
		{
			boxText = m_addContactTxt.GetText();
			if (boxText.LengthUtf8() >= m_contactMaxLength)
				return true;
		}
		if (w.GetName() == m_message.GetName())
		{
			boxText = m_message.GetText();
			if (boxText.LengthUtf8() >= m_messageMaxLength)
				return true;
		}
		if (w.GetName() == m_faction_input.GetName())
		{
			boxText = m_faction_input.GetText();
			if (boxText.LengthUtf8() >= m_contactMaxLength)
				return true;
		}
		/*if (w.GetName() == m_group_input.GetName())
		{
			boxText = m_group_input.GetText();
			if (boxText.LengthUtf8() >= m_contactMaxLength)
				return true;
		}*/
		return false;
	}
	bool SendMessageEvent()
	{
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		if (m_sendFuncEnabled && m_sendMessageTimeout <= 0 && m_sendMessageStatus == 0)
		{
			int selectedRow = m_lastSelectedContact;
			string message = m_message.GetText();
			if (selectedRow >= 0 && message.LengthUtf8() > 0)
			{
				if (message.LengthUtf8() > m_messageMaxLength)
					message = message.Substring(0, m_messageMaxLength);
				int rowShift = 0;
				if (m_PluginPDA.m_enableGlobalChat)
				{
					if (selectedRow == rowShift)
					{
						m_sendMessageTimeout = 1.0;
						m_sendMessageStatus = 1;
						GetRPCManager().SendRPC("X18PDA", "SendGlobalMessage", new Param2<bool, string>(m_PluginPDA.m_options.m_Undercover, message), true);
						m_message.SetText("");
						return true;
					}
					rowShift = rowShift + 1;
				}
				if (m_PluginPDA.m_faction_chatName.Length() > 0)
				{
					if (selectedRow == rowShift)
					{
						m_sendMessageTimeout = 1.0;
						m_sendMessageStatus = 1;
						GetRPCManager().SendRPC("X18PDA", "SendFactionMessage", new Param1<string>(message), true);
						m_message.SetText("");
						return true;
					}
					rowShift = rowShift + 1;
				}
				/*if (m_PluginPDA.m_group_chatName.Length() > 0)
				{
					if (selectedRow == rowShift)
					{
						m_sendMessageTimeout = 1.0;
						m_sendMessageStatus = 1;
						GetRPCManager().SendRPC("X18PDA", "SendGroupMessage", new Param1<string>(message), true);
						m_message.SetText("");
						return true;
					}
					rowShift = rowShift + 1;
				}*/
				ref PluginPDA_Conversation msgContact = m_PluginPDA.m_contacts[selectedRow - rowShift];
				string target = msgContact.m_UID;
				if ((m_PluginPDA.m_onlineContacts.Find(target) != -1) && (!msgContact.m_IsBanned))
				{
					m_sendMessageTimeout = 0.25;
					m_sendMessageStatus = 1;
					GetRPCManager().SendRPC("X18PDA", "SendMessage", new Param2<string, string>(target, message), true);
					m_message.SetText("");
					return true;
				}
			}
		}
		return false;
	}
	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			SEffectManager.PlaySound("PDA_Button_SoundSet", m_Player.GetPosition());

		int selectedRow;
		int rowShift;
		PluginPDA m_PluginPDA;
		Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA));
		if (w == m_addContactBtn)
		{
			if (m_addContactTimeout <= 0 && m_addContactStatus == 0)
			{
				string contactId = m_addContactTxt.GetText();
				if (contactId.LengthUtf8() <= m_contactMaxLength && contactId.LengthUtf8() > 0)
				{
					m_addContactStatus = 1;
					m_addContactTimeout = 1;
					GetRPCManager().SendRPC("X18PDA", "AddContact", new Param1<string>(contactId), true);
				}
			}
			return true;
		}
		if (w == m_send)
			return SendMessageEvent();
		if (w == m_deleteContactBtn)
		{
			selectedRow = m_lastSelectedContact;
			rowShift = 0;
			if (m_PluginPDA.m_enableGlobalChat)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			if (m_PluginPDA.m_faction_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			/*if (m_PluginPDA.m_group_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}*/
			if (selectedRow >= 0 && selectedRow < m_PluginPDA.m_contacts.Count() + rowShift)
			{
				string contactToDeleteUid = m_PluginPDA.m_contacts[selectedRow - rowShift].m_UID;
				m_PluginPDA.RemoveContact(contactToDeleteUid);
				m_Dirty = true;
			}
			return true;
		}
		if (w == m_undercover_btn)
		{
			m_PluginPDA.m_options.m_Undercover = !m_PluginPDA.m_options.m_Undercover;
			GetRPCManager().SendRPC("X18PDA", "SetUndercoverStatus", new Param2<PlayerBase, bool>(m_Player, m_PluginPDA.m_options.m_Undercover), true);
			UpdateUndercoverButton();
			return true;
		}
		if (w == m_sharegps_btn)
		{
			m_PluginPDA.m_options.m_ShareGPS = !m_PluginPDA.m_options.m_ShareGPS;
			GetRPCManager().SendRPC("X18PDA", "SetGPSStatus", new Param2<PlayerBase, bool>(m_Player, m_PluginPDA.m_options.m_ShareGPS), true);
			UpdateShareGPSButton();
			return true;
		}
		if (w == m_mute_btn)
		{
			m_PluginPDA.m_options.m_Muted = !m_PluginPDA.m_options.m_Muted;
			UpdateMutedButton();
			return true;
		}
		if (w == m_rename_btn)
		{
			selectedRow = m_lastSelectedContact;
			rowShift = 0;
			if (m_PluginPDA.m_enableGlobalChat)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			if (m_PluginPDA.m_faction_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			/*if (m_PluginPDA.m_group_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}*/
			if (selectedRow >= 0 && selectedRow < m_PluginPDA.m_contacts.Count() + rowShift)
			{
				string newContactName = m_addContactTxt.GetText();
				if (newContactName.LengthUtf8() <= m_contactMaxLength && newContactName.LengthUtf8() > 0)
				{
					string contactToRenameUid = m_PluginPDA.m_contacts[selectedRow - rowShift].m_UID;
					m_PluginPDA.RenameContact(contactToRenameUid, newContactName);
					m_Dirty = true;
				}
			}
			return true;
		}
		if (w == m_ban_btn)
		{
			selectedRow = m_lastSelectedContact;
			rowShift = 0;
			if (m_PluginPDA.m_enableGlobalChat)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			if (m_PluginPDA.m_faction_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}
			/*if (m_PluginPDA.m_group_chatName.Length() > 0)
			{
				if (selectedRow == rowShift)
					return true;
				rowShift = rowShift + 1;
			}*/
			if (selectedRow >= 0 && selectedRow < m_PluginPDA.m_contacts.Count() + rowShift)
			{
				string contactToBanUid = m_PluginPDA.m_contacts[selectedRow - rowShift].m_UID;
				m_PluginPDA.BanUnbanContact(contactToBanUid);
				m_Dirty = true;
			}
			return true;
		}
		if (w == m_page_msg_btn)
		{
			SelectPdaPage(0);
			return true;
		}
		if (w == m_page_map_btn)
		{
			SelectPdaPage(1);
			return true;
		}
		/*if (w == m_page_group_btn)
		{
			SelectPdaPage(2);
			return true;
		}*/
		if (w == m_page_faction_btn)
		{
			SelectPdaPage(3);
			return true;
		}
		if (w.GetName() == m_factionMembersList.GetName())
			return true;
		/*if (w.GetName() == m_faction_add_btn.GetName())
		{
			string memberId = m_faction_input.GetText();
			if (memberId.LengthUtf8() > m_contactMaxLength)
				memberId = memberId.Substring(0, m_contactMaxLength);
			m_faction_input.SetText("");
			GetRPCManager().SendRPC("X18PDA", "FactionCommand", new Param2< int, string >(0, memberId), true);
			return true;
		}*/
		if (w.GetName() == m_faction_del_btn.GetName())
		{
			int selectedMemberId = m_factionMembersList.GetSelectedRow();
			if (selectedMemberId >= 0 && selectedMemberId < m_faction_members.Count())
			{
				ref FactionMember member = m_faction_members.Get(selectedMemberId);
				GetRPCManager().SendRPC("X18PDA", "FactionCommand", new Param3< int, string, string >(1, member.UID, ""), true);
			}
			return true;
		}
		/*if (w.GetName() == m_groupMembersList.GetName()) {
			return true;
		}
		if (w.GetName() == m_group_add_btn.GetName())
		{
			string memberId = m_group_input.GetText();
			if (memberId.LengthUtf8() > m_contactMaxLength)
				memberId = memberId.Substring(0, m_contactMaxLength);
			m_group_input.SetText("");
			GetRPCManager().SendRPC("X18PDA", "GroupCommand", new Param2< int, string >(0, memberId), true);
			return true;
		}
		if (w.GetName() == m_group_del_btn.GetName())
		{
			int selectedMemberId = m_groupMembersList.GetSelectedRow();
			if (selectedMemberId >= 0 && selectedMemberId < m_group_members.Count())
			{
				ref GroupMember member = m_group_members.Get(selectedMemberId);
				GetRPCManager().SendRPC("X18PDA", "GroupCommand", new Param3< int, string, string >(1, member.UID, ""), true);
			}
			return true;
		}*/
		return false;
	}
	void UpdateUndercoverButton()
	{
		PluginPDA m_PluginPDA;
		if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
		{
			if (m_PluginPDA.m_faction_chatName.Length() > 0 && m_PluginPDA.m_faction_chatName == "Sin")
			{
				m_undercover_btn.Show(true);
				if (m_PluginPDA.m_options.m_Undercover)
					m_undercover_btn.SetText("#undercover_enabled");
				else
					m_undercover_btn.SetText("#undercover_disabled");
			}
			else
				m_undercover_btn.Show(false);
		}
	}
	void UpdateShareGPSButton()
	{
		PluginPDA m_PluginPDA;
		if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
		{
			if (m_PluginPDA.m_faction_chatName.Length() > 0 && m_PluginPDA.m_faction_chatName != "Loner")
			{
				m_sharegps_btn.Show(true);
				if (m_PluginPDA.m_options.m_ShareGPS)
					m_sharegps_btn.SetText("#gps_enabled");
				else
					m_sharegps_btn.SetText("#gps_disabled");
			}
			else
				m_sharegps_btn.Show(false);
		}
	}
	void UpdateMutedButton()
	{
		PluginPDA m_PluginPDA;
		if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
		{
			if (m_PluginPDA.m_options.m_Muted)
				m_mute_btn.SetText("#pda_unmute");
			else
				m_mute_btn.SetText("#pda_mute");
		}
	}
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		super.OnChange(w, x, y, finished);
		string boxText;
		if (w.GetName() == m_addContactTxt.GetName())
		{
			boxText = m_addContactTxt.GetText();
			if (boxText.LengthUtf8() > m_contactMaxLength)
				m_addContactTxt.SetText(boxText.Substring(0, m_contactMaxLength));
			return true;
		}
		if (w.GetName() == m_message.GetName())
		{
			boxText = m_message.GetText();
			if (boxText.LengthUtf8() > m_messageMaxLength)
				m_message.SetText(boxText.Substring(0, m_messageMaxLength));
			return true;
		}
		if (w.GetName() == m_faction_input.GetName())
		{
			boxText = m_faction_input.GetText();
			if (boxText.LengthUtf8() > m_contactMaxLength)
				m_faction_input.SetText(boxText.Substring(0, m_contactMaxLength));
			return true;
		}
		/*if (w.GetName() == m_group_input.GetName())
		{
			boxText = m_group_input.GetText();
			if (boxText.LengthUtf8() > m_contactMaxLength)
				m_group_input.SetText(boxText.Substring(0, m_contactMaxLength));
			return true;
		}*/
		return false;
	}
	override bool OnItemSelected(Widget w, int x, int y, int row, int  column, int  oldRow, int  oldColumn)
	{
		super.OnItemSelected(w, x, y, row, column, oldRow, oldColumn);
		if (w == m_contactList)
			return true;
		if (w == m_chat)
			return true;
		if (w == m_factionMembersList)
			return true;
		/*if (w == m_groupMembersList)
			return true;*/
		return false;
	}

	void MoveMapToPlayer(vector pos)
	{
		float x = pos[0];
		float y = pos[2];
		float shift_x = 320.0;
		float shift_y = 311.25;

		float scale = 0.1;

		int multiplier = Math.Round(scale * 10);

		if (scale >= 0.1)
		{
			shift_x = 200;
			shift_y = 185;
		}

		x = x + (shift_x * multiplier);
		y = y - (shift_y * multiplier);
		vector map_pos = Vector(x, 0, y);
		m_map.SetScale(0.1);
		m_map.SetMapPos(map_pos);
	}
}