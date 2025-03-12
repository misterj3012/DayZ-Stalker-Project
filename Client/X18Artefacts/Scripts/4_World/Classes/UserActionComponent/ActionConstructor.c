modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionChangeLocation);
		actions.Insert(ActionCreateSpaceAnomaly);
		actions.Insert(ActionTurnOnDetectorWhileInHands);
		actions.Insert(ActionTurnOffDetectorWhileInHands);
		actions.Insert(ActionOpenArtefactCharger);
		actions.Insert(ActionCloseArtefactCharger);
		actions.Insert(ActionTurnOnArtefactCharger);
		actions.Insert(ActionTurnOffArtefactCharger);
		actions.Insert(ActionTurnOnStorageLights);
		actions.Insert(ActionTurnOffStorageLights);
	}
};