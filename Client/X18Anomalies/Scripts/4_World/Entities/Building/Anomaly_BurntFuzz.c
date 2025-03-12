class X18_Anomaly_BurntFuzz_Small : Anomaly_Base
{
	protected ref AnomalyDamageRegular m_AnomalyDamage;
	protected SoundOnVehicle m_TriggerSound;
	protected bool m_Triggered = true;
	void X18_Anomaly_BurntFuzz_Small()
	{
		RegisterNetSyncVariableBool("m_Triggered");
	}
	void ~X18_Anomaly_BurntFuzz_Small()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			CleanUpClient();
		if (GetGame() && (GetGame().IsServer() || !GetGame().IsMultiplayer()))
			DestroyDamageTrigger();
	}
	protected void CleanUpClient()
	{
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
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-0.25 -0.5 -0.25", "0.25 0.5 0.25", "AnomalyBurntFuzzHit", { "Head", "Torso" }, 0.5);
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
class X18_Anomaly_BurntFuzz_Middle : X18_Anomaly_BurntFuzz_Small
{
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-0.375 -0.7 -0.375", "0.375 0.7 0.375", "AnomalyBurntFuzzHit", { "Head", "Torso" }, 0.5);
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
}
class X18_Anomaly_BurntFuzz_Normal : X18_Anomaly_BurntFuzz_Small
{
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-0.5 -1.5 -0.5", "0.5 1.5 0.5", "AnomalyBurntFuzzHit", { "Head", "Torso" }, 0.5);
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
}
class X18_Anomaly_BurntFuzz_SemiTall : X18_Anomaly_BurntFuzz_Small
{
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-0.75 -2 -0.75", "0.75 2 0.75", "AnomalyBurntFuzzHit", { "Head", "Torso" }, 0.5);
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
}
class X18_Anomaly_BurntFuzz_Tall : X18_Anomaly_BurntFuzz_Small
{
	protected void CreateDamageTrigger()
	{
		DestroyDamageTrigger();
		m_AnomalyDamage = new AnomalyDamageRegular(this, "-1 -3 -1", "1 3 1", "AnomalyBurntFuzzHit", { "Head", "Torso" }, 0.5);
		if (m_AnomalyDamage)
			m_AnomalyDamage.Spawn();
	}
}