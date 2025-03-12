modded class WorldData
{
	protected float m_TemperatureEvent;
	protected float m_WetnessEvent;
	override void Init()
	{
		super.Init();
		m_TemperatureEvent = 0.0;
		m_WetnessEvent = 0.0;
	}
	float GetTemperatureEvent()
	{
		return m_TemperatureEvent;
	}
	float GetWetnessEvent()
	{
		return m_WetnessEvent;
	}
	void SetTemperatureEvent(float tempEvent)
	{
		m_TemperatureEvent = tempEvent;
	}
	override float GetBaseEnvTemperature()
	{
		return super.GetBaseEnvTemperature() + GetTemperatureEvent();
	}
	void SetWetnessEvent(float wetness)
	{
		m_WetnessEvent = wetness;
	}
};