modded class PlayerBase
{
	override bool CanBeTargetedByAI(EntityAI ai)
	{
		if (GetFaction() == EFactions.Sin && !IsUndercover() && ai.IsInherited(ZombieBase))
			return false;
		return super.CanBeTargetedByAI(ai);
	}
	void SetFaction(int faction)
	{
		m_Faction = faction;
		SetSynchDirty();
	}
}