class X18_Artefact_Detector_Echo : Detector_Base
{
	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStop;
	ref Timer 					m_SoundLoopStartTimer;
	ChemlightLight 				m_Chemlight;
	bool  						IsWorking;
	float 						m_time = 0;
	protected ref OpenableBehaviour m_Openable;
	void X18_Artefact_Detector_Echo()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		UpdateVisualState();
	}
	override void Open()
	{
		m_Openable.Open();
		SetSynchDirty();
		UpdateVisualState();
	}
	override void Close()
	{
		m_Openable.Close();
		SetSynchDirty();
		UpdateVisualState();
	}
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	protected void UpdateVisualState()
	{
		if (IsOpen())
			SetAnimationPhase("Open", 1.0);
		else
			SetAnimationPhase("Open", 0.0);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateVisualState();
	}
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		if (GetCompEM().IsWorking())
		{
			if (player)
			{
				vector ori_rotate = player.GetOrientation();
				ori_rotate = ori_rotate + Vector(270, 0, 0);
				SetOrientation(ori_rotate);
			}
		}
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		if (!GetGame().IsDedicatedServer())
		{
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_SYSTEM);
			m_SoundLoopStartTimer.Run(0.005, this, "StartLoopSound", NULL, true);
		}
		SetObjectMaterial(GetHiddenSelectionIndex("led"), "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\green.rvmat");
	}
	void StartLoopSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (GetCompEM().IsWorking() && GetLootDistance() >= 0.0)
			{
				float calc = 10 - GetLootDistance();
				if (calc > 8) calc = 9;
				if (calc < 1) calc = 1;
				float koef = calc / 2;
				float time = 0.005 * koef;
				m_time += time;
				if (m_time >= 0.1)
				{
					SEffectManager.PlaySoundOnObject("Detector_SoundSet", this);
					SetObjectMaterial(GetHiddenSelectionIndex("lamp"), "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\green.rvmat");
					m_time = 0;
				}
				else if (GetLootDistance() >= 4.1)
					SetObjectMaterial(GetHiddenSelectionIndex("lamp"), "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\off.rvmat");
			}
			else if (GetCompEM().IsWorking() && GetLootDistance() <= -1)
				SetObjectMaterial(GetHiddenSelectionIndex("lamp"), "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\off.rvmat");
		}
	}
	override void OnWorkStop()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_SoundLoopStartTimer)
				m_SoundLoopStartTimer.Stop();
		}
		SetObjectMaterial(GetHiddenSelectionIndex("led"), "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\off.rvmat");
	}
	override void OnSwitchOn()
	{
		Open();
		super.OnSwitchOn();
	}
	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		Close();
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
	override int GetTier()
	{
		return 1;
	}
	override float GetLootDetectRadius()
	{
		return 15;
	}
	override int GetDetectTime()
	{
		return 10;
	}
};