class MediKitTier1Mdfr : ModifierBase
{
	int m_EffectLifetime;
	float m_IncreaseHealth;
	float m_IncreaseWater;
	float m_IncreaseEnergy;
	float m_IncreaseBlood;
	float m_DecreaseRadiation;
	int m_RemoveCuts;
	int m_Ticks = 0;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_ID = X18MedicalModifiers.MDF_MEDIKIT_TIER1;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
		m_EffectLifetime = MedicalConfig.Tier1_MediKitDuration;
		m_IncreaseHealth = MedicalConfig.Tier1_MediKitHealth;
		m_IncreaseWater = MedicalConfig.Tier1_MediKitWater;
		m_IncreaseEnergy = MedicalConfig.Tier1_MediKitEnergy;
		m_IncreaseBlood = MedicalConfig.Tier1_MediKitBlood;
		m_DecreaseRadiation = MedicalConfig.Tier1_MediKitRadiation;
		m_RemoveCuts = MedicalConfig.Tier1_MediKitCuts;
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
	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	override void OnActivate(PlayerBase player)
	{
		player.IncreaseHealingsCount();
	}
	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseHealingsCount();
	}
	override void OnTick(PlayerBase player, float deltaT)
	{
		if (m_IncreaseHealth > 0)
			player.AddHealth("", "Health", m_IncreaseHealth / m_EffectLifetime);
		if (m_IncreaseWater > 0)
			player.GetStatWater().Add(m_IncreaseWater / m_EffectLifetime);
		if (m_IncreaseEnergy > 0)
			player.GetStatEnergy().Add(m_IncreaseEnergy / m_EffectLifetime);
		if (m_IncreaseBlood > 0)
			player.AddHealth("", "Blood", m_IncreaseBlood / m_EffectLifetime);
		if (m_DecreaseRadiation > 0)
			player.GetStatRadiation().Add(-m_DecreaseRadiation / m_EffectLifetime);
		if (m_RemoveCuts > 0)
		{
			float m_Time = m_EffectLifetime / m_RemoveCuts;
			if (m_Ticks >= m_Time)
			{
				BleedingSourcesManagerServer bleedingSourcesManagerServer = player.GetBleedingManagerServer();
				if (bleedingSourcesManagerServer)
					player.GetBleedingManagerServer().RemoveMostSignificantBleedingSource();
				m_Ticks = 0;
			}
			m_Ticks++;
		}
	}
};