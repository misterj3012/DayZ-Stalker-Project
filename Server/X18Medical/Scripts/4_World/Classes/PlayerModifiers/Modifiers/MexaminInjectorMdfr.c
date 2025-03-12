class MexaminInjectorMdfr : ModifierBase
{
	float m_DecreaseRadiation;
	int m_EffectLifetime;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_ID = X18MedicalModifiers.MDF_MEXAMIN_INJECTOR;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
		m_DecreaseRadiation = MedicalConfig.DecreaseRadiationByMexamineStick;
		m_EffectLifetime = MedicalConfig.DecreaseRadiationByMexamineStickDuration;
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
		if (player.GetStatRadiation())
			player.GetStatRadiation().Add(-m_DecreaseRadiation / m_EffectLifetime);
	}
};