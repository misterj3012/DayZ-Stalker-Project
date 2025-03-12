modded class PlayerBase
{
	const float m_TimeOffset = 0.5;
	float m_Timeslice = 0;
	int IsInArea = -1;
	protected float StrengthOfRadiation;
	protected int RadiationSickStage = 0;
	int GeigerCounter = 0;
	ref AreaHandler m_AreaHandler;
	private PluginPlayerStatus m_PluginPlayerStatus;
	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("IsInArea");
		RegisterNetSyncVariableInt("RadiationSickStage");
		RegisterNetSyncVariableFloat("StrengthOfRadiation");
		m_PluginPlayerStatus = PluginPlayerStatus.Cast(GetPlugin(PluginPlayerStatus));

		if (GetGame().IsClient())
			m_AreaHandler = new AreaHandler(this);
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsClient())
		{
			switch (rpc_type) {
			case EcologyRPC.SENDAREADATA:
			{
				Param1<array<ref AreaData>> sendAreaData;
				if (!ctx.Read(sendAreaData))
					break;

				array<ref AreaData> areas;
				areas = sendAreaData.param1;
				m_AreaHandler.AddAreas(areas);
				break;
			}
			case EcologyRPC.SHOWRADIATIONONPLAYER:
			{
				Param2<int, float> showRadiationData;
				if (!ctx.Read(showRadiationData))
					return;

				if (showRadiationData.param1 == 0)
				{
					if (m_PluginPlayerStatus)
						m_PluginPlayerStatus.ShowRadiationOnPlayer(showRadiationData.param2);
				}
				else
				{
					if (m_PluginPlayerStatus)
						m_PluginPlayerStatus.ShowRadiationOnTarget(showRadiationData.param2);
				}
				break;
			}
			}
		}
	}
	void ShowRadiationSicknessSymbol(bool show)
	{
		if (m_PluginPlayerStatus)
			m_PluginPlayerStatus.ShowRadiationSicknessSymbol(show);
	}
	void ShowGeigerCounter(bool show)
	{
		if (m_PluginPlayerStatus)
			m_PluginPlayerStatus.ShowGeigerCounter(show);
	}
	void SetGeigerCounterValue(float value)
	{
		if (m_PluginPlayerStatus)
			m_PluginPlayerStatus.SetGeigerCounterValue(value);
	}
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		if (GetGame().IsClient())
		{
			if (m_AreaHandler)
			{
				m_Timeslice += deltaTime;
				if (m_Timeslice >= m_TimeOffset)
				{
					m_AreaHandler.TouchEvent();
					m_Timeslice = 0;
				}
			}
			if (GetRadiationSickStage() > 0)
				ShowRadiationSicknessSymbol(true);
			else
				ShowRadiationSicknessSymbol(false);
		}
	}
	void SetRadiationSickStage(int stage)
	{
		RadiationSickStage = stage;
		SetSynchDirty();
	}
	float GetIsInArea()
	{
		return IsInArea;
	}
	int GetRadiationSickStage()
	{
		return RadiationSickStage;
	}
	float GetStrengthOfRadiation()
	{
		return StrengthOfRadiation;
	}
	PlayerStatRadiation GetStatRadiation()
	{
		if (GetPlayerStats())
		{
			PlayerStatRadiation stat = PlayerStatRadiation.Cast(GetPlayerStats().GetStatObject(PlayerStats_Ecology.RADIATION));
			return stat;
		}
		return null;
	}
	EStatLevels GetStatLevelRadiation()
	{
		float m_Radiation = GetStatRadiation().Get();
		return GetStatLevelReverse(m_Radiation, PlayerConstants.RADIATION_CRITICAL, PlayerConstants.RADIATION_LOW, PlayerConstants.RADIATION_NORMAL, PlayerConstants.RADIATION_HIGH);
	}
}
modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_High", "dz/anims/workspaces/player/player_main/props/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/battery_charger.anm");
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_Low", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/gear/flashlight.anm");
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_Mid", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/gear/flashlight.anm");
	};
};