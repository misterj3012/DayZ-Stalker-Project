class EcologySystem
{
	const float m_TimeOffset = 1.0;
	float m_Timeslice = 0;
	ref RadiationOptions m_RadiationOptions;
	protected ref AreasMainList m_AreasListNew = new AreasMainList();
	ref EcologyAreas m_AreasInit;
	ref map<int, ref EcologyArea> m_Areas = new map<int, ref EcologyArea>;
	ref RadiationSuit m_RadiationSuit = new RadiationSuit;
	void EcologySystem()
	{
		LoadAreaList();
		if (!m_AreasListNew)
			return;
		LoadRadiationConfig();
		m_AreasInit = new ref EcologyAreas(this);
		ChooseAreaTemplate();
		SetRadiationSuit();
	}
	private void LoadAreaList()
	{
		if (!FileExist(EcologyPath))
			MakeDirectory(EcologyPath);

		string s_AreaListNew;
		s_AreaListNew = EcologyPath + "Areas.json";
		if (FileExist(s_AreaListNew))
			JsonFileLoader<ref AreasMainList>.JsonLoadFile(s_AreaListNew, m_AreasListNew);
		else
		{
			m_AreasListNew = CreateDefaultAreaJson();
			JsonFileLoader<AreasMainList>.JsonSaveFile(s_AreaListNew, m_AreasListNew);
		}
	}
	private void LoadRadiationConfig()
	{
		string s_RadiationConfig;
		s_RadiationConfig = EcologyPath + "RadiationOptions.json";
		if (FileExist(s_RadiationConfig))
			JsonFileLoader<ref RadiationOptions>.JsonLoadFile(s_RadiationConfig, m_RadiationOptions);
		else
		{
			m_RadiationOptions = new RadiationOptions();
			JsonFileLoader<ref RadiationOptions>.JsonSaveFile(s_RadiationConfig, m_RadiationOptions);
		}
		RadiationConfig = m_RadiationOptions;
	}
	private void SetRadiationSuit()
	{
		string s_RadiationSuit;
		s_RadiationSuit = EcologyPath + "RadiationSuit.json";
		if (FileExist(s_RadiationSuit))
			JsonFileLoader<ref RadiationSuit>.JsonLoadFile(s_RadiationSuit, m_RadiationSuit);
		else
		{
			m_RadiationSuit = CreateDefaultRadiationSuitJson();
			JsonFileLoader<ref RadiationSuit>.JsonSaveFile(s_RadiationSuit, m_RadiationSuit);
		}
	}
	protected void ChooseAreaTemplate()
	{
		foreach(AreasList m_AreasItemNew : m_AreasListNew.AreaList)
		{
			m_AreasInit.SetArea(m_AreasItemNew.Type, m_AreasItemNew.Name, m_AreasItemNew.AreaDetails);
		}
	}
	void AddArea(EcologyArea area)
	{
		m_Areas.Insert(area.Id, area);
	}
	private AreaData SetAreaData(ref EcologyArea area)
	{
		AreaData areaData = new AreaData();
		areaData.Id = area.Id;
		areaData.AreaName = area.AreaName;
		areaData.Type = area.Type;
		areaData.Position = area.Position;
		areaData.RadiusOfArea = area.RadiusOfArea;
		areaData.StrengthOfArea = area.StrengthOfArea;
		return areaData;
	}
	EcologySystem GetEcologySystem()
	{
		return this;
	}
	RadiationSuit GetRadiationSuit()
	{
		return m_RadiationSuit;
	}
	void SendPlayerAllData(PlayerBase player)
	{
		player.m_EcologySystem = GetEcologySystem();
		player.m_RadiationSuit = GetRadiationSuit();
		array<ref AreaData> m_AreaData = new array<ref AreaData>;
		foreach(EcologyArea area : m_Areas)
		{
			AreaData areaData;
			areaData = SetAreaData(area);
			m_AreaData.Insert(areaData);
		}
		GetGame().RPCSingleParam(player, EcologyRPC.SENDAREADATA, new Param1<array<ref AreaData>>(m_AreaData), true, player.GetIdentity());
	}
	EcologyArea GetArea(int id)
	{
		return m_Areas.Get(id);
	}
	private AreasMainList CreateDefaultAreaJson()
	{
		ref AreasMainList DefaultJSONAreaMainList = new AreasMainList();
		ref array <ref AreasList> DefaultAreasListNew = new array <ref AreasList>;
		DefaultAreasListNew.Insert(CreateElement_Area("Radiation", "Agroprom-Yantar", "1813.00 0.0 5475.00", 300, 10000));
		DefaultJSONAreaMainList.AreaList = DefaultAreasListNew;
		return DefaultJSONAreaMainList;
	}
	private AreasList CreateElement_Area(string areaType, string areaName, vector areaPosition, int radius, int strength)
	{
		private ref AreasList DefaultJSONAreasList = new ref AreasList();
		DefaultJSONAreasList.Type = areaType;
		DefaultJSONAreasList.Name = areaName;
		DefaultJSONAreasList.AreaDetails = CreateElement_AreaDetails(areaPosition, radius, strength);
		return DefaultJSONAreasList;
	}
	private AreaConfig CreateElement_AreaDetails(vector position, int radius, int strength)
	{
		private ref AreaConfig DefaultJSONAreaDetails = new ref AreaConfig();
		DefaultJSONAreaDetails.Position = position;
		DefaultJSONAreaDetails.RadiusOfArea = radius;
		DefaultJSONAreaDetails.StrengthOfArea = strength;
		return DefaultJSONAreaDetails;
	}
	private RadiationSuit CreateDefaultRadiationSuitJson()
	{
		ref RadiationSuit DefaultJSONRadiationSuit = new RadiationSuit();
		ref array <ref RadiationSuitItem> DefaultHeadgear = new array <ref RadiationSuitItem>;
		DefaultHeadgear.Insert(CreateElement_RadiationSuit("NBCHoodGray", 10));
		DefaultJSONRadiationSuit.Headgear = DefaultHeadgear;
		ref array <ref RadiationSuitItem> DefaultMask = new array <ref RadiationSuitItem>;
		DefaultMask.Insert(CreateElement_RadiationSuit("GP5GasMask", 10));
		DefaultMask.Insert(CreateElement_RadiationSuit("GasMask", 10));
		DefaultJSONRadiationSuit.Mask = DefaultMask;
		ref array <ref RadiationSuitItem> DefaultBody = new array <ref RadiationSuitItem>;
		DefaultBody.Insert(CreateElement_RadiationSuit("NBCJacketGray", 10));
		DefaultJSONRadiationSuit.Body = DefaultBody;
		ref array <ref RadiationSuitItem> DefaultVest = new array <ref RadiationSuitItem>;
		DefaultJSONRadiationSuit.Vest = DefaultVest;
		ref array <ref RadiationSuitItem> DefaultGloves = new array <ref RadiationSuitItem>;
		DefaultGloves.Insert(CreateElement_RadiationSuit("NBCGlovesGray", 10));
		DefaultJSONRadiationSuit.Gloves = DefaultGloves;
		ref array <ref RadiationSuitItem> DefaultLegs = new array <ref RadiationSuitItem>;
		DefaultLegs.Insert(CreateElement_RadiationSuit("NBCPantsGray", 10));
		DefaultJSONRadiationSuit.Legs = DefaultLegs;
		ref array <ref RadiationSuitItem> DefaultFeet = new array <ref RadiationSuitItem>;
		DefaultFeet.Insert(CreateElement_RadiationSuit("NBCBootsGray", 10));
		DefaultJSONRadiationSuit.Feet = DefaultFeet;
		return DefaultJSONRadiationSuit;
	}
	private RadiationSuitItem CreateElement_RadiationSuit(string className, int shield)
	{
		private ref RadiationSuitItem DefaultJSONRadiationSuit = new ref RadiationSuitItem();
		DefaultJSONRadiationSuit.className = className;
		DefaultJSONRadiationSuit.shield = shield;
		return DefaultJSONRadiationSuit;
	}
};