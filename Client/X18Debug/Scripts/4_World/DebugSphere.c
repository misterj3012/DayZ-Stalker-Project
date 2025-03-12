class X18_Debug_Sphere_Base : Inventory_Base
{
	protected Shape m_DebugShapeInner;
	protected Shape m_DebugShapeOuter;

	float m_Height = 50;
	void X18_Debug_Sphere_Base()
	{
		SetEventMask(EntityEvent.POSTSIMULATE | EntityEvent.POSTFRAME);
	}
	void ~X18_Debug_Sphere_Base()
	{
		ShapeCleanup();
	}
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			ShapeCleanup();
			m_DebugShapeInner = Shape.CreateCylinder(COLOR_BLUE, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition(), 0.1, GetRadius());
			m_DebugShapeOuter = Shape.CreateSphere(COLOR_YELLOW, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition(), GetRadius());
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
class X18_Debug_Sphere_2 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 1;
	}
}
class X18_Debug_Sphere_3 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 1.5;
	}
}
class X18_Debug_Sphere_5 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 2.5;
	}
}
class X18_Debug_Sphere_10 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 5;
	}
}
class X18_Debug_Sphere_15 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 7.5;
	}
}
class X18_Debug_Sphere_20 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 10;
	}
}
class X18_Debug_Sphere_25 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 12.5;
	}
}
class X18_Debug_Sphere_50 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 25;
	}
}
class X18_Debug_Sphere_75 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 37.5;
	}
}
class X18_Debug_Sphere_100 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 50;
	}
}
class X18_Debug_Sphere_125 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 62.5;
	}
}
class X18_Debug_Sphere_150 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 75;
	}
}
class X18_Debug_Sphere_200 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 100;
	}
}
class X18_Debug_Sphere_250 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 125;
	}
}
class X18_Debug_Sphere_300 : X18_Debug_Sphere_Base
{
	override float GetRadius()
	{
		return 150;
	}
}