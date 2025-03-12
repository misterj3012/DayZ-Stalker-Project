void LerpColorizationEmission(PPERequester_EmissionColours PPE_Colours, float r, float g, float b, int time, float start_r = 0, float start_g = 0, float start_b = 0)
{
	if (!PPE_Colours.IsRequesterRunning())
		PPE_Colours.Start();
	int td = 0;
	while (td < time)
	{
		float time_value = 1 / time * td;
		PPE_Colours.SetEmissionColorization(SmoothLerp(start_r, r, time_value), SmoothLerp(start_g, g, time_value), SmoothLerp(start_b, b, time_value));
		td += 10;
		Sleep(10);
	}
}
void LerpColorizationPsiEmission(PPERequester_PsiEmissionColours PPE_Colours, float r, float g, float b, int time, float start_r = 0, float start_g = 0, float start_b = 0)
{
	if (!PPE_Colours.IsRequesterRunning())
		PPE_Colours.Start();
	int td = 0;
	while (td < time)
	{
		float time_value = 1 / time * td;
		PPE_Colours.SetPsiEmissionColorization(SmoothLerp(start_r, r, time_value), SmoothLerp(start_g, g, time_value), SmoothLerp(start_b, b, time_value));
		td += 10;
		Sleep(10);
	}
}
void LerpEffectPsiEmission(PPERequester_PsiEmissionColours PPE_Colours, float v, int time, float start_v = 0)
{
	if (!PPE_Colours.IsRequesterRunning())
		PPE_Colours.Start();
	int td = 0;
	while (td < time)
	{
		float time_value = 1 / time * td;
		PPE_Colours.SetPsiEmissionBlur(SmoothLerp(start_v, v, time_value) * 20);
		PPE_Colours.SetPsiEmissionVignette(SmoothLerp(start_v, v, time_value) * 20);
		td += 10;
		Sleep(10);
	}
}
static vector SmoothLerpVector(vector a, vector b, float t)
{
	vector ret;
	for (int i = 0; i < 3; i++) {
		ret[i] = SmoothLerp(a[i], b[i], t);
	}
	return ret;
}
static float SmoothLerp(float a, float b, float t)
{
	return (b - a) * SmoothTime(t) + a;
}
static float SmoothTime(float t)
{
	return (-Math.Cos(Math.PI * t) / 2) + 0.5;
}