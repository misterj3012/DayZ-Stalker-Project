#ifdef JM_COT
enum JMEventManagerRPC
{
	INVALID = 10900,
	LoadEvents,
	RequestEvents,
	StartEvent,
	CancelEvent,
	COUNT
};

class JMEventManagerModule : JMRenderableModuleBase
{
	private Class m_EventManager;

	autoptr array<string> Events = new array<string>();
	bool AllowMultipleEvents;

	void JMEventManagerModule()
	{
		GetPermissionsManager().RegisterPermission("Events");
		GetPermissionsManager().RegisterPermission("Events.View");
	}

	override bool HasButton()
	{
		return true; // module isn't loaded if namalsk isn't loaded anyways
	}

	override bool HasAccess()
	{
		return GetPermissionsManager().HasPermission("Events.View");
	}

	override string GetLayoutRoot()
	{
		return "Noosphere/X18Events/Data/GUI/Layouts/EventManager_Form.layout";
	}

	override string GetTitle()
	{
		return "Events";
	}

	override string GetIconName()
	{
		return "E";
	}

	override void OnMissionLoaded()
	{
		super.OnMissionLoaded();

		if (GetGame().IsServer())
		{
			RetrievePossibleEvents();
		}
		else if (GetPermissionsManager().HasPermission("Events"))
		{
			RequestEvents();
		}
	}

	override void OnClientPermissionsUpdated()
	{
		super.OnClientPermissionsUpdated();

		if (Events.Count() > 0) return;

		if (GetPermissionsManager().HasPermission("Events"))
		{
			RequestEvents();
		}
	}

	override int GetRPCMin()
	{
		return JMEventManagerRPC.INVALID;
	}

	override int GetRPCMax()
	{
		return JMEventManagerRPC.COUNT;
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ref ParamsReadContext ctx)
	{
		JMPlayerInstance instance;

		string evt;

		switch (rpc_type)
		{
		case JMEventManagerRPC.StartEvent:
		{
			if (!ctx.Read(evt)) return;

			if (!GetPermissionsManager().HasPermission("Events." + evt + ".Start", sender, instance)) return;

			StartEvent(evt);

			return;
		}

		case JMEventManagerRPC.CancelEvent:
		{
			if (!ctx.Read(evt)) return;

			if (!GetPermissionsManager().HasPermission("Events." + evt + ".Cancel", sender, instance)) return;

			CancelEvent(evt);

			return;
		}

		case JMEventManagerRPC.LoadEvents:
		{
			if (!GetGame().IsClient()) return;

			array<string> evts;
			if (!ctx.Read(evts)) return;
			Events.Copy(evts);

			if (!ctx.Read(AllowMultipleEvents)) return;

			OnSettingsUpdated();

			break;
		}

		case JMEventManagerRPC.RequestEvents:
		{
			if (!GetPermissionsManager().HasPermission("Events", sender, instance)) return;

			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(Events);
			rpc.Write(AllowMultipleEvents);
			rpc.Send(NULL, JMEventManagerRPC.LoadEvents, true, NULL);

			break;
		}
		}
	}

	bool IsEventActive(string evt)
	{
		if (!m_EventManager) return false;

		bool active = false;
		g_Script.CallFunction(m_EventManager, "IsEventActive", active, evt.ToType());
		return active;
	}

	void RetrievePossibleEvents()
	{
		g_Script.CallFunction(GetGame().GetMission(), "GetEventManager", m_EventManager, null);
		if (!m_EventManager) return;

		map<typename, float> possibleEvents;
		EnScript.GetClassVar(m_EventManager, "m_PossibleEventTypes", 0, possibleEvents);

		EnScript.GetClassVar(m_EventManager, "m_AllowMultipleEvents", 0, AllowMultipleEvents);

		Events.Clear();

		array<typename> types = possibleEvents.GetKeyArray();
		for (int i = 0; i < types.Count(); i++)
		{
			string evt = types[i].ToString();
			Events.Insert(evt);

			GetPermissionsManager().RegisterPermission("Events." + evt + ".Start");
			GetPermissionsManager().RegisterPermission("Events." + evt + ".Cancel");
		}
	}

	void StartEvent(string evt)
	{
		if (!m_EventManager)
			return;

		Param2<typename, bool> param = new Param2<typename, bool>(evt.ToType(), true);
		g_Script.CallFunctionParams(m_EventManager, "StartEvent", null, param);
	}

	void CancelEvent(string evt)
	{
		if (!m_EventManager)
			return;

		g_Script.CallFunction(m_EventManager, "CancelEvent", null, evt.ToType());
	}

	void RequestEvents()
	{
		if (IsMissionClient() && !IsMissionOffline())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(NULL, JMEventManagerRPC.RequestEvents, true, NULL);
		}
		else
		{
			OnSettingsUpdated();
		}
	}
};
#endif