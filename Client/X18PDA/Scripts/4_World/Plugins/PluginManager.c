modded class PluginManager
{
	override void Init()
	{
		if (GetGame().IsClient())
			RegisterPlugin("PluginPDA", true, false);
		RegisterPlugin("PluginPDALogic", true, true);
		super.Init();
	}
}