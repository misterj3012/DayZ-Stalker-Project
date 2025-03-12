class ActionPlaySinnerSoundShort : ActionSingleUseBase
{
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	override bool HasTarget()
	{
		return false;
	}
	override string GetText()
	{
		return "Play Sinner Sound Short";
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
}