modded class DayZGame
{
	static float HEATMAP_TICK_TIME = 30;
	static float HEATMAP_TICK_TIME_VEHICLE = 30.0;
	override void GlobalsInit()
	{
		super.GlobalsInit();
		int ticktime = GetGame().ServerConfigGetInt("heatmapTickTime");
		if (ticktime != 0)
			HEATMAP_TICK_TIME = ticktime;
		ticktime = GetGame().ServerConfigGetInt("heatmapTickTimeVehicle");
		if (ticktime != 0)
			HEATMAP_TICK_TIME_VEHICLE = ticktime;
	}
}