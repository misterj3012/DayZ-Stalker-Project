modded class OptionsMenuGame
{
	protected Widget m_VIASection;
	protected Widget m_VIALocalAnimation;
	protected Widget m_VIAPreviewAnimation;
	protected ref OptionSelectorMultistate m_VIALocalAnimationGameSelector;
	protected ref OptionSelectorMultistate m_VIAPreviewAnimationGameSelector;

	void OptionsMenuGame(Widget parent, Widget details_root, GameOptions options, OptionsMenu menu)
	{
		// Create VIA section
		m_VIASection = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18InventoryAnimation/GUI/Layouts/SettingsMenuVIASection.layout", m_Root.FindAnyWidget("game_settings_root"));
		m_Root.FindAnyWidget("game_settings_root").Update();

		// Local animation
		array<string> opt = { "#options_controls_disabled", "#options_controls_enabled" };
		m_VIALocalAnimation = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18InventoryAnimation/GUI/Layouts/SettingsMenuElement.layout", m_Root.FindAnyWidget("via_settings_root"));
		m_VIALocalAnimation.FindAnyWidget("setting_option").SetUserID(VIAOptionAccessType.AT_OPTIONS_ANIMATION);
		TextWidget.Cast(m_VIALocalAnimation.FindAnyWidget("setting_label")).SetText("PLAYER ANIMATION");
		m_VIALocalAnimationGameSelector = new OptionSelectorMultistate(m_VIALocalAnimation.FindAnyWidget("setting_option"), g_Game.GetVIAProfileVal(EVIAProfileOptions.ANIMATION), this, false, opt);
		m_VIALocalAnimationGameSelector.m_OptionChanged.Insert(OnVIASettingChanged);
		if (VIASettings.SETTINGS.forceAnimation)
		{
			m_VIALocalAnimationGameSelector.Disable();
			TextWidget.Cast(m_VIALocalAnimation.FindAnyWidget("setting_label")).SetText("PLAYER ANIMATION (FORCED)");
			m_VIALocalAnimationGameSelector.SetValue(1, false);
		}

		// Preview animation
		m_VIAPreviewAnimation = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18InventoryAnimation/GUI/Layouts/SettingsMenuElement.layout", m_Root.FindAnyWidget("via_settings_root"));
		m_VIAPreviewAnimation.FindAnyWidget("setting_option").SetUserID(VIAOptionAccessType.AT_OPTIONS_PREVIEW);
		TextWidget.Cast(m_VIAPreviewAnimation.FindAnyWidget("setting_label")).SetText("PREVIEW ANIMATION");
		m_VIAPreviewAnimationGameSelector = new OptionSelectorMultistate(m_VIAPreviewAnimation.FindAnyWidget("setting_option"), g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW), this, false, opt);
		m_VIAPreviewAnimationGameSelector.m_OptionChanged.Insert(OnVIASettingChanged);
		if (VIASettings.SETTINGS.forcePreview)
		{
			m_VIAPreviewAnimationGameSelector.Disable();
			TextWidget.Cast(m_VIAPreviewAnimation.FindAnyWidget("setting_label")).SetText("PREVIEW ANIMATION (FORCED)");
			m_VIAPreviewAnimationGameSelector.SetValue(1, false);
		}
	}

	override void Apply()
	{
		super.Apply();

		if (!VIASettings.SETTINGS.forceAnimation)
		{
			g_Game.SetVIAProfileVal(EVIAProfileOptions.ANIMATION, m_VIALocalAnimationGameSelector.GetValue());
		}
		if (!VIASettings.SETTINGS.forcePreview)
		{
			g_Game.SetVIAProfileVal(EVIAProfileOptions.PREVIEW, m_VIAPreviewAnimationGameSelector.GetValue());
		}
	}

	override bool IsChanged()
	{
		if (!VIASettings.SETTINGS.forceAnimation && m_VIALocalAnimationGameSelector && m_VIALocalAnimationGameSelector.GetValue() != g_Game.GetVIAProfileVal(EVIAProfileOptions.ANIMATION))
		{
			return true;
		}
		if (!VIASettings.SETTINGS.forcePreview && m_VIAPreviewAnimationGameSelector && m_VIAPreviewAnimationGameSelector.GetValue() != g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW))
		{
			return true;
		}

		return super.IsChanged();
	}

	override void Revert()
	{
		super.Revert();

		if (m_VIALocalAnimationGameSelector)
		{
			m_VIALocalAnimationGameSelector.SetValue(g_Game.GetVIAProfileVal(EVIAProfileOptions.ANIMATION), false);
		}

		if (m_VIAPreviewAnimationGameSelector)
		{
			m_VIAPreviewAnimationGameSelector.SetValue(g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW), false);
		}
	}

	override void SetOptions(GameOptions options)
	{
		super.SetOptions(options);

		if (m_VIALocalAnimationGameSelector && !VIASettings.SETTINGS.forceAnimation)
		{
			m_VIALocalAnimationGameSelector.SetValue(g_Game.GetVIAProfileVal(EVIAProfileOptions.ANIMATION), false);
		}
		if (m_VIAPreviewAnimationGameSelector && !VIASettings.SETTINGS.forcePreview)
		{
			m_VIAPreviewAnimationGameSelector.SetValue(g_Game.GetVIAProfileVal(EVIAProfileOptions.PREVIEW), false);
		}
	}

	override void FillTextMap()
	{
		super.FillTextMap();

		m_TextMap.Insert(VIAOptionAccessType.AT_OPTIONS_ANIMATION, new Param2<string, string>("Play animation locally", "Enables or disables playing the animation on the controlling player. Disabling this option does not disable the animation for other players. Other players will still see the animation on your player when you are in inventory. This option can be forced from the server."));
		m_TextMap.Insert(VIAOptionAccessType.AT_OPTIONS_PREVIEW, new Param2<string, string>("Play animation preview", "Enables or disables playing the animation on the player preview in the inventory. This option can be forced from the server."));
	}

	void OnVIASettingChanged(int new_index)
	{
		m_Menu.OnChanged();
	}
}