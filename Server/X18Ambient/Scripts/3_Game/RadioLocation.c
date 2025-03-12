class RadioLocation
{
	string m_RadioObjectClassName;
	string m_LocationName;
	string m_RadioPosition;
	string m_RadioRotation;
	void RadioLocation(string object, string locationName, string position, string rotation)
	{
		m_RadioObjectClassName = object;
		m_LocationName = locationName;
		m_RadioPosition = position;
		m_RadioRotation = rotation;
	}
}
class PlayList
{
	ref TIntArray m_SongList;
	void PlayList(ref TIntArray songList)
	{
		m_SongList = songList;
	}
}
class RadioConfig
{
	ref array< ref RadioLocation > m_RadioLocations;
	ref TIntArray m_RadioPlayList;
	void RadioConfig()
	{
		m_RadioLocations = new ref array< ref RadioLocation >;
		m_RadioPlayList = new ref TIntArray;
	}
}
class RadioConfigServer
{
	protected const static string m_ConfigRoot = "$profile:\\Noosphere\\";
	static RadioConfig LoadConfig(string configName)
	{
		RadioConfig configData;
		string configPath = m_ConfigRoot + configName;
		if (!FileExist(configPath))
		{
			CreateDefaultConfig(configData);
			SaveConfig(configName, configData);
			return configData;
		}
		JsonFileLoader<RadioConfig>.JsonLoadFile(configPath, configData);
		return configData;
	}
	protected static void SaveConfig(string configName, RadioConfig configData)
	{
		string configPath = m_ConfigRoot + configName;
		if (!FileExist(m_ConfigRoot))
			MakeDirectory(m_ConfigRoot);
		JsonFileLoader<RadioConfig>.JsonSaveFile(configPath, configData);
	}
	protected static void CreateDefaultConfig(out RadioConfig configData)
	{
		configData = new RadioConfig();
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Cordon Sidorovich", "4547.552246 72.980003 1815.843384", "-140.000000 0.000000 0.000000"));
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Swamps Clear Sky Cold", "1518.005981 82.273262 1416.642334", "-150.000000 0.000000 0.000000"));
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Garbage Trainstation", "5045.147949 120.176003 4638.852539", "40.000000 0.000000 0.000000"));
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Rostock Bar", "4864.825195 123.657997 6669.887207", "-20.000000 0.000000 0.000000"));
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Darkscape Small Radar", "8808.098633 69.785225 1711.520020", "-155.000000 0.000000 0.000000"));
		configData.m_RadioLocations.Insert(new ref RadioLocation("X18_Sound_Radio", "Agroprom Research", "1673.221558 45.026001 4106.830566", "-125.000000 0.000000 0.000000"));
		configData.m_RadioPlayList.InsertArray({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70 });
	}
};