class ZenNoteGUI extends UIScriptedMenu
{
	static const string LAYOUT_FILE = "Noosphere/X18Notes/Data/gui/layouts/NoteGUI.layout";
	private int m_FontIndex = 0;
	private ref array<ref MultilineEditBoxWidget> m_TextBoxes = {};
	private ref array<ref TextWidget> m_Dates = {};
	private ButtonWidget m_ExitBtn;
	private ButtonWidget m_SelectFontBtn;
	private ItemBase m_Paper;
	private int m_PenColour;
	static string DATE_TEXT = "";
	void ~ZenNoteGUI()
	{
		m_ExitBtn.Unlink();
		m_SelectFontBtn.Unlink();
		foreach(MultilineEditBoxWidget box : m_TextBoxes)
		{
			box.Unlink();
		}
		foreach(TextWidget date : m_Dates)
		{
			date.Unlink();
		}
	}
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(LAYOUT_FILE);
		for (int i = 0; i < 100; i++)
		{
			MultilineEditBoxWidget box = MultilineEditBoxWidget.Cast(layoutRoot.FindAnyWidget("NoteText" + i));
			TextWidget date = TextWidget.Cast(layoutRoot.FindAnyWidget("DateText" + i));
			if (box && date)
			{
				m_TextBoxes.Insert(box);
				m_Dates.Insert(date);
				date.SetText(DATE_TEXT);
			}
			else
			{
				break;
			}
		}
		m_ExitBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CloseBtn"));
		m_SelectFontBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FontBtn"));
		ButtonWidget fontBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FontBtn"));
		if (fontBtn)
		{
			fontBtn.SetText("#STR_X18NoteStyle");
		}
		if (!m_ExitBtn || !m_SelectFontBtn)
		{
			ErrorMsg("Failed to load widgets for ZenNotes!");
			return NULL;
		}
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetMission().GetHud().Show(false);
		return layoutRoot;
	}
	void SetPaper(ItemBase item)
	{
		m_Paper = item;
	}
	void SetNoteData(ZenNoteData data)
	{
		SetFontIndex(data.m_FontIndex);
		MultilineEditBoxWidget edit_box = m_TextBoxes.Get(m_FontIndex);
		TextWidget date = m_Dates.Get(m_FontIndex);
		if (!edit_box || !date)
		{
			OnExitBtnClick();
			return;
		}
		edit_box.Show(true);
		edit_box.SetText(data.m_NoteText);
		date.Show(true);
		date.SetText(data.m_DateText);
		for (int i = 0; i < m_TextBoxes.Count(); i++)
		{
			MultilineEditBoxWidget temp_box = m_TextBoxes.Get(i);
			TextWidget temp_date = m_Dates.Get(i);
			if (i != m_FontIndex)
			{
				temp_box.Enable(false);
				temp_date.Enable(false);
				temp_box.Show(false);
				temp_date.Show(false);
			}
		}
		m_SelectFontBtn.Enable(false);
		m_SelectFontBtn.Show(false);
		SetPenColour(data.m_ARGBColour);
	}
	void SetDate(string date)
	{
		DATE_TEXT = date;
		TextWidget dateWidget = m_Dates.Get(m_FontIndex);
		if (dateWidget)
		{
			dateWidget.SetText(DATE_TEXT);
		}
	}
	void SetFontIndex(int index)
	{
		m_FontIndex = index;
	}
	void SetPenColour(int colour)
	{
		foreach(MultilineEditBoxWidget box : m_TextBoxes)
		{
			box.SetColor(colour);
		}
		foreach(TextWidget date : m_Dates)
		{
			date.SetColor(colour);
		}
		m_ExitBtn.SetTextColor(colour);
		m_SelectFontBtn.SetTextColor(colour);
		m_PenColour = colour;
	}
	void SetReadOnly(bool readOnly)
	{
		foreach(MultilineEditBoxWidget box : m_TextBoxes)
		{
			box.Enable(!readOnly);
		}
	}
	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		if (w == m_ExitBtn)
		{
			return OnExitBtnClick();
		}
		if (w == m_SelectFontBtn)
		{
			return HandleFontClick();
		}
		return true;
	}
	bool HandleFontClick()
	{
		string msgTxt;
		MultilineEditBoxWidget edit_box_old = m_TextBoxes.Get(m_FontIndex);
		TextWidget date_old = m_Dates.Get(m_FontIndex);
		if (edit_box_old)
		{
			m_FontIndex++;
			if (m_FontIndex >= m_TextBoxes.Count())
				m_FontIndex = 0;
			MultilineEditBoxWidget edit_box_new = m_TextBoxes.Get(m_FontIndex);
			TextWidget date_new = m_Dates.Get(m_FontIndex);
			if (edit_box_new && date_new)
			{
				edit_box_old.GetText(msgTxt);
				edit_box_new.SetText(msgTxt);
				date_new.SetText(DATE_TEXT);
				edit_box_old.Show(false);
				edit_box_old.Enable(false);
				date_old.Show(false);
				edit_box_new.Show(true);
				edit_box_new.Enable(true);
				date_new.Show(true);
			}
			else
			{
				ErrorMsg("NEW EDIT BOX NOT FOUND!");
			}
		}
		else
		{
			ErrorMsg("OLD EDIT BOX NOT FOUND!");
		}
		return true;
	}
	bool OnExitBtnClick()
	{
		string msgTxt;
		MultilineEditBoxWidget box = m_TextBoxes.Get(m_FontIndex);
		if (box)
		{
			box.GetText(msgTxt);
		}
		else
		{
			ErrorMsg("EDIT BOX NOT FOUND FOR FONT INDEX " + m_FontIndex);
			return false;
		}
		if (m_Paper)
		{
			ZenNoteData note_data = new ZenNoteData;
			note_data.m_FontIndex = m_FontIndex;
			note_data.m_NoteText = msgTxt;
			note_data.m_DateText = DATE_TEXT;
			note_data.m_ARGBColour = m_PenColour;
			Param1<ref ZenNoteData> params = new Param1<ref ZenNoteData>(note_data);
			if (msgTxt != "" && GetGame().GetPlayer())
			{
				m_Paper.RPCSingleParam(ZENNOTERPCs.SEND_WRITTEN_NOTE, params, true, NULL);
			}
		}
		UIManager uiManager = GetGame().GetUIManager();
		if (!uiManager)
			return true;
		UIScriptedMenu menu = uiManager.GetMenu();
		if (menu)
		{
			ZenNoteGUI noteMenu = ZenNoteGUI.Cast(menu);
			if (noteMenu)
			{
				uiManager.HideScriptedMenu(noteMenu);
				Mission mission = GetGame().GetMission();
				if (mission)
				{
					mission.PlayerControlEnable(true);
					mission.GetHud().Show(true);
				}
			}
		}
		return true;
	}
	private void ErrorMsg(string s)
	{
		Print("[ZenNotesGUI] Error - " + s);
		ZenNote_DebugMsg("[ZenNotesGUI] Error - " + s + " Please tell the server admin to contact Zenarchist");
	}
	private void ZenNote_DebugMsg(string msg)
	{
		GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
	}
}