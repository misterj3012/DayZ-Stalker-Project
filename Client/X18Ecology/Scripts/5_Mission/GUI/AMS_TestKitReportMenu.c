#ifdef AMS_AdditionalMedicSupplies
modded class AMS_TestKitReportMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18Ecology/Data/Layouts/TestKitReport.layout");

		return layoutRoot;
	}

	override void ReadReport(AMS_TestKitReport report)
	{
		if (report)
		{
			SimpleProgressBarWidget progressBar;

			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("cholerar"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_Cholera);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("salmonellar"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_Salmonella);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("influenzar"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_Influenza);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("woundinfectionr"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_Woundinfection);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("kurur"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_Kuru);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("foodpoisonr"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_FoodPoison);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("chemicalpoisonr"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_ChemicalPoison);
			}
			progressBar = SimpleProgressBarWidget.Cast(layoutRoot.FindAnyWidget("radiationsickstager"));
			if (progressBar)
			{
				progressBar.SetCurrent(report.m_RadiationSickStage);
			}
		}
	}
}
#endif