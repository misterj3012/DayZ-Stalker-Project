modded class ActionOpenPersonalChest : ActionInteractBase
{
	override void OnExecuteServer(ActionData action_data)
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player)
		{
			if (!player.IsPersonalChestExists())
				GetPersonalChestReader().ReadChestFromConfig(player);
		}
	}
}