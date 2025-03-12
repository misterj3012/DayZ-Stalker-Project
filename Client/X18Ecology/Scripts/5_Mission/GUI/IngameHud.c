modded class IngameHud : Hud
{
	ref Widget m_RadiationLayout;
	ref ImageWidget m_RadiationSickness;
	ref Widget m_GeigerCounterDisplay;
	ref TextWidget m_GeigerCounterValue;
	ref Widget m_RadiationOnPlayer;
	ref TextWidget m_RadiationOnPlayerValue;
	ref Widget m_RadiationOnTarget;
	ref TextWidget m_RadiationOnTargetValue;
	override void Update(float timeslice)
	{
		super.Update(timeslice);
	}
	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);
		m_RadiationLayout = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18Ecology/Data/Layouts/Ecology.layout");
		m_RadiationLayout.Show(false);
		m_RadiationSickness = ImageWidget.Cast(m_RadiationLayout.FindAnyWidget("RadiationSickness"));
		m_RadiationSickness.LoadImageFile(0, "Noosphere/X18Ecology/Data/Images/RadiationSickness.paa");
		m_RadiationSickness.Show(false);

		m_GeigerCounterDisplay = m_RadiationLayout.FindAnyWidget("GeigerCounterDisplay");
		m_GeigerCounterDisplay.Show(false);
		m_GeigerCounterValue = TextWidget.Cast(m_RadiationLayout.FindAnyWidget("GeigerCounterValue"));

		m_RadiationOnPlayer = m_RadiationLayout.FindAnyWidget("RadiationOnPlayer");
		m_RadiationOnPlayer.Show(false);
		m_RadiationOnPlayerValue = TextWidget.Cast(m_RadiationLayout.FindAnyWidget("RadiationOnPlayerValue"));

		m_RadiationOnTarget = m_RadiationLayout.FindAnyWidget("RadiationOnTarget");
		m_RadiationOnTarget.Show(false);
		m_RadiationOnTargetValue = TextWidget.Cast(m_RadiationLayout.FindAnyWidget("RadiationOnTargetValue"));
	}
	override void OnResizeScreen()
	{
		super.OnResizeScreen();
		m_RadiationLayout.Update();
	}
	override void RefreshHudVisibility()
	{
		m_RadiationLayout.Show((!m_HudHidePlayer && !m_HudHideUI && m_HudState) || m_HudInventory);
		super.RefreshHudVisibility();
	}
	override void ShowRadiationSicknessSymbol(bool show)
	{
		m_RadiationSickness.Show(show);
	}
	override void ShowGeigerCounter(bool show)
	{
		m_GeigerCounterDisplay.Show(show);
	}
	override void SetGeigerCounterValue(float value, int state = 0)
	{
		if (value < 0)
			value = 0;

		if (state == 1 && value >= 10000)
			value = 10000;
		if (state == 2 && value >= 5000)
			value = 5000;
		if (state == 3 && value >= 500)
			value = 500;

		m_GeigerCounterValue.SetText(GetFormattedRadValue(value));
	}
	override void EnableRadiationOnPlayerDisplay(bool show)
	{
		m_RadiationOnPlayer.Show(show);
	}
	override void ShowRadiationOnPlayer(float value, int state = 0)
	{
		if (value < 0)
			value = 0;

		if (state == 1 && value >= 10000)
			value = 10000;
		if (state == 2 && value >= 5000)
			value = 5000;
		if (state == 3 && value >= 500)
			value = 500;

		EnableRadiationOnPlayerDisplay(true);
		m_RadiationOnPlayerValue.SetText(GetFormattedRadValue(value));
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(EnableRadiationOnPlayerDisplay, 30000, false, false);
	}
	override void EnableRadiationOnTargetDisplay(bool show)
	{
		m_RadiationOnTarget.Show(show);
	}
	override void ShowRadiationOnTarget(float value, int state = 0)
	{
		if (value < 0)
			value = 0;

		if (state == 1 && value >= 10000)
			value = 10000;
		if (state == 2 && value >= 5000)
			value = 5000;

		EnableRadiationOnTargetDisplay(true);
		m_RadiationOnTargetValue.SetText(GetFormattedRadValue(value));
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(EnableRadiationOnTargetDisplay, 15000, false, false);
	}

	string GetFormattedRadValue(float value)
	{
		TStringArray strs = new TStringArray;
		string text = value.ToString();
		text.Split(".", strs);
		return strs.Get(0);
	}
}