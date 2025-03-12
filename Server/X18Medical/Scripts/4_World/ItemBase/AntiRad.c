modded class X18_Meds_AntiRad
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if (consumer.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_MEXAMIN))
			consumer.GetModifiersManager().DeactivateModifier(X18MedicalModifiers.MDF_MEXAMIN);
		consumer.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_MEXAMIN);

		consumer.InsertAgent(X18MedicalAgents.ANTIRAD, amount);
	}
}