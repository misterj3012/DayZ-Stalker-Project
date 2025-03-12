modded class Environment
{
	override void CollectAndSetEnvironmentData()
	{
		super.CollectAndSetEnvironmentData();
		Weather weather = g_Game.GetWeather();
		m_Rain = weather.GetRain().GetActual() + g_Game.GetMission().GetWorldData().GetWetnessEvent();
	}
	protected override float GetEnvironmentTemperature()
	{
		float temperature;
		temperature = g_Game.GetMission().GetWorldData().GetBaseEnvTemperature();
		temperature += Math.AbsFloat(temperature * m_Clouds * GameConstants.ENVIRO_CLOUDS_TEMP_EFFECT);
		if (IsWaterContact())
			temperature -= Math.AbsFloat(temperature * GameConstants.ENVIRO_WATER_TEMPERATURE_COEF);
		if (IsInside())
		{
			temperature += Math.AbsFloat(temperature * GameConstants.ENVIRO_TEMPERATURE_INSIDE_COEF);
		}
		else if (IsInsideVehicle())
		{
			temperature += Math.AbsFloat(temperature * GameConstants.ENVIRO_TEMPERATURE_INSIDE_VEHICLE_COEF);
		}
		else if (IsUnderRoof())
		{
			temperature += Math.AbsFloat(temperature * GameConstants.ENVIRO_TEMPERATURE_UNDERROOF_COEF);
			temperature -= GameConstants.ENVIRO_TEMPERATURE_WIND_COEF * GetWindModifierPerSurface() * m_Wind;
		}
		else
		{
			temperature -= GameConstants.ENVIRO_TEMPERATURE_WIND_COEF * GetWindModifierPerSurface() * m_Wind;
			temperature -= Math.AbsFloat(temperature * m_Fog * GameConstants.ENVIRO_FOG_TEMP_EFFECT);
			temperature -= GetTemperatureHeightCorrection();
		}
		if (Math.AbsFloat(m_UTSAverageTemperature) > 0.001)
			temperature += m_UTSAverageTemperature;
		return temperature;
	}
	bool IsInside()
	{
		return m_Player.m_IsInside;
	}
};