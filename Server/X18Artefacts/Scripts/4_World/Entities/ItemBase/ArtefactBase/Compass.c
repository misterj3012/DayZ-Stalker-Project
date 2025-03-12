modded class X18_Artefact_Compass_Base : X18_Artefact_Base
{
	override void OnTickNegative(PlayerBase player)
	{
		if (player.GetFaction() != EFactions.Sin)
			player.GetStatRadiation().Add(50);
	}

	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.5);
		player.GetStatMeleeProtection().Add(0.5);
		player.GetStatInventoryWeightReduction().Add(0.5);
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.50);
	}

	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.5);
		player.GetStatMeleeProtection().Add(-0.5);
		player.GetStatInventoryWeightReduction().Add(-0.5);
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.50);
	}
}