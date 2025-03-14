modded class PluginManager
{
	ref array<string> lockedDoorsPluginList;

	void PluginManager()
	{
		lockedDoorsPluginList = new array<string>();
	}

	override void Init()
	{
		super.Init();

		lockedDoorsPluginList.Insert("LDClientRPC");
		lockedDoorsPluginList.Insert("LDManager");
		lockedDoorsPluginList.Insert("LDConfigHandler");

		RegisterPlugin("LDClientRPC", true, false);
		RegisterPlugin("LDManager", true, true);
		RegisterPlugin("LDConfigHandler", true, true);
	}

	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true)
	{
		if (lockedDoorsPluginList.Find(plugin_class_name) != -1)
		{
			if (!reg_on_client)
				if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) return;
			if (!reg_on_server)
				if (GetGame().IsServer() && GetGame().IsMultiplayer()) return;
			if (!reg_on_release)
				if (!GetGame().IsDebug()) return;
			m_PluginRegister.Insert(plugin_class_name.ToType());
		}
		else
			super.RegisterPlugin(plugin_class_name, reg_on_client, reg_on_server, reg_on_release);
	}
}