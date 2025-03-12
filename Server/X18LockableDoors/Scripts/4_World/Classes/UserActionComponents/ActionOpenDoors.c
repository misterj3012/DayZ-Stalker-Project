modded class ActionOpenDoors
{
	override void OnStartServer(ActionData action_data)
	{
		Building building;
		if (Class.CastTo(building, action_data.m_Target.GetObject()))
		{
			int dIdx = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			vector doorPos = building.GetDoorSoundPos(dIdx);
			if (dIdx != -1)
			{
				building.OpenDoor(dIdx);
#ifdef DIAG_DEVELOPER
				PlayerBase m_Player;
				if (CastTo(m_Player, action_data.m_Player))
					m_Player.SendMessage("doorPos: " + doorPos);
#endif

				LockDoorStorage doorData;
				if (GetLDManager() && GetLDManager().IsDoorExist(doorPos, doorData))
					GetLDManager().OnDoorOpen(dIdx, building, doorData);
			}
			else
				super.OnStartServer(action_data);
		}
	}
}