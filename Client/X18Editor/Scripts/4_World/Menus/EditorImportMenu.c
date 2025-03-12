modded class EditorImportMenu
{
	void EditorImportMenu()
	{
		EditorLog.Trace("EditorImportMenu");
		AddMenuButton(m_Editor.CommandManager[EditorImportFromAnomalySpawner]);
		AddMenuButton(m_Editor.CommandManager[EditorImportFromStashSpawner]);
	}
}