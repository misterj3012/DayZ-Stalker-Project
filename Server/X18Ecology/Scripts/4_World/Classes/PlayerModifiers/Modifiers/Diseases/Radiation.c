class RadiationMdfr : ModifierBase
{
	float m_DecreaseRadiation;
	int m_EffectLifetime;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID = EcologyModifiers.MDF_RADIATION;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
		m_DecreaseRadiation = RadiationConfig.DecreaseRadiationByItself;
		m_EffectLifetime = RadiationConfig.DecreaseRadiationByItselfDuration;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}
	override void OnActivate(PlayerBase player)
	{}
	override void OnReconnect(PlayerBase player)
	{}
	override void OnDeactivate(PlayerBase player)
	{}
	override bool DeactivateCondition(PlayerBase player)
	{
		return false;
	}
	override void OnTick(PlayerBase player, float deltaT)
	{
		if (player.IsAdminActive())
			return;
		float l_Shield = player.Shield;
		if (player.GetStrengthOfRadiation() > 0 && l_Shield <= 100)
		{
			float l_Radiation = player.GetStrengthOfRadiation() / 60 / 2;
			float p_Radiation = 0;
			if (l_Shield > 0)
			{
				float calc1 = (l_Radiation / 100) * l_Shield;
				float calc2 = l_Radiation - calc1;
				if (calc2 < 0.0)
					calc2 = 0.0;
				player.GetStatRadiation().Add(calc2);
			}
			else
				player.GetStatRadiation().Add(l_Radiation);
		}
		else
		{
			if (player.GetStatRadiation().Get() > 0)
			{
				p_Radiation = m_DecreaseRadiation / m_EffectLifetime;
				player.GetStatRadiation().Add(-p_Radiation);
			}
		}
	}
};