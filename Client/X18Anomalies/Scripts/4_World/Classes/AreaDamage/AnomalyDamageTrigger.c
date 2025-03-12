class AnomalyDamageTrigger : Trigger
{
	protected AnomalyDamageBase m_AnomalyDamageType;
	override void OnEnter(Object obj)
	{
		super.OnEnter(obj);
		if (m_AnomalyDamageType)
			m_AnomalyDamageType.OnEnter(obj);
	}
	override void OnLeave(Object obj)
	{
		super.OnLeave(obj);
		if (m_AnomalyDamageType)
			m_AnomalyDamageType.OnLeave(obj);
	}
	void SetAnomalyDamageType(AnomalyDamageBase anomalyDamage)
	{
		m_AnomalyDamageType = anomalyDamage;
	}
}