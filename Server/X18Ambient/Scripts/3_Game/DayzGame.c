modded class DayZGame
{
  protected ref RadioConfig m_RadioConfig;
  void SetRadioConfig(RadioConfig config)
  {
    m_RadioConfig = config;
  }
  RadioConfig GetRadioConfig()
  {
    return m_RadioConfig;
  }
}