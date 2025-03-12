modded class Emission
{
	protected float m_TempBonus;
	void Emission()
	{
		m_TempBonus = Math.RandomFloat(15.0, 22.0);
		m_WindTargetSpeed = Math.RandomFloat(15.0, 30.0);
		m_WindRelMinTarget = 0.9;
		m_WindRelMaxTarget = 1.0;
	}
	override void InitPhaseServer()
	{
		m_Weather.SetWindMaximumSpeed(m_WindTargetSpeed / 2);
		m_Weather.GetWindFunctionParams(m_WindRelMin, m_WindRelMax, m_WindChangeSpeed);
		m_Weather.SetWindFunctionParams(m_WindRelMinTarget, m_WindRelMaxTarget, m_WindChangeSpeed);
		Sleep(40000);
		GetSoundManager().StartSirenSounds("Emission_Warning_1", 1.0);
		GetSoundManager().StartTransmitterSounds("Emission_Warning_1", 0.5);
		Sleep(40000);
		GetSoundManager().StartSirenSounds("Emission_Warning_2", 1.0);
		GetSoundManager().StartTransmitterSounds("Emission_Warning_2", 0.5);
		Sleep(10000);
		m_Weather.SetStorm(1, 0.9, 15);
		GetSoundManager().StartSirenSounds("Emission_Alarm", 0.5);
		super.InitPhaseServer();
	}
	override void MidPhaseServer()
	{
		GetSoundManager().StartAmbientSound("Emission_Begin", m_Position);
		m_Weather.SetWindMaximumSpeed(m_WindTargetSpeed);
		m_Weather.SetStorm(1, 0.9, 5);
		thread StartHitPhaseServer(GetMidPhaseLength());
		Sleep(25000);
		GetSoundManager().StartAmbientSound("Emission_Impact", m_Position);
		thread CreateEmissionServer(1, 0.25);
		Sleep(9600);
		thread CreateEmissionServer(2, 0.5);
		Sleep(7000);
		GetSoundManager().StartAmbientSound("Emission_Bass", m_Position);
		thread CreateEmissionServer(3, 0.6);
		Sleep(25000);
		thread CreateEmissionServer(4, 0.7);
		Sleep(6500);
		thread CreateEmissionServer(5, 0.85);
		Sleep(6500);
		GetGame().GetMission().GetWorldData().SetTemperatureEvent(m_TempBonus);
		thread CreateEmissionServer(6, 1.0);
		Sleep(4500 - 2200);
		CreateEmissionFinalServer();
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
		Sleep(100);
		GetGame().GetMission().GetWorldData().SetTemperatureEvent(0.0);
		Sleep(35000);
		GetSoundManager().StartSirenSounds("Emission_Relief", 0.5);
		GetSoundManager().StartTransmitterSounds("Emission_Relief", 0.5);
		super.EndPhaseServer();
	}
	override void OnEventEndServer()
	{
		m_Weather.SetStorm(0, 0, 30);
		m_Weather.SetWindMaximumSpeed(m_WindTargetSpeed / 2);
		m_Weather.SetWindFunctionParams(m_WindRelMin, m_WindRelMax, m_WindChangeSpeed);
		super.OnEventEndServer();
	}
	void OnEmissionFinished(notnull SurvivorBase player)
	{
		float current_shock = player.GetHealth("", "Shock");
		float shock_value = EmissionConstants.SHOCK_WHEN_UNSAFE;

		player.GetStaminaHandler().SetStamina(0);

		if (player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
			shock_value += 2.0;
		if (!player.m_IsInside)
		{
			player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_6);
			DamagePlayerItems(player);
			shock_value += 7.0;
		}
		if (shock_value < current_shock)
			player.SetHealth("", "Shock", shock_value);
		if (DistanceFromCenter(player) < EmissionConstants.EMISSION_KILL_RADIUS)
			player.SetHealth("", "Health", 0);
	}
	void CreateEmissionServer(int level, float intensity)
	{
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach(Man man : players)
		{
			PlayerBase player = PlayerBase.Cast(man);
			if (player)
			{
				if (!player.m_IsInside)
				{
					switch (level)
					{
						case 1:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_1);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_1 * 3));
							break;
						case 2:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_2);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_2 * 3));
							break;
						case 3:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_3);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_3 * 3));
							break;
						case 4:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_4);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_4 * 3));
							break;
						case 5:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_5);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_5 * 3));
							break;
						case 6:
							player.RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_HEAVY);
							player.AddHealth("", "Health", -EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_6);
							player.GetStaminaHandler().SetStamina(player.GetStaminaHandler().GetStamina() - (EmissionConstants.DAMAGE_WHEN_UNSAFE_LEVEL_6 * 3));
							break;
					}
				}
			}
		}
		GetGame().RPCSingleParam(null, X18EmissionRPCs.EMISSION_RPC_CREATE_EMISSION, new Param1<float>(intensity), true);
	}
	void CreateEmissionFinalServer()
	{
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach(Man player : players)
		{
			PlayerBase m_Player;
			if (Class.CastTo(m_Player, player))
				GetGame().RPCSingleParam(null, X18EmissionRPCs.EMISSION_RPC_CREATE_EMISSION_FINAL, null, true, m_Player.GetIdentity());
		}
	}
	void StartHitPhaseServer(float time)
	{
		GetGame().RPCSingleParam(null, X18EmissionRPCs.EMISSION_RPC_HIT_PHASE, new Param1<float>(time), true);
	}
	void LerpColorizationServer(vector rgb, int time, vector start_rgb = "0 0 0")
	{
		GetGame().RPCSingleParam(null, X18EmissionRPCs.EMISSION_RPC_COLOR_SKY, new Param3<vector, int, vector>(rgb, time, start_rgb), true);
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
		return 0.4;
	}
	override float GetRainTarget()
	{
		return Math.RandomFloatInclusive(0.0, 0.2);
	}
	override float GetOvercastTarget()
	{
		return 0.94;
	}
	override float GetEventCooldown()
	{
		return 1800.0;
	}
}