modded class DayZGame
{
	protected ref X18Config m_X18Config;
	void SetX18Config(X18Config config)
	{
		m_X18Config = config;
	}
	X18Config GetX18Config()
	{
		return m_X18Config;
	}
	void DayZGame()
	{
		SetX18Config(X18ConfigServer.LoadConfig());
	}
}