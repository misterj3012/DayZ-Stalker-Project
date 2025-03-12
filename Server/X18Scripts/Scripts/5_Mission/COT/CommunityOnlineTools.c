modded class CommunityOnlineTools
{
	override private void RPC_Active(ref ParamsReadContext ctx, PlayerIdentity senderRPC, Object target)
	{
		bool active;
		if (!ctx.Read(active))
			return;

		JMPlayerInstance instance = GetPermissionsManager().GetPlayer(senderRPC.GetId());

		PlayerBase m_Player = GetPlayerObjectByIdentity(senderRPC);
		m_Player.SetAdmin(active);

		auto message = m_Webhook.CreateDiscordMessage();

		if (active)
			message.GetEmbed().AddField("Admin Activity", "" + instance.FormatSteamWebhook() + " has activated Community Online Tools");
		else
			message.GetEmbed().AddField("Admin Activity", "" + instance.FormatSteamWebhook() + " has de-activated Community Online Tools");

		m_Webhook.Post("AdminActive", message);
	}
}