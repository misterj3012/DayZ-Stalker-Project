enum AreaType
{
	Radiation
};
const ref TStringArray m_AreaType = { "Radiation" };
class EcologyAreas : Managed
{
	int Id = 0;
	ref EcologySystem m_EcologySystem;
	void EcologyAreas(ref EcologySystem ecologySystem)
	{
		m_EcologySystem = ecologySystem;
	}
	void SetArea(string type, string areaName, AreaConfig areaDetails)
	{
		if (!areaDetails)
			return;
		int typeIndex = m_AreaType.Find(type);
		int i;
		switch (typeIndex)
		{
		case AreaType.Radiation:
		{
			m_EcologySystem.AddArea(new RadiationArea(areaName, areaDetails, Id, AreaType.Radiation));
			Id += 1;
			break;
		}
		}
	}
};