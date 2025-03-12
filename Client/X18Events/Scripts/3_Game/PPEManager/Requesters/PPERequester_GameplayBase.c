modded class PPERequester_GameplayBase
{
	private void _LerpParamBlur(float start, float finish, float duration)
	{
		int i = 0;
		while (i < duration * 1000)
		{
#ifdef S_VISUAL
			getSPPE().setGausBlur(Math.Lerp(start, finish, (1 / duration) * i / 1000));
#endif
			Sleep(1);
			i += 10;
		}
	}
	void LerpParamBlur(float start, float finish, float duration)
	{
		thread _LerpParamBlur(start, finish, duration);
	}
	private void _LerpParamChroma(float start, float finish, float duration)
	{
		int i = 0;
		while (i < duration * 1000)
		{
#ifdef S_VISUAL
			getSPPE().setChromAber(Math.Lerp(start, finish, (1 / duration) * i / 1000));
#endif
			Sleep(1);
			i += 10;
		}
	}
	void LerpParamChroma(float start, float finish, float duration)
	{
		thread _LerpParamChroma(start, finish, duration);
	}
	private void _LerpParamVignette(float start, float finish, float duration)
	{
		int i = 0;
		while (i < duration * 1000)
		{
#ifdef S_VISUAL
			getSPPE().setVignetteIntensity(Math.Lerp(start, finish, (1 / duration) * i / 1000));
#endif
			Sleep(1);
			i += 10;
		}
	}
	void LerpParamVignette(float start, float finish, float duration)
	{
		thread _LerpParamVignette(start, finish, duration);
	}

}