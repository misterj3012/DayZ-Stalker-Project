modded class X18_Artefact_Goldfish_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.AddHealth("", "Blood", 5);
		BrokenLegs(player, 5, false);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatRadiation().Add(5);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStatMeleeProtection().Add(0.05);
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 2.5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStatMeleeProtection().Add(-0.05);
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 2.5);
	}
}