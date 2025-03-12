class PluginGasMaskOverlay : PluginBase
{
    private ref GasMaskOverlay m_GasMaskOverlay = new GasMaskOverlay();

    override void OnUpdate(float delta_time)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && player.IsAlive() && !player.IsUnconscious() && m_GasMaskOverlay)
        {
            EntityAI m_GasMask = player.GetHumanInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Mask"));
            EntityAI m_Helmet = player.GetHumanInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Headgear"));

            if (m_GasMask && (m_GasMask.GetType().Contains("CM7") || m_GasMask.GetType().Contains("GMS") || m_GasMask.GetType().Contains("GP5") || m_GasMask.GetType().Contains("HOMA") || m_GasMask.GetType().Contains("M04") || m_GasMask.GetType().Contains("M40") || m_GasMask.GetType().Contains("PFBP1") || m_GasMask.GetType().Contains("PMG4") || m_GasMask.GetType().Contains("RSH4") || m_GasMask.GetType().Contains("S10") || m_GasMask.GetType().Contains("WW1")))
                m_GasMaskOverlay.Show(m_GasMask, m_GasMask.GetHealthLevel());
            else if (m_GasMask && (m_GasMask.GetType().Contains("GP21") || m_GasMask.GetType().Contains("GP7") || m_GasMask.GetType().Contains("M50") || m_GasMask.GetType().Contains("MK10") || m_GasMask.GetType().Contains("P2") || m_GasMask.GetType().Contains("AVC")))
                m_GasMaskOverlay.Show(m_GasMask, m_GasMask.GetHealthLevel());
            else if (m_Helmet && m_Helmet.GetType().Contains("Seva"))
                m_GasMaskOverlay.Show(m_Helmet, m_Helmet.GetHealthLevel());
            else
                m_GasMaskOverlay.Hide();
        }
    }
}