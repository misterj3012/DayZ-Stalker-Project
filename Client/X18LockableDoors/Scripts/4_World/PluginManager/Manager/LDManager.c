class LDManager : PluginBase
{
	void LDManager() {}
	bool IsDoorNeedKey(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
			return doorData.GetNeedKey();
		return true;
	}
	bool IsRightKey(vector doorPos, ItemBase key)
	{
		if (!key)
			return false;
		array<string> AllowKeys = GetKeysByDoorPos(doorPos);
		if (AllowKeys && (AllowKeys.Find(key.GetType()) != -1))
			return true;
		return false;
	}
	array<string> IsFactionDoor(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
			return doorData.GetFactions();
		return NULL;
	}
	bool IsDoorExist(vector pos, out LockDoorStorage doorData)
	{
		array<ref LockDoorStorage> AllDoorsData = GetLDConfigHandler().GetConfig().GetAllDoorsData();
		for (int i = 0; i < AllDoorsData.Count(); i++)
		{
			LockDoorStorage singleDoor = AllDoorsData.Get(i);
			if (InDistance(pos, singleDoor.GetPos(), singleDoor.GetDistance()))
			{
				doorData = singleDoor;
				return true;
			}
		}
		return false;
	}
	float GetDoorHealth(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
			return doorData.GetHealth();
		return 0.0;
	}
	ref array<string> GetKeysByDoorPos(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
			return doorData.GetAllowKeys();
		return null;
	}
}
LDManager GetLDManager()
{
	return LDManager.Cast(GetPlugin(LDManager));
}