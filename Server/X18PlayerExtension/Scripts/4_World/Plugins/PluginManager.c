modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("PluginPlayerData", true, true);
	}
}