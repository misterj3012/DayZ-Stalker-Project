modded class BrokenLegsMdfr
{
    override void OnDeactivate(PlayerBase player)
    {
        player.UpdateBrokenLegs(eBrokenLegs.NO_BROKEN_LEGS);
        if (player.IsWearingSplint())
        {
            AMS_Splint_Applied splint = AMS_Splint_Applied.Cast(player.GetItemOnSlot("Splint_Right"));
            if (splint)
                splint.Delete();
            else
                MiscGameplayFunctions.RemoveSplint(player);
        }
        player.SetBrokenLegs(eBrokenLegs.NO_BROKEN_LEGS);
        player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_FRACTURE);
    }
}