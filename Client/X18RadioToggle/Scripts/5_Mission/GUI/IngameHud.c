modded class IngameHud
{
	protected ImageWidget m_RadioPtt;
	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);
		if (m_HudPanelWidget)
			Class.CastTo(m_RadioPtt, GetGame().GetWorkspace().CreateWidgets("Noosphere/X18RadioToggle/GUI/Layouts/radio_ptt_radio_standalone.layout", m_HudPanelWidget));
	}
}