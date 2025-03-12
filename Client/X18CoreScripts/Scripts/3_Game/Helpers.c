bool IsPlayerInRange(vector objectPosition, float radius)
{
	array<Man> v_Players = new array<Man>;
	GetGame().GetPlayers(v_Players);
	for (int i = 0; i < v_Players.Count(); ++i)
	{
		Man player = v_Players.Get(i);
		if (player)
		{
			if (Distance2D(v_Players[i].GetPosition(), objectPosition) <= radius)
				return true;
		}
	}
	return false;
}
static float Distance2D(vector v_PointA, vector v_PointB)
{
	return Math.Sqrt(Math.Pow((v_PointA[0] - v_PointB[0]), 2) + Math.Pow((v_PointA[2] - v_PointB[2]), 2));
}
static bool InDistance(vector v_PointA, vector v_PointB, float radius)
{
	if (Distance2D(v_PointA, v_PointB) <= radius)
		return true;
	return false;
}
string GetTime(bool utc = false)
{
	return CF_Date.Now(utc).ToString("hh:mm:ss");
}
string GetDate(bool utc = false)
{
	return CF_Date.Now(utc).ToString("DD.MM.YYYY");
}
string GetDateTime(bool utc = false)
{
	return CF_Date.Now(utc).DateToString();
}
void PrintLog(string text, string logText = "Default")
{
	Print(GetDateTime() + " [" + logText + "] " + text);
}
void PrintDebugLog(string text, string logText = "Default")
{
	Print(GetDateTime() + "[DEBUG][" + logText + "] " + text);
}
vector GetRandomPosition(float x = 5250, float z = 5250, float radius = 7000)
{
	vector position;
	position[0] = Math.RandomInt(x - radius, x + radius);
	position[2] = Math.RandomInt(z - radius, z + radius);
	position[1] = GetGame().SurfaceY(position[0], position[2]) + 1;

	if (GetGame().SurfaceIsSea(position[0], position[2]) || GetGame().SurfaceIsPond(position[0], position[2]))
		return GetRandomPosition(x, z, radius);

	return position;
}
vector GetRandomPositionAtSameHeight(float x = 5250, float y = 50, float z = 5250, float minRadius = 1, float maxRadius = 5, float height = 0)
{
	vector position;
	position[0] = Math.RandomFloat(x + Math.RandomFloat(-minRadius, minRadius), x + Math.RandomFloat(-maxRadius, maxRadius));
	position[1] = y + height;
	position[2] = Math.RandomFloat(z + Math.RandomFloat(-minRadius, minRadius), z + Math.RandomFloat(-maxRadius, maxRadius));
	return position;
}
vector RandomizeVector(vector in, float rand)
{
	for (int i = 0; i < 3; i++)
	{
		in[i] = Math.RandomFloat(in[i] - rand, in[i] + rand);
	}
	return in;
}
vector RandomizeVector(vector in, float min, float max)
{
	for (int i = 0; i < 3; i++)
	{
		in[i] = Math.RandomFloat(in[i] + Math.RandomFloat(-min, min), in[i] + Math.RandomFloat(-max, max));
	}
	return in;
}

vector RandomizeVectorXZ(vector in, float min, float max)
{
	vector position = in;
	while (InDistance(position, in, min))
	{
		in[0] = Math.RandomFloat(in[0] + Math.RandomFloat(-min, min), in[0] + Math.RandomFloat(-max, max));
		in[2] = Math.RandomFloat(in[2] + Math.RandomFloat(-min, min), in[2] + Math.RandomFloat(-max, max));
		in[1] = GetGame().SurfaceY(in[0], in[2]) + 1;
	}
	return in;
}
vector RoundFloat(vector in)
{
	for (int i = 0; i < 3; i++)
	{
		in[i] = (Math.Round(in[i] * 100000) / 100000);
	}
	return in;
}
string MakeStringSafe(string safeString)
{
	string m_String = safeString;
	m_String.Replace(",", "");
	string m_String2 = m_String;
	m_String2.Replace("\n", "");
	return m_String2;
}
static bool CalculateChance(float chance)
{
	private bool ret_value = false;
	private float max_procents_can_be = 100.0;
	private float min_procents_can_be = 0.0;
	private float generated_procents = Math.RandomFloatInclusive(min_procents_can_be, max_procents_can_be);
	chance = max_procents_can_be - chance;
	if (generated_procents < chance)
		ret_value = false;
	else
		ret_value = true;
	return ret_value;
}
static float FindDegree(float x, float y)
{
	float value = (float)((Math.Atan2(x, y) / Math.PI) * 180);
	if (value < 0)
		value += 360;
	return value;
}
bool ItemHasQuantity(string itemClassname)
{
	return GetItemMaxQuantity(itemClassname) > 0;
}
int GetItemMaxQuantity(string itemClassname)
{
	string path = CFG_VEHICLESPATH + " " + itemClassname + " varQuantityMax";
	if (GetGame().ConfigIsExisting(path))
		return GetGame().ConfigGetInt(path);
	return -1;
}
bool ItemHasCount(string itemClassname)
{
	return GetItemCount(itemClassname) > 0;
}
int GetItemCount(string itemClassname)
{
	string path = CFG_MAGAZINESPATH + " " + itemClassname + " count";
	if (GetGame().ConfigIsExisting(path))
		return GetGame().ConfigGetInt(path);
	return -1;
}
bool HasQuantityBar(string itemClassname)
{
	string path = CFG_VEHICLESPATH + " " + itemClassname + " quantityBar";
	if (GetGame().ConfigIsExisting(path))
		return GetGame().ConfigGetInt(path) == 1;
	return false;
}
class Helpers
{
	protected static ref Helpers m_Instance;

	void Helpers()
	{
		if (!m_Instance)
			m_Instance = new Helpers();
		m_Instance = this;
	}

	static TStringArray CreateChunksFromString(string input, int chunkSize = 160)
	{
		Print("CreateChunksFromString whole length input: " + input.LengthUtf8());
		Print("CreateChunksFromString input: " + input);
		autoptr TStringArray chunks = new TStringArray;
		int chunksCount = input.LengthUtf8() / chunkSize;
		int lastChunkSize = input.LengthUtf8() - (chunksCount * chunkSize);
		for (int j = 0; j < chunksCount; j++)
		{
			chunks.Insert(input.SubstringUtf8(j * chunkSize, chunkSize));
		}
		chunks.Insert(input.SubstringUtf8(chunksCount * chunkSize, lastChunkSize));

		Print("CreateChunksFromString chunksCount: " + chunksCount);
		Print("CreateChunksFromString chunkSize: " + chunkSize);
		Print("CreateChunksFromString lastChunkSize: " + lastChunkSize);
		Print("CreateChunksFromString chunks: " + chunks);

		for (int i = 0; i < chunks.Count(); i++)
		{
			Print("ChunksPrint: " + chunks.Get(i));
		}

		return chunks;
	}

	static string CreateStringFromChunks(TStringArray input)
	{
		string dataString;
		if (input)
		{
			for (int i = 0; i < input.Count(); i++)
			{
				dataString = dataString + input.Get(i);
				Print("CreateStringFromChunks input: " + i);
				Print("CreateStringFromChunks dataString: " + dataString);
				Print("CreateStringFromChunks length dataString: " + dataString.LengthUtf8());
			}
		}
		Print("CreateStringFromChunks whole length dataString: " + dataString.LengthUtf8());
		Print("CreateStringFromChunks whole dataString: " + dataString);
		return dataString;
	}
}