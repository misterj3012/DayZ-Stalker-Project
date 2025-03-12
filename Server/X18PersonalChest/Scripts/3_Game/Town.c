modded class Town
{
	override static array<ref Town> GetMapTowns(ExtendedTownFlags flags = 3, string world_name = "")
	{
		if (world_name == string.Empty) {
			GetGame().GetWorldName(world_name);
		}
		array<ref Town> town_positions = {};
		string cfg = "CfgWorlds " + world_name + " Names";
		for (int i = 0; i < GetGame().ConfigGetChildrenCount(cfg); i++)
		{
			string city;
			GetGame().ConfigGetChildName(cfg, i, city);
			vector city_position;
			TFloatArray float_array = {};
			GetGame().ConfigGetFloatArray(string.Format("%1 %2 position", cfg, city), float_array);
			city_position[0] = float_array[0]; city_position[2] = float_array[1];
			city_position[1] = GetGame().SurfaceY(city_position[0], city_position[2]);
			ExtendedTownFlags flag = GetTownFlag(GetGame().ConfigGetTextOut(string.Format("%1 %2 type", cfg, city)));
			if ((flags & flag) != flag)
				continue;
			if (flag == 0)
				continue;
			Town town_entry();
			town_entry.Entry = city;
			town_entry.Type = flag;
			town_entry.Name = GetGame().ConfigGetTextOut(string.Format("%1 %2 name", cfg, city));
			town_entry.Position = city_position;
			town_positions.Insert(town_entry);
		}
		return town_positions;
	}
	override static string GetTownTypeString(ExtendedTownFlags flag)
	{
		switch (flag) {
		case ExtendedTownFlags.CAPITAL: return "Capital";
		case ExtendedTownFlags.CITY: 	return "City";
		case ExtendedTownFlags.VILLAGE: return "Village";
		case ExtendedTownFlags.CAMP: 	return "Camp";
		case ExtendedTownFlags.LOCAL: 	return "Local";
		case ExtendedTownFlags.HILL: 	return "Hill";
		case ExtendedTownFlags.MARINE: 	return "Marine";
		case ExtendedTownFlags.RUIN: 	return "Ruin";
		case ExtendedTownFlags.RAILROAD:return "RailroadStation";
		case ExtendedTownFlags.OFFICE: 	return "LocalOffice";
		case ExtendedTownFlags.VIEWPOINT:return "ViewPoint";
		case ExtendedTownFlags.BIGMILITARY: return "BigMilitary";
		case ExtendedTownFlags.MEDIUMMILITARY: return "MediumMilitary";
		case ExtendedTownFlags.SMALLMILITARY: return "SmallMilitary";
		case ExtendedTownFlags.INDUSTRIALSITE: return "IndustrialSite";
		case ExtendedTownFlags.BORDERCROSSING: return "BorderCrossing";
		case ExtendedTownFlags.BAR: return "Bar";
		case ExtendedTownFlags.LAB: return "Lab";
		case ExtendedTownFlags.FACTORY: return "Factory";
		case ExtendedTownFlags.PERSONALCHEST: return "PersonalChest";
		}
		return string.Empty;
	}
	override static int GetTownFlag(string town_type)
	{
		town_type.Replace("Name", "");
		switch (town_type) {
		case "Capital": 	return ExtendedTownFlags.CAPITAL;
		case "City": 		return ExtendedTownFlags.CITY;
		case "Village": 	return ExtendedTownFlags.VILLAGE;
		case "Camp": 		return ExtendedTownFlags.CAMP;
		case "Local": 		return ExtendedTownFlags.LOCAL;
		case "Hill": 		return ExtendedTownFlags.HILL;
		case "Marine": 		return ExtendedTownFlags.MARINE;
		case "Ruin": 		return ExtendedTownFlags.RUIN;
		case "RailroadStation": return ExtendedTownFlags.RAILROAD;
		case "LocalOffice": return ExtendedTownFlags.OFFICE;
		case "ViewPoint": 	return ExtendedTownFlags.VIEWPOINT;
		case "BigMilitary": 	return ExtendedTownFlags.BIGMILITARY;
		case "MediumMilitary": 	return ExtendedTownFlags.MEDIUMMILITARY;
		case "SmallMilitary": 	return ExtendedTownFlags.SMALLMILITARY;
		case "IndustrialSite": 	return ExtendedTownFlags.INDUSTRIALSITE;
		case "BorderCrossing": 	return ExtendedTownFlags.BORDERCROSSING;
		case "Bar": 	return ExtendedTownFlags.BAR;
		case "Lab": 	return ExtendedTownFlags.LAB;
		case "Factory": 	return ExtendedTownFlags.FACTORY;
		case "PersonalChest": 	return ExtendedTownFlags.PERSONALCHEST;
		}
		return 0;
	}
}