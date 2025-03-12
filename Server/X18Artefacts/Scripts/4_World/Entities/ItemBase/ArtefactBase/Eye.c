modded class X18_Artefact_Eye_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatWater().Add(10);
		player.AddHealth("", "Shock", 5.5);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(15);
		player.AddHealth("", "Blood", -4);
	}

	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 5);
	}

	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 5);
	}
}