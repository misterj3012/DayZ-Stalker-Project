class PPERequester_Psi extends PPERequester_GameplayBase
{
	void UpdateColorization(array<float> color)
	{
		super.OnStart();
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, color, PPEGlow.L_23_NVG, PPOperators.ADD);
	}
}

class PPERequester_PsiColor extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, 0.008, PPEChromAber.L_1_INTRO, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, 0.008, PPEChromAber.L_1_INTRO, PPOperators.SET);

		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_SHARPNESS, false, 10.0, PPEFilmGrain.L_1_NVG, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_GRAINSIZE, false, 1.0, PPEFilmGrain.L_2_NVG, PPOperators.SET);
		SetTargetValueFloat(PPEExceptions.NVLIGHTPARAMS, PPELightIntensityParamsNative.PARAM_LIGHT_MULT, false, 2.0, PPELightIntensityParamsNative.L_0_NVG, PPOperators.HIGHEST);
		SetTargetValueFloat(PPEExceptions.NVLIGHTPARAMS, PPELightIntensityParamsNative.PARAM_NOISE_MULT, false, 1.0, PPELightIntensityParamsNative.L_1_NVG, PPOperators.HIGHEST);
	}

	void Update(float strenght)
	{
		float shapness = Math.Lerp(10, 7, strenght / 0.8);
		float size = Math.Lerp(1.0, 0.3, strenght / 0.8);
		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_SHARPNESS, false, shapness, PPEFilmGrain.L_1_NVG, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_GRAINSIZE, false, size, PPEFilmGrain.L_2_NVG, PPOperators.SET);
	}
}