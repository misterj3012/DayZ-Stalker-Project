class PC1Mdfr : ModifierBase
{
	int m_EffectLifetime;
	static const int WATER_DRAIN_FROM_VOMIT = 70;
	static const int ENERGY_DRAIN_FROM_VOMIT = 55;
	static const float STOMACH_MIN_VOLUME = 200;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_ID = X18MedicalModifiers.MDF_PC1;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
		m_EffectLifetime = MedicalConfig.PC1Duration;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		if (attached_time >= m_EffectLifetime)
			return true;
		else
			return false;
	}
	override void OnActivate(PlayerBase player)
	{
		player.IncreaseHealingsCount();
		player.UpdateRadiationShield();
	}
	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseHealingsCount();
		player.UpdateRadiationShield();
	}
	override void OnTick(PlayerBase player, float deltaT)
	{
		float m_PC1 = player.GetSingleAgentCount(X18MedicalAgents.PC1);
		if (player.IsUnconscious())
			return;
		if (m_PC1 >= 5 && (0.15 > Math.RandomFloatInclusive(0, 1)))
		{
			float stomach_volume = player.m_PlayerStomach.GetStomachVolume();
			if (stomach_volume >= STOMACH_MIN_VOLUME)
			{
				SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				if (symptom)
				{
					symptom.SetDuration(Math.RandomIntInclusive(4, 8));
					if (m_Player.GetStatWater().Get() > (WATER_DRAIN_FROM_VOMIT))
						m_Player.GetStatWater().Add(-1 * WATER_DRAIN_FROM_VOMIT);
					if (m_Player.GetStatEnergy().Get() > (ENERGY_DRAIN_FROM_VOMIT))
						m_Player.GetStatEnergy().Add(-1 * ENERGY_DRAIN_FROM_VOMIT);
				}
			}
		}
		if (m_PC1 >= 7 && (0.2 > Math.RandomFloatInclusive(0, 1)))
			player.SetHealth("", "Shock", 20);
	}
};