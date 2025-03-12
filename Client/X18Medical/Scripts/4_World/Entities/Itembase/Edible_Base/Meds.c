class X18_Meds_AntiRad : Edible_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}

class X18_Meds_RadioProtectant : Edible_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}

class X18_Meds_PC1 : Edible_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}