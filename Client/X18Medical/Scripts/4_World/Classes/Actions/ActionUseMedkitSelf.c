class ActionUseMediKitSelf : ActionBandageSelf
{
	void ActionUseMediKitSelf()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return item.IsInherited(X18_Meds_MediKit_Tier1) && item.IsOpen();
	}
	override string GetText()
	{
		return "#apply";
	}
	override void ApplyBandage(ItemBase item, PlayerBase player)
	{
		item.OnApply(player);
		item.Delete();
	}
}