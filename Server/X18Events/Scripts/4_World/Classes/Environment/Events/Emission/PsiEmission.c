modded class PsiEmission
{
	protected float m_TempBonus;
	void PsiEmission()
	{
		m_TempBonus = Math.RandomFloat(15.0, 22.0);
	}
	override void InitPhaseServer()
	{
		thread LerpColorizationServer(Vector(2.55, 1.68, 0.0), GetInitPhaseLength() * 1000, Vector(1.0, 0.95, 0.9));
		super.InitPhaseServer();
	}
	override void MidPhaseServer()
	{
		GetSoundManager().StartTransmitterSounds("PsiEmission_Warning_2", 1);
		thread StartHitPhaseServer(GetMidPhaseLength());
		Sleep(25000);
		GetSoundManager().StartAmbientSound("PsiEmission_Impact", m_Position);
		thread LerpPsiEffectServer(0.25, 0.25, 0.0);
		thread CreatePsiEmissionServer(1, 0.25);
		Sleep(9600);
		thread CreatePsiEmissionServer(2, 0.5);
		thread LerpPsiEffectServer(0.5, 0.5, 0.0);
		Sleep(7000);
		GetSoundManager().PlaySoundOnPlayerServer("PsiEmission_Bass", 1);
		thread CreatePsiEmissionServer(3, 0.6);
		thread LerpPsiEffectServer(0.6, 0.6, 0.0);
		Sleep(25000);
		thread CreatePsiEmissionServer(4, 0.7);
		thread LerpPsiEffectServer(0.7, 0.7, 0.0);
		Sleep(6500);
		thread CreatePsiEmissionServer(5, 0.85);
		thread LerpPsiEffectServer(0.85, 0.85, 0.0);
		Sleep(6500);
		GetGame().GetMission().GetWorldData().SetTemperatureEvent(m_TempBonus);
		thread CreatePsiEmissionServer(0, 1.0);
		thread LerpPsiEffectServer(1.0, 1.0, 0.0);
		Sleep(4500 - 2200);
		CreatePsiEmissionFinalServer();
		Sleep(100);
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach(Man player : players)
		{
			SurvivorBase m_Player = SurvivorBase.Cast(player);
			if (m_Player)
				OnEmissionFinished(m_Player);
		}
	}
	override void EndPhaseServer()
	{
		thread LerpColorizationServer(Vector(1.0, 0.95, 0.9), GetEndPhaseLength() * 1000, Vector(2.55, 1.68, 0.0));
		Sleep(100);
		GetGame().GetMission().GetWorldData().SetTemperatureEvent(0.0);
		super.EndPhaseServer();
	}
	override void OnEventEndServer()
	{
		super.OnEventEndServer();
	}
	void OnEmissionFinished(notnull SurvivorBase player)
	{
		float current_shock = player.GetHealth("", "Shock");
		float shock_value = PsiEmissionConstants.SHOCK_WHEN_UNSAFE;

		player.GetStaminaHandler().SetStamina(0);

		if (player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
			shock_value += 2.0;
		player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_6);
		DamagePlayerItems(player);
		shock_value += 7.0;
		if (shock_value < current_shock)
			player.SetHealth("", "Shock", shock_value);
		if (DistanceFromCenter(player) < PsiEmissionConstants.EMISSION_KILL_RADIUS)
			player.SetHealth("", "Health", 0);
	}
	void CreatePsiEmissionServer(int level, float intensity)
	{
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach(Man man : players)
		{
			PlayerBase player = PlayerBase.Cast(man);
			if (player)
			{
				switch (level)
				{
					case 0:
						break;
					case 1:
						player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
						player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_1);
						player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_1 * 3));
						break;
					case 2:
						player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
						player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_2);
						player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_2 * 3));
						break;
					case 3:
						player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
						player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_3);
						player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_3 * 3));
						break;
					case 4:
						player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
						player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_4);
						player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_4 * 3));
						break;
					case 5:
						player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
						player.AddHealth("", "Health", -PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_5);
						player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (PsiEmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_5 * 3));
						break;
				}
			}
		}
		GetGame().RPCSingleParam(null, X18PsiEmissionRPCs.PSIEMISSION_RPC_CREATE_PSIEMISSION, new Param1<float>(intensity), true);
	}
	void CreatePsiEmissionFinalServer()
	{
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach(Man player : players)
		{
			PlayerBase m_Player;
			if (Class.CastTo(m_Player, player))
				GetGame().RPCSingleParam(null, X18PsiEmissionRPCs.PSIEMISSION_RPC_CREATE_PSIEMISSION_FINAL, null, true, m_Player.GetIdentity());
		}
	}
	void StartHitPhaseServer(float time)
	{
		GetGame().RPCSingleParam(null, X18PsiEmissionRPCs.PSIEMISSION_RPC_HIT_PHASE, new Param1<float>(time), true);
	}
	void LerpColorizationServer(vector rgb, int time, vector start_rgb = "0 0 0")
	{
		GetGame().RPCSingleParam(null, X18PsiEmissionRPCs.PSIEMISSION_RPC_COLOR_SKY, new Param3<vector, int, vector>(rgb, time, start_rgb), true);
	}
	void LerpPsiEffectServer(float intensity, int time, float start_intensity = 0.0)
	{
		GetGame().RPCSingleParam(null, X18PsiEmissionRPCs.PSIEMISSION_RPC_EFFECT, new Param3<float, int, float>(intensity, time, start_intensity), true);
	}
	void DamagePlayerItems(PlayerBase player)
	{
		PlayerBase m_Player = PlayerBase.Cast(player);
		if (!m_Player)
			return;

		EntityAI m_Item;

		for (int x = 0; x < m_Slots.Count(); x++)
		{
			m_Item = EntityAI.Cast(m_Player.FindAttachmentBySlotName(m_Slots.Get(x)));
			if (m_Item)
			{
				float m_Health = m_Item.GetHealth();
				m_Item.DecreaseHealth(25, false);
			}
		}
	}
	override bool JIPRunPreviousPhases()
	{
		return false;
	}
	override float GetServerTick()
	{
		return 0.06;
	}
	override float GetFogTarget()
	{
		return 0.3;
	}
	override float GetOvercastTarget()
	{
		return 1.0;
	}
	override float GetEventCooldown()
	{
		return 1800.0;
	}
}