class X18_Anomaly_Electra : Anomaly_Base
{
	protected const int TRIGGER_COOLDOWN = 1000 * 10;
	protected ref AnomalyDamageOneTime m_AnomalyDamage;
	protected Particle m_ParticleEfxIdle;
	protected Particle m_ParticleEfxTrigger;
	protected PointLightBase m_LightTrigger;
	protected SoundOnVehicle m_IdleSound;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = false;
	void X18_Anomaly_Electra()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_IdleSound = PlaySoundLoop("electra_idle", 30);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.ELECTRO_IDLE, this, "0 0.1 0");
		}
	}
	void ~X18_Anomaly_Electra()
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
		if (m_LightTrigger)
			m_LightTrigger.FadeOut();
		GetGame().ObjectDelete(m_IdleSound);
	}
	protected void UpdateVisuals()
	{
		if (m_Triggered)
		{
			if (m_ParticleEfxIdle)
				m_ParticleEfxIdle.Stop();
			GetGame().ObjectDelete(m_IdleSound);
			m_TriggerSound = PlaySound("electra_hit", 100);
			CreateTriggerLight();
			m_ParticleEfxTrigger = Particle.PlayOnObject(ParticleList.ELECTRO_ACTIVE, this, "0 0.1 0");
		}
		else
		{
			if (m_ParticleEfxTrigger)
				m_ParticleEfxTrigger.Stop();
			m_IdleSound = PlaySoundLoop("electra_idle", 30);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.ELECTRO_IDLE, this, "0 0.1 0");
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
		m_AnomalyDamage = new AnomalyDamageOneTime(this, "-2.4 0 -2.4", "2.4 1.0 2.4", "AnomalyElectraHit", { "Torso" });
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
	protected void DestroyDamageTrigger()
	{
		if (m_AnomalyDamage)
			m_AnomalyDamage.Destroy();
	}
	void Trigger()
	{
		m_Triggered = true;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ReActivate, TRIGGER_COOLDOWN, false);
	}
	protected void CreateTriggerLight()
	{
		m_LightTrigger = PointLightBase.Cast(ScriptedLightBase.CreateLight(PointLightBase, "0 1.5 0"));
		if (m_LightTrigger)
		{
			m_LightTrigger.SetVisibleDuringDaylight(true);
			m_LightTrigger.SetRadiusTo(25);
			m_LightTrigger.SetBrightnessTo(25);
			m_LightTrigger.SetCastShadow(false);
			m_LightTrigger.EnableSpecular(false);
			m_LightTrigger.EnableLinear(false);
			m_LightTrigger.SetFlareVisible(false);
			m_LightTrigger.FadeIn(0.1);
			m_LightTrigger.SetLifetime(0.4);
			m_LightTrigger.SetFadeOutTime(0.1);
			m_LightTrigger.SetAmbientColor(0.8, 0.8, 1.0);
			m_LightTrigger.SetDiffuseColor(0.8, 0.8, 1.0);
			m_LightTrigger.AttachOnObject(this);
		}
	}
	override void EOnInit(IEntity other, int extra)
	{
		CreateDamageTrigger();
	}
}