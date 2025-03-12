modded class X18_Artefact_NightStar_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(25);
		player.AddHealth("", "Shock", -5.5);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 1.0);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() + 0.50);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 1.0);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() - 0.50);
	}
}