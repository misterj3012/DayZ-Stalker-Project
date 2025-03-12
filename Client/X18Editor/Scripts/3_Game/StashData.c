class StashArea
{
	[NonSerialized()]
	static const string BIN_CHECK = "EditorBinned";

	static const int Version = 3;
	ref array <ref StashObject> Stashes = new ref array <ref StashObject>;

	void Write(Serializer serializer)
	{
		serializer.Write(BIN_CHECK);
		serializer.Write(Version);

		serializer.Write(Stashes.Count());
		foreach(StashObject data : Stashes)
		{
			data.Write(serializer, Version);
		}
	}

	bool Read(Serializer serializer)
	{
		string bincheck;
		serializer.Read(bincheck);
		if (bincheck != BIN_CHECK)
			return false;

		int read_version;
		serializer.Read(read_version);

		int stashes_count;
		serializer.Read(stashes_count);
		for (int i = 0; i < stashes_count; i++)
		{
			StashObject data();
			data.Read(serializer, read_version);
			Stashes.Insert(data);
		}
		return true;
	}

	static bool IsBinnedFile(string file)
	{
		FileSerializer serializer();

		if (!serializer.Open(file))
			return false;

		string bincheck;
		if (!serializer.Read(bincheck))
		{
			serializer.Close();
			return false;
		}

		serializer.Close();

		return (bincheck == BIN_CHECK);
	}
}
class StashObject : SerializableBase
{
	string ClassName = "";
	vector Position = "0 0 0";
	vector Orientation = "0 0 0";

	override void Write(Serializer serializer, int version)
	{
		serializer.Write(ClassName);
		serializer.Write(Position);
		serializer.Write(Orientation);

		if (version < 2)
			return;
	}

	override bool Read(Serializer serializer, int version)
	{
		serializer.Read(ClassName);
		serializer.Read(Position);
		serializer.Read(Orientation);

		if (version < 2)
			return true;

		return true;
	}
}