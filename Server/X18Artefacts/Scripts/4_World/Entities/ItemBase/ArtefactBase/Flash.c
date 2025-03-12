modded class X18_Artefact_Flash_Base : X18_Artefact_Base
{
	override void OnTickNegative(PlayerBase player)
	{
		player.AddHealth("", "Shock", -2.5);
		player.GetStatEnergy().Add(-10);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.15);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() + 0.05);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.15);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() - 0.05);
	}
}