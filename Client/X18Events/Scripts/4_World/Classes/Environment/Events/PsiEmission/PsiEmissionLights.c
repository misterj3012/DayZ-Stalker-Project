class PsiEmissionLightning : ScriptedLightBase
{
	void PsiEmissionLightning()
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

class PsiEmissionLightFlash : ScriptedLightBase
{
	void PsiEmissionLightFlash()
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