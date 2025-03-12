modded class X18_Meds_MediKit_Tier1
{
	override void OnApply(PlayerBase player)
	{
		if (!player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_MEDIKIT_TIER1))
			player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_MEDIKIT_TIER1);
	}
}
modded class X18_Meds_MediKit_Tier2
{
	override void OnApply(PlayerBase player)
	{
		if (!player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_MEDIKIT_TIER2))
			player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_MEDIKIT_TIER2);
	}
}
modded class X18_Meds_MediKit_Tier3
{
	override void OnApply(PlayerBase player)
	{
		if (!player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_MEDIKIT_TIER3))
			player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_MEDIKIT_TIER3);
	}
}