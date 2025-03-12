modded class DayZPlayerMeleeFightLogic_LightHeavy
{
    override protected void EvaluateHit_Infected(InventoryItem weapon, Object target)
    {
        if (Mutant_AoD_Krovosos1_Base.Cast(target))
            EvaluateHit_Common(weapon, target);
        else
            super.EvaluateHit_Infected(weapon, target);
    }
}