modded class PlayerBase
{
	protected string m_FactionString;
	protected float m_TemperatureAroundPlayer;
	protected bool m_Undercover;
	protected bool m_GPSEnabled = true;

	protected int m_Faction;

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableFloat("m_TemperatureAroundPlayer");
		RegisterNetSyncVariableBool("m_GPSEnabled");
		RegisterNetSyncVariableBool("m_Undercover");
		RegisterNetSyncVariableInt("m_Faction");

		m_Faction = -1;

		PluginPDA m_PluginPDA;
		if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)))
		{
			m_PluginPDA.m_options.m_ShareGPS = true;
			m_PluginPDA.m_options.m_Muted = false;
			m_PluginPDA.m_options.m_Undercover = false;
		}
	}
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(ActionOpenPDA, InputActionMap);
	}
	// void SetFaction(string faction)
	// {
	// 	m_FactionString = faction;
	// }
	int GetFaction()
	{
		return m_Faction;
	}
	void SetTemperatureAroundPlayer(float temperature)
	{
		m_TemperatureAroundPlayer = temperature;
		SetSynchDirty();
	}
	float GetTemperatureAroundPlayer()
	{
		return m_TemperatureAroundPlayer;
	}
	void SetUndercoverStatus(bool undercover)
	{
		m_Undercover = undercover;
		SetSynchDirty();
	}
	bool IsUndercover()
	{
		return m_Undercover;
	}
	void SetGPSStatus(bool status)
	{
		m_GPSEnabled = status;
		SetSynchDirty();
	}
	bool HasGPSEnabled()
	{
		return m_GPSEnabled;
	}
	int GetEnvironmentTemperature()
	{
		if (m_Environment)
			return Math.Round(m_Environment.GetTemperature());
		return 0;
	}
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		if (GetGame().IsServer())
			SetTemperatureAroundPlayer(Math.Round(GetEnvironmentTemperature()));
	}
}
modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("X18_PDA", "dz/anims/workspaces/player/player_main/props/player_main_1h_radio.asi", pBehavior, "dz/anims/anm/player/ik/gear/cassette.anm");
	}
}