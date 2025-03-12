modded class Paper
{
	Pen_ColorBase m_Pen;

	void ~Paper()
	{
		m_Pen = NULL;
	}

	void SetPen(Pen_ColorBase pen)
	{
		m_Pen = pen;
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (rpc_type == ZENNOTERPCs.SEND_WRITTEN_NOTE)
		{
			int highBits, lowBits;
			GetGame().GetPlayerNetworkIDByIdentityID(sender.GetPlayerId(), lowBits, highBits);
			PlayerBase player = PlayerBase.Cast(GetGame().GetObjectByNetworkId(lowBits, highBits));

			if (!player) 				return;

			ZenNoteData clientNoteData;
			Param1<ref ZenNoteData> server_params = new Param1<ref ZenNoteData>(clientNoteData);

			if (ctx.Read(server_params))
			{
				if (server_params.param1)
				{
					if (GetZenNotesConfig().IsBlacklisted(server_params.param1.m_NoteText))
					{
						ZenNotesLogger.Log("Blacklist", "[BLACKLIST] " + sender.GetName() + " (" + sender.GetPlainId() + ") @ " + this.GetPosition() + " tried to write: " + server_params.param1.m_NoteText);

						if (GetZenNotesConfig().SendPlayerWarning != "")
						{
							player.SendMessage(GetZenNotesConfig().SendPlayerWarning);
						}

						return;
					}

					ZenNoteData noteData = new ZenNoteData;
					noteData.m_FontIndex = server_params.param1.m_FontIndex;
					noteData.m_DateText = server_params.param1.m_DateText; 					noteData.m_NoteText = server_params.param1.m_NoteText;
					noteData.m_ARGBColour = server_params.param1.m_ARGBColour;

					if (this.GetQuantity() == 1)
					{
						ReplacePaperWithNoteLambda lambda = new ReplacePaperWithNoteLambda(this, "X18_Note", noteData);

						if (player.GetItemInHands() == this)
							player.ServerReplaceItemInHandsWithNew(lambda);
						else
							player.ServerReplaceItemWithNew(lambda);
					}
					else
					{
						this.SetQuantity(this.GetQuantity() - 1);

						X18_Note noteGround = X18_Note.Cast(GetGame().CreateObjectEx("X18_Note", this.GetPosition(), ECE_PLACE_ON_SURFACE));

						if (!noteGround)
							return;

						noteGround.SetNoteData(noteData);

						if (player.GetItemInHands() == this && noteGround)
						{
							HumanInventory inventory = player.GetHumanInventory();

							if (!inventory)
								return;

							InventoryLocation loc_dst = new InventoryLocation;
							int reservedIndex = inventory.FindUserReservedLocationIndex(this);
							inventory.GetUserReservedLocation(reservedIndex, loc_dst);

							InventoryLocation loc_src = new InventoryLocation;
							this.GetInventory().GetCurrentInventoryLocation(loc_src);

							if (reservedIndex == -1 || !player.ServerTakeToDst(loc_src, loc_dst))
							{
								player.ServerTakeEntityToInventory(FindInventoryLocationType.ANY_CARGO, this);
							}

							m_NotePickupTries = 0;

							GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TakeNoteToHands, 200, true, player, noteGround);
						}
					}

					if (GetZenNotesConfig().PenConsumeQuantity > 0 && m_Pen)
					{
						m_Pen.SetQuantity(m_Pen.GetQuantity() - GetZenNotesConfig().PenConsumeQuantity);
					}

					ZenNotesLogger.Log("General", sender.GetName() + " (" + sender.GetPlainId() + ") @ " + this.GetPosition() + " wrote: " + noteData.m_NoteText);
				}
			}
		}
	}
}