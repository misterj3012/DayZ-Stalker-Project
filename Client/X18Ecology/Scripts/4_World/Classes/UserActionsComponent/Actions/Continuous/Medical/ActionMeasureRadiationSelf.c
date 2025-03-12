class ActionMeasureRadiationSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.COLLECT_SAMPLE);
	}
};
class ActionMeasureRadiationSelf : ActionContinuousBase
{
	void ActionMeasureRadiationSelf()
	{
		m_CallbackClass = ActionMeasureRadiationSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAG;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	override string GetText()
	{
		return "#measure_persons_radiation";
	}
	override bool HasTarget()
	{
		return false;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		GeigerCounter_Base m_GeigerCounter = GeigerCounter_Base.Cast(item);
		if (!m_GeigerCounter)
			return false;
		if (m_GeigerCounter.HasEnergyManager() && m_GeigerCounter.GetCompEM().IsWorking())
			return true;
		return false;
	}
};