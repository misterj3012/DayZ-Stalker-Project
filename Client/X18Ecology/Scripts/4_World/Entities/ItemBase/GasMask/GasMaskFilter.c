class GasMaskFilter_Base : ItemBase
{
	private int				m_Efficiency0To10;
	static private float 	m_EfficiencyDecayStart = 0.1;
	void GasMaskFilter_Base()
	{
		m_Efficiency0To10 = 10;
		RegisterNetSyncVariableInt("m_Efficiency0To10");
	}
	override void SetCEBasedQuantity()
	{
		super.SetCEBasedQuantity();
		if (GetCompEM())
			GetCompEM().SetEnergy(GetCompEM().GetEnergyMax() * (GetQuantity() / GetQuantityMax()));
	}
	float GetEfficiency0To1()
	{
		return m_Efficiency0To10 / 10;
	}
	float GetEfficiencyDecayStart()
	{
		return m_EfficiencyDecayStart;
	}
};
class X18_GasMask_AVC_Filter : GasMaskFilter_Base {};
class X18_GasMask_CM7_Filter : GasMaskFilter_Base {};
class X18_GasMask_CN2F_Filter : GasMaskFilter_Base {};
class X18_GasMask_GMS_Filter : GasMaskFilter_Base {};
class X18_GasMask_GP5_Filter : GasMaskFilter_Base {};
class X18_GasMask_GP7_Filter : GasMaskFilter_Base {};
class X18_GasMask_GP21_Filter : GasMaskFilter_Base {};
class X18_GasMask_HOMA_Filter : GasMaskFilter_Base {};
class X18_GasMask_M04_Filter : GasMaskFilter_Base {};
class X18_GasMask_M40_Filter : GasMaskFilter_Base {};
class X18_GasMask_M50_Filter : GasMaskFilter_Base {};
class X18_GasMask_M50M2_Filter : GasMaskFilter_Base {};
class X18_GasMask_M50CBRN_Filter : GasMaskFilter_Base {};
class X18_GasMask_MK10_Filter : GasMaskFilter_Base {};
class X18_GasMask_P2_Filter : GasMaskFilter_Base {};
class X18_GasMask_P2_Filter_Duty : GasMaskFilter_Base {};
class X18_GasMask_PFBP1_Filter : GasMaskFilter_Base {};
class X18_GasMask_PMG4_Filter : GasMaskFilter_Base {};
class X18_GasMask_RSH4_Filter : GasMaskFilter_Base {};
class X18_GasMask_S10_Filter : GasMaskFilter_Base {};
class X18_GasMask_WW1_Filter : GasMaskFilter_Base {};
class X18_GasMask_CBRN_Filter_Right : GasMaskFilter_Base {};
class X18_GasMask_CBRN_Filter_Left : GasMaskFilter_Base {};
class X18_GasMask_Stalker_Filter : GasMaskFilter_Base {};
class X18_GasMask_Stalker_FullFace_Filter : GasMaskFilter_Base {};
class X18_GasMask_PPM88_Filter : GasMaskFilter_Base {};