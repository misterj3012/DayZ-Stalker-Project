class PPERequester_PsiEmissionColours : PPERequester_GameplayBase
{
	void SetPsiEmissionColorization(float r, float g, float b)
	{
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { r, g, b, 0.0 }, 150, PPOperators.MULTIPLICATIVE);
	}
	void SetPsiEmissionBlur(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, true, intensity, 105, PPOperators.ADD_RELATIVE);
	}
	void SetPsiEmissionVignette(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, 105, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, intensity, 105, PPOperators.SET);
	}
}