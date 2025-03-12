class ActionTurnOffStorageLights : ActionInteractBase
{
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
			X18_ArtefactStorage building = X18_ArtefactStorage.Cast(target.GetObject());
			if (building)
			{
				return building.GetCompEM().CanSwitchOff();
			}
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		X18_ArtefactStorage building = X18_ArtefactStorage.Cast(action_data.m_Target.GetObject());
		if (building)
		{
			building.GetCompEM().SwitchOff();
		}
	}
};