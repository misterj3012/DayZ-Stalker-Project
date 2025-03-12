modded class X18_Meds_Mexamin_Injector
{
	override void OnApply(PlayerBase player)
	{
		if (!player.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_MEXAMIN_INJECTOR))
			player.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_MEXAMIN_INJECTOR);
	}
}