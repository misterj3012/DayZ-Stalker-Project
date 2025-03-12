modded class X18_Artefact_StoneFlower_Base : X18_Artefact_Base
{
	override void OnTickNegative(PlayerBase player)
	{
		player.AddHealth("", "Health", -5);
		player.GetStatRadiation().Add(5);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.2);
		player.GetStatMeleeProtection().Add(-0.2);
	}
	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.2);
		player.GetStatMeleeProtection().Add(0.2);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 5);
	}
}