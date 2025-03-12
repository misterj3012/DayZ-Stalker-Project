modded class PlayerBase
{
	ref Timer 					m_c_ShakeTimer;
	ref Timer 					m_c_SoundTimer;
	float 						m_c_time = 0;
	int c_ShakeTime;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		switch (rpc_type)
		{
		case PSI_HIT:
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(c_wave2, Math.RandomInt(1000, 3000), false);
			break;
		case CONTR_PSI_HIT:
			c_SingleSound("psi_supersonic_SoundSet", false, 4);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(c_wave1, Math.RandomInt(1000, 3000), false);
			break;
		case CONTR_PSI_HIT_HELMET:
			c_SingleSound("psi_supersonic_SoundSet", false, 4);
			break;
		}
	}

	void c_wave1()
	{
		private int time = Math.RandomIntInclusive(1, 2);
		EffectSound m_Vybros;
		PPEffects.SetBlurFlashbang(0.8);
		c_ShakeTime(1.1, 3, 0.5, 1.0, time);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(c_CleanEffect, time * 1000, false);
		m_Vybros = SEffectManager.PlaySound("CONTR_PSI_HIT_SoundSet", GetPosition());
		m_Vybros.SetSoundAutodestroy(true);
	}

	void c_wave2()
	{
		private int time = Math.RandomIntInclusive(1, 2);
		PPEffects.SetBlurFlashbang(0.8);
		c_ShakeTime(1.1, 3, 0.5, 1.0, time);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(c_CleanEffect, time * 1000, false);
	}

	void c_SingleSound(string sound, bool repeat = false, int rate = 0)
	{
		if (!m_c_SoundTimer && repeat)
		{
			m_c_SoundTimer = new Timer();
			m_c_SoundTimer.Run(rate, this, "c_SingleSound", new Param2<string, bool>(sound, repeat), true);
		}

		EffectSound m_sound = SEffectManager.PlaySound(sound, GetPosition());
		m_sound.SetSoundAutodestroy(true);

		if (!repeat && m_c_SoundTimer) m_c_SoundTimer = NULL;
	}

	void c_ShakeTime(float strength, float radius, float smoothness, float radius_decay_speed, int time)
	{
		c_ShakeTime = 0;

		if (!m_c_ShakeTimer)
		{
			m_c_ShakeTimer = new Timer();
			m_c_ShakeTimer.Run(1, this, "c_Shake", new Param5<float, float, float, float, int>(strength, radius, smoothness, radius_decay_speed, time), true);
		}
	}

	void c_Shake(float strength, float radius, float smoothness, float radius_decay_speed, int time = 0)
	{
		++c_ShakeTime;
		DayZPlayerCameraBase camera = DayZPlayerCameraBase.Cast(this.GetCurrentCamera());
		camera.SpawnCameraShakeProper(strength, radius, smoothness, radius_decay_speed);

		if (c_ShakeTime >= time)
			m_c_ShakeTimer = NULL;
	}

	void c_CleanEffect()
	{
		PPEffects.SetBlurFlashbang(0);
	}
}