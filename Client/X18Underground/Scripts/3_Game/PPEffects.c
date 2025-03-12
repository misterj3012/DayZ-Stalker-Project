modded class PPEffects
{
    static void FlashBoomEffect(float value)
    {
        m_MatColors.SetParam("TargetBrightness", 0.1);
        m_MatColors.SetParam("OverlayFactor", 0.99);
    }
};