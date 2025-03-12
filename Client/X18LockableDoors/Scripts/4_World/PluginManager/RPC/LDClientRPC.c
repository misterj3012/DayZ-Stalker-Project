class LDClientRPC : PluginBase
{
	void LDClientRPC()
	{
		GetRPCManager().AddRPC("X18", "SetDoorDataFromServer", this, SingleplayerExecutionType.Both);
	}

	void SetDoorDataFromServer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param1<ref LockDoorConfig> lockableDoorData;
			if (!ctx.Read(lockableDoorData))
				return;
			GetLDConfigHandler().SetConfig(lockableDoorData.param1);
		}
	}
}