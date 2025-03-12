class StoneLight : PointLightBase
{
	private static float m_DefaultBrightness = 1.5;
	private static float m_DefaultRadius = 1.5;
	void StoneLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(m_DefaultRadius);
		SetBrightnessTo(m_DefaultBrightness);
		FadeIn(1);
		SetFadeOutTime(2);
		SetFlareVisible(false);
		SetCastShadow(false);
	}
	void SetIntensity(float coef, float time)
	{
		FadeBrightnessTo(m_DefaultBrightness * coef, time);
		FadeRadiusTo(m_DefaultRadius * coef, time);
	}
	void SetColorToWhite()
	{
		SetAmbientColor(0.9, 0.9, 1.0);
		SetDiffuseColor(0.9, 0.9, 1.0);
	}
	void SetColorToRed()
	{
		SetAmbientColor(1.0, 0.3, 0.2);
		SetDiffuseColor(1.0, 0.3, 0.2);
	}
	void SetColorToGreen()
	{
		SetAmbientColor(0.3, 1.0, 0.2);
		SetDiffuseColor(0.3, 1.0, 0.2);
	}
	void SetColorToLightBlue()
	{
		SetAmbientColor(0.6, 0.6, 1.0);
		SetDiffuseColor(0.6, 0.6, 1.0);
	}
	void SetColorToBlue()
	{
		SetAmbientColor(0.3, 0.3, 1.0);
		SetDiffuseColor(0.3, 0.3, 1.0);
	}
	void SetColorToYellow()
	{
		SetAmbientColor(1.0, 1.0, 0.3);
		SetDiffuseColor(1.0, 1.0, 0.3);
	}
	void SetColorToOrange()
	{
		SetAmbientColor(0.9, 0.5, 0.1);
		SetDiffuseColor(0.9, 0.5, 0.1);
	}
}