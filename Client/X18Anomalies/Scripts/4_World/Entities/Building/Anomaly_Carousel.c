class X18_Anomaly_Carousel : Anomaly_Base
{
	protected const int TRIGGER_COOLDOWN = 1000 * 14;
	protected const int EXPLODE_COOLDOWN = 1000 * 2;
	protected ref AnomalyDamageDeadOneTime m_AnomalyDamage;
	protected Particle m_ParticleEfxIdle;
	protected SoundOnVehicle m_IdleSound;
	protected Particle m_ParticleEfxTrigger;
	protected Particle m_ParticleEfxTrigger2;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = false;
	protected vector m_Position = "0.0 0.0 0.0";
	protected PlayerBase m_PlayerInRange;
	protected float velocity = 2.3;
	protected float TimeAction = 2;
	protected float minRadius = 10;
	protected float maxRadius = 20;
	protected float angleVelocity = 720;
	protected float cT;
	void X18_Anomaly_Carousel()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() && GetGame().IsMultiplayer())
		{
			m_IdleSound = PlaySoundLoop("VortexIdle", 7);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.VORTEX_IDLE, this, "0 0.1 0");
		}
		else
		{
			m_Position = this.GetPosition();
			m_Position[1] = m_Position[1] + 4.0;
		}
	}
	void ~X18_Anomaly_Carousel()
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
		if (m_ParticleEfxTrigger2)
			m_ParticleEfxTrigger2.Stop();
		GetGame().ObjectDelete(m_IdleSound);
	}
	protected void UpdateVisuals()
	{
		if (m_Triggered)
		{
			if (m_ParticleEfxIdle)
				m_ParticleEfxIdle.Stop();
			if (m_ParticleEfxTrigger2)
				m_ParticleEfxTrigger2.Stop();
			GetGame().ObjectDelete(m_IdleSound);
			m_TriggerSound = PlaySound("VortexActive", 100);
			m_ParticleEfxTrigger = Particle.PlayOnObject(ParticleList.VORTEX_ACTIVE_1, this, "0 0.1 0");
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TriggerStage2Client, 1000 * 2, false);
		}
		else
		{
			if (m_ParticleEfxTrigger)
				m_ParticleEfxTrigger.Stop();
			if (m_ParticleEfxTrigger2)
				m_ParticleEfxTrigger2.Stop();
			m_IdleSound = PlaySoundLoop("VortexIdle", 7);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.VORTEX_IDLE, this, "0 0.1 0");
		}
	}
	protected void TriggerStage2Client()
	{
		if (m_ParticleEfxIdle)
			m_ParticleEfxIdle.Stop();
		if (m_ParticleEfxTrigger)
			m_ParticleEfxTrigger.Stop();
		m_ParticleEfxTrigger2 = Particle.PlayOnObject(ParticleList.VORTEX_ACTIVE_2, this, "0 0.1 0");
		/*HumanInputController hic = m_Player.GetInputController();
		hic.SetDisabled(true);*/
	}
	protected void TriggerStage2Server()
	{
		//Explode(DT_EXPLOSION, "AnomalyVortexHit");
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
		//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TriggerStage2Server, EXPLODE_COOLDOWN, false);
	}
	override void DamageAreaDamageActions(Object obj)
	{
		PlayerBase m_PlayerInRange = PlayerBase.Cast(obj);
		cT = 0;
	}
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageDeadOneTime(this, "-1.5 0 -1.5", "1.5 1.0 1.5", "", { "Torso" });
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