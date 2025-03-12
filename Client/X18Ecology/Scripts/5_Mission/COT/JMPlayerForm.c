#ifdef JM_COT
modded class JMPlayerForm
{
	private UIActionEditableText m_Radiation;
	private bool m_RadiationUpdated;
	private UIActionEditableText m_RadiationSickStage;
	private bool m_RadiationSickStageUpdated;

	override void OnClientPermissionsUpdated()
	{
		UpdatePermission(m_Radiation, "Admin.Player.Set.Radiation");
		UpdatePermission(m_RadiationSickStage, "Admin.Player.Set.RadiationSickStage");
		super.OnClientPermissionsUpdated();
	}

	override Widget InitActionWidgetsStats(Widget actionsParent)
	{
		Widget parent = UIActionManager.CreateGridSpacer(actionsParent, 4, 1);

		Widget header = UIActionManager.CreateGridSpacer(parent, 1, 2);
		UIActionManager.CreateText(header, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_HEADER", "");
		m_RefreshStats = UIActionManager.CreateButton(header, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_REFRESH", this, "Click_RefreshStats");

		Widget actions = UIActionManager.CreateGridSpacer(parent, 4, 2);

		m_Health = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_HEALTH", this, "Click_SetHealth", "", "");
		m_Shock = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_SHOCK", this, "Click_SetShock", "", "");
		m_Blood = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_BLOOD", this, "Click_SetBlood", "", "");
		m_Energy = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_FOOD", this, "Click_SetEnergy", "", "");
		m_Water = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_WATER", this, "Click_SetWater", "", "");
		m_Stamina = UIActionManager.CreateEditableText(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_STAMINA", this, "Click_SetStamina", "", "");
		m_Radiation = UIActionManager.CreateEditableText(actions, "Rad", this, "Click_SetRadiation", "", "");
		m_RadiationSickStage = UIActionManager.CreateEditableText(actions, "Rad Stage", this, "Click_SetRadiationSickStage", "", "");

		m_BloodyHands = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_BLOODY_HANDS", this, "Click_BloodyHands", false);
		m_GodMode = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_GODMODE", this, "Click_GodMode", false);
		m_Freeze = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_FREEZE", this, "Click_Freeze", false);
		//m_Invisibility = UIActionManager.CreateCheckbox( actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_INVISIBLE", this, "Click_Invisible", false );
		m_UnlimitedAmmo = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_UNLIMITED_AMMO", this, "Click_UnlimitedAmmo", false);
		m_UnlimitedStamina = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_UNLIMITED_STAMINA", this, "Click_UnlimitedStamina", false);
		m_BrokenLegs = UIActionManager.CreateCheckbox(actions, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_BROKEN_LEGS", this, "Click_SetBrokenLegs", false);

		m_ApplyStats = UIActionManager.CreateButton(parent, "#STR_COT_PLAYER_MODULE_RIGHT_PLAYER_VARIABLES_APPLY", this, "Click_ApplyStats");

		m_Health.SetOnlyNumbers(true);
		m_Shock.SetOnlyNumbers(true);
		m_Blood.SetOnlyNumbers(true);
		m_Energy.SetOnlyNumbers(true);
		m_Water.SetOnlyNumbers(true);
		m_Stamina.SetOnlyNumbers(true);
		m_Radiation.SetOnlyNumbers(true);
		m_RadiationSickStage.SetOnlyNumbers(true);

		UIActionManager.CreatePanel(parent, 0xFF000000, 3);

		return parent;
	}

	override void RefreshStats()
	{
		super.RefreshStats();

		m_RadiationUpdated = false;
		m_RadiationSickStageUpdated = false;

		if (m_Radiation)
			m_Radiation.SetText(m_SelectedInstance.GetRadiation().ToString());

		if (m_RadiationSickStage)
			m_RadiationSickStage.SetText(m_SelectedInstance.GetRadiationSickStage().ToString());
	}

	override void Click_ApplyStats(UIEvent eid, ref UIActionBase action)
	{
		super.Click_ApplyStats(eid, action);

		if (m_RadiationUpdated)
		{
			m_RadiationUpdated = false;

			if (m_Radiation)
				m_Module.SetRadiation(ToFloat(m_Radiation.GetText()), JM_GetSelected().GetPlayers());
		}

		if (m_RadiationSickStageUpdated)
		{
			m_RadiationSickStageUpdated = false;

			if (m_RadiationSickStage)
				m_Module.SetRadiationSickStage(m_RadiationSickStage.GetText().ToInt(), JM_GetSelected().GetPlayers());
		}
	}

	void Click_SetRadiation(UIEvent eid, ref UIActionBase action)
	{
		if (eid != UIEvent.CHANGE)
			return;

		m_RadiationUpdated = true;
	}

	void Click_SetRadiationSickStage(UIEvent eid, ref UIActionBase action)
	{
		if (eid != UIEvent.CHANGE)
			return;

		m_RadiationSickStageUpdated = true;
	}
}
#endif