class EditorImportFromAnomalySpawner : EditorImportCommandBase
{
	override typename GetFileType()
	{
		return EditorAnomalySpawnerFile;
	}

	override string GetName()
	{
		return "Importiere von Anomaly Spawner (*.asf)";
	}
}