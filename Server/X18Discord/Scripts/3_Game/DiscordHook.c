class DiscordHook
{
	ref map<string, string> m_alias;
	string m_DiscordMessagePath = GetDayZGame().GetX18Config().DiscordPath + "DiscordMessage.json";
	protected RestApi m_RestApi;
	void DiscordHook()
	{
		m_alias = new map<string, string>;
		if (!FileExist(m_DiscordMessagePath))
		{
			DiscordMessage m_DiscordMessage = CreateDiscordMessage();
			JsonFileLoader<DiscordMessage>.JsonSaveFile(m_DiscordMessagePath, m_DiscordMessage);
		}

		if (!m_RestApi)
			m_RestApi = CreateRestApi();
	}
	void ~DiscordHook()
	{
		if (m_RestApi)
			DestroyRestApi();
	}
	private DiscordMessage CreateDiscordMessage()
	{
		private ref DiscordMessage m_DiscordMessage = new ref DiscordMessage();
		ref array <ref DiscordMessageEmbeds> m_DiscordMessageEmbeds = new array <ref DiscordMessageEmbeds>;

		m_DiscordMessageEmbeds.Insert(CreateDiscordMessageEmbeds());

		m_DiscordMessage.embeds = m_DiscordMessageEmbeds;
		return m_DiscordMessage;
	}

	private DiscordMessageEmbeds CreateDiscordMessageEmbeds()
	{
		private ref DiscordMessageEmbeds m_DiscordMessageEmbeds = new ref DiscordMessageEmbeds();
		private ref DiscordMessageEmbedsFields m_DiscordMessageEmbedsFields = new ref DiscordMessageEmbedsFields();
		m_DiscordMessageEmbedsFields.name = "MESSAGETITLE";
		m_DiscordMessageEmbedsFields.value = "```MESSAGE```";
		m_DiscordMessageEmbeds.fields = m_DiscordMessageEmbedsFields;
		m_DiscordMessageEmbeds.thumbnail.url = "THUMBNAILURL";
		return m_DiscordMessageEmbeds;
	}
	void SendEmbed(string alias, DiscordMessage discordMessage)
	{
		thread _SendEmbed(alias, discordMessage);
	}
	void _SendEmbed(string alias, DiscordMessage discordMessage)
	{
		if (!m_alias.Contains(alias))
			return;

		if (!m_RestApi)
			m_RestApi = CreateRestApi();

		if (m_RestApi)
			RestContext m_RestContext = m_RestApi.GetRestContext(m_alias.Get(alias));

		if (m_RestContext)
		{
			string jsonString = JsonFileLoader<DiscordMessage>.JsonMakeData(discordMessage);
			m_RestContext.SetHeader("application/json");
			m_RestContext.POST_now("", jsonString);
		}
	}
	void SetAlias(string alias, string url)
	{
		if (!m_alias.Contains(alias))
			m_alias.Set(alias, url);
	}

	void RemoveAlias(string alias)
	{
		if (m_alias.Contains(alias))
			m_alias.Remove(alias);
	}
}

class SilentCallBack : RestCallback
{
	override void OnError(int errorCode) {};
	override void OnTimeout() {};
	override void OnSuccess(string data, int dataSize) {};
}

static ref DiscordHook g_discordHook;
static ref DiscordHook GetDiscordHook()
{
	if (!g_discordHook)
		g_discordHook = new DiscordHook;
	return g_discordHook;
}