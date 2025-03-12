class ZenNotesLogger
{
	const static string LOG_FOLDER = "$profile:\\Noosphere\\Notes\\Logs\\";
	const static string LOG_FILE = "Notes";

	static void Log(string type, string txt)
	{
		string file_path = LOG_FOLDER + LOG_FILE + "_" + type + ".log";

		if (!FileExist(LOG_FOLDER))
		{
			MakeDirectory(LOG_FOLDER);
		}

		FileHandle logFile = OpenFile(file_path, FileMode.APPEND);
		if (logFile != 0)
		{
			FPrintln(logFile, GetDate() + " [ZenNotes] " + txt);
			CloseFile(logFile);
		}
	}

	static private string GetDate(bool fileFriendly = false)
	{
		int year, month, day, hour, minute, second;

		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);

		string date = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(4) + " " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
		if (fileFriendly)
		{
			date.Replace(" ", "_");
			date.Replace(".", "-");
			date.Replace(":", "-");
		}

		return date;
	}
}