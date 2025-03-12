modded class PlayerBase
{
	protected ref ViewInventoryHandlerBase m_ViewInventoryHandler;

	override void OnConnect()
	{
		super.OnConnect();

		RPCSingleParam(EVIARPCs.RPC_SETTINGS, new Param1<ref VIASettings>(VIASettings.SETTINGS), true, GetIdentity());
	}

#ifndef SERVER
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == EVIARPCs.RPC_SETTINGS)
		{
			Param1<VIASettings> param;
			if (ctx.Read(param))
			{
				VIASettings.SETTINGS = param.param1;
			}
		}
	}
#endif

	override void OnSelectPlayer()
	{
		super.OnSelectPlayer();

		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			m_ViewInventoryHandler = new ViewInventoryHandlerServer(this);
		}
		else
		{
			m_ViewInventoryHandler = new ViewInventoryHandlerClient(this);
		}
	}

	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		super.CommandHandler(pDt, pCurrentCommandID, pCurrentCommandFinished);

		if (m_ViewInventoryHandler)
		{
			m_ViewInventoryHandler.OnUpdate(pCurrentCommandID, pDt);
		}
	}

	override bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if (super.OnInputUserDataProcess(userDataType, ctx))
		{
			return true;
		}
		if (userDataType == INPUT_UDT_VIEWINVENTORY && m_ViewInventoryHandler)
		{
			return m_ViewInventoryHandler.OnInputUserDataProcess(ctx);
		}
		return false;
	}
}