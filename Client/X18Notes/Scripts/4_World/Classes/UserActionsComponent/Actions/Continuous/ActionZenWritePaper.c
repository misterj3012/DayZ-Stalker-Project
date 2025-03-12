class ActionZenWritePaperCB : ActionContinuousBaseCB {}
class ActionZenWritePaper : ActionContinuousBase
{
	void ActionZenWritePaper()
	{
		m_CallbackClass = ActionZenWritePaperCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#write_note";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(1.2);
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (GetGame().IsServer())
			return true;
		if (!item || !target.GetObject())
			return false;
		if (item.IsInherited(X18_Note) || target.GetObject().IsInherited(X18_Note))
			return false;
		if ((item.ConfigIsExisting("penColor") && Paper.Cast(target.GetObject())) || (target.GetObject().ConfigIsExisting("penColor") && Paper.Cast(item)))
		{
			return true;
		}
		return false;
	}
	override void OnStartClient(ActionData action_data)
	{
		ZenNoteGUI gui = ZenNoteGUI.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_ZEN_NOTE_GUI, NULL));
		if (gui)
		{
			Paper paper = Paper.Cast(action_data.m_MainItem);
			if (!paper)
				paper = Paper.Cast(action_data.m_Target.GetObject());
			Pen_ColorBase pen = Pen_ColorBase.Cast(action_data.m_MainItem);
			if (!pen)
				pen = Pen_ColorBase.Cast(action_data.m_Target.GetObject());
			gui.SetPaper(paper);
			gui.SetReadOnly(false);
			gui.SetPenColour(GetPenColour(pen));
		}
	}
	static int GetPenColour(Pen_ColorBase pen)
	{
		if (!pen)
			return 0;
		TIntArray rgbArray = new TIntArray();
		pen.ConfigGetIntArray("penColor", rgbArray);
		return ARGB(255, rgbArray[0], rgbArray[1], rgbArray[2]);
	}
};