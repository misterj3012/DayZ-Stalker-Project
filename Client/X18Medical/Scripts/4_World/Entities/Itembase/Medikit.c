class X18_Meds_MediKit_Tier1 : Inventory_Base
{
	protected ref OpenableBehaviour m_Openable;
	void X18_Meds_MediKit_Tier1()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		UpdateVisualState();
	}
	override void Open()
	{
		m_Openable.Open();
		SetSynchDirty();
		UpdateVisualState();
	}
	override void Close()
	{
		m_Openable.Close();
		SetSynchDirty();
		UpdateVisualState();
	}
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	protected void UpdateVisualState()
	{
		if (IsOpen())
			SetAnimationPhase("lid", 0.0);
		else
			SetAnimationPhase("lid", 1.0);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisualState();
	}
	override float GetBandagingEffectivity()
	{
		return 1.0;
	}
	override float GetInfectionChance(int system = 0, Param param = null)
	{
		return 0.0;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpen);
		AddAction(ActionClose);
		AddAction(ActionUseMediKitSelf);
		AddAction(ActionUseMediKitTarget);
	}
}
class X18_Meds_MediKit_Tier2 : X18_Meds_MediKit_Tier1 {}
class X18_Meds_MediKit_Tier3 : X18_Meds_MediKit_Tier1 {}