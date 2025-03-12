class ActionSearchStashCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		X18_StashesBase target = X18_StashesBase.Cast(m_ActionData.m_Target.GetObject());
		m_ActionData.m_ActionComponent = new CAContinuousTime(CalcTime(target));
	}
	float CalcTime(X18_StashesBase m_Stash)
	{
		float result = 3.0;
		if (m_Stash)
		{
			int num_items = m_Stash.GetNumberOfItems();
			for (int i = 0; i < num_items; ++i)
			{
				result += 0.25;
			}
		}
		return result;
	}
};
class ActionSearchStash : ActionContinuousBase
{
	void ActionSearchStash()
	{
		m_CallbackClass = ActionSearchStashCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_CRAFTING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_PRONE;
		//m_FullBody = true;
		m_Text = "Durchsuchen";
	}
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		X18_StashesBase ntarget = X18_StashesBase.Cast(target.GetObject());
		if (ntarget != NULL && !ntarget.CanInspect())
			return true;
		return false;
	}
	override void OnFinishProgressClient(ActionData action_data)
	{
		X18_StashesBase ntarget = X18_StashesBase.Cast(action_data.m_Target.GetObject());
		if (ntarget)
			ntarget.SetCanInspect();
	}
};