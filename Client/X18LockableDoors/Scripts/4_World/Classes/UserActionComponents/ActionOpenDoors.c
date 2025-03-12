modded class ActionOpenDoors
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			if (GetGame().IsClient())
			{
				Building building;
				if (Class.CastTo(building, target.GetObject()))
				{
					int dIdx = building.GetDoorIndex(target.GetComponentIndex());
					vector doorPos = building.GetDoorSoundPos(dIdx);
					LockDoorStorage fix;
					if (dIdx != -1 && GetLDManager() && GetLDManager().IsDoorExist(doorPos, fix))
						return false;
				}
			}
			return true;
		}
		return false;
	}
}