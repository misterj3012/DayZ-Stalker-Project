class X18_ArtefactStorage : WorldContainer_Base
{
	static const string SEL_SWITCH_ON = "switch_on";
	static const string SEL_SWITCH_OFF = "switch_off";
	protected FlashlightLight m_Light1;
	protected FlashlightLight m_Light2;
	protected FlashlightLight m_Light3;
	void X18_ArtefactStorage()
	{
		SetAllowDamage(false);
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			m_Light1 = FlashlightLight.Cast(ScriptedLightBase.CreateLight(FlashlightLight, "0 0 0", 0.08));
			m_Light2 = FlashlightLight.Cast(ScriptedLightBase.CreateLight(FlashlightLight, "0 0 0", 0.08));
			m_Light3 = FlashlightLight.Cast(ScriptedLightBase.CreateLight(FlashlightLight, "0 0 0", 0.08));
			m_Light1.AttachOnMemoryPoint(this, "light11", "light1");
			m_Light2.AttachOnMemoryPoint(this, "light22", "light2");
			m_Light3.AttachOnMemoryPoint(this, "light33", "light3");
		}
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (m_Light1)
			{
				m_Light1.FadeOut();
				m_Light2.FadeOut();
				m_Light3.FadeOut();
			}
			m_Light1 = NULL;
			m_Light2 = NULL;
			m_Light3 = NULL;
		}
	}
	override void OnSwitchOn()
	{
		HideSelection(SEL_SWITCH_OFF);
		ShowSelection(SEL_SWITCH_ON);
	}
	override void OnSwitchOff()
	{
		HideSelection(SEL_SWITCH_ON);
		ShowSelection(SEL_SWITCH_OFF);
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnStorageLights);
		AddAction(ActionTurnOffStorageLights);
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (item.IsKindOf("X18_Artefact_Base"))
			return super.CanReceiveItemIntoCargo(item);
		return false;
	}
	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		if (child_entity.IsKindOf("X18_Artefact_Base") && new_entity.IsKindOf("X18_Artefact_Base"))
			return super.CanSwapItemInCargo(child_entity, new_entity);
		return false;
	}
}