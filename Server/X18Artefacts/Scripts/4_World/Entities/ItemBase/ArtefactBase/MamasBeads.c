modded class X18_Artefact_MamasBeads_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		Bleeding(player, 5, false);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.GetStatEnergy().Add(-10);
		player.GetStatWater().Add(-10);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.05);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.05);
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