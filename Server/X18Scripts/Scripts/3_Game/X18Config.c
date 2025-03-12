class X18Config
{
	[NonSerialized()]
	string ProfilePath = "$profile:/Noosphere/";
	string PlayersPath = "Players/";
	string PlayersDatabasePath = "Players/ID/";
	string InventoryDumpFolderPath = "InventoryDump/";
	string DiscordPath = "Discord/";
	string HostURL = "http:	string ScriptsPath = "scripts / ";
		string LogosPath = "logos/";
}

class X18ConfigServer
{
	static X18Config LoadConfig()
	{
		ref X18Config m_X18Config = new X18Config();
		string m_ConfigPath = m_X18Config.ProfilePath + "X18Config.json";
		if (FileExist(m_ConfigPath))
			JsonFileLoader<X18Config>.JsonLoadFile(m_ConfigPath, m_X18Config);
		else
		{
			if (!FileExist(m_X18Config.ProfilePath))
				MakeDirectory(m_X18Config.ProfilePath);
			JsonFileLoader<X18Config>.JsonSaveFile(m_ConfigPath, m_X18Config);
		}

		m_X18Config.PlayersPath = m_X18Config.ProfilePath + m_X18Config.PlayersPath;
		m_X18Config.PlayersDatabasePath = m_X18Config.PlayersPath + m_X18Config.PlayersDatabasePath;
		m_X18Config.InventoryDumpFolderPath = m_X18Config.PlayersPath + m_X18Config.InventoryDumpFolderPath;
		m_X18Config.DiscordPath = m_X18Config.ProfilePath + m_X18Config.DiscordPath;

		if (!FileExist(m_X18Config.PlayersPath))
			MakeDirectory(m_X18Config.PlayersPath);
		if (!FileExist(m_X18Config.PlayersDatabasePath))
			MakeDirectory(m_X18Config.PlayersDatabasePath);
		if (!FileExist(m_X18Config.InventoryDumpFolderPath))
			MakeDirectory(m_X18Config.InventoryDumpFolderPath);
		if (!FileExist(m_X18Config.DiscordPath))
			MakeDirectory(m_X18Config.DiscordPath);

		return m_X18Config;
	}
}