class EditorExportToAnomalySpawner : EditorExportCommandBase
{
	override typename GetFileType()
	{
		return EditorAnomalySpawnerFile;
	}

	override string GetName()
	{
		return "Exportieren zu Anomaly Spawner (*.asf)";
	}
}