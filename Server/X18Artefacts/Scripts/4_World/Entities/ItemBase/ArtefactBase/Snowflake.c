modded class X18_Artefact_Snowflake_Base : X18_Artefact_Base
{
	override void OnTickPositive(PlayerBase player)
	{
		player.GetStatEnergy().Add(50);
		player.GetStatWater().Add(50);
	}
	override void OnPassiveNegativeActivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort - 10);
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() + 0.5);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() - 0.5);
	}
	override void OnPassiveNegativeDeactivate(PlayerBase player)
	{
		private float m_GetStatHeatComfort = player.GetStatHeatComfort().Get();
		player.GetStatHeatComfort().Set(m_GetStatHeatComfort + 10);
		player.GetStaminaHandler().SetDepletionMultiplier(player.GetStaminaHandler().GetDepletionMultiplier() - 0.5);
		player.GetStaminaHandler().SetRecoveryMultiplier(player.GetStaminaHandler().GetRecoveryMultiplier() + 0.5);
	}
}