class RadiationSicknessMdfr : ModifierBase
{
	const int DEFAULT_TICK_TIME_ACTIVE = 1;
	const int DEFAULT_TICK_TIME_INACTIVE = 1;
	int m_Tick = 0;
	bool m_HasFever;
	int m_WaterDrainVomit;
	int m_EnergyDrainVomit;
	float m_ChanceVomit;
	float m_ChanceBleeding;
	float m_ChanceUnconscious;
	float m_ChanceBlindness;
	float m_ChanceDepletingStamina;
	float m_RadHighMultiplier;
	float m_RadHealthDamage;
	int m_RadBloodLossDamage;
	const ref array<string> m_BleedingZones = { "Head", "Neck", "Pelvis", "Spine", "LeftShoulder", "LeftArm", "LeftArmRoll", "LeftForeArm", "RightShoulder", "RightArm", "RightArmRoll", "RightForeArm", "LeftForeArmRoll", "RightForeArmRoll", "LeftLeg", "LeftLegRoll", "LeftUpLeg", "LeftUpLegRoll", "RightLeg", "RightLegRoll", "RightUpLeg", "RightUpLegRoll", "LeftFoot", "LeftToeBase", "RightFoot", "RightToeBase" };
	const float m_RadiationPoisoning1 = 500;
	const float m_RadiationPoisoning2 = 1000;
	const float m_RadiationPoisoning3 = 3000;
	const float m_RadiationDisease1 = 6000;
	const float m_RadiationDisease2 = 8000;
	const float m_RadiationDisease3 = 10000;
	ref Param1<int> m_RadiationSickStage = new Param1<int>(0);
	ref Param1<int> m_RegenTime = new Param1<int>(0);
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_ID = EcologyModifiers.MDF_RADIATIONSICKNESS;
		m_TickIntervalInactive = DEFAULT_TICK_TIME_ACTIVE;
		m_TickIntervalActive = DEFAULT_TICK_TIME_INACTIVE;
		m_IsPersistent = true;
		m_Tick = 0;
		m_HasFever = false;
		MakeParamObjectPersistent(m_RadiationSickStage);
		MakeParamObjectPersistent(m_RegenTime);
		m_WaterDrainVomit = RadiationConfig.RadWaterDrainVomit;
		m_EnergyDrainVomit = RadiationConfig.RadEnergyDrainVomit;
		m_ChanceDepletingStamina = RadiationConfig.RadChanceDepletingStamina;
		m_ChanceVomit = RadiationConfig.RadChanceVomit;
		m_ChanceBleeding = RadiationConfig.RadChanceBleeding;
		m_ChanceUnconscious = RadiationConfig.RadChanceUnconscious;
		m_ChanceBlindness = RadiationConfig.RadChanceBlindness;
		m_RadHighMultiplier = RadiationConfig.RadHighMultiplier;
		m_RadHealthDamage = RadiationConfig.RadHealthDamage;
		m_RadBloodLossDamage = RadiationConfig.RadBloodLossDamage;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		if (!IsActive() && player.GetStatRadiation().Get() >= m_RadiationPoisoning1)
			return true;
		else
			return false;
	}
	override void OnActivate(PlayerBase player)
	{
		player.IncreaseDiseaseCount();
	}
	override void OnReconnect(PlayerBase player)
	{
		player.SetRadiationSickStage(m_RadiationSickStage.param1);
		OnActivate(player);
	}
	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs.SYMPTOM_VOMIT);
	}
	override bool DeactivateCondition(PlayerBase player)
	{
		if (player.GetRadiationSickStage() == 0 && player.GetStatRadiation().Get() <= m_RadiationPoisoning1)
			return true;
		else
			return false;
	}
	override void OnTick(PlayerBase player, float deltaT)
	{
		if (player.IsAdminActive())
			return;

		if (player.GetStatRadiation().Get() >= m_RadiationPoisoning1 && player.GetRadiationSickStage() <= 1)
		{
			player.SetRadiationSickStage(1);
			SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
		}
		if (player.GetStatRadiation().Get() >= m_RadiationPoisoning2 && player.GetRadiationSickStage() <= 2)
		{
			player.SetRadiationSickStage(2);
			if (m_Tick >= 65)
			{
				SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
				m_Tick = 0;
			}
		}
		if (player.GetStatRadiation().Get() >= m_RadiationPoisoning3 && player.GetRadiationSickStage() <= 3)
		{
			player.SetRadiationSickStage(3);
			if (m_Tick >= 55)
			{
				SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
				m_Tick = 0;
			}
		}
		if (player.GetStatRadiation().Get() >= m_RadiationDisease1 && player.GetRadiationSickStage() <= 4)
		{
			player.SetRadiationSickStage(4);
			if (m_Tick >= 45)
			{
				SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
				m_Tick = 0;
			}
		}
		if (player.GetStatRadiation().Get() >= m_RadiationDisease2 && player.GetRadiationSickStage() <= 5)
		{
			player.SetRadiationSickStage(5);
			if (m_Tick >= 30)
			{
				SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
				m_Tick = 0;
			}
		}
		if (player.GetStatRadiation().Get() >= m_RadiationDisease3 && player.GetRadiationSickStage() <= 6)
		{
			player.SetRadiationSickStage(6);
			if (m_Tick >= 20)
			{
				SetRadiationSicknessEffect(player.GetRadiationSickStage(), m_RadHighMultiplier, player);
				m_Tick = 0;
			}
		}
		CheckRadiationReduction(player);
		++m_Tick;
	}
	void CheckRadiationReduction(PlayerBase player)
	{
		array<int> timeStamp = { 0, RadiationRegenTime.L1, RadiationRegenTime.L2, RadiationRegenTime.L3, RadiationRegenTime.L4, RadiationRegenTime.L5, RadiationRegenTime.L6 };
		array<float> radLimit = { 0, m_RadiationPoisoning1, m_RadiationPoisoning2, m_RadiationPoisoning3, m_RadiationDisease1, m_RadiationDisease2, m_RadiationDisease3 };
		if (player.GetStatRadiation().Get() < radLimit.Get(player.GetRadiationSickStage()))
		{
			m_RegenTime.param1 = m_RegenTime.param1 + m_TickIntervalActive;
			if (m_RegenTime.param1 >= timeStamp.Get(player.GetRadiationSickStage()))
			{
				player.SetRadiationSickStage(player.GetRadiationSickStage() - 1);
				m_RegenTime.param1 = 0;
			}
		}
	};
	void SetRadiationSicknessEffect(int radiationSicknessStage, float radMultiplier, PlayerBase player)
	{
		if (radiationSicknessStage == 1 || radiationSicknessStage == 2 || radiationSicknessStage == 3 || radiationSicknessStage == 4 || radiationSicknessStage == 5 || radiationSicknessStage == 6)
		{
			if (!m_HasFever)
			{
				player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
				m_HasFever = true;
			}
		}
		if (radiationSicknessStage == 2)
		{
			if (m_ChanceVomit > Math.RandomFloatInclusive(0, 1))
			{
				SymptomBase vomitSymptom1 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				if (vomitSymptom1)
				{
					vomitSymptom1.SetDuration(Math.RandomFloatInclusive(2, 4));
					if (m_Player.GetStatWater().Get() > (m_WaterDrainVomit / 2))
						m_Player.GetStatWater().Add(-1 * m_WaterDrainVomit / 2);
					if (m_Player.GetStatEnergy().Get() > (m_EnergyDrainVomit / 2))
						m_Player.GetStatEnergy().Add(-1 * m_EnergyDrainVomit / 2);
				}
			}
		}
		if (radiationSicknessStage == 3)
		{
			if (m_ChanceDepletingStamina > Math.RandomFloatInclusive(0, 1))
				player.GetStaminaHandler().DepleteStamina(EStaminaModifiers.MELEE_LIGHT);
			if (m_ChanceVomit > Math.RandomFloatInclusive(0, 1))
			{
				SymptomBase vomitSymptom2 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				if (vomitSymptom2)
				{
					if (radiationSicknessStage == 3)
						vomitSymptom2.SetDuration(Math.RandomFloatInclusive(4, 6));
					if (m_Player.GetStatWater().Get() > (m_WaterDrainVomit))
						m_Player.GetStatWater().Add(-1 * m_WaterDrainVomit);
					if (m_Player.GetStatEnergy().Get() > (m_EnergyDrainVomit))
						m_Player.GetStatEnergy().Add(-1 * m_EnergyDrainVomit);
				}
			}
			if (m_ChanceBleeding > Math.RandomFloatInclusive(0, 1))
				player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingZones.GetRandomElement());
		}
		if (radiationSicknessStage == 4 || radiationSicknessStage == 5 || radiationSicknessStage == 6)
		{
			if (m_ChanceDepletingStamina > Math.RandomFloatInclusive(0, 1))
				player.GetStaminaHandler().DepleteStamina(EStaminaModifiers.MELEE_LIGHT);
			if (m_ChanceVomit > Math.RandomFloatInclusive(0, 1))
			{
				SymptomBase vomitSymptom3 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				if (vomitSymptom3)
				{
					if (radiationSicknessStage == 4)
						vomitSymptom3.SetDuration(Math.RandomFloatInclusive(6, 8));
					if (radiationSicknessStage == 5 || radiationSicknessStage == 6)
						vomitSymptom3.SetDuration(Math.RandomFloatInclusive(8, 12));
					if (m_Player.GetStatWater().Get() > (m_WaterDrainVomit * m_RadHighMultiplier))
						m_Player.GetStatWater().Add(-1 * m_WaterDrainVomit * m_RadHighMultiplier);
					if (m_Player.GetStatEnergy().Get() > (m_EnergyDrainVomit * m_RadHighMultiplier))
						m_Player.GetStatEnergy().Add(-1 * m_EnergyDrainVomit * m_RadHighMultiplier);
				}
			}
			if (m_ChanceBleeding > Math.RandomFloatInclusive(0, 1))
				player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingZones.GetRandomElement());
			float currenthealth = player.GetHealth("GlobalHealth", "Blood");
			player.SetHealth("GlobalHealth", "Blood", currenthealth - m_RadBloodLossDamage * radMultiplier);
			currenthealth = player.GetHealth();
			player.SetHealth(currenthealth - m_RadHealthDamage * radMultiplier);
		}
		m_RadiationSickStage.param1 = radiationSicknessStage;
	}
}