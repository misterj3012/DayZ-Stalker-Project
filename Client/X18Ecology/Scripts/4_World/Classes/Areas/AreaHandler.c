class AreaData
{
	int Id;
	string AreaName;
	int Type = 0;
	vector Position = vector.Zero;
	int RadiusOfArea = 0;
	int StrengthOfArea = 0;
};
class AreaHandler
{
	PlayerBase m_Player;
	ref map<int, ref AreaData> m_Areas;
	float m_Koef1Calc, m_Koef2Calc;
	float m_Koef1 = 0.0, m_Koef2 = 0.0;
	protected Shape m_DebugShapeInner;
	protected Shape m_DebugShapeOuter;
	void AreaHandler(PlayerBase player)
	{
		m_Player = player;
		m_Areas = new map<int, ref AreaData>;
	}
	void AddAreas(array<ref AreaData> areas)
	{
		for (int i = 0; i < areas.Count(); i++)
		{
			AreaData data = areas.Get(i);
			m_Areas.Insert(data.Id, data);

			if (data.Type == 0)
			{
				m_DebugShapeInner = Shape.CreateCylinder(COLOR_BLUE, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, data.Position, 0.1, data.RadiusOfArea);
				m_DebugShapeOuter = Shape.CreateSphere(COLOR_YELLOW, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, data.Position, data.RadiusOfArea);
			}
			else if (data.Type == 1)
			{
				m_DebugShapeInner = Shape.CreateCylinder(COLOR_YELLOW, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, data.Position, 0.1, data.RadiusOfArea);
				m_DebugShapeOuter = Shape.CreateSphere(COLOR_BLUE, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, data.Position, data.RadiusOfArea);
			}
		}
	}
	void TouchEvent()
	{
		int type = -1;
		m_Koef1 = 0.0;
		foreach(AreaData areaData : m_Areas)
		{
			if (vector.Distance(m_Player.GetPosition(), areaData.Position) <= areaData.RadiusOfArea)
			{
				int distance = vector.Distance(areaData.Position, m_Player.GetPosition());
				if (m_Koef1 == 0.0)
				{
					m_Koef2 = 0.0;
					m_Koef1Calc = 1 - (distance / areaData.RadiusOfArea);
					m_Koef1 = m_Koef1Calc * areaData.StrengthOfArea;
				}
				else
				{
					m_Koef2Calc = 1 - (distance / areaData.RadiusOfArea);
					m_Koef2 = m_Koef2Calc * areaData.StrengthOfArea;
				}
				m_Koef1 = Math.Max(m_Koef1, m_Koef2);
				type = areaData.Type;
			}
		}
		if (m_Koef1 >= 0.05)
			GetGame().RPCSingleParam(m_Player, EcologyRPC.SETAREAVALUEONPLAYER, new Param2<int, float>(type, m_Koef1), true, m_Player.GetIdentity());
		else
			GetGame().RPCSingleParam(m_Player, EcologyRPC.SETAREAVALUEONPLAYER, new Param2<int, float>(type, 0), true, m_Player.GetIdentity());
	}
};