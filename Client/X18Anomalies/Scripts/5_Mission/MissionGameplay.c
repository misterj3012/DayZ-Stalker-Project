modded class MissionGameplay
{
	private const float BOLT_COOLDOWN = 5.0;
	private float boltCooldown = 0.0;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		boltCooldown = boltCooldown + timeslice;
		if (boltCooldown >= BOLT_COOLDOWN)
		{
			UAInput inp = GetUApi().GetInputByName("EquipBolt");
			if (inp)
			{
				if (inp.LocalHoldBegin())
				{
					PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
					if (player)
					{
						if (!player.GetItemInHands())
						{
							player.RPCSingleParam(X18AnomaliesRPC.EQUIP_BOLT, NULL, true, player.GetIdentity());
							boltCooldown = 0.0;
						}
					}
				}
			}
		}
	}
}