modded class PluginTransmissionAgents
{
	void PluginTransmissionAgents()
	{
		RegisterAgent(new AntiRadAgent);
		RegisterAgent(new RadioProtectantAgent);
		RegisterAgent(new PC1CysteamineHydrochlorideAgent);
	}
}