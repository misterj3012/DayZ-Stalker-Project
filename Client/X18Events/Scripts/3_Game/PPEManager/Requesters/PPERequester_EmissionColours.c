class PPERequester_EmissionColours : PPERequester_GameplayBase
{
	void SetEmissionColorization(float r, float g, float b)
	{
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { r, g, b, 0.0 }, 150, PPOperators.MULTIPLICATIVE);
	}
}