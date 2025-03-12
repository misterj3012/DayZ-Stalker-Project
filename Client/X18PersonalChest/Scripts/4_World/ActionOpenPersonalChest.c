class ActionOpenPersonalChest : ActionInteractBase
{
	void ActionOpenPersonalChest()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	override string GetText()
	{
		return "#open";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;
		if (!IsBuilding(target))
			return false;
		X18_PersonalChest_Base chest;
		if (Class.CastTo(chest, target.GetObject()) && !player.IsPersonalOpeninig() && !player.IsPersonalOpened())
			return true;
		return false;
	}
	override void OnStartClient(ActionData action_data)
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player)
			player.SetPersonalOpening();
	}
	override void OnEndClient(ActionData action_data)
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player)
			player.OpenPersonalInventory();
	}
}