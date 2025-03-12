modded class BleedingSource
{
	void BleedingSource(PlayerBase player, int bit, string bone, vector orientation, vector offset, int max_time, float flow_modifier, string particle_name)
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			m_FlowModifier = flow_modifier * (1.0 + player.GetStatBloodLossModifier().Get());
	}
}