class StashLoot
{
	ref array <ref StashItems> Items = new array <ref StashItems>;
}
class StashItems
{
	ref StashItem Item = new StashItem;
	ref array <ref StashItem> ItemAttachments = new array <ref StashItem>;
}
class StashItem
{
	string ClassName = "ClassName";
	int Quantity = 1;
	float SpawnChance = 100.0;
	string Damaged = "Random";
	float Wet = 30;
	float Temperature = 30;
	bool IsStacked = 0;
	float CountStack = 30;
	string MeatFoodStage = "RAW";
}