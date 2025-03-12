modded class ItemManager
{
	EntityAI item;
	protected ProgressBarWidget					m_Armor;
	protected ProgressBarWidget					m_Melee;
	protected ProgressBarWidget					m_Infected;
	protected ProgressBarWidget					m_Exposion;
	float ArmorLevel;
	float MeleeLevel;
	float InfectedLevel;
	float ExposionLevel;
	void ItemManager(Widget root)
	{
		m_TooltipWidget = GetGame().GetWorkspace().CreateWidgets("Noosphere/X18ItemInfo/Data/GUI/Layout/ItemInfo.layout", root);
		m_TooltipSlotWidget = GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_slot.layout", root);
	}
	override void ShowTooltip()
	{
		Widget m_ItemInfo = Widget.Cast(m_TooltipWidget.FindAnyWidget("ItemInfo"));
		if (m_HoveredItem.IsInherited(Clothing_Base))
		{
			m_ItemInfo.Show(true);
			string SelectItem;
			SelectItem = m_HoveredItem.GetType();
			ArmorLevel = GetGame().ConfigGetFloat("CfgVehicles " + SelectItem + " DamageSystem " + "GlobalArmor " + "Projectile " + "Health " + "damage");
			MeleeLevel = GetGame().ConfigGetFloat("CfgVehicles " + SelectItem + " DamageSystem " + "GlobalArmor " + "Melee " + "Health " + "damage");
			InfectedLevel = GetGame().ConfigGetFloat("CfgVehicles " + SelectItem + " DamageSystem " + "GlobalArmor " + "Infected " + "Health " + "damage");
			ExposionLevel = GetGame().ConfigGetFloat("CfgVehicles " + SelectItem + " DamageSystem " + "GlobalArmor " + "FragGrenade " + "Health " + "damage");
			ProgressBarWidget m_Armor = ProgressBarWidget.Cast(m_TooltipWidget.FindAnyWidget("ProgressBarWidget0"));
			ProgressBarWidget m_Melee = ProgressBarWidget.Cast(m_TooltipWidget.FindAnyWidget("ProgressBarWidget1"));
			ProgressBarWidget m_Infected = ProgressBarWidget.Cast(m_TooltipWidget.FindAnyWidget("ProgressBarWidget2"));
			ProgressBarWidget m_Exposion = ProgressBarWidget.Cast(m_TooltipWidget.FindAnyWidget("ProgressBarWidget3"));
			float Armor_max = m_Armor.GetMax();
			float Melee_max = m_Melee.GetMax();
			float Infected_max = m_Infected.GetMax();
			float Exposion_max = m_Exposion.GetMax();
			int max_value = 100;
			if (ArmorLevel > 0)
			{
				float ArmorValue = Math.Round(100 - (ArmorLevel * max_value));
				m_Armor.SetCurrent(ArmorValue);
				m_Armor.Show(true);
			}
			else
			{
				m_Armor.SetCurrent(0);
				m_Armor.Show(true);
			}
			if (MeleeLevel > 0)
			{
				float MeleeValue = Math.Round(100 - (MeleeLevel * max_value));
				m_Melee.SetCurrent(MeleeValue);
				m_Melee.Show(true);
			}
			else
			{
				m_Melee.SetCurrent(0);
				m_Melee.Show(true);
			}
			if (InfectedLevel > 0)
			{
				float InfectedValue = Math.Round(100 - (InfectedLevel * max_value));
				m_Infected.SetCurrent(InfectedValue);
				m_Infected.Show(true);
			}
			else
			{
				m_Infected.SetCurrent(0);
				m_Infected.Show(true);
			}
			if (ExposionLevel > 0)
			{
				float ExplosionValue = Math.Round(100 - (ExposionLevel * max_value));
				m_Exposion.SetCurrent(ExplosionValue);
				m_Exposion.Show(true);
			}
			else
			{
				m_Exposion.SetCurrent(0);
				m_Exposion.Show(true);
			}
		}
		else
		{
			m_ItemInfo.Show(false);
		}
		Widget m_GridWidget = Widget.Cast(m_TooltipWidget.FindAnyWidget("BackPanelWidget"));
		super.ShowTooltip();
	}
}