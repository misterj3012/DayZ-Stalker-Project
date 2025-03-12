class X18_Debug_Cylinder_Base : Inventory_Base
{
	protected Shape m_DebugShapeInner;
	protected Shape m_DebugShapeOuter;

	float m_Height = 50;
	void X18_Debug_Cylinder_Base()
	{
		SetEventMask(EntityEvent.POSTSIMULATE | EntityEvent.POSTFRAME);
	}
	void ~X18_Debug_Cylinder_Base()
	{
		ShapeCleanup();
	}
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			ShapeCleanup();
			m_DebugShapeInner = Shape.CreateCylinder(COLOR_BLUE, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition() + "0.0 5.8 0.0", 0.1, m_Height);
			m_DebugShapeOuter = Shape.CreateCylinder(COLOR_YELLOW, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition() + "0.0 5.8 0.0", GetRadius(), m_Height);
		}
	}

	protected void ShapeCleanup()
	{
		if (m_DebugShapeInner)
		{
			m_DebugShapeInner.Destroy();
			m_DebugShapeInner = null;
		}
		if (m_DebugShapeOuter)
		{
			m_DebugShapeOuter.Destroy();
			m_DebugShapeOuter = null;
		}
	}
	float GetRadius()
	{
		return 0;
	}
}
class X18_Debug_Cylinder_2 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 1;
	}
}
class X18_Debug_Cylinder_3 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 1.5;
	}
}
class X18_Debug_Cylinder_5 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 2.5;
	}
}
class X18_Debug_Cylinder_10 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 5;
	}
}
class X18_Debug_Cylinder_15 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 7.5;
	}
}
class X18_Debug_Cylinder_20 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 10;
	}
}
class X18_Debug_Cylinder_25 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 12.5;
	}
}
class X18_Debug_Cylinder_50 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 25;
	}
}
class X18_Debug_Cylinder_75 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 37.5;
	}
}
class X18_Debug_Cylinder_100 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 50;
	}
}
class X18_Debug_Cylinder_125 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 62.5;
	}
}
class X18_Debug_Cylinder_150 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 75;
	}
}
class X18_Debug_Cylinder_200 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 100;
	}
}
class X18_Debug_Cylinder_250 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 125;
	}
}
class X18_Debug_Cylinder_300 : X18_Debug_Cylinder_Base
{
	override float GetRadius()
	{
		return 150;
	}
}