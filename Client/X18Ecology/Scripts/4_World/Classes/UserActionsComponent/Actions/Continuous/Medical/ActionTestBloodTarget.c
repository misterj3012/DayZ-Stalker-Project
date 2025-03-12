#ifdef AMS_AdditionalMedicSupplies
modded class ActionTestBloodTarget
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		PlayerBase player = PlayerBase.Cast(action_data.m_Target.GetObject());

		if (player && GameConstants.BLOODTESTKIT_YIELD_REPORT)
		{
			AMS_TestKitReport report = AMS_TestKitReport.Cast(action_data.m_Player.GetInventory().CreateInInventory("AMS_TestKitReport"));
			if (!report)
				report = AMS_TestKitReport.Cast(action_data.m_Player.SpawnEntityOnGroundOnCursorDir("AMS_TestKitReport", 0.5));

			if (report)
			{
				if (report.GetEconomyProfile())
					report.SetLifetime(report.GetEconomyProfile().GetLifetime());

				report.m_Cholera = player.GetSingleAgentCountNormalized(eAgents.CHOLERA);
				report.m_Salmonella = player.GetSingleAgentCountNormalized(eAgents.SALMONELLA);
				report.m_Influenza = player.GetSingleAgentCountNormalized(eAgents.INFLUENZA);
				report.m_Woundinfection = player.GetSingleAgentCountNormalized(eAgents.WOUND_AGENT);
				report.m_Kuru = player.GetSingleAgentCountNormalized(eAgents.BRAIN);
				report.m_FoodPoison = player.GetSingleAgentCountNormalized(eAgents.FOOD_POISON);
				report.m_ChemicalPoison = player.GetSingleAgentCountNormalized(eAgents.CHEMICAL_POISON);
				report.m_RadiationSickStage = player.GetRadiationSickStage();
			}
		}
	}
}
#endif