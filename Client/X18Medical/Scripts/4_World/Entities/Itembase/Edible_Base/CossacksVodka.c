class X18_Drinks_CossacksVodka : Bottle_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDrinkVodka);
		AddAction(ActionForceDrinkVodka);
		RemoveAction(ActionWashHandsItem);
		RemoveAction(ActionDrink);
		RemoveAction(ActionForceDrink);
	}
};