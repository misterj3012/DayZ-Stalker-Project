class X18_PsiField_Base : BuildingSuper
{
#ifdef DIAG_DEVELOPER
	protected Shape m_DebugShapeInner;
	protected Shape m_DebugShapeOuter;
#endif
	protected PlayerBase m_Player;
	ref PsiPlugin m_Plugin;
	void X18_PsiField_Base()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (Class.CastTo(m_Plugin, GetPlugin(PsiPlugin)))
				m_Plugin.GetScriptInvoker().Insert(CheckInPsi);
#ifdef DIAG_DEVELOPER
			SetEventMask(EntityEvent.POSTSIMULATE | EntityEvent.POSTFRAME);
#endif
		}
	}
	void ~X18_PsiField_Base()
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
	protected void CheckInPsi()
	{
		if (Class.CastTo(m_Player, GetGame().GetPlayer()))
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
}