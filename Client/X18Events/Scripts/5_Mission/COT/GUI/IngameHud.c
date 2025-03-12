modded class IngameHud : Hud
{
	ref Widget m_EventLayout;
	ref ImageWidget m_Sheltered;
	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);
		m_EventLayout = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18Events/Data/GUI/Layouts/Event.layout");
		m_EventLayout.Show(false);
		m_Sheltered = ImageWidget.Cast(m_EventLayout.FindAnyWidget("ShelteredOverlay"));
		m_Sheltered.Show(false);
	}
	override void OnResizeScreen()
	{
		super.OnResizeScreen();
		m_EventLayout.Update();
	}
	override void RefreshHudVisibility()
	{
		m_EventLayout.Show((!m_HudHidePlayer && !m_HudHideUI && m_HudState) || m_HudInventory);
		super.RefreshHudVisibility();
	}
	override void ShowInsideIcon(bool show)
	{
		m_Sheltered.Show(show);
	}
}