enum ViewInventoryStates
{
	WANTS_SYNC,
	PROCESSING
}

class ViewInventoryHandlerClient extends ViewInventoryHandlerBase
{
	protected ViewInventoryStates m_State = ViewInventoryStates.PROCESSING;
	protected bool m_IsViewingInventory = false;
	protected float m_SyncDelay = 0.0;

	void ViewInventoryHandlerClient(PlayerBase player)
	{
	}

	override void OnUpdate(int pCurrentCommandID, float pDt)
	{
		// check if inventory open state changed
		bool isViewingInventory = GetGame().IsInventoryOpen();
		if (isViewingInventory != m_IsViewingInventory)
		{
			m_IsViewingInventory = isViewingInventory;
			m_SyncDelay = pDt * -1.0;
		}

		// check if its time to sync
		if (m_IsViewingInventory != m_IsViewingInventorySynced)
		{
			m_SyncDelay += pDt;

			if (!m_IsViewingInventory && m_IsViewingInventorySynced)
			{
				// instantly sync closing of inventory
				m_State = ViewInventoryStates.WANTS_SYNC;
			}
			else if (m_SyncDelay >= VIASettings.SETTINGS.delay)
			{
				m_State = ViewInventoryStates.WANTS_SYNC;
			}
		}

		switch (m_State)
		{
		case ViewInventoryStates.WANTS_SYNC:
		{
			if (GetGame().IsClient() && GetGame().IsMultiplayer())
			{
				if (ScriptInputUserData.CanStoreInputUserData())
				{
					m_IsViewingInventorySynced = m_IsViewingInventory;

					ScriptInputUserData ctx = new ScriptInputUserData;
					ctx.Write(INPUT_UDT_VIEWINVENTORY);
					ctx.Write(m_IsViewingInventorySynced);
					ctx.Send();

					m_State = ViewInventoryStates.PROCESSING;
				}
			}
			else
			{
				m_IsViewingInventorySynced = m_IsViewingInventory;
				m_State = ViewInventoryStates.PROCESSING;
			}
			break;
		}
		default:
		{
			if (g_Game.GetVIAProfileVal(EVIAProfileOptions.ANIMATION) || VIASettings.SETTINGS.forceAnimation || !m_IsViewingInventorySynced)
			{
				super.OnUpdate(pCurrentCommandID, pDt);
			}
			break;
		}
		}
	}
}