class ActionOpenPDACB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		EnableStateChangeCallback();
		m_ActionData.m_ActionComponent = new CAContinuousTime(-1.0);
	}
};

class ActionOpenPDA : ActionContinuousBase
{
	void ActionOpenPDA()
	{
		m_CallbackClass = ActionOpenPDACB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
	}
	override bool IsInstant()
	{
		return true;
	}
	override bool HasTarget()
	{
		return false;
	}
	override bool UseMainItem()
	{
		return true;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	override typename GetInputType()
	{
		return TogglePDAActionInput;
	}
	override string GetText()
	{
		return "#openpda";
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (UseMainItem() && MainItemAlwaysInHands())
		{
			if (player.GetItemInHands() != item)
				return false;
			else
			{
				X18_PDA m_PDA;;
				if (Class.CastTo(m_PDA, item) && m_PDA.HasEnergyManager() && m_PDA.GetCompEM().IsWorking())
					return true;
				return false;
			}

		}
		return false;
	}
	override void Start(ActionData action_data)
	{
		super.Start(action_data);

		PluginPDA m_PluginPDA;
		if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && !m_PluginPDA.IsOpen())
			m_PluginPDA.Open();
	}

	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			PluginPDA m_PluginPDA = PluginPDA.Cast(GetPlugin(PluginPDA));
			if (Class.CastTo(m_PluginPDA, GetPlugin(PluginPDA)) && m_PluginPDA.IsOpen() && action_data.m_State == UA_FINISHED)
				ActionManagerClient.Cast(action_data.m_Player.GetActionManager()).RequestEndAction();
		}
	}

	override void OnEndRequest(ActionData action_data)
	{
		if (action_data.m_Callback)
			action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
	}
};