modded class Paper
{
	private int m_NotePickupTries = 0;
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionWritePaper);
		AddAction(ActionZenWritePaper);
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (rpc_type == ZENNOTERPCs.RECEIVE_NOTE_DATE)
		{
			string serverDateData;
			Param1<string> client_params = new Param1<string>(serverDateData);
			if (ctx.Read(client_params))
			{
				if (client_params.param1 && client_params.param1 != "")
				{
					ZenNoteGUI.DATE_TEXT = client_params.param1;
					m_UpdateTries = 0;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateDateText, 250, false, client_params.param1);
				}
			}
			return;
		}
	}
	private void TakeNoteToHands(PlayerBase player, EntityAI item)
	{
		if (item && player && player.IsAlive() && !player.IsUnconscious() && !player.IsPlayerDisconnected())
		{
			InventoryLocation loc_src = new InventoryLocation;
			item.GetInventory().GetCurrentInventoryLocation(loc_src);
			InventoryLocation loc_dst = new InventoryLocation;
			loc_dst.Copy(loc_src);
			loc_dst.SetHands(player, item);
			player.ServerTakeToDst(loc_src, loc_dst);
			m_NotePickupTries++;
			if (m_NotePickupTries >= 5)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.TakeNoteToHands);
			}
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.TakeNoteToHands);
		}
	}
	int m_UpdateTries = 0;
	void UpdateDateText(string txt)
	{
		m_UpdateTries++;
		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		if (menu)
		{
			ZenNoteGUI noteMenu = ZenNoteGUI.Cast(menu);
			if (noteMenu)
			{
				noteMenu.SetDate(txt);
			}
		}
		else
			if (m_UpdateTries < 10)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateDateText, 250, false, txt);
			}
	}
}
class ReplacePaperWithNoteLambda extends ReplaceItemWithNewLambdaBase
{
	ref ZenNoteData m_NoteData;
	void ~ReplacePaperWithNoteLambda()
	{
		m_NoteData = NULL;
		delete m_NoteData;
	}
	void ReplacePaperWithNoteLambda(EntityAI old_item, string new_item_type, ZenNoteData data)
	{
		m_NoteData = data;
	}
	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
		X18_Note note = X18_Note.Cast(new_item);
		note.SetNoteData(m_NoteData);
		if (!note.GetParent())
		{
			note.SetOrientation(old_item.GetOrientation());
			note.SetPosition(old_item.GetPosition());
		}
		m_NoteData = NULL;
	}
}