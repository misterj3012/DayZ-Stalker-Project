class ActionDrinkVodkaCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.DRINK, UATimeSpent.DEFAULT);
	}
};
class ActionDrinkVodka : ActionConsume
{
	void ActionDrinkVodka()
	{
		m_CallbackClass = ActionDrinkVodkaCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DRINK;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_DRINK;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	override bool IsDrink()
	{
		return true;
	}
	override bool HasTarget()
	{
		return false;
	}
	override string GetText()
	{
		return "#drink";
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item && item.GetQuantity() <= 0.01)
			return false;
		return true;
	}
};