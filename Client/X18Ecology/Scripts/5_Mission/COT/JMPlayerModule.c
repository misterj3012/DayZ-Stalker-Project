#ifdef JM_COT
enum X18_JMPlayerModuleRPC : JMPlayerModuleRPC
{
	SetRadiation,
	SetRadiationSickStage
}

modded class JMPlayerModule
{
	void JMPlayerModule()
	{
		GetPermissionsManager().RegisterPermission("Admin.Player.Set.Radiation");
		GetPermissionsManager().RegisterPermission("Admin.Player.Set.RadiationSickStage");
	}

	override private void Exec_Heal(array< string > guids, PlayerIdentity ident, JMPlayerInstance instance = NULL)
	{
		array< JMPlayerInstance > players = GetPermissionsManager().GetPlayers(guids);

		for (int i = 0; i < players.Count(); i++)
		{
			PlayerBase player = PlayerBase.Cast(players[i].PlayerObject);
			if (player == NULL)
				continue;

			if (player.GetBleedingManagerServer())
				player.GetBleedingManagerServer().RemoveAllSources();

			player.SetHealth("GlobalHealth", "Health", player.GetMaxHealth("GlobalHealth", "Health"));
			player.SetHealth("GlobalHealth", "Blood", player.GetMaxHealth("GlobalHealth", "Blood"));
			player.SetHealth("GlobalHealth", "Shock", player.GetMaxHealth("GlobalHealth", "Shock"));
			player.SetHealth("RightLeg", "Health", 100);
			player.SetHealth("LeftLeg", "Health", 100);
			player.UpdateBrokenLegs(eBrokenLegs.NO_BROKEN_LEGS);
			player.GetStatRadiation().Set(0);
			player.SetRadiationSickStage(0);
			player.RemoveAllAgents();

			player.GetStatEnergy().Set(player.GetStatEnergy().GetMax());
			player.GetStatWater().Set(player.GetStatWater().GetMax());

			GetCommunityOnlineToolsBase().Log(ident, "Healed [guid=" + players[i].GetGUID() + "]");

			SendWebhook("Set", instance, "Healed " + players[i].FormatSteamWebhook());

			players[i].Update();
		}
	}
	void SetRadiation(float radiation, array< string > guids)
	{
		if (IsMissionHost())
		{
			Exec_SetRadiation(radiation, guids, NULL);
		}
		else
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(radiation);
			rpc.Write(guids);
			rpc.Send(NULL, X18_JMPlayerModuleRPC.SetRadiation, true, NULL);
		}
	}
	private void Exec_SetRadiation(float radiation, array< string > guids, PlayerIdentity ident, JMPlayerInstance instance = NULL)
	{
		array< JMPlayerInstance > players = GetPermissionsManager().GetPlayers(guids);

		for (int i = 0; i < players.Count(); i++)
		{
			PlayerBase player = PlayerBase.Cast(players[i].PlayerObject);
			if (player == NULL)
				continue;

			player.GetStatRadiation().Set(radiation);

			GetCommunityOnlineToolsBase().Log(ident, "Set Radiation To " + radiation + " [guid=" + players[i].GetGUID() + "]");

			SendWebhook("Set", instance, "Set " + players[i].FormatSteamWebhook() + " Radiation to " + radiation);

			players[i].Update();
		}
	}
	private void RPC_SetRadiation(ref ParamsReadContext ctx, PlayerIdentity senderRPC, Object target)
	{
		float radiation;
		if (!ctx.Read(radiation))
			return;

		array< string > guids;
		if (!ctx.Read(guids))
			return;

		JMPlayerInstance instance;
		if (!GetPermissionsManager().HasPermission("Admin.Player.Set.Radiation", senderRPC, instance))
			return;

		Exec_SetRadiation(radiation, guids, senderRPC, instance);
	}
	void SetRadiationSickStage(int radiationSickStage, array< string > guids)
	{
		if (IsMissionHost())
		{
			Exec_SetRadiationSickStage(radiationSickStage, guids, NULL);
		}
		else
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(radiationSickStage);
			rpc.Write(guids);
			rpc.Send(NULL, X18_JMPlayerModuleRPC.SetRadiationSickStage, true, NULL);
		}
	}
	private void Exec_SetRadiationSickStage(int radiationSickStage, array< string > guids, PlayerIdentity ident, JMPlayerInstance instance = NULL)
	{
		array< JMPlayerInstance > players = GetPermissionsManager().GetPlayers(guids);

		for (int i = 0; i < players.Count(); i++)
		{
			PlayerBase player = PlayerBase.Cast(players[i].PlayerObject);
			if (player == NULL)
				continue;

			player.SetRadiationSickStage(radiationSickStage);

			GetCommunityOnlineToolsBase().Log(ident, "Set RadiationSickStage To " + radiationSickStage + " [guid=" + players[i].GetGUID() + "]");

			SendWebhook("Set", instance, "Set " + players[i].FormatSteamWebhook() + " RadiationSickStage to " + radiationSickStage);

			players[i].Update();
		}
	}
	private void RPC_SetRadiationSickStage(ref ParamsReadContext ctx, PlayerIdentity senderRPC, Object target)
	{
		int radiationSickStage;
		if (!ctx.Read(radiationSickStage))
			return;

		array< string > guids;
		if (!ctx.Read(guids))
			return;

		JMPlayerInstance instance;
		if (!GetPermissionsManager().HasPermission("Admin.Player.Set.RadiationSickStage", senderRPC, instance))
			return;

		Exec_SetRadiationSickStage(radiationSickStage, guids, senderRPC, instance);
	}
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ref ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);
		switch (rpc_type)
		{
		case X18_JMPlayerModuleRPC.SetRadiation:
			RPC_SetRadiation(ctx, sender, target);
			break;
		case X18_JMPlayerModuleRPC.SetRadiationSickStage:
			RPC_SetRadiationSickStage(ctx, sender, target);
			break;
		}
	}
}
#endif