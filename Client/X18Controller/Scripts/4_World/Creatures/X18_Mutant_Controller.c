class X18_Mutant_Controller : ZombieBase
{
	void X18_Mutant_Controller()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PsiPlugin plugin = PsiPlugin.Cast(GetPlugin(PsiPlugin));
			if (plugin)
				plugin.GetScriptInvoker().Insert(CheckInPsi);
		}
	}
	void ~X18_Mutant_Controller()
	{
		if (GetGame() && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
		{
			PsiPlugin plugin = PsiPlugin.Cast(GetPlugin(PsiPlugin));
			if (plugin)
				plugin.GetScriptInvoker().Remove(CheckInPsi);
		}
	}
	protected void CheckInPsi()
	{
		PlayerBase m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		if (m_Player && IsAlive())
		{
			float distance = vector.Distance(m_Player.GetPosition(), GetPosition());
			float radius = ConfigGetFloat("psiRadius");
			if (distance <= radius)
			{
				PsiPlugin plugin = PsiPlugin.Cast(GetPlugin(PsiPlugin));
				if (plugin)
					plugin.ApplyForClosestPsi(GetPosition(), distance, radius);
			}
		}
	}
}