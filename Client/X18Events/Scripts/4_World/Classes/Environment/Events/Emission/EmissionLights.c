class EmissionLightning : ScriptedLightBase
{
	void EmissionLightning()
	{
		SetLightType(LightType.AMBIENT);
		SetVisibleDuringDaylight(true);
		SetRadiusTo(500);
		SetBrightnessTo(20);
		SetLifetime(1);
		SetCastShadow(true);
		SetFlareVisible(true);
	}
}

class EmissionLightFlash : ScriptedLightBase
{
	void EmissionLightFlash()
	{
		SetLightType(LightSourceType.PointLight);
		SetVisibleDuringDaylight(true);
		SetRadiusTo(3000);
		SetBrightnessTo(1);
		SetLifetime(1);
		SetFadeOutTime(0.5);
		SetCastShadow(true);
		SetFlareVisible(true);
	}
}