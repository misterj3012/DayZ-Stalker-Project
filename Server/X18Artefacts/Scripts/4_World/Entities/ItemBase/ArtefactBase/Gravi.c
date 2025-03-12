modded class X18_Artefact_Gravi_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Blood", 5);
	}
	override void OnTickNegative(PlayerBase player)
	{
		BrokenLegs(player, 3);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(-0.1);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatInventoryWeightReduction().Add(0.1);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 2.5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 2.5);
	}
}