modded class PlayerBase
{
	protected bool m_radioPtt = false;
	EffectSound m_RadioPttSound;
	bool HasEnabledRadioTransmitterReceivers()
	{
		GameInventory inventory = PlayerBase.Cast(this).GetInventory();
		ref array<EntityAI> items = new array<EntityAI>;
		inventory.EnumerateInventory(InventoryTraversalType.INORDER, items);
		for (int i = 0; i < items.Count(); ++i)
		{
			EntityAI item = items.Get(i);
			ItemTransmitter transmitter = NULL;
			if (Class.CastTo(transmitter, item) && transmitter)
			{
				if (transmitter.IsReceiving())
					return true;
			}
		}
		return false;
	}
	bool SynchronizeRadioPushToTalk()
	{
		bool found = false;
		GameInventory inventory = PlayerBase.Cast(this).GetInventory();
		ref array<EntityAI> items = new array<EntityAI>;
		inventory.EnumerateInventory(InventoryTraversalType.INORDER, items);
		for (int i = 0; i < items.Count(); ++i)
		{
			EntityAI item = items.Get(i);
			ItemTransmitter transmitter = NULL;
			if (Class.CastTo(transmitter, item) && transmitter)
			{
				if (transmitter.IsReceiving())
				{
					transmitter.EnableBroadcast(m_radioPtt);
					if (m_radioPtt)
						transmitter.RPCSingleParam(RPC_RADIO_PTT_ENABLE_PTT, NULL, true);
					else
						transmitter.RPCSingleParam(RPC_RADIO_PTT_DISABLE_PTT, NULL, true);
					found = true;
				}
			}
		}
		return found;
	}
	bool EnableRadioPushToTalk(bool ptt = true)
	{
		m_radioPtt = ptt;
		return SynchronizeRadioPushToTalk();
	}
	bool DisableRadioPushToTalk()
	{
		return EnableRadioPushToTalk(false);
	}
	bool IsRadioPushToTalk()
	{
		return m_radioPtt;
	}
	void PlayRadioPttOnSound()
	{
		PlaySoundSet(m_RadioPttSound, "RadioPTT_Self_Down_SoundSet", 0.0, 0.0);
	}
	void PlayRadioPttOffSound()
	{
		PlaySoundSet(m_RadioPttSound, "RadioPTT_Self_Up_SoundSet", 0.0, 0.0);
	}
}