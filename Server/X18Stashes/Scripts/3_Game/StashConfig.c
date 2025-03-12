class StashConfig
{
	bool DebugLogs = false;
	bool PostToDiscord = false;
	string DiscordWebhook = "";
	float TimeToCheckForStashFilling = 5;
	int MinTimeToStartSpawnItems = 1;
	int MaxTimeToStartSpawnItems = 5;
	ref map<string, map<string, float>> Areas = new map<string, map<string, float>>;
}