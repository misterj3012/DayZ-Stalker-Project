modded class ActionZenWritePaper
{
	override void OnStartServer(ActionData action_data)
	{
		Paper paper = Paper.Cast(action_data.m_MainItem);
		if (!paper)
			paper = Paper.Cast(action_data.m_Target.GetObject());

		Pen_ColorBase pen = Pen_ColorBase.Cast(action_data.m_MainItem);
		if (!pen)
			pen = Pen_ColorBase.Cast(action_data.m_Target.GetObject());

		if (!paper || !pen)
			return;

		if (GetZenNotesConfig().PenConsumeQuantity > 0)
		{
			paper.SetPen(pen);
		}

		if (GetZenNotesConfig().NoteDateFormat.Format == 0)
		{
			return;
		}

		Param1<string> data = new Param1<string>(GetZenNotesConfig().GetDate());
		paper.RPCSingleParam(ZENNOTERPCs.RECEIVE_NOTE_DATE, data, true, action_data.m_Player.GetIdentity());
	}
};