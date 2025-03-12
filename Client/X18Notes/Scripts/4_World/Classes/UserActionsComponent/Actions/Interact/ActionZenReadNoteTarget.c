class ActionZenReadNoteTarget : ActionInteractBase
{
	void ActionZenReadNote()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_Text = "Read note";
	}
	override string GetText()
	{
		return "Read note";
	}
	override bool IsInstant()
	{
		return true;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (target && target.GetObject().IsInherited(X18_Note))
			return true;
		return false;
	}
	override void OnStartServer(ActionData action_data)
	{
		X18_Note note = X18_Note.Cast(action_data.m_Target.GetObject());
		if (note)
		{
			auto data = new Param1<ref ZenNoteData>(note.GetNoteData());
			note.RPCSingleParam(ZENNOTERPCs.RECEIVE_WRITTEN_NOTE, data, true, action_data.m_Player.GetIdentity());
		}
	}
}