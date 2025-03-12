class AnomalySpawner
{
	protected static ref AnomalySpawner Instance;
	const private string m_ConfigFile = "AnomalySpawner.json";
	const private string m_LogText = "AnomalySpawner";
	bool m_AnomalyConfigLoaded = false;
	ref AnomalyConfig m_AnonmalyConfig;
	private ref array<string> m_WrongSymbols = { ">","<","," };
	private int m_MaxArtefactCount = 0;
	private int m_ArtefactCount = 0;
	void AnomalySpawner()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
			thread LoadConfigServer();
	}
	void ~AnomalySpawner()
	{
	}
	static AnomalySpawner GetInstance()
	{
		if (!Instance)
			Instance = new AnomalySpawner();
		return Instance;
	}
	static void ClearInstance()
	{
		Instance = null;
	}
	private bool CreateDefaultConfig()
	{
		ref AnomalyConfig t_AnomalyConfig = CreateAnomalyConfig();
		JsonFileLoader<AnomalyConfig>.JsonSaveFile((AnomaliesPath + m_ConfigFile), t_AnomalyConfig);

		if (FileExist((AnomaliesPath + m_ConfigFile)))
			return true;
		else
			return false;
	}
	private bool CreateDefaultLootConfig()
	{
		ref AnomalyLoot t_AnomalyLootConfig = CreateAnomalyLootConfig();
		JsonFileLoader<AnomalyLoot>.JsonSaveFile(AnomaliesPath + "test.json", t_AnomalyLootConfig);

		if (FileExist((AnomaliesPath + t_AnomalyLootConfig)))
			return true;
		else
			return false;
	}
	void LoadConfigServer()
	{
		if (!FileExist(AnomaliesPath))
			MakeDirectory(AnomaliesPath);
		private bool m_ConfigReadSuccessful = false;
		ref AnomalyConfig t_AnomalyConfig;
		if (FileExist((AnomaliesPath + m_ConfigFile)))
		{
			JsonFileLoader<AnomalyConfig>.JsonLoadFile((AnomaliesPath + m_ConfigFile), t_AnomalyConfig);
			if (CheckConfigJSON(t_AnomalyConfig))
				m_ConfigReadSuccessful = true;
		}
		else
		{
			if (CreateDefaultConfig())
			{
				JsonFileLoader<AnomalyConfig>.JsonLoadFile((AnomaliesPath + m_ConfigFile), t_AnomalyConfig);
				if (CheckConfigJSON(t_AnomalyConfig))
					m_ConfigReadSuccessful = true;
			}
		}
		if (m_ConfigReadSuccessful)
		{
			m_AnonmalyConfig = t_AnomalyConfig;
			m_AnomalyConfigLoaded = true;
		}
		LoadedConfigInfo();
	}
	void LoadedConfigInfo()
	{
		if (m_AnonmalyConfig)
		{
			if (m_AnonmalyConfig.Areas.Count() > 0)
				thread SpawnAnomalies();
		}
	}
	bool CheckConfigJSON(AnomalyConfig DefaultCFG)
	{
		private bool m_CorrectConfig = true;
		if (DefaultCFG)
		{
			if (DefaultCFG.Areas.Count() < 1)
				m_CorrectConfig = false;
		}
		else
			m_CorrectConfig = false;
		return m_CorrectConfig;
	}
	private AnomalyConfig CreateAnomalyConfig()
	{
		ref AnomalyConfig DefaultCFGMAIN = new AnomalyConfig();
		ref map<string, map<int, float>> m_Areas = new map<string, map<int, float>>;
		map<int, float> m_AreasDetail = new map<int, float>;
		m_AreasDetail.Insert(1, 50.0);
		m_Areas.Insert("Cordon", m_AreasDetail);
		m_Areas.Insert("GreatSwamps", m_AreasDetail);
		m_Areas.Insert("Predbannik", m_AreasDetail);
		m_Areas.Insert("Darkscape", m_AreasDetail);
		m_Areas.Insert("Agroprom", m_AreasDetail);
		m_Areas.Insert("Garbage", m_AreasDetail);
		m_Areas.Insert("DarkValley", m_AreasDetail);
		m_Areas.Insert("Yantar", m_AreasDetail);
		m_Areas.Insert("WildTerritory", m_AreasDetail);
		m_Areas.Insert("Junkyard", m_AreasDetail);
		m_Areas.Insert("ArmyWarehouse", m_AreasDetail);
		m_Areas.Insert("Barrier", m_AreasDetail);
		m_Areas.Insert("Limansk", m_AreasDetail);
		m_Areas.Insert("DeadCity", m_AreasDetail);
		m_Areas.Insert("RedForest", m_AreasDetail);
		m_Areas.Insert("NorthernSwamps", m_AreasDetail);
		DefaultCFGMAIN.Areas = m_Areas;
		return DefaultCFGMAIN;
	}
	private AnomalyLoot CreateAnomalyLootConfig()
	{
		ref AnomalyLoot DefaultCFGMAIN = new AnomalyLoot();
		ref map<string, map<string, float>> m_Anomalies = new map<string, map<string, float>>;
		map<string, float> m_Artefacts = new map<string, float>;
		m_Artefacts.Insert("Anomaly1", 50.0);
		m_Artefacts.Insert("Anomaly2", 50.0);
		m_Artefacts.Insert("Anomaly3", 50.0);
		m_Artefacts.Insert("Anomaly4", 50.0);
		m_Anomalies.Insert("X18_Anomaly_FruitPunch", m_Artefacts);
		m_Anomalies.Insert("X18_Anomaly_SpringBoard", m_Artefacts);
		m_Anomalies.Insert("X18_Anomaly_Vortex", m_Artefacts);
		m_Anomalies.Insert("X18_Anomaly_Burner", m_Artefacts);
		m_Anomalies.Insert("X18_Anomaly_Electra", m_Artefacts);
		DefaultCFGMAIN.Artefacts = m_Anomalies;
		return DefaultCFGMAIN;
	}
	map<string, map<int, float>> GetAreas()
	{
		if ((m_AnonmalyConfig) && (m_AnomalyConfigLoaded))
			return m_AnonmalyConfig.Areas;
		else
			return NULL;
	}
	ref map<string, map<string, float>> GetArtefactsList(string m_LootFile)
	{
		if (FileExist(m_LootFile))
		{
			ref AnomalyLoot m_ArtefactLoot;
			JsonFileLoader<AnomalyLoot>.JsonLoadFile(m_LootFile, m_ArtefactLoot);
			return m_ArtefactLoot.Artefacts;
		}
		return NULL;
	}
	AnomalyArea LoadBinFile(string file)
	{
		AnomalyArea save_data = new AnomalyArea();
		if (!FileExist(file))
			return save_data;
		FileSerializer file_serializer = new FileSerializer();
		if (!file_serializer.Open(file, FileMode.READ))
			return save_data;
		if (!save_data.Read(file_serializer))
		{
			file_serializer.Close();
			return save_data;
		}
		file_serializer.Close();
		return save_data;
	}
	ref array <ref AnomalyObjects> GetAnomalyList(string anomalyArea)
	{
		AnomalyArea import_data = new AnomalyArea();
		if (!FileExist(anomalyArea))
			return NULL;
		if (AnomalyArea.IsBinnedFile(anomalyArea))
			import_data = LoadBinFile(anomalyArea);
		if (import_data)
			return import_data.Anomalies;
		return NULL;
	}
	string VectorToString(vector value)
	{
		private string return_val = "0 0 0";
		if (value)
		{
			return_val = value.ToString();
			for (private int i = 0; i < m_WrongSymbols.Count(); i++)
			{
				if (return_val.Contains(m_WrongSymbols.Get(i)))
					return_val.Replace(m_WrongSymbols.Get(i), "");
			}
		}
		return return_val;
	}
	void SpawnAnomalies()
	{
		private map<string, map<int, float>> m_Areas = GetAreas();
		private int m_MaxAnomalyCount = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		for (i = 0; i < m_Areas.Count(); ++i)
		{
			private int m_AnomalyCount = 0;
			string m_AnomalyFile = AnomaliesPath + "Areas/" + m_Areas.GetKey(i) + ".asf";

			if (FileExist(m_AnomalyFile))
			{
				float m_SpawnChance = 0.0;
				private ref array <ref AnomalyObjects> m_TempAnomalies = GetAnomalyList(m_AnomalyFile);
				private ref map<string, map<string, float>> m_TempItems;
				private map<string, float> m_TempArtefacts = new map<string, float>;

				map<string, ref map<string, float>> temp_map = new map<string, ref map<string, float>>;

				map<int, float> m_Test = m_Areas.GetElement(i);
				if (m_Test != NULL)
				{
					for (j = 0; j < m_Test.Count(); ++j)
					{
						string m_LootFile = AnomaliesPath + "Loot/Tier" + m_Test.GetKey(j) + ".json";
						m_TempItems = GetArtefactsList(m_LootFile);
						m_SpawnChance = m_Test.GetElement(j);
					}
				}
				for (k = 0; k < m_TempItems.Count(); ++k)
				{
					m_TempArtefacts = m_TempItems.GetElement(k);
					for (l = 0; l < m_TempItems.GetElement(k).Count(); ++l)
					{
						temp_map.Set(m_TempItems.GetKey(k), m_TempItems.GetElement(k));
					}
				}
				foreach(ref AnomalyObjects m_TempAnomaly : m_TempAnomalies)
				{
					if (CalculateChance(m_SpawnChance))
					{
						Anomaly_Base m_Anomaly = SpawnAnomaly(m_TempAnomaly.ClassName, VectorToString(m_TempAnomaly.Position), VectorToString(m_TempAnomaly.Orientation));
						if (m_Anomaly)
						{
							m_AnomalyCount++;
							if (!FoundArtefactsAtPosition(m_Anomaly.GetPosition(), 250));
							{
								for (k = 0; k < temp_map.Count(); ++k)
								{
									if (m_Anomaly.GetType() == temp_map.GetKey(k))
									{
										m_TempArtefacts = temp_map.GetElement(k);
										for (l = 0; l < temp_map.GetElement(k).Count(); ++l)
										{
											if (CalculateChance(temp_map.GetElement(k).GetElement(l)))
											{
												X18_Artefact_Spawn_Base m_Artefact = X18_Artefact_Spawn_Base.Cast(GetGame().CreateObjectEx(temp_map.GetElement(k).GetKey(l), GetRandomPositionAtSameHeight(m_Anomaly.GetPosition()[0], m_Anomaly.GetPosition()[1], m_Anomaly.GetPosition()[2], 4.0, 8.0, 0.5), ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
												if (m_Artefact && m_AnonmalyConfig.DebugLogs)
												{
													if (m_AnonmalyConfig.DebugLogs)
														PrintLog("Spawn Artefact: [" + m_Artefact.GetType() + "] at Position: [" + m_Artefact.GetPosition().ToString() + "]", m_LogText);
													m_ArtefactCount++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
				m_MaxAnomalyCount = m_MaxAnomalyCount + m_AnomalyCount;
				m_MaxArtefactCount = m_MaxArtefactCount + m_ArtefactCount;
				if (m_AnonmalyConfig.DebugLogs)
				{
					PrintLog("Count: " + m_AnomalyCount + " anomalies were spawned in: " + m_Areas.GetKey(i) + "!", m_LogText);
					PrintLog("Count: " + m_ArtefactCount + " artefacts were spawned in: " + m_Areas.GetKey(i) + "!", m_LogText);
				}
				m_AnomalyCount = 0;
				m_ArtefactCount = 0;
			}
		}

		if (m_AnonmalyConfig.DebugLogs)
		{
			PrintLog("Count: " + m_MaxAnomalyCount + " anomalies were spawned in total!", m_LogText);
			PrintLog("Count: " + m_MaxArtefactCount + " artefacts were spawned in total!", m_LogText);
		}
		m_MaxAnomalyCount = 0;
		m_MaxArtefactCount = 0;
	}
	void DeleteAtPosition(string ClassName, vector position, float radius)
	{
		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition(position, radius, nearest_objects, proxy_cargos);

		foreach(ref Object obj : nearest_objects)
		{
			if (obj.GetType() == ClassName)
				GetGame().ObjectDelete(obj);
		}
	}
	bool FoundArtefactsAtPosition(vector position, float radius)
	{
		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition3D(position, radius, nearest_objects, proxy_cargos);

		foreach(ref Object obj : nearest_objects)
		{
			if (obj.IsInherited(X18_Artefact_Spawn_Base))
				return true;
		}
		return false;
	}
	Anomaly_Base SpawnAnomaly(string ClassName, string t_AnomalyPosition, string t_AnomalyOrientation)
	{
		private vector position = t_AnomalyPosition.ToVector();
		private vector orientation = t_AnomalyOrientation.ToVector();

		if ((ClassName) && (position))
		{
			Anomaly_Base m_Anomaly = Anomaly_Base.Cast(GetGame().CreateObjectEx(ClassName, position, ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_KEEPHEIGHT));
			if (m_Anomaly)
			{
				m_Anomaly.SetPosition(position);
				m_Anomaly.SetOrientation(orientation);
				m_Anomaly.SetOrientation(m_Anomaly.GetOrientation());
				m_Anomaly.SetFlags(EntityFlags.STATIC, false);
				m_Anomaly.Update();
				m_Anomaly.SetAffectPathgraph(true, false);
				if (m_Anomaly.CanAffectPathgraph())
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, m_Anomaly);

				if (m_AnonmalyConfig.DebugLogs)
					PrintLog("Spawn Anomaly: [" + m_Anomaly.GetType() + "] at Position: [" + m_Anomaly.GetPosition().ToString() + "]", m_LogText);
				return m_Anomaly;
			}
		}
		return NULL;
	}
}