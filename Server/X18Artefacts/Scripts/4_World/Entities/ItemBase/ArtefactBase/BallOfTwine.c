modded class X18_Artefact_BallOfTwine_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatRadiation().Add(-20);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.AddHealth("", "Blood", -7);
		Bleeding(player, 5);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(-0.2);
	}

	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(0.2);
	}
}