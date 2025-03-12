modded class PlayerBase
{
	private string m_SteamID;
	override void OnConnect()
	{
		super.OnConnect();
		if (GetIdentity())
			m_SteamID = GetIdentity().GetPlainId();
	}
	string GetSteamID() return m_SteamID;
	bool IsPersonalChestExists()
	{
		return GetPersonalChestReader().IsPersonalChestExist(this);
	}
	void RemovePersonalChest()
	{
		if (IsPersonalChestExists())
			GetPersonalChestReader().SaveChestToConfig(this);
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		switch (rpc_type)
		{
		case X18PersonalChestERPCs.REMOVE_CHEST_RPC:
			RemovePersonalChest();
			break;
		}
	}
	override void OnDisconnect()
	{
		super.OnDisconnect();
		RemovePersonalChest();
	}
}