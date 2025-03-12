modded class Mutant_AoD_Poltergeist_Base
{
	void Mutant_AoD_Poltergeist_Base()
	{
		if (GetGame().IsDedicatedServer())
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartCrawling, 100, false);
	}
	override bool EvaluateDamageHitAnimation(EntityAI pSource, string pComponent, string pAmmoType, out bool pHeavyHit, out int pAnimType, out float pAnimHitDir)
	{
		stagger = stagger + 1;

		if ((pComponent == "Torso" || pComponent == "Head") && stagger % 3 == 0)
		{
			pAnimType = 0;

			pAnimHitDir = ComputeHitDirectionAngle(pSource);
			m_ShockDamage = GetGame().ConfigGetFloat("CfgAmmo " + pAmmoType + " DamageApplied " + "Shock " + "damage");

			return true;
		}

		return false;
	}

	override bool HandleMindStateChange(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		super.HandleMindStateChange(pCurrentCommandID, pInputController, pDt);

		switch (pInputController.GetMindState())
		{
		case DayZInfectedConstants.MINDSTATE_ALERTED:
		case DayZInfectedConstants.MINDSTATE_CHASE:
		case DayZInfectedConstants.MINDSTATE_DISTURBED:
		{
			ChangeVisible(true);
		}
		}

		return false;
	}

	override void EEKilled(Object killer)
	{
		ChangeVisible(true);
		super.EEKilled(killer);
	}

	override bool CanBeSkinned()
	{
		return true;
	}

	private void StartCrawling()
	{
		if (this)
		{
			StartCommand_Crawl(0);
			m_IsCrawling = true;
		}
	}
}

modded class Mutant_AoD_Poltergeist
{
	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		super.CommandHandler(pDt, pCurrentCommandID, pCurrentCommandFinished);

		DayZInfectedInputController inputController = GetInputController();

		if (inputController)
		{
			if (FightLogic(pCurrentCommandID, inputController, pDt))
				ChangeVisible(true);
		}
	}
	override void ChangeVisible(bool v)
	{
		super.ChangeVisible(v);
		SetAllowDamage(true);
	}
}