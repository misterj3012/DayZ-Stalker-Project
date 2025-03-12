modded class EditorCommandManager
{
	void Init()
	{
		super.Init();
		RegisterCommand(EditorExportToAnomalySpawner);
		RegisterCommand(EditorImportFromAnomalySpawner);
		RegisterCommand(EditorExportToStashSpawner);
		RegisterCommand(EditorImportFromStashSpawner);
	}
}