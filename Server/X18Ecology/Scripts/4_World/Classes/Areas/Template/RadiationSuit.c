class RadiationSuit
{
	ref array<ref RadiationSuitItem> Headgear = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Mask = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Body = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Vest = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Back = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Gloves = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Legs = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> Feet = new ref array<ref RadiationSuitItem>;
	ref array<ref RadiationSuitItem> GetItems(string slot)
	{
		switch (slot)
		{
			case "Headgear":
				{
					return Headgear;
					break;
				}
			case "Mask":
				{
					return Mask;
					break;
				}
			case "Body":
				{
					return Body;
					break;
				}
			case "Vest":
				{
					return Vest;
					break;
				}
			case "Back":
				{
					return Back;
					break;
				}
			case "Gloves":
				{
					return Gloves;
					break;
				}
			case "Legs":
				{
					return Legs;
					break;
				}
			case "Feet":
				{
					return Feet;
					break;
				}
		}
		return null;
	}
};
class RadiationSuitItem
{
	string className;
	int shield;
};