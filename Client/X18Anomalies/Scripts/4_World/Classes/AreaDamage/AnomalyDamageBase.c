class AnomalyDamageBase
{
	protected Anomaly_Base m_Anomaly;
	protected AnomalyDamageTrigger m_AnomalyDamageTrigger;
	protected string m_AmmoName;
	protected vector m_ExtentMin;
	protected vector m_ExtentMax;
	protected ref array<string> m_HitZones;
	protected ref array<typename> m_DamageableTypes = { DayZPlayer, DayZInfected, DayZAnimal };
	void AnomalyDamageBase(Anomaly_Base anomaly, vector min, vector max, string ammo, array<string> hitzones)
	{
		m_Anomaly = anomaly;
		m_HitZones = hitzones;
		m_AmmoName = ammo;
		m_ExtentMin = min;
		m_ExtentMax = max;
	}
	void ~AnomalyDamageBase()
	{
		Destroy();
	}
	vector GetPosition()
	{
		if (m_Anomaly)
			return m_Anomaly.GetPosition();
		return "0 0 0";
	}
	void Spawn()
	{
		CreateDamageTrigger();
	}
	void Destroy()
	{
		DestroyDamageTrigger();
	}
	void OnEnter(Object obj)
	{}
	void OnLeave(Object obj)
	{}
	void PreDamageActions()
	{
		if (m_Anomaly)
			m_Anomaly.PreAreaDamageActions();
	}
	void DamageActions(Object obj)
	{
		if (m_Anomaly)
			m_Anomaly.DamageAreaDamageActions(obj);
	}
	void PostDamageActions()
	{
		if (m_Anomaly)
			m_Anomaly.PostAreaDamageActions();
	}
	protected void CreateDamageTrigger()
	{
		if (m_Anomaly && !m_AnomalyDamageTrigger)
		{
			if (Class.CastTo(m_AnomalyDamageTrigger, GetGame().CreateObjectEx("AnomalyDamageTrigger", m_Anomaly.GetPosition(), ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT)))
			{
				m_AnomalyDamageTrigger.SetExtents(m_ExtentMin, m_ExtentMax);
				m_AnomalyDamageTrigger.SetAnomalyDamageType(this);

				if (GetGame().IsClient() && GetGame().IsMultiplayer())
				{
					vector minmax[2];
					m_AnomalyDamageTrigger.GetCollisionBox(minmax);
					Shape dbgShape = Debug.DrawBox(minmax[0], minmax[1]);

					vector mat[4];

					m_AnomalyDamageTrigger.GetTransform(mat);
					dbgShape.CreateMatrix(mat);
					dbgShape.SetMatrix(mat);
				}
			}
		}
	}
	protected void DestroyDamageTrigger()
	{
		if (GetGame() && m_AnomalyDamageTrigger)
		{
			GetGame().ObjectDelete(m_AnomalyDamageTrigger);
			m_AnomalyDamageTrigger = null;
		}
	}
	protected void EvaluateDamage(Object obj)
	{
		if (obj && obj.IsAlive())
		{
			if (obj.IsAnyInherited(m_DamageableTypes) && m_HitZones)
				obj.ProcessDirectDamage(DT_CUSTOM, m_Anomaly, m_HitZones.GetRandomElement(), m_AmmoName, "0.5 0.5 0.5", 1);
			else if (obj.IsInherited(X18_Bolt))
				GetGame().ObjectDelete(obj);
		}
	}
}