class X18_ArtefactCharger : WorldContainer_Base
{
	static const string OPEN_SOUND = "ArtifactChargerOpen_SoundSet";
	static const string LOOP_SOUND = "ArtifactChargerLoop_SoundSet";
	static const string CLOSE_SOUND = "ArtifactChargerClose_SoundSet";
	static const string STOP_SOUND = "ArtifactChargerStop_SoundSet";
	static const string START_SOUND = "ArtifactChargerStart_SoundSet";
	static const string ARM_SOUND = "ArtifactChargerArm_SoundSet";
	static const string SWITCH_SOUND = "ArtifactChargerSwitch_SoundSet";
	static const string CHARGE_SOUND = "ArtifactChargerCharge_SoundSet";
	static const string SEL_SWITCH_ON = "switch_on";
	static const string SEL_SWITCH_OFF = "switch_off";
	protected EffectSound m_ArtifactChargerOpen;
	protected EffectSound m_ArtifactChargerLoop;
	protected EffectSound m_ArtifactChargerClose;
	protected EffectSound m_ArtifactChargerStop;
	protected EffectSound m_ArtifactChargerArm;
	protected EffectSound m_ArtifactChargerStart;
	protected EffectSound m_ArtifactChargerSwitch;
	protected EffectSound m_ArtifactChargerCharge;
	protected ref Timer m_SoundLoopStartTimer;
	protected ref OpenableBehaviour m_Openable;
	void X18_ArtefactCharger()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		SetAllowDamage(false);
	}
	override void EEInit()
	{
		super.EEInit();
		if (IsOpen())
			GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		else
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	void StartLoopSound()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (GetCompEM().IsWorking())
			{
				PlaySoundSetLoop(m_ArtifactChargerLoop, LOOP_SOUND, 0, 0);
				PlaySoundSetLoop(m_ArtifactChargerCharge, CHARGE_SOUND, 0, 0);
			}
		}
	}
	override void Open()
	{
		PlaySoundSet(m_ArtifactChargerOpen, OPEN_SOUND, 0, 0);
		PlaySoundSet(m_ArtifactChargerArm, ARM_SOUND, 0, 0);
		m_Openable.Open();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}
	override void Close()
	{
		PlaySoundSet(m_ArtifactChargerClose, CLOSE_SOUND, 0, 0);
		PlaySoundSet(m_ArtifactChargerArm, ARM_SOUND, 0, 0);
		m_Openable.Close();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	void UpdateVisualState()
	{
		if (IsOpen())
		{
			SetAnimationPhase("upperglass", 1);
			SetAnimationPhase("lowerglass", 1);
			SetAnimationPhase("lowerrightarm", 0);
			SetAnimationPhase("lowerleftarm", 0);
			SetAnimationPhase("upperarm", 0);
		}
		else
		{
			SetAnimationPhase("upperglass", 0);
			SetAnimationPhase("lowerglass", 0);
			SetAnimationPhase("lowerrightarm", 1);
			SetAnimationPhase("lowerleftarm", 1);
			SetAnimationPhase("upperarm", 1);
		}
	}
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (item.IsKindOf("X18_Artefact_Base"))
			return IsOpen();
		return false;
	}
	override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		if (child_entity.IsKindOf("X18_Artefact_Base") && new_entity.IsKindOf("X18_Artefact_Base"))
			return IsOpen();
		return false;
	}
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}
	override bool CanDisplayAttachmentSlot(string slot_name)
	{
		return true;
	}
	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);
		if (GetGame().IsServer() || GetGame().!IsMultiplayer())
		{
			PrintLog("OnWork");
			EntityAI chargedartifact = GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("ArtefactSlot1"));
			if (chargedartifact)
			{
				float chargedartifact_capacity = chargedartifact.GetCompEM().GetEnergyMax();
				PrintLog("chargedartifact: " + chargedartifact.GetType() + "chargedartifact_capacity: " + chargedartifact_capacity);
				if (chargedartifact.GetCompEM().GetEnergy() < chargedartifact_capacity - 1)
					chargedartifact.GetCompEM().AddEnergy(consumed_energy);
			}
		}
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		PrintLog("OnWorkStart");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlaySoundSet(m_ArtifactChargerStart, START_SOUND, 0, 0);
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_SYSTEM);
			if (!m_SoundLoopStartTimer.IsRunning())
				m_SoundLoopStartTimer.Run(1.5, this, "StartLoopSound", NULL, false);
		}
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		PrintLog("OnWorkStop");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlaySoundSet(m_ArtifactChargerStop, STOP_SOUND, 0, 0);
			StopSoundSet(m_ArtifactChargerLoop);
			StopSoundSet(m_ArtifactChargerCharge);
		}
	}
	override void OnSwitchOn()
	{
		PlaySoundSet(m_ArtifactChargerSwitch, SWITCH_SOUND, 0, 0);
		HideSelection(SEL_SWITCH_OFF);
		ShowSelection(SEL_SWITCH_ON);
	}
	override void OnSwitchOff()
	{
		PlaySoundSet(m_ArtifactChargerSwitch, SWITCH_SOUND, 0, 0);
		HideSelection(SEL_SWITCH_ON);
		ShowSelection(SEL_SWITCH_OFF);
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenArtefactCharger);
		AddAction(ActionCloseArtefactCharger);
		AddAction(ActionTurnOnArtefactCharger);
		AddAction(ActionTurnOffArtefactCharger);
	}
}