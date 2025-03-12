modded class LDManager
{
	private int AutoCloseDoorTime;
	void LDManager()
	{
		AutoCloseDoorTime = -1;
	}
	void OnDoorOpen(int doorIdx, Building building, LockDoorStorage doorData)
	{
		AutoCloseDoorTime = doorData.GetAutoCloseDoorTime();
		if (AutoCloseDoorTime > 0)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(building.CloseDoor, AutoCloseDoorTime * 1000, false, doorIdx);
	}
	void SetDoorHealth(vector doorPos, float health)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
			doorData.SetHealth(health);
	}
}