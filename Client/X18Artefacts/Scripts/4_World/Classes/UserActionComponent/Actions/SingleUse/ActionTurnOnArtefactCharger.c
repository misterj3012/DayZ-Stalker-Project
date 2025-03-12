class ActionTurnOnArtefactCharger : ActionInteractBase
{
	void ActionTurnOnArtefactCharger()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#switch_on";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (IsInReach(player, target, UAMaxDistances.DEFAULT))
		{
			X18_ArtefactCharger building = X18_ArtefactCharger.Cast(target.GetObject());
			if (building)
			{
				EntityAI chargedartifact = building.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("ArtefactSlot1"));
				EntityAI batteryartifact = building.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("BatteryArtefact"));

				if (!building.IsOpen() && batteryartifact && chargedartifact && !building.GetCompEM().IsSwitchedOn())
				{
					return true;
				}
			}
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		X18_ArtefactCharger building = X18_ArtefactCharger.Cast(action_data.m_Target.GetObject());
		if (building)
		{
			building.GetCompEM().SwitchOn();
		}
	}
};