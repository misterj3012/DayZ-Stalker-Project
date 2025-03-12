class MedicalSystem
{
	ref MedicalOptions m_MedicalOptions;
	void MedicalSystem()
	{
		LoadConfig();
	}
	private void LoadConfig()
	{
		string s_MedicalConfig;
		s_MedicalConfig = ProfilePath + "MedicalOptions.json";
		if (FileExist(s_MedicalConfig))
			JsonFileLoader<ref MedicalOptions>.JsonLoadFile(s_MedicalConfig, m_MedicalOptions);
		else
		{
			m_MedicalOptions = new MedicalOptions();
			JsonFileLoader<ref MedicalOptions>.JsonSaveFile(s_MedicalConfig, m_MedicalOptions);
		}
		MedicalConfig = m_MedicalOptions;
	}
};