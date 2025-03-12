class AreasMainList : Managed
{
	ref array<ref AreasList> AreaList = new ref array<ref AreasList>;
};
class AreasList : Managed
{
	string Type;
	string Name;
	ref AreaConfig AreaDetails = new ref AreaConfig;
};
class AreaConfig
{
	vector Position = "0 0 0";
	int RadiusOfArea;
	int StrengthOfArea;
};