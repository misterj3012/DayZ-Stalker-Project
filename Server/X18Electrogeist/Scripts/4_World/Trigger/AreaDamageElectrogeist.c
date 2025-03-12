class AreaDamageElectrogeist : AreaDamageBase
{
	void AreaDamageElectrogeist(EntityAI parent)
	{
		AreaDamageBase(parent);
		m_DamageableTypes.Insert(Man);
		m_DamageableTypes.Insert(DayZCreature);
	}
	void ~AreaDamageElectrogeist() {}
	override void SetHitZones(array<string> hitzones)
	{
		m_HitZones = hitzones;
	}
	override void OnEnterServer(Object object)
	{
		super.OnEnterServer(object);
		EvaluateDamage_Electrogeist(object);
	}
	protected void EvaluateDamage_Electrogeist(Object object)
	{
		string hitzone;
		if (m_RaycastSources.Count())
		{
			hitzone = GetRaycastedHitZone(object, m_RaycastSources);
			EvaluateDamage_Electrogeist_Common(object, hitzone);
		}
		else
		{
			hitzone = GetRandomHitZone(m_HitZones);
			EvaluateDamage_Electrogeist_Common(object, hitzone);
		}
	}
	void EvaluateDamage_Electrogeist_Common(Object object, string hitzone)
	{
		if (object && object.IsAlive())
		{
			EntityAI eai = EntityAI.Cast(object);
			if (object.GetType() == "X18_Mutant_Electrogeist")
				return;
			else if (object.IsInherited(DayZPlayer))
			{
				Man mantarget = Man.Cast(object);
				PlayerBase player = PlayerBase.Cast(object);
				player.GetStatHeatComfort().Set(60);
				eai.ProcessDirectDamage(m_DamageType, EntityAI.Cast(m_ParentObject), hitzone, m_AmmoName, "0.5 0.5 0.5", 1);
			}
			else if (object.IsAnyInherited(m_DamageableTypes))
				eai.ProcessDirectDamage(m_DamageType, EntityAI.Cast(m_ParentObject), hitzone, m_AmmoName, "0.5 0.5 0.5", 1);
		}
	}
}