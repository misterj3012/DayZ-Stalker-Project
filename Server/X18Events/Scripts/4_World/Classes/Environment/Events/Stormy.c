class Stormy : WeatherEvent
{
	override float GetInitPhaseLength()
	{
		return 120.0;
	}
	override float GetMidPhaseLength()
	{
		return Math.RandomFloat(300, 600);
	}
	override float GetEndPhaseLength()
	{
		return GetInitPhaseLength();
	}
	void Stormy()
	{
		if (GetGame().IsServer())
		{
			m_WindRelMinTarget = 0.2;
			m_WindRelMaxTarget = 0.4;
			m_WindTargetSpeed = Math.RandomFloat(20.0, 30.0);
		}
	}
	override void InitPhaseServer()
	{
		m_Weather.GetWindFunctionParams(m_WindRelMin, m_WindRelMax, m_WindChangeSpeed);
		m_Weather.SetWindFunctionParams(m_WindRelMinTarget, m_WindRelMaxTarget, m_WindChangeSpeed);
		m_Weather.SetStorm(Math.RandomFloat(0.0, 0.5), Math.RandomFloat(0.5, 0.6), Math.RandomFloat(10.0, 30.0));
		super.InitPhaseServer();
	}
	override void MidPhaseServer()
	{
		m_Weather.SetWindMaximumSpeed(m_WindTargetSpeed);
		m_Weather.SetStorm(Math.RandomFloat(1.0, 1.0), 0.6, Math.RandomFloat(2.0, 8.0));
		super.MidPhaseServer();
	}
	override void EndPhaseServer()
	{
		m_Weather.SetWindFunctionParams(m_WindRelMinTarget, m_WindRelMaxTarget, m_WindChangeSpeed);
		m_Weather.SetStorm(Math.RandomFloat(0.0, 0.2), Math.RandomFloat(0.5, 0.6), Math.RandomFloat(10.0, 30.0));
		super.EndPhaseServer();
	}
	override void OnEventEndServer()
	{
		m_Weather.SetWindMaximumSpeed(1.5);
		m_Weather.SetWindFunctionParams(m_WindRelMin, m_WindRelMax, m_WindChangeSpeed);
		m_Weather.SetStorm(0.0, 0.0, 0.0);
		super.OnEventEndServer();
	}
	override float GetFogTarget()
	{
		return Math.RandomFloatInclusive(0.05, 0.15);
	}
	override float GetRainTarget()
	{
		return Math.RandomFloatInclusive(0.0, 0.90);
	}
	override float GetOvercastTarget()
	{
		return Math.RandomFloatInclusive(0.8, 0.9);
	}
	override TTypenameArray GetDisallowedEvents()
	{
		return { Emission, Sunny };
	}
}