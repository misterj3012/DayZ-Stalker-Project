class X18_Artefact_Detector_Veles : Detector_Base
{
	protected EffectSound 		m_EngineLoop;
	ref Timer 					m_SoundLoopStartTimer;
	float 						m_time = 0;

	static int		REFLECTOR_ID = 1;
	static int		GLASS_ID = 2;

	static string 	LIGHT_OFF_GLASS = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_OFF_REFLECTOR = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_ON_GLASS = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_ON_REFLECTOR = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";

	void X18_Artefact_Detector_Veles()
	{
		DisableVisuals();
		SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
		SetObjectTexture(GetHiddenSelectionIndex("num8"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectMaterial(GetHiddenSelectionIndex("num8"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
	}
	override void OnWorkStart()
	{
		super.OnWorkStart();
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_SYSTEM);
			m_SoundLoopStartTimer.Run(0.005, this, "Loop", NULL, true);
		}

		SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
	}
	void Loop()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (GetCompEM().IsWorking() && (GetLootDistance() >= 0.0 && GetLootDistance() <= GetLootDetectRadius()))
			{
				float calc = 10 - GetLootDistance();
				if (calc > 8) calc = 9;
				if (calc < 1) calc = 1;
				float koef = calc / 2;
				float time = 0.005 * koef;
				m_time += time;
				if (m_time >= 0.2)
				{
					SEffectManager.PlaySoundOnObject("Detector_SoundSet", this);
					m_time = 0;
				}
				if (GetLootDistance() < 4 && GetLootDistance() > 0)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
				}
				if (GetLootDistance() > 4 && GetLootDistance() < 6)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 6 && GetLootDistance() < 10)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 10 && GetLootDistance() < 16)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 16 && GetLootDistance() < 25)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 25 && GetLootDistance() < 35)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(3, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
			}
			else
			{
				DisableVisuals();
			}
		}
	}
	void DisableVisuals()
	{
		SetObjectTexture(GetHiddenSelectionIndex("num2"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num3"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num4"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num5"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num6"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num7"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectMaterial(GetHiddenSelectionIndex("num2"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num3"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num4"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num5"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num6"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num7"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if (m_SoundLoopStartTimer) m_SoundLoopStartTimer.Stop();
			DisableVisuals();
		}
		SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
	}
	override void OnSwitchOn()
	{
		SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\red.rvmat");
		super.OnSwitchOn();
	}
	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
	override int GetTier()
	{
		return 3;
	}
	override float GetLootDetectRadius()
	{
		return 35;
	}
	override int GetDetectTime()
	{
		return 5;
	}
};