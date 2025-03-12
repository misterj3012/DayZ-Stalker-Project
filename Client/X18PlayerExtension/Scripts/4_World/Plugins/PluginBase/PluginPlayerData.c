class PluginPlayerData : PluginBase
{
	void PluginPlayerData()
	{}
	void ~PluginPlayerData()
	{}
	override void OnInit()
	{
		super.OnInit();
		//GetRPCManager().AddRPC("X18", "GetVisualUserName", this, SingleplayerExecutionType.Both);
	}
};