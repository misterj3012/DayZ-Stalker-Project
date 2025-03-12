modded class X18_Artefact_AlteredInsulator_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatEnergy().Add(25);
		player.GetStatWater().Add(25);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(6);
		Bleeding(player, 6);
	}
}