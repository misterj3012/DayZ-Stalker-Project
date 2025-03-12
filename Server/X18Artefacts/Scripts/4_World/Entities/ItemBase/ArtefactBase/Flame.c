modded class X18_Artefact_Flame_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatEnergy().Add(10);
		player.GetStatWater().Add(10);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(3);
		Bleeding(player, 6);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 2.5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 2.5);
	}
}