#ifdef AMS_AdditionalMedicSupplies
modded class AMS_TestKitReport
{
	float m_RadiationSickStage;
	override void InitItemVariables()
	{
		super.InitItemVariables();
		RegisterNetSyncVariableFloat("m_RadiationSickStage");
	}
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (super.OnStoreLoad(ctx, version))
		{
			if (!ctx.Read(m_RadiationSickStage))
				return false;
			return true;
		}
		return false;
	}
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_RadiationSickStage);
	}
}
#endif