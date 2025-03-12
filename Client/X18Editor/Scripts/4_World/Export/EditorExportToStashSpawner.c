class EditorExportToStashSpawner : EditorExportCommandBase
{
	override typename GetFileType()
	{
		return EditorStashSpawnerFile;
	}

	override string GetName()
	{
		return "Exportieren zu Stash Spawner (*.ssf)";
	}
}