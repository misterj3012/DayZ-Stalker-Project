modded class MissionBase
{
	const private static string m_DetectorLogText = "DetectorBase";
	void MissionBase()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
			GetRPCManager().AddRPC("X18_RPCManager", "SpawnArtefact", this, SingeplayerExecutionType.Client);
	}

	void SpawnArtefact(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if (type == CallType.Server && GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			Param2<X18_Artefact_Spawn_Base, vector> data;

			if (!sender) return;
			if (!ctx.Read(data)) return;

			PrintLog("[SpawnArtefact] Player: '" + sender.GetName() + "' | '" + sender.GetPlainId() + "' has found an Artefact at position: " + data.param2, m_DetectorLogText);

			X18_Artefact_Spawn_Base m_ArtefactSpawnBase = X18_Artefact_Spawn_Base.Cast(data.param1);
			if (!m_ArtefactSpawnBase)
				return;

			vector m_PortalPosition = data.param2;
			EntityAI m_Portal = EntityAI.Cast(GetGame().CreateObjectEx("ID_MONOLITH_PORTAL_IDLE", m_PortalPosition, ECE_KEEPHEIGHT));
			if (m_Portal)
			{
				m_Portal.SetOrientation(Vector(0, 90, 0));
				m_Portal.Update();
			}
			GetGame().CreateObjectEx(m_ArtefactSpawnBase.GetArtefact(), m_PortalPosition, ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
			if (m_ArtefactSpawnBase)
				GetGame().ObjectDelete(m_ArtefactSpawnBase);
			if (m_Portal)
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 2000, false, m_Portal);

			PrintLog("[SpawnArtefact] Artefact: " + m_ArtefactSpawnBase.GetArtefact() + " spawned at position: " + m_PortalPosition, m_DetectorLogText);
		}
	}
}