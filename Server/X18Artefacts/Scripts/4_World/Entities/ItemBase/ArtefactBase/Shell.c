modded class X18_Artefact_Shell_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatRadiation().Add(-7.5);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.25);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.25);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.1);
		player.GetStatMeleeProtection().Add(0.1);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.1);
		player.GetStatMeleeProtection().Add(-0.1);
	}
}