modded class ScriptedLightBase
{
    void ScriptedLightBase()
    {
        if (GetGame().IsClient())
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(SetVisibleDuringDaylight, true);
    }
}
class DaylightLight : PointLightBase
{
    private static float m_DefaultBrightness = 200;
    private static float m_DefaultRadius = 500;
    void DaylightLight()
    {
        SetVisibleDuringDaylight(true);
        SetRadiusTo(m_DefaultRadius);
        SetCastShadow(true);
        EnableSpecular(false);
        SetBrightnessTo(m_DefaultBrightness);
        SetFadeOutTime(0.15);
        SetAmbientColor(1.0, 0.85, 0.75);
        SetDiffuseColor(1.0, 0.85, 0.75);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateDaytime, 1000, true);
    }
    void ~DaylightLight()
    {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(UpdateDaytime);
    }
    void UpdateDaytime()
    {
        World world = GetGame().GetWorld();
        if (world) {
            float accom = world.GetEyeAccom();
            if (accom >= 1)
            {
                FadeBrightnessTo(0.0001, 2.0);
                return;
            }
            int year = 0, month = 0, day = 0, hour = 0, min = 0;
            world.GetDate(year, month, day, hour, min);
            float daytime = (hour * 60 + min) / 24 / 60;
            daytime = 1.1 - Math.AbsFloat((daytime - 0.5) * 2.0);
            //Print("Daytime: " + daytime + " Time: " + hour + ":" + min + " Accom: " + accom);
            FadeBrightnessTo(Math.Max(0.0001, m_DefaultBrightness * daytime * (1.0 - accom)), 0.95);
            if (world.IsNight())
            {
                float color = 0.55;
                SetAmbientColor(color, color, color);
                SetDiffuseColor(color, color, color);
            }
            else
            {
                SetAmbientColor(1.0, 0.77, 0.56);
                SetDiffuseColor(1.0, 0.77, 0.56);
            }
        }
    }
    void SetIntensity(float coef, float time)
    {
        FadeBrightnessTo(m_DefaultBrightness * coef, time);
    }
}