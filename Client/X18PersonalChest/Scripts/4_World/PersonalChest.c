class X18_PersonalChest_Base : BuildingSuper
{
	private bool m_InventoryVisible = false;
	void X18_PersonalChest_Base() {}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenPersonalChest);
	}
	override bool IsInventoryVisible()
	{
		return false;
	}
};
class X18_PersonalChest_Army_Box : X18_PersonalChest_Base {};
class X18_PersonalChest_Army_Case : X18_PersonalChest_Base {};
class X18_PersonalChest_MetalCrate_Black : X18_PersonalChest_Base {};
class X18_PersonalChest_MetalCrate_Blue : X18_PersonalChest_Base {};
class X18_PersonalChest_MetalCrate_Olive : X18_PersonalChest_Base {};
class X18_PersonalChest_MetalCrate_Red : X18_PersonalChest_Base {};
class X18_PersonalChest_MetalCrate_Yellow : X18_PersonalChest_Base {};
class X18_PersonalChest_Palette : X18_PersonalChest_Base {};
class X18_PersonalChest_SeaChest : X18_PersonalChest_Base {};
class X18_PersonalChest_SupplyCrate_Wood : X18_PersonalChest_Base {};
class X18_PersonalChest_SupplyCrate_Blue : X18_PersonalChest_Base {};
class PersonalChest : ItemBase
{
	protected bool m_IsMyPersonalChest = false;
	void PersonalChest()
	{
		SetInvisible(true);
		//SetTakeable(false);
	}
	bool IsMyPersonalChest()
	{
		return m_IsMyPersonalChest;
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		switch (rpc_type)
		{
		case X18PersonalChestERPCs.SET_PERSONAL:
			m_IsMyPersonalChest = true;
			break;
		}
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (GetHealthLevel() == GameConstants.STATE_RUINED)
			return false;
		return super.CanReceiveAttachment(attachment, slotId);
	}
	override bool CanLoadAttachment(EntityAI attachment)
	{
		if (GetHealthLevel() == GameConstants.STATE_RUINED)
			return false;
		return super.CanLoadAttachment(attachment);
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (GetHealthLevel() == GameConstants.STATE_RUINED)
			return false;
		return super.CanReceiveItemIntoCargo(item);
	}
	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (!super.CanLoadItemIntoCargo(item))
			return false;
		if (GetHealthLevel() == GameConstants.STATE_RUINED)
			return false;
		return true;
	}
}