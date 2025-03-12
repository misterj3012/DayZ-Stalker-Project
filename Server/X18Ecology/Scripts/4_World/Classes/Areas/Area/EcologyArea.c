class EcologyArea : Managed
{
	string AreaName;
	int Id;
	int Type;
	ref AreaConfig m_AreaConfig;
	vector Position;
	int RadiusOfArea = 0;
	int StrengthOfArea;
	void EcologyArea(string areaName, AreaConfig areaConfig, int areaId, int areaType)
	{
		AreaName = areaName;
		m_AreaConfig = areaConfig;
		Id = areaId;
		Type = areaType;
		Position = m_AreaConfig.Position;
		RadiusOfArea = m_AreaConfig.RadiusOfArea;
		StrengthOfArea = m_AreaConfig.StrengthOfArea;
		OnInit();
	}
	void OnInit()
	{}
}