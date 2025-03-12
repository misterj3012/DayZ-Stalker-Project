modded class ActionClose
{
	override void SetCloseAnimation(ItemBase item)
	{
		if (item && item.IsKindOf("X18_Meds_MediKit_Tier1"))
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_CLOSEITEM_ONCE;
		else
			super.SetCloseAnimation(item);
	}
}