class ActionDismantleCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT / 2 );
	}
};

class ActionDismantle: ActionContinuousBase
{
	void ActionDismantle()
	{
		m_CallbackClass = ActionDismantleCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override string GetText()
	{
		return "Abbauen";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{				
			ItemBase myItem = ItemBase.Cast( targetObject );
			if(myItem){
				if(!myItem.IsInvEmpty()) return false;				
				if (myItem.IsInherited(X18_Item) || myItem.IsInherited(X18_Item_Storage))								
					return true;
			}
			
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		vector pos = action_data.m_Player.GetPosition();
		string name = "";
		ItemBase myItem = ItemBase.Cast( action_data.m_Target.GetObject() );
		if(myItem)
		{
			name = myItem.Get_KitName();
			myItem.Delete();
		}
		action_data.m_MainItem.DecreaseHealth( 5, false );		
		GetGame().CreateObjectEx(name, pos, ECE_PLACE_ON_SURFACE);
	}	
}