class ActionStartEmission : ActionInteractBase
{
	void ActionStartEmission()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursorParent(UAMaxDistances.DEFAULT);
	}
	override string GetText()
	{
		return "Run Experiment";
	}
	override typename GetInputType()
	{
		return InteractActionInput;
	}
	override void OnEndServer(ActionData action_data)
	{
		//EventManager.GetInstance().StartEvent(Emission, true);
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		/*land_a2_basement_3rd basement_3rd;
		if (!Class.CastTo(basement_3rd, target.GetObject())) {
			return false;
		}
		bool is_in_range = vector.Distance(basement_3rd.WorldToModel(player.GetPosition()), "4.5 -1.5 10.81") < 2;
		return (is_in_range && !EventManager.GetInstance().IsEventActive(Emission));*/
	}
}