class X18_Key_Base : ItemBase
{
	string GetFaction()
	{
		return "BaseKey";
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenDoorWithKey);
	};
};
class X18_Key_Admin : X18_Key_Base
{
	override string GetFaction()
	{
		return "Admin";
	}
};
class X18_Key_Loner : X18_Key_Base
{
	override string GetFaction()
	{
		return "Loner";
	}
};
class X18_Key_Bandit : X18_Key_Base
{
	override string GetFaction()
	{
		return "Bratya";
	}
};
class X18_Key_ClearSky : X18_Key_Base
{
	override string GetFaction()
	{
		return "Clear Sky";
	}
};
class X18_Key_Duty : X18_Key_Base
{
	override string GetFaction()
	{
		return "Duty";
	}
};
class X18_Key_UNISG : X18_Key_Base
{
	override string GetFaction()
	{
		return "UNISG";
	}
};
class X18_Key_Freedom : X18_Key_Base
{
	override string GetFaction()
	{
		return "Freedom";
	}
};
class X18_Key_Mercenary : X18_Key_Base
{
	override string GetFaction()
	{
		return "Mercenaries";
	}
};
class X18_Key_Military : X18_Key_Base
{
	override string GetFaction()
	{
		return "Military";
	}
};
class X18_Key_Monolith : X18_Key_Base
{
	override string GetFaction()
	{
		return "Monolith";
	}
};
class X18_Key_Sin : X18_Key_Base
{
	override string GetFaction()
	{
		return "Sin";
	}
};
class X18_Key_Wolf : X18_Key_Base
{
	override string GetFaction()
	{
		return "Wolf";
	}
};