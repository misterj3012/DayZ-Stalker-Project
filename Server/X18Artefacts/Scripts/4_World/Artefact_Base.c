modded class X18_Artefact_Base : ItemBase
{
	private bool m_InitialOnWork = true;
	private bool m_PassivePositiveActive = false;
	private bool m_PassiveNegativeActive = false;
	private bool m_Positive = false;
	private int m_Tick = 0;
	const ref array<string> m_BleedingZones = { "Head", "Neck", "Pelvis", "Spine", "LeftShoulder", "LeftArm", "LeftArmRoll", "LeftForeArm", "RightShoulder", "RightArm", "RightArmRoll", "RightForeArm", "LeftForeArmRoll", "RightForeArmRoll", "LeftLeg", "LeftLegRoll", "LeftUpLeg", "LeftUpLegRoll", "RightLeg", "RightLegRoll", "RightUpLeg", "RightUpLegRoll", "LeftFoot", "LeftToeBase", "RightFoot", "RightToeBase" };
	protected PlayerBase m_OldPlayer;
	protected void OnTickNegative(PlayerBase player)
	{}
	protected void OnTickPositive(PlayerBase player)
	{}
	protected void OnPassiveNegativeActivate(PlayerBase player)
	{}
	protected void OnPassiveNegativeDeactivate(PlayerBase player)
	{}
	protected void OnPassivePositiveActivate(PlayerBase player)
	{}
	protected void OnPassivePositiveDeactivate(PlayerBase player)
	{}
	override void OnWork(float consumed_energy)
	{
		m_Tick++;
		super.OnWork(consumed_energy);
		if (m_InitialOnWork)
		{
			m_InitialOnWork = false;
			if ((GetGame().IsServer() || !GetGame().IsMultiplayer()) && HasEnergyManager())
				GetCompEM().AddEnergy(consumed_energy);
			return;
		}
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			PlayerBase m_Player;
			if (Class.CastTo(m_Player, GetHierarchyRootPlayer()) && m_Player.IsAlive())
			{
				if (m_Player != m_OldPlayer)
				{
					if (m_PassiveNegativeActive)
					{
						OnPassiveNegativeDeactivate(m_OldPlayer);
						m_PassiveNegativeActive = false;
					}
					if (m_PassivePositiveActive)
					{
						OnPassivePositiveDeactivate(m_OldPlayer);
						m_PassivePositiveActive = false;
					}
				}
				m_OldPlayer = m_Player;
				bool m_Negative = true;
				EntityAI parent;
				if (Class.CastTo(parent, GetHierarchyParent()))
					m_Negative = true;
				if (m_Negative)
				{
					if (!m_PassiveNegativeActive)
					{
						OnPassiveNegativeActivate(m_Player);
						m_PassiveNegativeActive = true;
					}
					OnTickNegative(m_Player);
				}
				else if (!m_Negative && m_PassiveNegativeActive)
				{
					OnPassiveNegativeDeactivate(m_Player);
					m_PassiveNegativeActive = false;
				}
				if (m_Positive)
				{
					if (!m_PassivePositiveActive)
					{
						OnPassivePositiveActivate(m_Player);
						m_PassivePositiveActive = true;
					}
					OnTickPositive(m_Player);
				}
				else if (!m_Positive && m_PassivePositiveActive)
				{
					OnPassivePositiveDeactivate(m_Player);
					m_PassivePositiveActive = false;
				}
			}
			else
				GetCompEM().SwitchOff();
			if (m_Tick >= 60)
				m_Tick = 0;
		}
	}
	override void OnWorkStart()
	{
		m_InitialOnWork = true;
		m_PassivePositiveActive = false;
		m_PassiveNegativeActive = false;
		private bool m_Positive = false;
		super.OnWorkStart();
	}
	override void OnWorkStop()
	{
		super.OnWorkStop();
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if (m_PassiveNegativeActive && m_OldPlayer)
			{
				OnPassiveNegativeDeactivate(m_OldPlayer);
				m_PassiveNegativeActive = false;
			}
			if (m_PassivePositiveActive && m_OldPlayer)
			{
				OnPassivePositiveDeactivate(m_OldPlayer);
				m_PassivePositiveActive = false;
			}
			m_Tick = 0;
		}
	}
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		if (m_PassiveNegativeActive && m_OldPlayer)
		{
			OnPassiveNegativeDeactivate(m_OldPlayer);
			m_PassiveNegativeActive = false;
		}
		if (m_PassivePositiveActive && m_OldPlayer)
		{
			OnPassivePositiveDeactivate(m_OldPlayer);
			m_PassivePositiveActive = false;
		}
		m_Tick = 0;
	}
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		bool m_TurnOnOff = false;
		EntityAI m_NewOwner = newLoc.GetParent();
		PlayerBase m_Player;
		if (m_NewOwner && Class.CastTo(m_Player, m_NewOwner.GetHierarchyRootPlayer()))
		{
			if (!m_NewOwner.IsInherited(X18_Artefact_Container_Base))
				m_TurnOnOff = true;
			if (m_NewOwner.IsInherited(X18_Artefact_Belt) && newLoc.GetType() == InventoryLocationType.ATTACHMENT)
				m_Positive = true;
			else
				m_Positive = false;
		}
		if (m_TurnOnOff)
		{
			if (HasEnergyManager() && GetCompEM().CanWork())
				GetCompEM().SwitchOn();
		}
		else
		{
			if (HasEnergyManager() && GetCompEM().IsWorking())
				GetCompEM().SwitchOff();
		}
	}
	void Bleeding(PlayerBase player, int chance = 100, bool status = true)
	{
		if (CalculateChance(chance) && m_Tick >= 60)
		{
			BleedingSourcesManagerServer bleedingSourcesManagerServer = player.GetBleedingManagerServer();
			if (bleedingSourcesManagerServer)
			{
				if (status)
					player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingZones.GetRandomElement());
				else
					player.GetBleedingManagerServer().RemoveMostSignificantBleedingSource();
			}
		}
	}
	void BrokenLegs(PlayerBase player, int chance = 100, bool status = true)
	{
		if (CalculateChance(chance) && m_Tick >= 60)
		{
			if (status)
			{
				player.SetHealth("RightLeg", "", 0);
				player.SetHealth("RightFoot", "", 0);
				player.SetHealth("LeftLeg", "", 0);
				player.SetHealth("LeftFoot", "", 0);
				if (player.GetHealth("RightLeg", "Health") <= 1 || player.GetHealth("LeftLeg", "Health") <= 1 || player.GetHealth("RightFoot", "Health") <= 1 || player.GetHealth("LeftFoot", "Health") <= 1)
				{
					if (player.GetModifiersManager().IsModifierActive(eModifiers.MDF_BROKEN_LEGS))
						player.GetModifiersManager().DeactivateModifier(eModifiers.MDF_BROKEN_LEGS);
					player.GetModifiersManager().ActivateModifier(eModifiers.MDF_BROKEN_LEGS);
				}
			}
			else
			{
				player.SetHealth("RightLeg", "", 100);
				player.SetHealth("RightFoot", "", 100);
				player.SetHealth("LeftLeg", "", 100);
				player.SetHealth("LeftFoot", "", 100);
			}
		}
	}
}