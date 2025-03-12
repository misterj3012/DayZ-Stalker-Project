class GasMaskOverlay
{
	private ref Widget      m_GasMaskOverlayWidget;
	private ref ImageWidget m_GasMaskOverlayImage;
	void GasMaskOverlay()
	{
		m_GasMaskOverlayWidget = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18Ecology/Data/Layouts/EcologyGasMasks.layout");
		m_GasMaskOverlayImage = ImageWidget.Cast(m_GasMaskOverlayWidget.FindAnyWidget("GasMaskOverlay"));
		m_GasMaskOverlayWidget.Show(false);
	}
	void Show(EntityAI item, int healthlevel = 0)
	{
		if (item.GetType().Contains("CM7") || item.GetType().Contains("GMS") || item.GetType().Contains("GP5") || item.GetType().Contains("HOMA") || item.GetType().Contains("M04") || item.GetType().Contains("M40") || item.GetType().Contains("PFBP1") || item.GetType().Contains("PMG4") || item.GetType().Contains("RSH4") || item.GetType().Contains("S10") || item.GetType().Contains("WW1"))
		{
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_PRISTINE, "Noosphere/X18Ecology/Data/Overlays/Eyes_Overlay_Pristine.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_WORN, "Noosphere/X18Ecology/Data/Overlays/Eyes_Overlay_Worn.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Eyes_Overlay_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_BADLY_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Eyes_Overlay_Badly_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_RUINED, "Noosphere/X18Ecology/Data/Overlays/Eyes_Overlay_Ruined.paa");
		}
		if (item.GetType().Contains("GP21") || item.GetType().Contains("GP7") || item.GetType().Contains("M50") || item.GetType().Contains("MK10") || item.GetType().Contains("P2"))
		{
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_PRISTINE, "Noosphere/X18Ecology/Data/Overlays/Notch_Overlay_Pristine.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_WORN, "Noosphere/X18Ecology/Data/Overlays/Notch_Overlay_Worn.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Notch_Overlay_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_BADLY_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Notch_Overlay_Badly_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_RUINED, "Noosphere/X18Ecology/Data/Overlays/Notch_Overlay_Ruined.paa");
		}
		if (item.GetType().Contains("Seva") || item.GetType().Contains("AVC"))
		{
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_PRISTINE, "Noosphere/X18Ecology/Data/Overlays/Full_Pristine.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_WORN, "Noosphere/X18Ecology/Data/Overlays/Full_Worn.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Full_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_BADLY_DAMAGED, "Noosphere/X18Ecology/Data/Overlays/Full_Badly_Damaged.paa");
			m_GasMaskOverlayImage.LoadImageFile(GameConstants.STATE_RUINED, "Noosphere/X18Ecology/Data/Overlays/Full_Ruined.paa");
		}
		m_GasMaskOverlayImage.SetImage(healthlevel);
		m_GasMaskOverlayWidget.Show(true);
	}
	void Hide()
	{
		m_GasMaskOverlayWidget.Show(false);
	}
}