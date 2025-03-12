class LDConfigHandler : PluginBase
{
	ref LockDoorConfig ldConfig;

	void LDConfigHandler() {}

	ref LockDoorConfig GetConfig()
	{
		return ldConfig;
	}

	void SetConfig(LockDoorConfig config)
	{
		ldConfig = config;
	}
}

LDConfigHandler GetLDConfigHandler()
{
	return LDConfigHandler.Cast(GetPlugin(LDConfigHandler));
}