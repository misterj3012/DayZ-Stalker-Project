modded class X18_Artefact_Bubble_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Blood", 5);
		player.GetStatRadiation().Add(-15);
	}
	override void OnTickNegative(PlayerBase player)
	{
		BrokenLegs(player, 15);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(0.5);
	}

	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(-0.5);
	}
}