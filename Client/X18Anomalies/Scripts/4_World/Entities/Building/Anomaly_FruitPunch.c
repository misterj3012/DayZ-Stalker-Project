class X18_Anomaly_FruitPunch : Anomaly_Base
{
	protected ref AnomalyDamageRegular m_AnomalyDamage;
	protected Particle m_ParticleEfxIdle;
	protected SoundOnVehicle m_IdleSound;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = true;
	void X18_Anomaly_FruitPunch()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.FRUITPUNCH_IDLE, this, "0 0.1 0");
			m_IdleSound = PlaySoundLoop("BurntFuzzIdle", 25);
		}
	}
	void ~X18_Anomaly_FruitPunch()
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
		GetGame().ObjectDelete(m_IdleSound);
	}
	protected void UpdateVisuals()
	{
		m_TriggerSound = PlaySound("BurntFuzzHit", 100);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisuals();
	}
	override void PreAreaDamageActions()
	{
		m_Triggered = !m_Triggered;
		SetSynchDirty();
	}
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-2.2 0 -2.2", "2.2 1.0 2.2", "AnomalyFruitPunchHit", { "RightLeg", "LeftLeg", "RightFoot", "LeftFoot" }, 0.5);
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