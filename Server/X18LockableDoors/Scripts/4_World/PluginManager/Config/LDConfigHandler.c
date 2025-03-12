modded class LDConfigHandler
{
	void LDConfigHandler()
	{
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			return;

		if (FileExist(LockableDoorsPath) && ldConfig == NULL)
		{
			JsonFileLoader<LockDoorConfig>.JsonLoadFile(LockableDoorsPath, ldConfig);
			ldConfig.Validate();
			JsonFileLoader<LockDoorConfig>.JsonSaveFile(LockableDoorsPath, ldConfig);
		}
		else
		{
			ldConfig = new LockDoorConfig();
			ldConfig.Validate();
			JsonFileLoader<LockDoorConfig>.JsonSaveFile(LockableDoorsPath, ldConfig);
		}
	}
}