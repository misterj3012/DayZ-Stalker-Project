modded class GasMask_Base
{
	protected PlayerBase m_Player;
	protected GasMaskFilter_Base m_GasMaskFilter;
	void ~GasMask_Base()
	{
		if (GetGame().IsServer())
			GetCompEM().SwitchOff();
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		if (parent.IsInherited(SurvivorBase) && Class.CastTo(m_Player, parent) && slot_id == InventorySlots.MASK)
			MutePlayer(m_Player, true);
		if (parent.IsKindOf("X18_GasMask_Container"))
			GetCompEM().SwitchOff();
	}
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		if (parent.IsInherited(SurvivorBase) && Class.CastTo(m_Player, parent))
			MutePlayer(m_Player, false);
		if (parent.IsKindOf("X18_GasMask_Container"))
			GetCompEM().SwitchOn();
	}
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		GasMaskFilter_Base m_GasMaskFilter;
		if (GetGame().IsServer() && GetCompEM().CanWork() && Class.CastTo(m_GasMaskFilter, item))
			GetCompEM().SwitchOn();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		if (GetGame().IsServer())
			GetCompEM().SwitchOff();
	}
	override void OnWork(float consumed_energy)
	{
		if (GetGame().IsServer())
		{
			if (Class.CastTo(m_Player, this.GetHierarchyRootPlayer()) && !m_Player.IsAlive())
				m_Player.UpdateRadiationShield();
		}
	}
	override void OnSwitchOn()
	{
		if (Class.CastTo(m_Player, this.GetHierarchyRootPlayer()))
			m_Player.UpdateRadiationShield();
	}
	override void OnSwitchOff()
	{
		if (Class.CastTo(m_Player, this.GetHierarchyRootPlayer()))
			m_Player.UpdateRadiationShield();
	}
	override void OnWorkStart()
	{}
	override void OnWorkStop()
	{}
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
	}
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;
		if (GetGame().IsServer())
		{
			if (GetCompEM().CanWork())
				GetCompEM().SwitchOn();
		}
		return true;
	}

	override bool IsObstructingVoice()
	{
		return true;
	}

	override int GetVoiceEffect()
	{
		return VoiceEffectObstruction;
	}
}
modded class X18_GasMask_AVC : GasMask_Base
{
	override bool IsObstructingVoice()
	{
		return true;
	}

	override int GetVoiceEffect()
	{
		return VoiceEffectExtortion;
	}
}