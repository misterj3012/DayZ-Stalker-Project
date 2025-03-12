class PsiMdfr : ModifierBase
{
	int m_Tick = 0;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID = PsiModifiers.MDF_PSI;
		m_TickIntervalInactive = 1;
		m_TickIntervalActive = 1;
		m_IsPersistent = true;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		if (!IsActive() && player.GetStatPsi().Get() > 0)
			return true;
		else
			return false;
	}
	override void OnActivate(PlayerBase player)
	{
		player.SetPlayVoices(true);
	}
	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	override void OnDeactivate(PlayerBase player)
	{
		player.SetPlayVoices(false);
	}
	override bool DeactivateCondition(PlayerBase player)
	{
		if (player.GetStatPsi().Get() <= 0)
			return true;
		else
			return false;
	}
	override void OnTick(PlayerBase player, float deltaT)
	{
		if (Class.CastTo(m_Player, player))
		{
			private float damage_player;
			if (m_Tick >= 5.0 && (m_Player.GetStatPsi().Get() > 0.0 && m_Player.GetStatPsi().Get() <= 1.0))
			{
				GetGame().RPCSingleParam(m_Player, PsiRPC.PSIHIT, new Param1<float>(m_Player.GetStatPsi().Get()), true, m_Player.GetIdentity());
				damage_player = m_Player.GetHealth("", "Shock");
				m_Player.SetHealth("", "Shock", damage_player - 5);
				damage_player = m_Player.GetHealth("", "Health");
				m_Player.SetHealth("", "Health", damage_player - 1);
				m_Player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
				m_Tick = 0;
			}
			if (m_Tick >= 4.0 && (m_Player.GetStatPsi().Get() >= 1.01 && m_Player.GetStatPsi().Get() <= 2.0))
			{
				GetGame().RPCSingleParam(m_Player, PsiRPC.PSIHIT, new Param1<float>(m_Player.GetStatPsi().Get()), true, m_Player.GetIdentity());
				damage_player = m_Player.GetHealth("", "Shock");
				m_Player.SetHealth("", "Shock", damage_player - 15);
				damage_player = m_Player.GetHealth("", "Health");
				m_Player.SetHealth("", "Health", damage_player - 2);
				m_Player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
				m_Tick = 0;
			}
			if (m_Tick >= 3.0 && (m_Player.GetStatPsi().Get() >= 2.01 && m_Player.GetStatPsi().Get() <= 5.0))
			{
				GetGame().RPCSingleParam(m_Player, PsiRPC.PSIHIT, new Param1<float>(m_Player.GetStatPsi().Get()), true, m_Player.GetIdentity());
				damage_player = m_Player.GetHealth("", "Shock");
				m_Player.SetHealth("", "Shock", damage_player - 30);
				damage_player = m_Player.GetHealth("", "Health");
				m_Player.SetHealth("", "Health", damage_player - 5);
				m_Player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
				m_Tick = 0;
			}
			if (m_Tick >= 2.0 && m_Player.GetStatPsi().Get() >= 5.01)
			{
				GetGame().RPCSingleParam(m_Player, PsiRPC.PSIHIT, new Param1<float>(m_Player.GetStatPsi().Get()), true, m_Player.GetIdentity());
				damage_player = m_Player.GetHealth("", "Shock");
				m_Player.SetHealth("", "Shock", damage_player - 50);
				damage_player = m_Player.GetHealth("", "Health");
				m_Player.SetHealth("", "Health", damage_player - 10);
				m_Player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
				if (m_Player.IsUnconscious())
					m_Player.SetHealth("", "", 0.0);
				m_Tick = 0;
			}
			++m_Tick;
		}
	}
};