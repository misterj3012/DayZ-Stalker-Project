modded class LockDoorConfig
{
	void Validate()
	{
		if (AllDoorsData.Count() == 0)
			AllDoorsData.Insert(new LockDoorStorage("4643.208008 57.579994 1560.214966", 5, 2.0, { "X18_Key_Admin" }, false, { "Admin" }, true, "Default", 100.0));
	}
}

modded class LockDoorStorage
{
	int GetAutoCloseDoorTime() { return AutoCloseDoorTime; }
	void SetHealth(float health)
	{
		private ref LockDoorConfig m_LockDoorConfig;
		JsonFileLoader<ref LockDoorConfig>.JsonLoadFile(LockableDoorsPath, m_LockDoorConfig);
		foreach(ref LockDoorStorage m_Doors : m_LockDoorConfig.AllDoorsData)
		{
			if (m_Doors.DoorPos == DoorPos)
			{
				float newHealth = Health + health;
				if (newHealth > 100)
				{
					Health = 100;
					m_Doors.Health = 100;
				}
				else
				{
					Health = newHealth;
					m_Doors.Health = newHealth;
				}
				JsonFileLoader<ref LockDoorConfig>.JsonSaveFile(LockableDoorsPath, m_LockDoorConfig);
				return;
			}
		}
		return;
	}
}