modded class PluginManager
{
	override void Init()
	{
		super.Init();
		if (GetGame().IsClient())
			RegisterPlugin("PluginPlayerData", true, false);
	}
}