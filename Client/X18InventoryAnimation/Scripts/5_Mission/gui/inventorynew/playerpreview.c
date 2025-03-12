modded class PlayerPreview
{
	protected HumanCommandActionCallback hcab;

	override void UpdateInterval()
	{
		UpdateViewAnimation();

		super.UpdateInterval();
	}

	protected void UpdateViewAnimation()
	{
		ItemBase hands = ItemBase.Cast(GetGame().GetPlayer().GetHumanInventory().GetEntityInHands());

		if (hcab && ((g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW) == 0 && !VIASettings.SETTINGS.forcePreview) || (hands && hands.IsHeavyBehaviour())))
		{
			hcab.Cancel();

			hcab = null;
		}
		else if ((g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW) || VIASettings.SETTINGS.forcePreview) && !hcab)
		{
			DayZPlayer dummyPlayer = m_CharacterPanelWidget.GetDummyPlayer();
			if (dummyPlayer && dummyPlayer.GetCommandModifier_Action() == null)
			{
				if (!hands || !hands.IsHeavyBehaviour())
				{
					hcab = dummyPlayer.AddCommandModifier_Action(DayZPlayerConstants.CMD_ACTIONMOD_SEARCHINVENTORY, HumanCommandActionCallback);
				}
			}
		}
	}
}