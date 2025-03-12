modded class ActionCloseDoors
{
	private float _Health = 100.0;

	override string GetText()
	{
		if (_Health <= 0.0)
			return "#destroyed";
		return "#close";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;
		if (!IsBuilding(target))
			return false;

		Building building;
		if (Class.CastTo(building, target.GetObject()))
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if (doorIndex != -1)
			{
				vector doorPos = building.GetDoorSoundPos(doorIndex);
				if (GetLDManager().IsFactionDoor(doorPos) != NULL)
				{
					_Health = GetLDManager().GetDoorHealth(doorPos);
					if (_Health <= 0.0)
						return false;
				}

				if (!IsInReach(player, target, 3.5))
					return false;

				return building.IsDoorOpen(doorIndex);
			}
		}
		return false;
	}
};