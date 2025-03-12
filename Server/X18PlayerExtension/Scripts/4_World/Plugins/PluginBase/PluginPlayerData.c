modded class PluginPlayerData
{
	protected ref PlayerDataExtendedConfig m_PlayerDataExtendedConfig;
	string m_PlayerDataExtendedPath = ProfilePath + "PlayerData/";

	override void OnInit()
	{
		super.OnInit();
		if (!FileExist(m_PlayerDataExtendedPath))
			MakeDirectory(m_PlayerDataExtendedPath);
	}
	bool UpdateLastTalkedTrader(PlayerBase player, int m_TraderID)
	{
		if (!player)
			return false;
		string m_UniquePlayerDataExtendedPath = m_PlayerDataExtendedPath + "" + player.GetIdentity().GetPlainId() + ".json";
		if (FileExist(m_UniquePlayerDataExtendedPath))
		{
			PlayerDataExtended m_PlayerDataExtended;
			JsonFileLoader<PlayerDataExtended>.JsonLoadFile(m_UniquePlayerDataExtendedPath, m_PlayerDataExtended);
			m_PlayerDataExtended.TalkedToTrader = m_TraderID;
			SavePlayerData(player.GetIdentity(), m_PlayerDataExtended);
			return true;
		}
		return false;
	}
	void UpdateLastBeardLength(PlayerBase player)
	{
		if (!player)
			return;
		string m_UniquePlayerDataExtendedPath = m_PlayerDataExtendedPath + "" + player.GetIdentity().GetPlainId() + ".json";
		if (FileExist(m_UniquePlayerDataExtendedPath))
		{
			PlayerDataExtended m_PlayerDataExtended;
			JsonFileLoader<PlayerDataExtended>.JsonLoadFile(m_UniquePlayerDataExtendedPath, m_PlayerDataExtended);
			m_PlayerDataExtended.BeardLength = player.GetLifeSpanState();
			SavePlayerData(player.GetIdentity(), m_PlayerDataExtended);
		}
	}
	PlayerDataExtended GetPlayerDataExtended(PlayerBase player)
	{
		if (!player)
			return NULL;
		string m_UniquePlayerDataExtendedPath = m_PlayerDataExtendedPath + "" + player.GetIdentity().GetPlainId() + ".json";

		bool m_NeededToSave = false;

		PlayerDataExtended m_PlayerDataExtended = new PlayerDataExtended();
		if (FileExist(m_UniquePlayerDataExtendedPath))
		{
			JsonFileLoader<PlayerDataExtended>.JsonLoadFile(m_UniquePlayerDataExtendedPath, m_PlayerDataExtended);
			if (m_PlayerDataExtended.Version < 2)
			{
				m_PlayerDataExtended.Version = 2;
				m_PlayerDataExtended.BloodType = BloodTypes.GenerateBloodType();
				m_NeededToSave = true;
			}
			if (m_PlayerDataExtended.Version < 3)
			{
				m_PlayerDataExtended.Version = 3;
				m_PlayerDataExtended.BeardLength = -1;
				m_NeededToSave = true;
			}
			if (m_NeededToSave)
				SavePlayerData(player.GetIdentity(), m_PlayerDataExtended);

			return m_PlayerDataExtended;
		}
		else
		{
			m_PlayerDataExtended.UID = player.GetIdentity().GetPlainId();
			m_PlayerDataExtended.LastLogin = GetDateTime();
			m_PlayerDataExtended.FirstLogin = GetDateTime();
			m_PlayerDataExtended.TalkedToTrader = -1;
			m_PlayerDataExtended.BloodType = BloodTypes.GenerateBloodType();
			m_PlayerDataExtended.BeardLength = -1;
			SavePlayerData(player.GetIdentity(), m_PlayerDataExtended);
			return m_PlayerDataExtended;
		}
		return NULL;
	}
	void SavePlayerData(PlayerIdentity identity, PlayerDataExtended m_PlayerDataExtended)
	{
		if (!identity)
			return;
		JsonFileLoader<PlayerDataExtended>.JsonSaveFile(m_PlayerDataExtendedPath + "" + identity.GetPlainId() + ".json", m_PlayerDataExtended);
	}
};