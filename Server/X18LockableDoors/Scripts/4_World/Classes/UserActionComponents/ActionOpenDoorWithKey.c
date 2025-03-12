modded class ActionOpenDoorWithKey
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		Building building;
		if (Class.CastTo(building, action_data.m_Target.GetObject()))
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if (doorIndex != -1)
			{
				building.OpenDoor(doorIndex);
				vector doorPos = building.GetDoorSoundPos(doorIndex);
				LockDoorStorage doorData;
				if (GetLDManager() && GetLDManager().IsDoorExist(doorPos, doorData))
					GetLDManager().OnDoorOpen(doorIndex, building, doorData);
			}
		}
	}
};