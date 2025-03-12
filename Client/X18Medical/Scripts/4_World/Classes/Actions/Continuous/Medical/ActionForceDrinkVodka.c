class ActionForceDrinkVodkaCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.DRINK, UATimeSpent.DEFAULT);
	}
};
class ActionForceDrinkVodka : ActionConsume
{
	void ActionForceDrinkVodka()
	{
		m_CallbackClass = ActionForceDrinkVodkaCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
	override string GetText()
	{
		return "#give_drink";
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item && item.GetQuantity() <= 0.01)
			return false;
		return true;
	}
};