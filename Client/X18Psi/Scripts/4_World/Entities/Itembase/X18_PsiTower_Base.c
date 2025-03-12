class X18_PsiTower_Base : ItemBase
{
#ifdef DIAG_DEVELOPER
	protected Shape m_DebugShapeInner;
	protected Shape m_DebugShapeOuter;
#endif
	protected float m_Health;
	protected PlayerBase m_Player;
	ref PsiPlugin m_Plugin;
	void X18_PsiTower_Base()
	{
		RegisterNetSyncVariableFloat("m_Health");
		if (!GetGame().IsDedicatedServer())
		{
			if (Class.CastTo(m_Plugin, GetPlugin(PsiPlugin)))
				m_Plugin.GetScriptInvoker().Insert(CheckInPsi);
#ifdef DIAG_DEVELOPER
			SetEventMask(EntityEvent.POSTSIMULATE | EntityEvent.POSTFRAME);
#endif
		}
		else
			SetHealth0100(GetHealth());
	}
	void ~X18_PsiTower_Base()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (Class.CastTo(m_Plugin, GetPlugin(PsiPlugin)))
				m_Plugin.GetScriptInvoker().Remove(CheckInPsi);
#ifdef DIAG_DEVELOPER
			ShapeCleanup();
#endif
		}
	}
#ifdef DIAG_DEVELOPER
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		if (!GetGame().IsDedicatedServer())
		{
			ShapeCleanup();
			m_DebugShapeInner = Shape.CreateCylinder(COLOR_YELLOW, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition(), 0.1, ConfigGetFloat("psiRadius"));
			m_DebugShapeOuter = Shape.CreateSphere(COLOR_BLUE, ShapeFlags.TRANSP | ShapeFlags.WIREFRAME | ShapeFlags.NOZWRITE, GetPosition(), ConfigGetFloat("psiRadius"));
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
#endif
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		SetHealth0100(GetHealth());
	}
	protected void CheckInPsi()
	{
		if (Class.CastTo(m_Player, GetGame().GetPlayer()) && GetHealth0100() > 1.0)
		{
			float distance = vector.Distance(m_Player.GetPosition(), GetPosition());
			float radius = ConfigGetFloat("psiRadius");
			if (distance <= radius)
			{
				if (Class.CastTo(m_Plugin, GetPlugin(PsiPlugin)))
					m_Plugin.ApplyForClosestPsi(GetPosition(), distance, radius);
			}
		}
	}
	protected void SetHealth0100(float energyLevel)
	{
		m_Health = energyLevel;
		SetSynchDirty();
	}
	protected float GetHealth0100()
	{
		return m_Health;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return false;
	}
	override bool IsInventoryVisible()
	{
		return false;
	}
	override void SetActions()
	{
	}
}
class X18_PsiTower_50 : X18_PsiTower_Base {};
class X18_PsiTower_100 : X18_PsiTower_Base {};
class X18_PsiTower_150 : X18_PsiTower_Base {};
class X18_PsiTower_200 : X18_PsiTower_Base {};
class X18_PsiTower_250 : X18_PsiTower_Base {};
class X18_PsiTower_300 : X18_PsiTower_Base {};
class X18_PsiTower_500 : X18_PsiTower_Base {};