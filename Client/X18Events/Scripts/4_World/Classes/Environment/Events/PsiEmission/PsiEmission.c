class PsiEmission : WeatherEvent
{
	static const int COLORIZE_SKY = 99;
	static const int COLORIZE_FLASH = 150;
	protected vector m_Position;
	protected PPERequester_PsiEmissionColours m_PPE_PsiEmissionColours;
	protected ref Timer m_HitPhaseTimer = new Timer(CALL_CATEGORY_SYSTEM);
	protected ref Timer m_VoicesTimer = new Timer(CALL_CATEGORY_SYSTEM);
	void PsiEmission()
	{
		m_Position = GetEventPosition();
		if (!GetGame().IsDedicatedServer())
		{
			Class.CastTo(m_PPE_PsiEmissionColours, PPERequesterBank.GetRequester(PPERequester_PsiEmissionColours));
			if (m_PPE_PsiEmissionColours)
				m_PPE_PsiEmissionColours.Start();
		}
	}
	void ~PsiEmission()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_PPE_PsiEmissionColours)
				m_PPE_PsiEmissionColours.Stop();
		}
		delete m_HitPhaseTimer;
		delete m_VoicesTimer;
	}
	override void InitPhaseClient(float phase_time, Param data)
	{
		Sleep(5000);
		float timepassed;
		while (timepassed < GetInitPhaseLength() * 1000) {
			float pregame_phase = 1 / (GetInitPhaseLength() * 1000) * timepassed;
			float dt = 10000;
			timepassed += dt;
			if (!GetGame().GetPlayer()) continue;
			PlayEnvironmentSound("PsiEmission_Drone", m_Position, pregame_phase * 0.1);
			Sleep(dt);
		}
		m_VoicesTimer.Run(GetInitPhaseLength() / 25, this, "OnVoicesUpdate", new Param1<float>(GetInitPhaseLength() / 25), true);
	}
	void CreatePsiEmissionClient(float intensity)
	{
		PlaySoundOnPlayer("PsiEmission_Contact", intensity);
		CreateCameraShake(intensity * 2);
		LerpEffectPsiEmission(m_PPE_PsiEmissionColours, intensity, 1 * intensity);
		// m_PPE_PsiEmissionColours.LerpParamBlur(1 * intensity, 0, 0.75 * intensity);
		// m_PPE_PsiEmissionColours.LerpParamChroma(0.3 * intensity, -1, 2.5 * intensity);
		// m_PPE_PsiEmissionColours.LerpParamVignette(0.3 * intensity, 0, 2.5 * intensity);
	}
	void CreatePsiEmissionFinalClient()
	{
		thread CreatePsiEmissionClient(1);
		Sleep(100);
		PlayEnvironmentSound("PsiEmission_Hit", GetGame().GetPlayer().GetPosition(), 0.5);
		Sleep(1000);
		thread PlayEarRingSound();
	}
	void CreateCameraShake(float intensity)
	{
		GetGame().GetPlayer().GetCurrentCamera().SpawnCameraShake(Math.Clamp(intensity, 0.2, 1), 2, 5, 3.5);
	}
	void StartHitPhase(float time)
	{
		m_HitPhaseDeltaTime = 0;
		m_HitPhaseTimer.Run(0.01, this, "RunHitPhase", new Param1<float>(time), true);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_HitPhaseTimer.Stop, time * 1000);
	}
	private float m_HitPhaseDeltaTime;
	private void RunHitPhase(float time)
	{
		m_HitPhaseDeltaTime += 0.01;
		int factor = Math.Clamp(time / m_HitPhaseDeltaTime, 0, 100);
		int rand = Math.RandomInt(0, 150);
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (factor == rand && player) {
			CreateBolt(player.GetPosition());
			if (DistanceFromCenter(player) < PsiEmissionConstants.EMISSION_KILL_RADIUS)
			{
				float intensity = Math.Clamp(factor, 0.3, 1);
				LerpEffectPsiEmission(m_PPE_PsiEmissionColours, intensity, 1 * intensity);
				// m_PPE_PsiEmissionColours.LerpParamBlur(0.2 * intensity, 0, 0.75 * intensity);
				// m_PPE_PsiEmissionColours.LerpParamChroma(0.25 * intensity, 0, 2.5 * intensity);
				// m_PPE_PsiEmissionColours.LerpParamVignette(0.5 * intensity, 0, 2.5 * intensity);
			}
		}
	}
	void CreateBolt(vector position)
	{
		position = RandomizeVector(position, 100, 350);
		position[1] = GetGame().SurfaceY(position[0], position[2]) + 500;
		vector direction = vector.Direction(GetGame().GetPlayer().GetPosition(), position);
		direction.Normalize();
		PlayEnvironmentSound("PsiEmission_Lightning", GetGame().GetPlayer().GetPosition() + (direction * 100), 0.25);
		ScriptedLightBase.CreateLight(PsiEmissionLightFlash, position - ((position - GetGame().GetPlayer().GetPosition()) * 0.5));
		ScriptedLightBase.CreateLight(PsiEmissionLightning, position);
		Object bolt = GetGame().CreateObjectEx(LIGHTNING_BOLT_TYPES.GetRandomElement(), position, ECE_LOCAL);
		bolt.SetOrientation(Vector(Math.RandomFloat(0, 360), 90, 0));
		bolt.SetScale(Math.RandomFloatInclusive(6, 10));
		bolt.Update();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, Math.RandomInt(50, 150), false, bolt);
		if (Math.RandomIntInclusive(0, 3) != 1)
			return;
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CreateSecondaryBolt, Math.RandomInt(50, 300), false, position.ToString(false)/*, underground*/);
	}
	private void CreateSecondaryBolt(string s_position/*, bool underground*/)
	{
		vector position = s_position.ToVector();
		vector direction = vector.Direction(GetGame().GetPlayer().GetPosition(), position);
		direction.Normalize();
		for (int i = 0; i < Math.RandomIntInclusive(0, 2); i++)
		{
			PlayEnvironmentSound("PsiEmission_Lightning", GetGame().GetPlayer().GetPosition() + (direction * 100), 0.1);
			ScriptedLightBase.CreateLight(PsiEmissionLightFlash, position - ((position - GetGame().GetPlayer().GetPosition()) * 0.5));
			ScriptedLightBase.CreateLight(PsiEmissionLightning, position);
			Object bolt = GetGame().CreateObjectEx(LIGHTNING_BOLT_TYPES.GetRandomElement(), position, ECE_LOCAL);
			bolt.SetOrientation(Vector(Math.RandomFloat(0, 360), 0, 0));
			bolt.SetScale(Math.RandomFloatInclusive(2, 10));
			bolt.Update();
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, Math.RandomInt(50, 250), false, bolt);
		}
	}
	float DistanceFromCenter(Object object)
	{
		return (vector.Distance(object.GetPosition(), m_Position));
	}
	vector GetEventPosition()
	{
		return Vector(3711, 115, 12825);
	}
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);
		if (GetGame().IsClient())
		{
			switch (rpc_type) {
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_HIT_PHASE:
			{
				Param1<float> hitphase_param;
				if (!ctx.Read(hitphase_param))
					break;
				StartHitPhase(hitphase_param.param1);
				break;
			}
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_CREATE_PSIEMISSION:
			{
				Param1<float> intensity;
				if (!ctx.Read(intensity))
					break;
				thread CreatePsiEmissionClient(intensity.param1);
				break;
			}
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_CREATE_PSIEMISSION_FINAL:
			{
				thread CreatePsiEmissionFinalClient();
				break;
			}
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_COLOR_SKY:
			{
				Param3<vector, int, vector> color_params;
				if (!ctx.Read(color_params))
					break;
				thread LerpColorizationPsiEmission(m_PPE_PsiEmissionColours, color_params.param1[0], color_params.param1[1], color_params.param1[2], color_params.param2, color_params.param3[0], color_params.param3[1], color_params.param3[2]);
				break;
			}
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_EFFECT:
			{
				Param3<float, int, float> effect_params;
				if (!ctx.Read(effect_params))
					break;
				thread LerpEffectPsiEmission(m_PPE_PsiEmissionColours, effect_params.param1, effect_params.param2, effect_params.param3);
				break;
			}
			case X18PsiEmissionRPCs.PSIEMISSION_RPC_BRIGHTNESS:
			{
				Param1<float> brightness_params;
				if (!ctx.Read(brightness_params))
					break;
				GetGame().SetEVUser(brightness_params.param1);
				break;
			}
			}
		}
	}
	protected void PlayEarRingSound()
	{
		vector pos;
		MiscGameplayFunctions.GetHeadBonePos(PlayerBase.Cast(GetGame().GetPlayer()), pos);
		EffectSound flashbang_sound = SEffectManager.CreateSound("Tinnitus_SoundSet", pos);
		flashbang_sound.SetParent(GetGame().GetPlayer());
		flashbang_sound.SetAttachedLocalPos(GetGame().GetPlayer().WorldToModel(pos));
		flashbang_sound.SetSoundWaveKind(WaveKind.WAVEEFFECTEX);
		flashbang_sound.SetSoundFadeIn(2);
		flashbang_sound.SetSoundFadeOut(4);
		flashbang_sound.SoundPlay();
		flashbang_sound.GetSoundObject().SetVolume(0.4);
		GetGame().GetPlayer().SetMasterAttenuation("FlashbangAttenuation");
		Sleep(2000);
		flashbang_sound.SoundStop();
		Sleep(4000);
		GetGame().GetPlayer().SetMasterAttenuation("");
	}
	float m_VoicesTimePassed;
	void OnVoicesUpdate(float timeslice)
	{
		m_VoicesTimePassed += timeslice;
		float pregame_phase = 1 / (GetInitPhaseLength() * 1000) * (m_VoicesTimePassed * 1000);
		float inverse_phase = Math.AbsFloat(pregame_phase - 1);
		inverse_phase *= 100;

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player)
		{
			vector voice_pos = RandomizeVector(GetGame().GetPlayer().GetPosition(), inverse_phase + 10, inverse_phase + 75);
			voice_pos[1] = GetGame().SurfaceY(voice_pos[0], voice_pos[2]);
			player.RegisterAnomalyVoice(PlayEnvironmentSound("PsiEmission_Voices", voice_pos, pregame_phase * 0.1));
		}

		// 1 in 10 shot of getting a distant thunder sound
		if (Math.RandomIntInclusive(1, 10) == 3)
			PlayEnvironmentSound("PsiEmission_Wave", RandomizeVector(GetGame().GetPlayer().GetPosition(), 1, 10), pregame_phase * 0.25);
	}
	override float GetClientTick()
	{
		return 5.0;
	}
	override float GetInitPhaseLength()
	{
		// return 180.0;
		return 10.0;
	}
	override float GetMidPhaseLength()
	{
		return 90.0;
	}
	override float GetEndPhaseLength()
	{
		return 220.0;
	}
}