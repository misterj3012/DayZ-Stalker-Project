modded class X18_Artefact_Fireball_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatRadiation().Add(-5);
	}
	override void OnTickNegative(PlayerBase player)
	{
		player.AddHealth("", "Health", -1);
	}
	override void OnPassivePositiveActivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(0.05);
	}

	override void OnPassivePositiveDeactivate(PlayerBase player)
	{
		player.GetStatBulletProtection().Add(-0.05);
	}

	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.36);
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 2.5);
	}

	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.36);
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 2.5);
	}
}