modded class FireplaceIndoor extends FireplaceBase
{
	const float	PARAM_IGNITE_RAIN_THRESHOLD 		= 5.1;
	const float	PARAM_BURN_WET_THRESHOLD 			= 0.40;
	const float	PARAM_WET_INCREASE_COEF 			= 0.02;
	
	void FireplaceIndoor()
	{
		m_LightDistance = 10;
	}
}