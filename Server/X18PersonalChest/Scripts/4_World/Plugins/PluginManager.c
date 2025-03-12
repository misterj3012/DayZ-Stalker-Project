modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("PersonalChestReader", false, true);
	}
}