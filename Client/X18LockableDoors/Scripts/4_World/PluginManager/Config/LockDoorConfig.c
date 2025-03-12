class LockDoorConfig
{
	ref array<ref LockDoorStorage> AllDoorsData;

	void LockDoorConfig()
	{
		AllDoorsData = new array<ref LockDoorStorage>();
	}

	ref array<ref LockDoorStorage> GetAllDoorsData()
	{
		return AllDoorsData;
	}
}

class LockDoorStorage
{
	private vector DoorPos;
	private int AutoCloseDoorTime;
	private float DistBetweenPlayerAndDoor;
	private bool NeedKey;
	private ref array<string> AllowKeys;
	private bool FactionOnly;
	private ref array<string> Factions;
	private string Zone;
	private float Health;

	void LockDoorStorage(vector pos, int autoCloseDoorTime, float distBetweenPlayerAndDoor, ref array<string> keys, bool factionOnly, ref array<string> factions, bool needKey, string zone, float health)
	{
		DoorPos = pos;
		AutoCloseDoorTime = autoCloseDoorTime;
		DistBetweenPlayerAndDoor = distBetweenPlayerAndDoor;
		NeedKey = needKey;
		AllowKeys = keys;
		FactionOnly = factionOnly;
		Factions = factions;
		Zone = zone;
		Health = health;
	}

	vector GetPos() { return DoorPos; }
	float GetDistance() { return DistBetweenPlayerAndDoor; }
	ref array<string> GetAllowKeys() { return AllowKeys; }
	ref array<string> GetFactions() { return Factions; }
	bool GetNeedKey() { return NeedKey; }
	float GetHealth() { return Health; }
}