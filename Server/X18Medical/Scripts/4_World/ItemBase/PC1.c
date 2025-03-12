modded class X18_Meds_PC1
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if (consumer.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_PC1))
			consumer.GetModifiersManager().DeactivateModifier(X18MedicalModifiers.MDF_PC1);
		consumer.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_PC1);

		consumer.InsertAgent(X18MedicalAgents.PC1, amount);
	}
}