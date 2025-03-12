class GeigerCounter_Base : ItemBase
{
	protected EffectSound m_BatteryAttachmentSound;
	protected EffectSound m_SwitchSound;
	protected EffectSound m_GeigerSound;
	protected float m_Radiation = 0.0;
	float m_time = 0;
	ref Timer m_SoundLoopStartTimer;
	void GeigerCounter_Base()
	{
		RegisterNetSyncVariableFloat("m_Radiation");
	}
	override void OnWorkStart()
	{
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		PlayerBase m_Player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (m_Player == GetGame().GetPlayer())
		{
			GeigerCounter_Base m_GeigerCounter = GeigerCounter_Base.Cast(m_Player.GetItemInHands());
			if (m_GeigerCounter.GetType() == this.GetType())
				m_Player.ShowGeigerCounter(true);
			m_Player.GeigerCounter = GetGeigerCounterType();
		}
		StartSound();
		m_SwitchSound = SEffectManager.PlaySoundOnObject("Switch_SoundSet", this);
		m_SwitchSound.SetSoundAutodestroy(true);
	}
	override void OnWork(float consumed_energy)
	{
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		PlayerBase m_Player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (m_Player == GetGame().GetPlayer())
		{
			if (m_Player.GetStrengthOfRadiation() > 0)
				m_Player.SetGeigerCounterValue(GetRadiationValueAroundPlayer());
			else
				m_Player.SetGeigerCounterValue(0);
		}
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		PlayerBase m_Player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (m_Player == GetGame().GetPlayer())
		{
			m_Player.ShowGeigerCounter(false);
			m_Player.GeigerCounter = 0;
		}
		StopSound();
		m_SwitchSound = SEffectManager.PlaySoundOnObject("Switch_SoundSet", this);
		m_SwitchSound.SetSoundAutodestroy(true);
	}
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			m_BatteryAttachmentSound = SEffectManager.PlaySoundOnObject("BatteryInsert_SoundSet", this);
			m_BatteryAttachmentSound.SetSoundAutodestroy(true);
		}
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		ItemBase itemBase = ItemBase.Cast(item);
		if (itemBase && itemBase.IsKindOf("Battery9V"))
		{
			m_BatteryAttachmentSound = SEffectManager.PlaySoundOnObject("BatteryRemove_SoundSet", this);
			m_BatteryAttachmentSound.SetSoundAutodestroy(true);
		}
	}
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		if (newLoc.IsValid())
		{
			if (newLoc.GetParent() && GetCompEM().IsWorking())
			{
				PlayerBase m_Player = PlayerBase.Cast(GetHierarchyRootPlayer());
				if (m_Player == GetGame().GetPlayer())
				{
					if (newLoc.GetType() == InventoryLocationType.HANDS)
						m_Player.ShowGeigerCounter(true);
					else
						m_Player.ShowGeigerCounter(false);
				}
			}
		}
	}
	void StartSound()
	{
		if (!m_SoundLoopStartTimer)
			m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_SYSTEM);
		m_SoundLoopStartTimer.Run(0.005, this, "StartLoopSound", NULL, true);
	}
	void StopSound()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (m_SoundLoopStartTimer)
				m_SoundLoopStartTimer.Stop();
			if (m_GeigerSound)
				m_GeigerSound.SoundStop();
		}
	}
	void StartLoopSound()
	{
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		if (GetCompEM().IsWorking())
		{
			if (GetRadiationValueAroundPlayer() <= 0.0)
			{
				if (m_GeigerSound)
					m_GeigerSound.SoundStop();
				return;
			}
			else
			{
				if (GetRadiationValueAroundPlayer() > 0.0)
				{
					float calc = GetRadiationValueAroundPlayer();
					if (calc > GetMaxRadiation()) calc = GetMaxRadiation();
					if (calc <= 25) calc = 25;
					float koef = calc / ((GetMaxRadiation() / 1000) * 100);
					float time = 0.005 * koef;
					m_time += time;
					if (m_time >= 0.2)
					{
						if (!m_GeigerSound)
						{
							m_GeigerSound = SEffectManager.PlaySoundOnObject("Geiger_Detect_SoundSet", this);
							m_GeigerSound.SetSoundAutodestroy(true);
						}
						m_time = 0;
					}
				}
			}
		}
	}
	int GetGeigerCounterType()
	{
		return 0;
	}
	int GetMaxRadiation()
	{
		return 10000;
	}
	float GetRadiationValue()
	{
		return m_Radiation;
	}
	void SetRadiationValue(float value)
	{
		m_Radiation = value;
		SetSynchDirty();
	}
	float GetRadiationValueAroundPlayer()
	{
		PlayerBase m_Player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (m_Player == GetGame().GetPlayer())
		{
			SetRadiationValue(m_Player.GetStrengthOfRadiation());
			return m_Player.GetStrengthOfRadiation();
		}
		else
			return GetRadiationValue();
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
};
class X18_Tools_GeigerCounter_High : GeigerCounter_Base
{
	int GetGeigerCounterType()
	{
		return 1;
	}
	int GetMaxRadiation()
	{
		return 10000;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionMeasureRadiationTarget);
		AddAction(ActionMeasureRadiationSelf);
	}
};
class X18_Tools_GeigerCounter_Mid : GeigerCounter_Base
{
	int GetGeigerCounterType()
	{
		return 2;
	}
	int GetMaxRadiation()
	{
		return 3000;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionMeasureRadiationTarget);
		AddAction(ActionMeasureRadiationSelf);
	}
};
class X18_Tools_GeigerCounter_Low : GeigerCounter_Base
{
	int GetGeigerCounterType()
	{
		return 3;
	}
	int GetMaxRadiation()
	{
		return 500;
	}
};