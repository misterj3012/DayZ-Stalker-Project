class EditorStashSpawnerFile : EditorFileType
{
	StashArea LoadBinFile(string file)
	{
		StashArea save_data = new StashArea();
		if (!FileExist(file))
		{
			EditorLog.Error("File not found %1", file);
			return save_data;
		}
		FileSerializer file_serializer = new FileSerializer();
		if (!file_serializer.Open(file, FileMode.READ))
		{
			EditorLog.Error("File in use %1", file);
			return save_data;
		}
		if (!save_data.Read(file_serializer))
		{
			file_serializer.Close();
			EditorLog.Error("Could not read file %1", file);
			return save_data;
		}
		file_serializer.Close();
		return save_data;
	}
	override void Export(EditorSaveData data, string file, ExportSettings settings)
	{
		EditorLog.Trace("EditorStashSpawnerFile::Export");
		StashArea export_data = new StashArea();
		export_data.Stashes = {};
		foreach(EditorObjectData object_data : data.EditorObjects)
		{
			if (object_data.Type.Contains("Stashes"))
			{
				StashObject spawn_object = new StashObject();
				spawn_object.ClassName = object_data.Type;
				spawn_object.Position[0] = object_data.Position[0];
				spawn_object.Position[1] = object_data.Position[1];
				spawn_object.Position[2] = object_data.Position[2];
				spawn_object.Orientation[0] = object_data.Orientation[0];
				spawn_object.Orientation[1] = object_data.Orientation[1];
				spawn_object.Orientation[2] = object_data.Orientation[2];
				export_data.Stashes.Insert(spawn_object);
			}
			if (object_data.Type.Contains("HighRisk"))
			{
				StashObject spawn_object = new StashObject();
				spawn_object.ClassName = object_data.Type;
				spawn_object.Position[0] = object_data.Position[0];
				spawn_object.Position[1] = object_data.Position[1];
				spawn_object.Position[2] = object_data.Position[2];
				spawn_object.Orientation[0] = object_data.Orientation[0];
				spawn_object.Orientation[1] = object_data.Orientation[1];
				spawn_object.Orientation[2] = object_data.Orientation[2];
				export_data.Stashes.Insert(spawn_object);
			}
		}
		FileSerializer file_serializer = new FileSerializer();
		if (!file_serializer.Open(file, FileMode.WRITE))
		{
			EditorLog.Error("Failed to open file %1", file);
			return;
		}
		export_data.Write(file_serializer);
		file_serializer.Close();
	}
	override EditorSaveData Import(string file, ImportSettings settings)
	{
		EditorLog.Trace("EditorStashSpawnerFile::Import");
		EditorSaveData save_data = new EditorSaveData();
		StashArea import_data = new StashArea();
		if (!FileExist(file))
		{
			EditorLog.Error("File not found %1", file);
			return save_data;
		}
		if (EditorSaveData.IsBinnedFile(file))
		{
			import_data = LoadBinFile(file);
		}
		else
		{
			JsonFileLoader<StashArea>.JsonLoadFile(file, import_data);
		}
		if (import_data)
		{
			foreach(StashObject scene_object : import_data.Stashes)
			{
				save_data.EditorObjects.Insert(EditorObjectData.Create(scene_object.ClassName, Vector(scene_object.Position[0], scene_object.Position[1], scene_object.Position[2]), Vector(scene_object.Orientation[0], scene_object.Orientation[1], scene_object.Orientation[2]), 1, EditorObjectFlags.ALL));
			}
		}
		return save_data;
	}
	override string GetExtension()
	{
		return ".ssf";
	}
}