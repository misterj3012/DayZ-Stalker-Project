modded class PlayerBase
{
	int IsInArea = -1;
	int Shield = 0;
	ref EcologySystem m_EcologySystem;
	ref RadiationSuit m_RadiationSuit;
	ref RadiationShieldHandler m_RadiationShieldHandler;
	override void Init()
	{
		super.Init();
		m_EcologySystem = new ref EcologySystem;
		m_RadiationShieldHandler = RadiationShieldHandler(this);
		m_RadiationSuit = new RadiationSuit;
	}
	override void OnConnect()
	{
		super.OnConnect();
		if (m_RadiationShieldHandler)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateRadiationShield, 10000);
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsServer())
		{
			switch (rpc_type) {
			case EcologyRPC.SETAREAVALUEONPLAYER:
			{
				Param2<int, float> areaData;
				if (!ctx.Read(areaData))
					break;

				switch (areaData.param1)
				{
				case -1:
					SetStrengthOfRadiation(areaData.param2);
					SetSynchDirty();
					break;
				case 0:
					SetStrengthOfRadiation(areaData.param2);
					SetSynchDirty();
					break;
				}
			}
			}
		}
	}
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		UpdateRadiationShield();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		UpdateRadiationShield();
	}
	void UpdateRadiationShield()
	{
		if ((GetGame().IsServer() && GetGame().IsMultiplayer()) && m_RadiationShieldHandler)
			m_RadiationShieldHandler.UpdateRadiationShield();
	}
	void SetIsInArea(int status)
	{
		IsInArea = status;
		SetSynchDirty();
	}
	void SetRadiationSickStage(int stage)
	{
		RadiationSickStage = stage;
		SetSynchDirty();
	}
	void SetStrengthOfRadiation(float value)
	{
		StrengthOfRadiation = value;
		SetSynchDirty();
	}
}
modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_High", "dz/anims/workspaces/player/player_main/props/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/battery_charger.anm");
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_Low", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/gear/flashlight.anm");
		pType.AddItemInHandsProfileIK("X18_Tools_GeigerCounter_Mid", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/gear/flashlight.anm");
	};
};