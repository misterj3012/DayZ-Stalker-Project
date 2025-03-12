modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionUseMediKitSelf);
		actions.Insert(ActionUseMediKitTarget);
		actions.Insert(ActionDrinkVodka);
		actions.Insert(ActionForceDrinkVodka);
	}
}