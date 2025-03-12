class X18_Anomaly_Portal : Anomaly_Base
{
	protected const int TRIGGER_COOLDOWN = 1000 * 5;
	protected ref AnomalyDamageOneTimeSpace m_AnomalyDamage;
	protected Particle m_ParticleEfxIdle;
	protected PointLightBase m_LightTrigger;
	protected SoundOnVehicle m_IdleSound;
	protected Particle m_ParticleEfxTrigger;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = false;
	void X18_Anomaly_Portal()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_IdleSound = PlaySoundLoop("PortalIdle", 50);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.MONOLITH_PORTAL_IDLE, this, "0 1.5 0");
		}
	}
	void ~X18_Anomaly_Portal()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
		if (GetGame() && (GetGame().IsServer() || !GetGame().IsMultiplayer()))
			DestroyDamageTrigger();
	}
	protected void CleanUpClient()
	{
		if (m_LightTrigger)
			m_LightTrigger.FadeOut();
		if (m_ParticleEfxIdle)
			m_ParticleEfxIdle.Stop();
		GetGame().ObjectDelete(m_IdleSound);
	}
	protected void UpdateVisuals()
	{
		if (m_Triggered)
		{
			CreateTriggerLight();
			m_TriggerSound = PlaySound("PortalTrigger_1", 100);
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
		m_AnomalyDamage = new AnomalyDamageOneTimeSpace(this, "-0.5 0 -0.5", "0.5 1.0 0.5", "", { "" });
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
	protected void DestroyDamageTrigger()
	{
		if (m_AnomalyDamage)
			m_AnomalyDamage.Destroy();
	}
	protected void CreateTriggerLight()
	{
		m_LightTrigger = PointLightBase.Cast(ScriptedLightBase.CreateLight(PointLightBase, "0 1.5 0"));
		if (m_LightTrigger)
		{
			m_LightTrigger.SetVisibleDuringDaylight(true);
			m_LightTrigger.SetRadiusTo(5);
			m_LightTrigger.SetBrightnessTo(1);
			m_LightTrigger.SetCastShadow(false);
			m_LightTrigger.EnableSpecular(false);
			m_LightTrigger.EnableLinear(false);
			m_LightTrigger.FadeIn(0.1);
			m_LightTrigger.SetLifetime(0.4);
			m_LightTrigger.SetFadeOutTime(0.1);
			m_LightTrigger.SetAmbientColor(0.2, 0.2, 1.0);
			m_LightTrigger.SetDiffuseColor(0.2, 0.2, 1.0);
			m_LightTrigger.SetFlareVisible(false);
			m_LightTrigger.SetDisableShadowsWithinRadius(-1);
			m_LightTrigger.SetDancingShadowsMovementSpeed(0.4);
			m_LightTrigger.SetDancingShadowsAmplitude(0.5);
			m_LightTrigger.SetFlickerSpeed(10);
			m_LightTrigger.SetFlickerAmplitude(0.5);
			m_LightTrigger.EnableHeatHaze(true);
			m_LightTrigger.SetHeatHazeRadius(0.6);
			m_LightTrigger.SetHeatHazePower(0.02);
			m_LightTrigger.AttachOnObject(this, "0 1.5 0", "0 0 0");
		}
	}
	override void EOnInit(IEntity other, int extra)
	{
		CreateDamageTrigger();
	}
}
class X18_Anomaly_Portal_ExitFX : House
{
	protected SoundOnVehicle m_ExitSound;
	protected PointLightBase m_LightExit;
	void X18_Anomaly_Portal_ExitFX()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			CreateExitLight();
			m_ExitSound = PlaySound("PortalTrigger_1", 100);
		}
	}
	void ~X18_Anomaly_Portal_ExitFX()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
	}
	protected void CleanUpClient()
	{
		if (m_LightExit)
			m_LightExit.FadeOut();
	}
	protected void CreateExitLight()
	{
		m_LightExit = PointLightBase.Cast(ScriptedLightBase.CreateLight(PointLightBase, "0 1.5 0"));
		if (m_LightExit)
		{
			m_LightExit.SetVisibleDuringDaylight(true);
			m_LightExit.SetRadiusTo(100);
			m_LightExit.SetBrightnessTo(50);
			m_LightExit.SetCastShadow(false);
			m_LightExit.EnableSpecular(false);
			m_LightExit.EnableLinear(false);
			m_LightExit.SetFlareVisible(false);
			m_LightExit.SetAmbientColor(0.2, 0.2, 1.0);
			m_LightExit.SetDiffuseColor(0.2, 0.2, 1.0);
			m_LightExit.FadeIn(0.1);
			m_LightExit.SetLifetime(0.4);
			m_LightExit.SetFadeOutTime(0.1);
			m_LightExit.SetDisableShadowsWithinRadius(-1);
			m_LightExit.SetDancingShadowsMovementSpeed(0.4);
			m_LightExit.SetDancingShadowsAmplitude(0.5);
			m_LightExit.SetFlickerSpeed(20);
			m_LightExit.SetFlickerAmplitude(0.5);
			m_LightExit.EnableHeatHaze(true);
			m_LightExit.SetHeatHazeRadius(2);
			m_LightExit.SetHeatHazePower(0.01);
			m_LightExit.AttachOnObject(this, "0 2 0", "0 0 0");
		}
	}
}
class X18_Anomaly_Portal_ExitSoundFX : House
{
	protected SoundOnVehicle m_ExitSound;
	void X18_Anomaly_Portal_ExitSoundFX()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_ExitSound = PlaySound("PortalTrigger_1", 100);
		}
	}
	void ~X18_Anomaly_Portal_ExitSoundFX()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
	}
	protected void CleanUpClient()
	{
	}
}