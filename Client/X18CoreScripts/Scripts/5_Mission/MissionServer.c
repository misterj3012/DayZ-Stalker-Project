modded class MissionServer
{
	void MissionServer()
	{
		string path = "$profile:NoosphereServer.lic";

		CF_FileStream input = new CF_FileStream(path, FileMode.READ);
		CF_TextReader reader = new CF_TextReader(input);

		CF_Base64Stream output = new CF_Base64Stream();
		CF_SHA256.Process(reader, output);

		if (output.Encode() != "mgwFrpoQPcXtskljDVeDw+0MQg1t+zeGd442fKit0mg=")
		{
			Print("[License System] Invalid License!");

			if (input.IsValid())
				Print("[License System] License used: " + output.Encode());

			reader.Close();
			GetGame().RequestExit(0);
		}
	}
	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player) {}
}