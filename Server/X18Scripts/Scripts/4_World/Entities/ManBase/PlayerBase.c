modded class PlayerBase
{
	void SetAdmin(bool active)
	{
		m_Admin = active;
		SetSynchDirty();
	}
	override bool CanBeTargetedByAI(EntityAI ai)
	{
		if (IsAdminActive() && (ai.IsInherited(ZombieBase) || ai.IsInherited(AnimalBase)))
			return false;
		return super.CanBeTargetedByAI(ai);
	}
}