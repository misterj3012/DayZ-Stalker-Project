class ActionChangeLocation : ActionSingleUseBase
{
	void ActionChangeLocation()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#STR_Compass_Change_Location";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		X18_Artefact_Compass_Base m_Compass;
		if (CastTo(m_Compass, item))
		{
			if (m_Compass.GetCompEM().IsWorking())
				return true;
		}

		return false;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		X18_Artefact_Compass_Base m_Compass = X18_Artefact_Compass_Base.Cast(action_data.m_MainItem);
		m_Compass.SetNextLocation();
	}
}