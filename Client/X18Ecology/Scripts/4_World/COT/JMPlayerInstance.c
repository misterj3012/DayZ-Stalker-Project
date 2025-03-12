#ifdef JM_COT
modded class JMPlayerInstance
{

	protected float m_Radiation;
	protected int m_RadiationSickStage;

	void Update()
	{
		if (GetGame().IsServer() && (GetGame().GetTime() - m_DataLastUpdated) >= 100)
		{
			if (!GetGame().IsMultiplayer())
			{
				Class.CastTo(PlayerObject, GetGame().GetPlayer());
			}

			if (PlayerObject)
			{
				m_DataLastUpdated = GetGame().GetTime();

				m_Position = PlayerObject.GetPosition();
				m_Orientation = PlayerObject.GetOrientation();

				m_Health = PlayerObject.GetHealth("GlobalHealth", "Health");
				m_Blood = PlayerObject.GetHealth("GlobalHealth", "Blood");
				m_Shock = PlayerObject.GetHealth("GlobalHealth", "Shock");

				m_Radiation = PlayerObject.GetStatRadiation().Get();
				m_RadiationSickStage = PlayerObject.GetRadiationSickStage();

				m_BloodStatType = PlayerObject.GetStatBloodType().Get();

				m_Energy = PlayerObject.GetStatEnergy().Get();
				m_Water = PlayerObject.GetStatWater().Get();
				m_HeatComfort = PlayerObject.GetStatHeatComfort().Get();
				m_Wet = PlayerObject.GetStatWet().Get();
				m_Tremor = PlayerObject.GetStatTremor().Get();
				m_Stamina = PlayerObject.GetStatStamina().Get();
				m_LifeSpanState = PlayerObject.GetLifeSpanState();
				m_BloodyHands = PlayerObject.HasBloodyHands();
				m_GodMode = PlayerObject.COTHasGodMode();
				m_Frozen = PlayerObject.COTIsFrozen();
				m_Invisibility = PlayerObject.COTIsInvisible();
				m_UnlimitedAmmo = PlayerObject.COTHasUnlimitedAmmo();
				m_UnlimitedStamina = PlayerObject.COTHasUnlimitedStamina();
				m_BrokenLegs = PlayerObject.m_BrokenLegState != eBrokenLegs.NO_BROKEN_LEGS;
			}
		}
	}

	override void OnSendHealth(ref ParamsWriteContext ctx)
	{
		super.OnSendHealth(ctx);
		ctx.Write(m_Radiation);
		ctx.Write(m_RadiationSickStage);
	}

	override void OnRecieveHealth(ref ParamsReadContext ctx)
	{
		super.OnRecieveHealth(ctx);
		ctx.Read(m_Radiation);
		ctx.Read(m_RadiationSickStage);
	}

	float GetRadiation()
	{
		return m_Radiation;
	}

	int GetRadiationSickStage()
	{
		return m_RadiationSickStage;
	}
};
#endif