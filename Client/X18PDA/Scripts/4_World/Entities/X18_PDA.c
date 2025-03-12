class X18_PDA : ItemBase
{
	void X18_PDA() {}

	override void EEInit()
	{
		super.EEInit();
		UpdateVisualStyle();
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		AddAction(ActionOpenPDA);
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
				SEffectManager.PlaySound("PDA_BatteryInsert_SoundSet", GetPosition());
		}
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
				SEffectManager.PlaySound("PDA_BatteryRemove_SoundSet", GetPosition());
		}
	}
	override void OnIsPlugged(EntityAI source_device)
	{
		super.OnIsPlugged(source_device);
		UpdateVisualStyle();
	}
	override void OnIsUnplugged(EntityAI last_energy_source)
	{
		super.OnIsUnplugged(last_energy_source);
		UpdateVisualStyle();
	}
	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);
		UpdateVisualStyle();
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		UpdateVisualStyle();
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			SEffectManager.PlaySound("PDA_TurnOn_SoundSet", GetPosition());
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		UpdateVisualStyle();

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			SEffectManager.PlaySound("PDA_TurnOff_SoundSet", GetPosition());
	}
	override void OnInitEnergy()
	{
		super.OnInitEnergy();
		UpdateVisualStyle();
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisualStyle();
	}
	void UpdateVisualStyle()
	{
		if (GetGame().IsClient())
		{
			if (!IsRuined() && HasEnergyManager() && GetCompEM().IsWorking())
				SetObjectTexture(GetHiddenSelectionIndex("front"), "Noosphere\X18PDA\Data\Model\Data\front\PDA_FIDOv_On.paa");
			else
				SetObjectTexture(GetHiddenSelectionIndex("front"), "Noosphere\X18PDA\Data\Model\Data\front\PDA_FIDOv.paa");
		}
	}
};