modded class GasMaskFilter_Base
{
	override void OnEnergyConsumed()
	{
		super.OnEnergyConsumed();
		if (GetGame().IsServer())
		{
			float energy_coef = GetCompEM().GetEnergy0To1();
			if (energy_coef < m_EfficiencyDecayStart && m_EfficiencyDecayStart > 0)
			{
				m_Efficiency0To10 = Math.Round((energy_coef / m_EfficiencyDecayStart) * 10);
				SetSynchDirty();
			}
		}
	}
};