modded class X18_Artefact_StoneBlood_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Health", 2);
	}
	override void OnTickNegative(PlayerBase player)
	{
		BrokenLegs(player, 10);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatBloodLossModifier().Add(0.1);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatBloodLossModifier().Add(-0.1);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() - 0.05);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() + 0.05);
	}
}