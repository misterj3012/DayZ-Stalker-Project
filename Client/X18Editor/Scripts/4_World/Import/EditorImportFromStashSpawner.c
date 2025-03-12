class EditorImportFromStashSpawner : EditorImportCommandBase
{
	override typename GetFileType()
	{
		return EditorStashSpawnerFile;
	}

	override string GetName()
	{
		return "Importiere von Stash Spawner (*.ssf)";
	}
}