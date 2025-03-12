class X18_StashesBase : ItemBase
{
	bool m_CanInspect;
	override void EEInit()
	{
		super.EEInit();
		m_CanInspect = false;
	}
	protected void Destructor()
	{
		if (GetGame().IsServer())
			GetGame().ObjectDelete(this);
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override bool CanRemoveFromHands(EntityAI player)
	{
		return false;
	}
	override bool IsInventoryVisible()
	{
		return m_CanInspect;
	}
	bool CanInspect()
	{
		return m_CanInspect;
	}
	void SetCanInspect()
	{
		if (GetGame().IsClient())
			m_CanInspect = true;
	}
};