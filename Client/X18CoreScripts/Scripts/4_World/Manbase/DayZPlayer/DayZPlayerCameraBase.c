modded class DayZPlayerCameraBase
{
	protected DayZPlayerImplement m_iPlayer;
	protected float m_time;
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput)
	{
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);
	}
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
	protected void updateCamAngles(float pDt, DayZPlayerCameraResult pOutResult)
	{
		m_time += pDt;
		vector camAngles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);

		if (canApplyHeadLean())
			applyHeadLean(pDt, camAngles);

		Math3D.YawPitchRollMatrix(camAngles, pOutResult.m_CameraTM);
	}
	protected bool canApplyHeadLean()
	{
		return !m_pPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE);
	}
	protected void applyHeadLean(float pDt, out vector angles)
	{
		angles[2] = angles[2] + getLeanRollAngle();
	}
	protected float getLeanRollAngle()
	{
		return m_iPlayer.m_MovementState.m_fLeaning * getHeadLeanAngle();
	}
	protected static float getHeadLeanAngle()
	{
		return 15.0;
	}
}