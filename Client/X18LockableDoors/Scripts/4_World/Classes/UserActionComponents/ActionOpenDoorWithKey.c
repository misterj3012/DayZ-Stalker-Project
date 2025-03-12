class ActionOpenDoorWithKeyCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
	}
};

class ActionOpenDoorWithKey : ActionContinuousBase
{
	void ActionOpenDoorWithKey()
	{
		m_CallbackClass = ActionOpenDoorWithKeyCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#unlock";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target) return false;
		if (!IsBuilding(target)) return false;
		if (!IsInReach(player, target, UAMaxDistances.SMALL)) return false;

		Building building;
		if (Class.CastTo(building, target.GetObject()))
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if (doorIndex != -1 && (!building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex)))
			{
				vector doorPos = building.GetDoorSoundPos(doorIndex);
				if (GetLDManager().IsFactionDoor(doorPos) != NULL && GetLDManager().IsDoorNeedKey(doorPos))
					return GetLDManager().IsRightKey(doorPos, item);

				/*array<string> m_Factions = GetLDManager().IsFactionDoor(doorPos);
				foreach(string m_Faction : m_Factions)
				{
					if (m_Faction == player.Faction)
					{
						if (GetLDManager().IsDoorNeedKey(doorPos))
							return GetLDManager().IsRightKey(doorPos, item);
					}
				}*/
				if (GetLDManager().IsFactionDoor(doorPos) == NULL && GetLDManager().IsDoorNeedKey(doorPos))
					return GetLDManager().IsRightKey(doorPos, item);
			}
		}
		return false;
	}
};