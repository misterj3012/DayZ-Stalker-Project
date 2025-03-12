modded class DayZPlayerCamera1stPerson
{
	override float getLeanRollAngle()
	{
		return m_iPlayer.m_MovementState.m_fLeaning * Math.Lerp(getHeadLeanAngle(), -getHeadLeanAngle(), Math.AbsFloat(m_fLeftRightAngle) / (CONST_LR_MAX / 2));
	}
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
}