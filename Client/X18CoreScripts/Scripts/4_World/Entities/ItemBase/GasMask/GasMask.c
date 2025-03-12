class VoiceExtortionItem : Clothing
{
	protected PlayerBase m_Player;
	override bool IsObstructingVoice()
	{
		return true;
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		if (parent.IsInherited(SurvivorBase) && Class.CastTo(m_Player, parent) && slot_id == InventorySlots.MASK)
			MutePlayer(m_Player, true);
	}
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		if (parent.IsInherited(SurvivorBase) && Class.CastTo(m_Player, parent))
			MutePlayer(m_Player, false);
	}
	override void MutePlayer(PlayerBase m_Player, bool state)
	{
		if ((GetGame().IsServer() && GetGame().IsMultiplayer()) || (GetGame().GetPlayer() == m_Player))
			GetGame().SetVoiceEffect(m_Player, VoiceEffectExtortion, state);
	}
};
class FS_Maniac : VoiceExtortionItem {};
class FS_SKULL_Balaclava : VoiceExtortionItem {};
class FS_BalaklavaSkull : VoiceExtortionItem {};