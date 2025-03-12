modded class PluginManager
{
	void Init()
	{
		super.Init();
		RegisterPlugin("PsiPlugin", true, false);
	}
}