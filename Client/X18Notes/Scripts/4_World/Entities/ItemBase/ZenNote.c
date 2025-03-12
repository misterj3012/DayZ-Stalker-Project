class X18_Note extends Paper
{
	protected ref ZenNoteData m_ZenNoteData;
	override string GetTooltip()
	{
		if (m_ZenNoteData && m_ZenNoteData.m_NoteText)
		{
			TStringArray lineArray = new TStringArray;
			m_ZenNoteData.m_NoteText.Split("\n", lineArray);
			string description = "";
			foreach(string s : lineArray)
			{
				description = description + s.Trim() + ". ";
			}
			description.Replace("  ", "");
			if (description.Length() > 280)
				description = description.Substring(0, 280);
			return description;
		}
		return ConfigGetString("descriptionShort");
	}
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionTakeItem);
		RemoveAction(ActionAttach);
		AddAction(ActionZenReadNoteHands);
		AddAction(ActionZenReadNoteTarget);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		Param1<ref ZenNoteData> params = new Param1<ref ZenNoteData>(m_ZenNoteData);
		if (rpc_type == ZENNOTERPCs.RECEIVE_WRITTEN_NOTE)
		{
			if (ctx.Read(params))
			{
				if (params.param1)
				{
					m_ZenNoteData = params.param1;
					ZenNoteGUI gui = ZenNoteGUI.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_ZEN_NOTE_GUI, NULL));
					if (gui)
					{
						gui.SetNoteData(m_ZenNoteData);
						gui.SetReadOnly(true);
					}
				}
			}
		}
	}
	ZenNoteData GetNoteData()
	{
		return m_ZenNoteData;
	}
	void SetNoteData(ZenNoteData data)
	{
		m_ZenNoteData = data;
	}
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;
		if (!ctx.Read(m_ZenNoteData))
			return false;
		return true;
	}
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_ZenNoteData);
	}
};