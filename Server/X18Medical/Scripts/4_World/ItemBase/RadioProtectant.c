modded class X18_Meds_RadioProtectant
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if (consumer.GetModifiersManager().IsModifierActive(X18MedicalModifiers.MDF_RADIOPROTECTANT))
			consumer.GetModifiersManager().DeactivateModifier(X18MedicalModifiers.MDF_RADIOPROTECTANT);
		consumer.GetModifiersManager().ActivateModifier(X18MedicalModifiers.MDF_RADIOPROTECTANT);

		consumer.InsertAgent(X18MedicalAgents.RADIOPROTECTANT, amount);
	}
}