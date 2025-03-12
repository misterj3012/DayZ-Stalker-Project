#ifdef CF_MODULE_PERMISSIONS
modded class CF_Permission_PlayerBase
{
	protected float m_Radiation;
	protected int m_RadiationSickStage;

	override void OnSendHealth(ref ParamsWriteContext ctx)
	{
		super.OnSendHealth(ctx);
		ctx.Write(m_Radiation);
		ctx.Write(m_RadiationSickStage);
	}

	override void OnRecieveHealth(ref ParamsReadContext ctx)
	{
		super.OnRecieveHealth(ctx);
		ctx.Read(m_Radiation);
		ctx.Read(m_RadiationSickStage);
	}

	float GetRadiation()
	{
		return m_Radiation;
	}

	int GetRadiationSickStage()
	{
		return m_RadiationSickStage;
	}
};
#endif