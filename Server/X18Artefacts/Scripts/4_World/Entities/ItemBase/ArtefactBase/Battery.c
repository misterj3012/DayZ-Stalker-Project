modded class X18_Artefact_Battery_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Shock", 3);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(1);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.02);
	}

	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.02);
	}

	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatBloodLossModifier().Add(0.07);
	}

	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatBloodLossModifier().Add(-0.07);
	}
}