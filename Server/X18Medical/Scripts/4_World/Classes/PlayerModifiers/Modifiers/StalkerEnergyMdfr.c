class StalkerEnergyMdfr : ModifierBase
{
	int m_EffectLifetime;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_ID = X18MedicalModifiers.MDF_ENERGYSTALKER;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
		m_EffectLifetime = MedicalConfig.StalkerEnergyDuration;
		DisableActivateCheck();
	}
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	override void OnActivate(PlayerBase player)
	{
		GetRPCManager().SendRPC("X18", "CreateCameraShake", new Param1<float>(4.0), true, player.GetIdentity());
		player.GetStaminaHandler().SetStamina(100);
		player.GetStaminaHandler().ActivateDepletionModifier(EStaminaMultiplierTypes.EPINEPHRINE);
	}
	override void OnDeactivate(PlayerBase player)
	{
		GetRPCManager().SendRPC("X18", "CreateCameraShake", new Param1<float>(4.0), true, player.GetIdentity());
		player.GetStaminaHandler().DeactivateDepletionModifier(EStaminaMultiplierTypes.EPINEPHRINE);
	}
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		if (attached_time >= m_EffectLifetime)
			return true;
		else
			return false;
	}
};