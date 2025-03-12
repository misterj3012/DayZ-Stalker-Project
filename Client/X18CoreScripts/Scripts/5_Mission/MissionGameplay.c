/*modded class MissionGameplay
{
	void MissionGameplay()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			string path = "$saves:NoosphereClient.lic";

			CF_FileStream input = new CF_FileStream(path, FileMode.READ);
			CF_TextReader reader = new CF_TextReader(input);

			CF_Base64Stream output = new CF_Base64Stream();
			CF_SHA256.Process(reader, output);

			if (output.Encode() != "qLaLWSoslYiE/fxjkKKWFTIY9z1dPJ7GYBvMZjZ4P44=")
			{
				Print("[License System] Invalid License!");

				if (input.IsValid())
					Print("[License System] License used: " + output.Encode());

				reader.Close();
				GetGame().RequestExit(0);
			}
			else
				Print("[License System] Valid License!");
		}
	}
}*/