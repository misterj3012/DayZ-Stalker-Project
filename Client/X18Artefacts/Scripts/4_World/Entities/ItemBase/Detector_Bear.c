class X18_Artefact_Detector_Bear : Detector_Base
{
	protected EffectSound 		m_EngineLoop;
	ref Timer 					m_SoundLoopStartTimer;
	float 						m_time = 0;
	protected ref OpenableBehaviour m_Openable;

	static int		REFLECTOR_ID = 1;
	static int		GLASS_ID = 2;

	static string 	LIGHT_OFF_GLASS = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_OFF_REFLECTOR = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_ON_GLASS = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";
	static string 	LIGHT_ON_REFLECTOR = "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat";

	void X18_Artefact_Detector_Bear()
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
		{
			SetAnimationPhase("cover", 1.0);
			SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
		}
		else
		{
			SetAnimationPhase("cover", 0.0);
			SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
		}
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
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_SYSTEM);
			m_SoundLoopStartTimer.Run(0.005, this, "StartLoopSound", NULL, true);
		}
		DisableVisuals();
	}
	void StartLoopSound()
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
				if (GetLootDistance() < 0 && GetLootDistance() > 1)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(22, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(23, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(24, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(25, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\red.rvmat");
				}
				if (GetLootDistance() > 1 && GetLootDistance() < 2)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(22, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(23, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(24, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 2 && GetLootDistance() < 3)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(22, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(23, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 3 && GetLootDistance() < 4)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(22, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 4 && GetLootDistance() < 5)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 5 && GetLootDistance() < 6)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 6 && GetLootDistance() < 7)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 7 && GetLootDistance() < 8)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 8 && GetLootDistance() < 9)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 9 && GetLootDistance() < 10)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 10 && GetLootDistance() < 11)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 11 && GetLootDistance() < 12)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 12 && GetLootDistance() < 13)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 13 && GetLootDistance() < 14)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 14 && GetLootDistance() < 15)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 15 && GetLootDistance() < 16)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 16 && GetLootDistance() < 17)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 17 && GetLootDistance() < 18)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 18 && GetLootDistance() < 19)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 19 && GetLootDistance() < 20)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 20 && GetLootDistance() < 21)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 21 && GetLootDistance() < 22)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 22 && GetLootDistance() < 23)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
				}
				if (GetLootDistance() > 23 && GetLootDistance() < 24)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(3, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");

				}
				if (GetLootDistance() > 24 && GetLootDistance() < 25)
				{
					SetObjectMaterial(1, "Noosphere\\X18Artefacts\\Models\\Detector\\Data\\yellow.rvmat");
					SetObjectMaterial(2, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(3, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(4, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(5, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(6, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(7, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(8, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(9, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(10, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(11, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(12, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(13, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(14, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(15, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(16, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(17, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(18, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(19, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(20, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(21, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(22, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(23, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(24, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
					SetObjectMaterial(25, "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");

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
		SetObjectTexture(GetHiddenSelectionIndex("num8"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num9"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num10"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num11"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num12"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num13"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num14"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num15"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num16"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num17"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num18"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num19"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num20"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num21"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num22"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num23"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num24"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectTexture(GetHiddenSelectionIndex("num25"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass_ca.paa");
		SetObjectMaterial(GetHiddenSelectionIndex("num2"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num3"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num4"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num5"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num6"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num7"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num8"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num9"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num10"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num11"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num12"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num13"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num14"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num15"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num16"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num17"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num18"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num19"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num20"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num21"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num22"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num23"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num24"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
		SetObjectMaterial(GetHiddenSelectionIndex("num25"), "dz\\structures\\furniture\\decoration\\wallboards\\wall_board\\data\\glass.rvmat");
	}
	override void OnWorkStop()
	{
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if (m_SoundLoopStartTimer)
				m_SoundLoopStartTimer.Stop();
		}
		DisableVisuals();
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
		return 2;
	}
	override float GetLootDetectRadius()
	{
		return 25;
	}
	override int GetDetectTime()
	{
		return 7;
	}
};