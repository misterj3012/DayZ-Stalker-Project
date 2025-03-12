class GasMask_Base : GasMask
{

	protected PlayerBase m_Player;
	void GasMask_Base()
	{}
	void ~GasMask_Base()
	{}
	override bool CanPutAsAttachment(EntityAI parent)
	{
		if (!super.CanPutAsAttachment(parent))
			return false;
		bool headgear_present = false;
		if (parent.FindAttachmentBySlotName("Headgear"))
			headgear_present = parent.FindAttachmentBySlotName("Headgear").ConfigGetBool("noMask");
		if ((GetNumberOfItems() == 0 || !parent || parent.IsMan()) && !headgear_present)
			return true;
		return false;
	}
	override bool IsObstructingVoice()
	{
		return true;
	}
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		return true;
	}
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (!super.CanReleaseAttachment(attachment))
			return false;
		return true;
	}
};
class X18_GasMask_AVC : GasMask_Base {};
class X18_GasMask_CM7 : GasMask_Base {};
class X18_GasMask_CN2F : GasMask_Base
{
	override void MutePlayer(PlayerBase m_Player, bool state)
	{
		if ((GetGame().IsServer() && GetGame().IsMultiplayer()) || (GetGame().GetPlayer() == m_Player))
			GetGame().SetVoiceEffect(m_Player, VoiceEffectExtortion, state);
	}
};
class X18_GasMask_GMS : GasMask_Base {};
class X18_GasMask_GP5 : GasMask_Base {};
class X18_GasMask_GP5_Black : GasMask_Base {};
class X18_GasMask_GP7 : GasMask_Base {};
class X18_GasMask_GP21 : GasMask_Base {};
class X18_GasMask_HOMA : GasMask_Base {};
class X18_GasMask_M04 : GasMask_Base {};
class X18_GasMask_M40 : GasMask_Base {};
class X18_GasMask_M40M2 : GasMask_Base {};
class X18_GasMask_M50 : GasMask_Base {};
class X18_GasMask_M50_Camo : GasMask_Base {};
class X18_GasMask_M50M2 : GasMask_Base {};
class X18_GasMask_M50CBRN : GasMask_Base {};
class X18_GasMask_M50CBRN_SMG : GasMask_Base {};
class X18_GasMask_MK10 : GasMask_Base {};
class X18_GasMask_PFBP1 : GasMask_Base {};
class X18_GasMask_PMG2 : GasMask_Base {};
class X18_GasMask_PMG4 : GasMask_Base {};
class X18_GasMask_RSH4 : GasMask_Base {};
class X18_GasMask_S10 : GasMask_Base {};
class X18_GasMask_S10SMG : GasMask_Base {};
class X18_GasMask_WW1 : GasMask_Base {};
class X18_GasMask_P2 : GasMask_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		X18_GasMask_P2_Filter m_GasMask;
		if (Class.CastTo(m_GasMask, attachment))
			return true;
		return false;
	}
};
class X18_GasMask_P2_Black : GasMask_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		X18_GasMask_P2_Filter m_GasMask;
		if (Class.CastTo(m_GasMask, attachment))
			return true;
		return false;
	}
};
class X18_GasMask_P2_Duty : GasMask_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		X18_GasMask_P2_Filter_Duty m_GasMask;
		if (Class.CastTo(m_GasMask, attachment))
			return true;
		return false;
	}
};
class X18_GasMask_CBRN : GasMask_Base {};
class X18_GasMask_Stalker : GasMask_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		X18_GasMask_Stalker_Filter m_GasMask;
		if (Class.CastTo(m_GasMask, attachment))
			return true;
		return false;
	}
};
class X18_GasMask_Stalker_FullFace : GasMask_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		X18_GasMask_Stalker_FullFace_Filter m_GasMask;
		if (Class.CastTo(m_GasMask, attachment))
			return true;
		return false;
	}
};
class X18_GasMask_PPM88 : GasMask_Base {};