modded class PlayerBase
{
	protected bool m_EnteredSpaceAnomaly = false;
	void SetEnteredSpaceAnomaly(bool status)
	{
		m_EnteredSpaceAnomaly = status;
		if (m_EnteredSpaceAnomaly)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetEnteredSpaceAnomaly, 300000, false, false);
	}
	bool HasEnteredSpaceAnomaly()
	{
		return m_EnteredSpaceAnomaly;
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsServer())
		{
			switch (rpc_type) {
				case X18AnomaliesRPC.EQUIP_BOLT:
					{
						if (!GetItemInHands())
						{
							private ref array<EntityAI> m_FoundBolts;
							m_FoundBolts = this.FindInheritedItemInInventory(X18_Bolt);

							if (!m_FoundBolts)
								return;

							foreach(EntityAI m_FoundBolt : m_FoundBolts)
							{
								X18_Bolt m_Bolt;
								if (Class.CastTo(m_Bolt, m_FoundBolt))
								{
									if (m_Bolt.GetQuantity() > 0)
									{
										X18_Bolt m_BoltInHands;
										if (Class.CastTo(m_BoltInHands, GetHumanInventory().CreateInHands("X18_Bolt")))
											m_BoltInHands.SetQuantity(1);
										m_Bolt.AddQuantity(-1);
										break;
									}
								}
							}
						}
					}
			}
		}
	}
}