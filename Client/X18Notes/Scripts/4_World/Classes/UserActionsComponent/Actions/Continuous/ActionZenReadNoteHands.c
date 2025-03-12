class ActionZenReadNoteHandsCB : ActionContinuousBaseCB {}
class ActionZenReadNoteHands : ActionContinuousBase
{
	void ActionZenReadNoteHands()
	{
		m_CallbackClass = ActionZenReadNoteHandsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#read";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (GetGame().IsServer())
			return true;
		if (target && target.GetObject() && target.GetObject().IsInherited(X18_Note))
			return false;
		return item && item.IsInherited(X18_Note) && !player.IsPlacingLocal();
	}
	override void OnStartServer(ActionData action_data)
	{
		X18_Note note = X18_Note.Cast(action_data.m_MainItem);
		if (note)
		{
			auto data = new Param1<ref ZenNoteData>(note.GetNoteData());
			note.RPCSingleParam(ZENNOTERPCs.RECEIVE_WRITTEN_NOTE, data, true, action_data.m_Player.GetIdentity());
		}
	}
};