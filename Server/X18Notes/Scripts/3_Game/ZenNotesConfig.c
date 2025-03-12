class ZenNotesConfig
{
	static const string CONFIG_VERSION = "1";

	private const static string zenModFolder = "$profile:\\Noosphere\\";
	private const static string zenConfigName = "Notes.json";

	string ConfigVersion = "";
	int PenConsumeQuantity;
	ref ZenNoteDateFormat NoteDateFormat;
	ref array<string> WordBlacklist = new array<string>;
	string SendPlayerWarning;

	void Load()
	{
		if (GetGame().IsServer())
		{
			if (FileExist(zenModFolder + zenConfigName))
			{
				JsonFileLoader<ZenNotesConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);

				if (ConfigVersion != CONFIG_VERSION)
				{
					JsonFileLoader<ZenNotesConfig>.JsonSaveFile(zenModFolder + zenConfigName + "_old", this);
					ConfigVersion = CONFIG_VERSION;
				}
				else
				{
					return;
				}
			}

			WordBlacklist.Clear();

			ConfigVersion = CONFIG_VERSION;

			SendPlayerWarning = "We don't tolerate that sort of language on our server. Your note has been logged and any repeat offenses may result in a permenent ban.";
			PenConsumeQuantity = 3;

			NoteDateFormat = new ZenNoteDateFormat;
			NoteDateFormat.Format = 1;
			NoteDateFormat.DaySuffix = new array<string>;
			NoteDateFormat.DaySuffix.Insert("st");
			NoteDateFormat.DaySuffix.Insert("nd");
			NoteDateFormat.DaySuffix.Insert("rd");
			NoteDateFormat.DaySuffix.Insert("th");
			NoteDateFormat.MonthName = new array<string>;
			NoteDateFormat.MonthName.Insert("January");
			NoteDateFormat.MonthName.Insert("February");
			NoteDateFormat.MonthName.Insert("March");
			NoteDateFormat.MonthName.Insert("April");
			NoteDateFormat.MonthName.Insert("May");
			NoteDateFormat.MonthName.Insert("June");
			NoteDateFormat.MonthName.Insert("July");
			NoteDateFormat.MonthName.Insert("August");
			NoteDateFormat.MonthName.Insert("September");
			NoteDateFormat.MonthName.Insert("October");
			NoteDateFormat.MonthName.Insert("November");
			NoteDateFormat.MonthName.Insert("December");

			WordBlacklist.Insert("REALLY_NASTY_WORDS_THAT");
			WordBlacklist.Insert("YOU_DONT_WANT_WRITTEN");

			Save();
		}
	}

	void Save()
	{
		if (!FileExist(zenModFolder))
		{
			MakeDirectory(zenModFolder);
		}

		JsonFileLoader<ZenNotesConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}

	static const string STRIP_CHARS = " /~|!@#$%^&*()_-+=[{]};:'\",<.>/?`~\\";
	bool IsBlacklisted(string msg)
	{
		msg = msg.Trim();
		msg.ToLower();

		for (int i = 0; i < STRIP_CHARS.Length(); i++)
		{
			msg.Replace(STRIP_CHARS.Get(i), "");
		}

		foreach(string s : WordBlacklist)
		{
			s.ToLower();
			if (msg.Contains(s))
				return true;
		}

		return false;
	}

	string GetDate()
	{
		if (NoteDateFormat.Format == 0)
		{
			return "";
		}

		int year, month, day;
		GetYearMonthDay(year, month, day);

		string date;
		string dayNumber;
		string monthNumber;

		dayNumber = day.ToStringLen(2);
		if (day <= 9)
			dayNumber = day.ToStringLen(1);

		monthNumber = month.ToStringLen(2);
		if (month <= 9)
			monthNumber = month.ToStringLen(1);

		if (NoteDateFormat.Format == 1) {
			string dayStr;
			string monthStr;
			dayStr = GetNumberDateyThingy(day);
			monthStr = GetMonth(month);
			date = dayNumber + dayStr + " " + monthStr + ", " + year.ToStringLen(4);
		}
		else
			if (NoteDateFormat.Format == 2) {
				date = day.ToStringLen(2) + "/" + month.ToStringLen(2) + "/" + year.ToStringLen(4);
			}
			else
				if (NoteDateFormat.Format == 3) {
					date = dayNumber + "/" + monthNumber + "/" + year.ToStringLen(4);
				}
				else
					if (NoteDateFormat.Format == 4) {
						date = month.ToStringLen(2) + "/" + day.ToStringLen(2) + "/" + year.ToStringLen(4);
					}
					else
						if (NoteDateFormat.Format == 5) {
							date = monthNumber + "/" + dayNumber + "/" + year.ToStringLen(4);
						}

		return date;
	}

	string GetNumberDateyThingy(int number)
	{
		switch (number % 10)
		{
			case 1:  return NoteDateFormat.DaySuffix.Get(0);
			case 2:  return NoteDateFormat.DaySuffix.Get(1);
			case 3:  return NoteDateFormat.DaySuffix.Get(2);
			default: return NoteDateFormat.DaySuffix.Get(3);
		}

		return "";
	}

	string GetMonth(int month)
	{
		return NoteDateFormat.MonthName.Get(month - 1);
	}
}

class ZenNoteDateFormat
{
	int Format;
	ref array<string> DaySuffix;
	ref array<string> MonthName;
};

ref ZenNotesConfig m_ZenNotesConfig;

static ZenNotesConfig GetZenNotesConfig()
{
	if (!m_ZenNotesConfig)
	{
		Print("[ZenNotesConfig] Init");
		m_ZenNotesConfig = new ZenNotesConfig;
		m_ZenNotesConfig.Load();
	}

	return m_ZenNotesConfig;
};