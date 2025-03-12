class ActionTurnOffArtefactCharger : ActionInteractBase
{
	void ActionTurnOffArtefactCharger()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#switch_off";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (IsInReach(player, target, UAMaxDistances.DEFAULT))
		{
			X18_ArtefactCharger building = X18_ArtefactCharger.Cast(target.GetObject());
			if (building)
			{
				return building.GetCompEM().CanSwitchOff();
			}
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		X18_ArtefactCharger building = X18_ArtefactCharger.Cast(action_data.m_Target.GetObject());
		if (building)
		{
			building.GetCompEM().SwitchOff();
		}
	}
}