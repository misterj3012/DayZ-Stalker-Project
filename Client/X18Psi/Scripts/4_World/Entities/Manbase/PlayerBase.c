modded class PlayerBase
{
	static const ref array<string> m_Patches = { "X18_Armband" };
	static const ref array<string> m_PsiHelment = { "X18_PsiHelmet" };
	protected EffectSound m_EffectLoopVoiceSound;
	protected bool m_PlayVoices = false;
	protected float m_VoicesOffset = 5.0;
	protected float m_VoicesDelayTimer = 0.0;
	protected float m_PsiImmune = 0.0;
	protected float m_PsiStrength = 0.0;
	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableFloat("m_PsiImmune");
		RegisterNetSyncVariableBool("m_PlayVoices");
		RegisterNetSyncVariableFloat("m_PsiStrength");
		m_PlayVoices = false;
		m_PsiImmune = 0.0;
		m_PsiStrength = 0.0;
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsDedicatedServer())
		{
			switch (rpc_type) {
				case PsiRPC.SETPSISTRENGTH:
					{
						ref Param1<float> psiStrength;
						if (!ctx.Read(psiStrength))
							break;
						GetStatPsi().Add(psiStrength.param1);
						SetPsiStrength(GetStatPsi().Get());
					}
			}
		}
		else if (!GetGame().IsDedicatedServer())
		{
			switch (rpc_type) {
				case PsiRPC.PSIHIT:
					{
						ref Param1<float> psiStrengthForHit;
						if (!ctx.Read(psiStrengthForHit))
							break;
						CreatePsiEffect(psiStrengthForHit.param1);
					}
			}
		}
	}
	void CreatePsiEffect(float coef)
	{
		int time = Math.RandomIntInclusive(1, 2);
		float flashBang = Math.Clamp(coef / 2, 0.1, 1.0);
		PPEffects.SetBlurFlashbang(flashBang);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CleanFlashbangEffect, time * 1000, false);
	}
	void CleanFlashbangEffect()
	{
		PPEffects.SetBlurFlashbang(0.0);
	}
	void SetPsiBlock(float psi)
	{
		m_PsiImmune = psi;
		SetSynchDirty();
	}
	void SetPlayVoices(bool playVoices)
	{
		m_PlayVoices = playVoices;
		SetSynchDirty();
	}
	bool GetPlayVoices()
	{
		return m_PlayVoices;
	}
	float IsPsiImmune()
	{
		EntityAI m_Headgear = GetHumanInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Headgear"));
		if (m_Headgear)
		{
			if (m_PsiHelment.Find(m_Headgear.GetType()) != -1)
				return 1.0;
		}
		return m_PsiImmune;
	}
	PlayerStatPsi GetStatPsi()
	{
		if (GetPlayerStats())
		{
			PlayerStatPsi stat = PlayerStatPsi.Cast(GetPlayerStats().GetStatObject(PlayerStats_Psi.PSI));
			return stat;
		}
		return null;
	}
	EStatLevels GetStatLevelPsi()
	{
		float m_Psi = GetStatPsi().Get();
		return GetStatLevelReverse(m_Psi, PlayerConstants.PSI_CRITICAL, PlayerConstants.PSI_LOW, PlayerConstants.PSI_NORMAL, PlayerConstants.PSI_HIGH);
	}
	override void EOnFrame(IEntity other, float timeSlice)
	{
		super.EOnFrame(other, timeSlice);
		if (!GetGame().IsDedicatedServer())
		{
			if (m_VoicesDelayTimer >= m_VoicesOffset && GetPlayVoices() && !m_EffectLoopVoiceSound)
				PlayVoicesSound();
			if (m_VoicesDelayTimer >= m_VoicesOffset && !GetPlayVoices())
				VoicesSoundStop();
			m_VoicesDelayTimer += timeSlice;
		}
	}
	protected void PlayVoicesSound()
	{
		if (m_EffectLoopVoiceSound)
			return;
		vector pos;
		MiscGameplayFunctions.GetHeadBonePos(this, pos);
		m_EffectLoopVoiceSound = SEffectManager.CreateSound("X18Psi_Voices_SoundSet", pos);
		m_EffectLoopVoiceSound.SetParent(this);
		m_EffectLoopVoiceSound.SetAttachedLocalPos(this.WorldToModel(pos));
		m_EffectLoopVoiceSound.SetSoundWaveKind(WaveKind.WAVEEFFECTEX);
		m_EffectLoopVoiceSound.SetSoundVolume(GetPsiStrength());
		m_EffectLoopVoiceSound.SetSoundFadeIn(4);
		m_EffectLoopVoiceSound.SetSoundFadeOut(2);
		m_EffectLoopVoiceSound.SetSoundLoop(false);
		m_EffectLoopVoiceSound.SoundPlay();
		m_EffectLoopVoiceSound.SetAutodestroy(true);
		m_VoicesDelayTimer = 0.0;
	}
	void VoicesSoundStop()
	{
		if (m_EffectLoopVoiceSound)
			m_EffectLoopVoiceSound.SoundStop();
		m_EffectLoopVoiceSound = null;
		m_VoicesDelayTimer = 0.0;
	}
	void SetPsiStrength(float psiStrength)
	{
		m_PsiStrength = psiStrength;
		SetSynchDirty();
	}
	float GetPsiStrength()
	{
		return m_PsiStrength;
	}
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		if (m_PsiStrength > 0.0)
		{
			vector m_PositionOffset = GetPosition() - "0.3 -0.3 0.3";
			ZombieBase m_Zombie = ZombieBase.Cast(GetGame().CreateObject("X18_HumanZombie", m_PositionOffset, false, true));
			if (m_Zombie)
			{
				m_Zombie.TransferAttachmentsToZombie(this);
				m_Zombie.SetOrientation(GetOrientation());
			}
			//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 5000, false, this);
		}
	}
}