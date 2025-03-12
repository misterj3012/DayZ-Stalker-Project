class X18_Anomaly_Burner : Anomaly_Base
{
	protected const int TRIGGER_COOLDOWN = 1000 * 10;
	protected ref AnomalyDamageOneTime m_AnomalyDamageOneTime;
	protected ref AnomalyDamageRegular m_AnomalyDamageRegular;
	protected Particle m_ParticleEfxIdle;
	protected Particle m_ParticleEfxTrigger;
	protected PointLightBase m_LightTrigger;
	protected SoundOnVehicle m_IdleSound;
	protected SoundOnVehicle m_TriggerSound;
	protected ref Timer m_HeatingTimer;
	ref array<Object> nearest_objects = new array<Object>;
	ref array<CargoBase> proxy_cargos = new array<CargoBase>;
	const float PARAM_HEAT_RADIUS = 6.5;
	const float PARAM_HEAT_THROUGH_AIR_COEF = 0.28;
	const float TEMPERATURE = 613.0;
	protected bool m_Triggered = false;
	void X18_Anomaly_Burner()
	{
		RegisterNetSyncVariableBool("m_Triggered");
		if (GetGame().IsClient() && GetGame().IsMultiplayer())
		{
			m_IdleSound = PlaySoundLoop("ZharkaIdle", 30);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.BURNER_IDLE, this, "0 0.1 0");
		}
	}
	void ~X18_Anomaly_Burner()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
		if (GetGame() && (GetGame().IsServer() || !GetGame().IsMultiplayer()))
			DestroyDamageTriggerOneTime();
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
		GetGame().ObjectDelete(m_TriggerSound);
	}
	protected void UpdateVisuals()
	{
		if (m_Triggered)
		{
			if (m_ParticleEfxIdle)
				m_ParticleEfxIdle.Stop();
			GetGame().ObjectDelete(m_IdleSound);
			m_TriggerSound = PlaySound("ZharkaActive", 50);
			CreateTriggerLight();
			m_ParticleEfxTrigger = Particle.PlayOnObject(ParticleList.BURNER_ACTIVE, this, "0 0.1 0");
			m_HeatingTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
			m_HeatingTimer.Run(1, this, "TransferHeatToNearPlayers", NULL, true);
		}
		else
		{
			if (m_ParticleEfxTrigger)
				m_ParticleEfxTrigger.Stop();
			m_IdleSound = PlaySoundLoop("ZharkaIdle", 30);
			m_ParticleEfxIdle = Particle.PlayOnObject(ParticleList.BURNER_IDLE, this, "0 0.1 0");
		}
	}
	override void ReActivate()
	{
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
		m_Triggered = false;
		SetSynchDirty();
		DestroyDamageTriggerRegular();
		CreateDamageTriggerOneTime();
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisuals();
	}
	override void PreAreaDamageActions()
	{
		if (!m_Triggered)
		{
			DestroyDamageTriggerOneTime();
			CreateDamageTriggerRegular();
			m_Triggered = true;
			SetSynchDirty();
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ReActivate, TRIGGER_COOLDOWN, false);
		}
	}
	protected void CreateDamageTriggerOneTime()
	{
		DestroyDamageTriggerOneTime();
		m_AnomalyDamageOneTime = new AnomalyDamageOneTime(this, "-1.5 0 -1.5", "1.5 1.0 1.5", "AnomalyBurnerHit", { "Torso" });
		if (m_AnomalyDamageOneTime)
			m_AnomalyDamageOneTime.Spawn();
	}
	protected void DestroyDamageTriggerOneTime()
	{
		if (m_AnomalyDamageOneTime)
			m_AnomalyDamageOneTime.Destroy();
	}
	protected void CreateDamageTriggerRegular()
	{
		DestroyDamageTriggerRegular();
		m_AnomalyDamageRegular = new AnomalyDamageRegular(this, "-1.5 0 -1.5", "1.5 1.0 1.5", "AnomalyBurnerHit2", { "RightLeg", "LeftLeg", "Torso" }, 0.5);
		if (m_AnomalyDamageRegular)
			m_AnomalyDamageRegular.Spawn();
	}
	protected void DestroyDamageTriggerRegular()
	{
		if (m_AnomalyDamageRegular)
			m_AnomalyDamageRegular.Destroy();

		m_HeatingTimer.Stop();
		nearest_objects.Clear();
		proxy_cargos.Clear();
	}
	protected void CreateTriggerLight()
	{
		m_LightTrigger = PointLightBase.Cast(ScriptedLightBase.CreateLight(PointLightBase, "0 1.5 0"));
		if (m_LightTrigger)
		{
			m_LightTrigger.SetVisibleDuringDaylight(true);
			m_LightTrigger.SetRadiusTo(10.0);
			m_LightTrigger.SetBrightnessTo(25.0);
			m_LightTrigger.SetCastShadow(false);
			m_LightTrigger.EnableSpecular(false);
			m_LightTrigger.EnableLinear(false);
			m_LightTrigger.SetFlareVisible(false);
			m_LightTrigger.FadeIn(0.1);
			m_LightTrigger.SetLifetime(10.0);
			m_LightTrigger.SetFadeOutTime(1.0);
			m_LightTrigger.SetAmbientColor(0.9, 0.4, 0.4);
			m_LightTrigger.SetDiffuseColor(0.9, 0.4, 0.4);
			m_LightTrigger.AttachOnObject(this);
		}
	}
	override void EOnInit(IEntity other, int extra)
	{
		CreateDamageTriggerOneTime();
	}
	void Trigger()
	{
		m_Triggered = true;
		SetSynchDirty();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ReActivate, TRIGGER_COOLDOWN, false);
	}
	protected void TransferHeatToNearPlayers()
	{
		float distance;
		GetGame().GetObjectsAtPosition(GetPosition(), PARAM_HEAT_RADIUS, nearest_objects, proxy_cargos);
		for (int i = 0; i < nearest_objects.Count(); i++)
		{
			Object nearest_object = nearest_objects.Get(i);
			if (nearest_object.IsInherited(PlayerBase))
			{
				PlayerBase player = PlayerBase.Cast(nearest_object);
				distance = vector.Distance(player.GetPosition(), GetPosition());
				distance = Math.Max(distance, 0.1);
				float temperature = TEMPERATURE * (PARAM_HEAT_THROUGH_AIR_COEF / distance);
				player.AddToEnvironmentTemperature(temperature);
			}
			else if (nearest_object != this && nearest_object.IsInherited(ItemBase) && nearest_object.GetParent() == null)
			{
				ItemBase item = ItemBase.Cast(nearest_object);
				float wetness = item.GetWet();
				if (wetness > 0)
				{
					distance = vector.Distance(item.GetPosition(), GetPosition());
					distance = Math.Max(distance, 0.1);
					wetness = wetness * (PARAM_HEAT_THROUGH_AIR_COEF / distance);
					wetness = Math.Clamp(wetness, item.GetWetMin(), item.GetWetMax());
					item.AddWet(-wetness);
				}
			}
		}
	}
}