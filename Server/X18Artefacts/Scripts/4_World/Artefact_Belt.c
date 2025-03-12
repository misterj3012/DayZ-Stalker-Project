class X18_Artefact_Belt extends Clothing
{
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);

		for (int i = 0; i < GetInventory().AttachmentCount(); i++)
		{
			X18_Artefact_Base m_Artefact = X18_Artefact_Base.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (m_Artefact)
			{
				if (m_Artefact.HasEnergyManager() && m_Artefact.GetCompEM().IsWorking())
					m_Artefact.GetCompEM().SwitchOff();
			}
		}
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);

		if (PlayerBase.Cast(parent))
		{
			for (int i = 0; i < GetInventory().AttachmentCount(); i++)
			{
				X18_Artefact_Base m_Artefact = X18_Artefact_Base.Cast(GetInventory().GetAttachmentFromIndex(i));
				if (m_Artefact)
				{
					if (m_Artefact.HasEnergyManager() && m_Artefact.GetCompEM().CanWork())
						m_Artefact.GetCompEM().SwitchOn();
				}
			}
		}
	}
}

class X18_Artefact_Belt_Freedom_Olive_Base : X18_Artefact_Belt {};
class X18_Artefact_Belt_Freedom_ERDL_Base : X18_Artefact_Belt {};
class X18_Artefact_TacticalBelt_Freedom_Green_Base : X18_Artefact_Belt {};
class X18_Artefact_Belt_ClearSky_Black_Base : X18_Artefact_Belt {};
class X18_Artefact_Belt_ClearSky_Tan_Base : X18_Artefact_Belt {};
class X18_Artefact_TacticalBelt_ClearSky_Black_Base : X18_Artefact_Belt {};
class X18_Artefact_TacticalBelt_ClearSky_Tan_Base : X18_Artefact_Belt {};