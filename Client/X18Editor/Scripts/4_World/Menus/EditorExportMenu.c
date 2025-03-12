modded class EditorExportMenu
{
	void EditorExportMenu()
	{
		EditorLog.Trace("EditorExportMenu");
		AddMenuButton(m_Editor.CommandManager[EditorExportToAnomalySpawner]);
		AddMenuButton(m_Editor.CommandManager[EditorExportToStashSpawner]);
	}
}