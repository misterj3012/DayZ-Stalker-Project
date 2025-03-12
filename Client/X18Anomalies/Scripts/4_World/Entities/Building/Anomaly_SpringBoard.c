class X18_Anomaly_SpringBoard : Anomaly_Base
{
	protected const int TRIGGER_COOLDOWN = 1000 * 7;
	protected ref AnomalyDamageOneTimeSpringBoard m_AnomalyDamage;
	protected Particle m_ParticleEfxIdle;
	protected SoundOnVehicle m_IdleSound;
	protected Particle m_ParticleEfxTrigger;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = false;
	void X18_Anomaly_SpringBoard()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() && GetGame().IsMultiplayer())
		{
			m_IdleSound = PlaySoundLoop("SpringboardIdle", 7);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.SPRINGBOARD_IDLE, this, "0 0.1 0");
		}
	}
	void ~X18_Anomaly_SpringBoard()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
		if (GetGame() && (GetGame().IsServer() || !GetGame().IsMultiplayer()))
			DestroyDamageTrigger();
	}
	protected void CleanUpClient()
	{
		if (m_ParticleEfxIdle)
			m_ParticleEfxIdle.Stop();
		if (m_ParticleEfxTrigger)
			m_ParticleEfxTrigger.Stop();
		GetGame().ObjectDelete(m_IdleSound);
	}
	protected void UpdateVisuals()
	{
		if (m_Triggered)
		{
			if (m_ParticleEfxIdle)
				m_ParticleEfxIdle.Stop();
			GetGame().ObjectDelete(m_IdleSound);
			m_TriggerSound = PlaySound("SpringboardActive", 100);
			m_ParticleEfxTrigger = Particle.PlayOnObject(ParticleList.SPRINGBOARD_ACTIVE, this, "0 0.1 0");
		}
		else
		{
			if (m_ParticleEfxTrigger)
				m_ParticleEfxTrigger.Stop();
			m_IdleSound = PlaySoundLoop("SpringboardIdle", 7);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.SPRINGBOARD_IDLE, this, "0 0.1 0");
		}
	}
	override void ReActivate()
	{
		CreateDamageTrigger();
		m_Triggered = false;
		SetSynchDirty();
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisuals();
	}
	override void PreAreaDamageActions()
	{
		m_Triggered = true;
		SetSynchDirty();
	}
	override void PostAreaDamageActions()
	{
		DestroyDamageTrigger();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ReActivate, TRIGGER_COOLDOWN, false);
	}
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageOneTimeSpringBoard(this, "-1.8 0 -1.8", "1.8 1.0 1.8", "AnomalySpringBoardHit", { "LeftLeg", "RightLeg" });
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
	protected void DestroyDamageTrigger()
	{
		if (m_AnomalyDamage)
			m_AnomalyDamage.Destroy();
	}
	override void EOnInit(IEntity other, int extra)
	{
		CreateDamageTrigger();
	}
}