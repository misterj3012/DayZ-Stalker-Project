modded class PlayerBase
{
	private bool m_IsPersonalOpened = false;
	private bool m_IsPersonalOpening = false;
	void SetPersonalOpening()
	{
		m_IsPersonalOpening = true;
	}
	bool IsPersonalOpeninig()
	{
		return m_IsPersonalOpening;
	}
	bool IsPersonalOpened()
	{
		return m_IsPersonalOpened;
	}
	void OpenPersonalInventory()
	{
		m_IsPersonalOpened = true;
		Mission mission = Mission.Cast(GetGame().GetMission());
		if (mission)
		{
			mission.ShowInventory();
			m_IsPersonalOpening = false;
		}
	}
	override void OnInventoryMenuClose()
	{
		super.OnInventoryMenuClose();
		if (m_IsPersonalOpened)
		{
			RPCSingleParam(X18PersonalChestERPCs.REMOVE_CHEST_RPC, null, true, GetIdentity());
			m_IsPersonalOpened = false;
		}
	}
}