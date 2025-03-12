class ActionCreateSpaceAnomalyCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_STASH);
	}
};

class ActionCreateSpaceAnomaly : ActionContinuousBase
{
	void ActionCreateSpaceAnomaly()
	{
		m_CallbackClass = ActionCreateSpaceAnomalyCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.LARGE);
	}

	override string GetText()
	{
		return "#STR_Compass_Create_Portal";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.IsPlacingLocal())
			return false;

		X18_Artefact_Compass_Base m_Compass;
		if (CastTo(m_Compass, item))
		{
			if (m_Compass.GetCompEM().IsWorking())
			{
				vector plr_pos = player.GetPosition();
				float height = GetGame().SurfaceY(plr_pos[0], plr_pos[2]);
				height = plr_pos[1] - height;

				if (height > 0.4)
					return false;

				vector targetPos = target.GetCursorHitPos();

				string surface_type;
				GetGame().SurfaceGetType(targetPos[0], targetPos[2], surface_type);

				if (!GetGame().SurfaceIsSea(targetPos[0], targetPos[2]) || !GetGame().SurfaceIsPond(targetPos[0], targetPos[2]))
					return true;
			}
		}
		return false;
	}
};