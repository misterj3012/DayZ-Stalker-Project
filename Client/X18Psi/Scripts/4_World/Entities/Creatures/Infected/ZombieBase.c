modded class ZombieBase
{
	protected bool m_ReceivedAttachments;
	void TransferAttachmentsToZombie(EntityAI entity)
	{
		for (int i = 0; i < entity.GetInventory().GetAttachmentSlotsCount(); i++)
		{
			int slot = entity.GetInventory().GetAttachmentSlotId(i);
			EntityAI item = entity.GetInventory().FindAttachment(slot);
			if (item)
			{
				float health;
				float max = item.GetMaxHealth("", "");
				if (GetGame().IsServer())
				{
					health = item.GetHealth();

					if (item.IsInherited(Sin_BeastMaster_SS) || item.IsInherited(VoiceExtortionItem) || item.IsInherited(X18_GasMask_CN2F) || item.IsInherited(X18_Key_Base))
						health = max * GameConstants.DAMAGE_RUINED_VALUE;

					item.SetHealth(item.GetMaxHealth());
				}
				if (GetInventory().CanAddAttachment(item))
				{
					if (GetGame().IsMultiplayer())
						entity.ServerTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
					else
						entity.LocalTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
				}
				else
				{
					if (GetGame().IsMultiplayer())
						entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, item);
					else
						entity.GetInventory().DropEntity(InventoryMode.LOCAL, entity, item);
				}
				if (GetGame().IsServer())
					item.SetHealth(health);
			}
			m_ReceivedAttachments = true;
			SetSynchDirty();
		}
	}
};