class HeatmapData
{
	static ref HeatmapData CURRENT_HEATMAP = new HeatmapData();
	ref map<string, ref array<vector>> m_WayPoints = new map<string, ref array<vector>>;
	ref array<vector> m_DeathPoints = new array<vector>;
	private void HeatmapData() {}
}