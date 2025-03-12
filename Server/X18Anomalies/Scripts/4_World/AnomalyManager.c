class AnomalyManager
{
	ref array<Object> m_SpaceAnomalies = new array<Object>();
	protected ref map<int, vector> m_SpaceAnomaliesDestinations = new map<int, vector>();
	ref array<Object> m_ElectraAnomalies = new array<Object>();
	ref array<Object> m_BurnerAnomalies = new array<Object>();
	void AnomalyManager()
	{
		m_SpaceAnomaliesDestinations.Insert(0, "1460.954712 80.466461 2296.006348");
		m_SpaceAnomaliesDestinations.Insert(1, "6294.430176 76.928055 488.422668");
		m_SpaceAnomaliesDestinations.Insert(2, "7907.576660 44.893631 1572.700439");
		m_SpaceAnomaliesDestinations.Insert(3, "5823.297852 109.915878 4538.524902");
		m_SpaceAnomaliesDestinations.Insert(4, "1576.282227 40.682281 4641.546387");
		m_SpaceAnomaliesDestinations.Insert(5, "4348.930176 126.820000 6819.216309");
		m_SpaceAnomaliesDestinations.Insert(6, "8330.017578 103.786819 4749.559570");
		m_SpaceAnomaliesDestinations.Insert(7, "2790.159912 35.721203 6488.451660");
		m_SpaceAnomaliesDestinations.Insert(8, "5559.374023 147.165497 8466.318359");
		m_SpaceAnomaliesDestinations.Insert(9, "8299.386719 137.580063 6071.731934");
		m_SpaceAnomaliesDestinations.Insert(10, "2670.740967 122.100006 8243.755859");
		m_SpaceAnomaliesDestinations.Insert(11, "4115.116211 98.379349 9934.944336");
		m_SpaceAnomaliesDestinations.Insert(12, "2173.65 118.413 11198.7");
	}
	void AddSpaceAnomaly(Object obj)
	{
		PrintInfo("Space Anomaly: %1 has been added!", obj.GetType());
		if (obj && m_SpaceAnomalies.Find(obj) == -1)
			m_SpaceAnomalies.Insert(obj);
	}
	void RemoveSpaceAnomaly(Object obj)
	{
		PrintInfo("Space Anomaly: %1 has been removed!", obj.GetType());
		if (!obj)
			return;
		m_SpaceAnomalies.RemoveItem(obj);
	}
	vector GetRandomSpaceAnomalyPosition(float radMin, float radMax)
	{
		PrintDebug("Getting random Space Anomaly position... " + m_SpaceAnomalies.Count());

		EntityAI m_Anomaly;
		if (Class.CastTo(m_Anomaly, m_SpaceAnomalies.GetRandomElement()))
			return RandomizeVectorXZ(m_Anomaly.GetPosition(), radMin, radMax);

		return RandomizeVectorXZ(Vector(4747, 64.75, 1688), radMin, radMax);
	}
	vector GetSpaceAnomalyDestination(int locationID)
	{
		return RandomizeVectorXZ(m_SpaceAnomaliesDestinations.Get(locationID), 1, 2);
	}
	void AddElectraAnomaly(Object obj)
	{
		PrintInfo("Electra Anomaly: %1 has been added!", obj.GetType());
		if (obj && m_ElectraAnomalies.Find(obj) == -1)
			m_ElectraAnomalies.Insert(obj);
	}
	void RemoveElectraAnomaly(Object obj)
	{
		PrintInfo("Electra Anomaly: %1 has been removed!", obj.GetType());
		if (!obj)
			return;
		m_ElectraAnomalies.RemoveItem(obj);
	}
	void StartElectraAnomalies()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
			PrintDebug("Starting Electra Anomalies all over the Server... " + m_ElectraAnomalies.Count());
			int start = GetGame().GetTime();
			foreach(EntityAI obj : m_ElectraAnomalies)
			{
				X18_Anomaly_Electra entity;
				if (Class.CastTo(entity, obj))
					entity.Trigger();
			}
			PrintDebug("Time to start all Electra Anomalies: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void StartElectraAnomaliesRandom()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
			PrintDebug("Starting Electra Anomalies all over the Server... " + m_ElectraAnomalies.Count());
			int start = GetGame().GetTime();
			int i = 0;
			foreach(EntityAI obj : m_ElectraAnomalies)
			{
				if (CalculateChance(50))
				{
					X18_Anomaly_Electra entity;
					if (Class.CastTo(entity, obj))
					{
						entity.Trigger();
						i++;
					}
				}
			}
			PrintDebug("Time to start " + i + " Electra Anomalies: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void AddBurnerAnomaly(Object obj)
	{
		PrintInfo("Burner Anomaly: %1 has been added!", obj.GetType());
		if (obj && m_BurnerAnomalies.Find(obj) == -1)
			m_BurnerAnomalies.Insert(obj);
	}
	void RemoveBurnerAnomaly(Object obj)
	{
		PrintInfo("Burner Anomaly: %1 has been removed!", obj.GetType());
		if (!obj)
			return;
		m_BurnerAnomalies.RemoveItem(obj);
	}
	void StartBurnerAnomalies()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
			PrintDebug("Starting Burner Anomalies all over the Server... " + m_BurnerAnomalies.Count());
			int start = GetGame().GetTime();
			foreach(EntityAI obj : m_BurnerAnomalies)
			{
				X18_Anomaly_Burner entity;
				if (Class.CastTo(entity, obj))
					entity.Trigger();
			}
			PrintDebug("Time to start all Burner Anomalies: " + (GetGame().GetTime() - start) + "ms");
		}
	}
	void StartBurnerAnomaliesRandom()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			PrintDebug("Starting Burner Anomalies all over the Server... " + m_BurnerAnomalies.Count());
			int start = GetGame().GetTime();
			int i = 0;
			foreach(EntityAI obj : m_BurnerAnomalies)
			{
				if (CalculateChance(50))
				{
					X18_Anomaly_Burner entity;
					if (Class.CastTo(entity, obj))
					{
						entity.Trigger();
						i++;
					}
				}
			}
			PrintDebug("Time to start " + i + " Burner Anomalies: " + (GetGame().GetTime() - start) + "ms");
		}
	}

	void PrintDebug(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
#ifdef AnomalyManager_DEBUG
		PrintLog(string.Format("[" + Type() + "]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SRPAnomalyManager");
#endif
	}
	void PrintInfo(string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		PrintLog(string.Format("[" + Type() + "]: " + msg, param1, param2, param3, param4, param5, param6, param7, param8, param9), "SRPAnomalyManager");
	}
}
static ref AnomalyManager g_AnomalyManager;
static AnomalyManager GetAnomalyManager()
{
	if (!g_AnomalyManager)
		g_AnomalyManager = new AnomalyManager();
	return g_AnomalyManager;
}