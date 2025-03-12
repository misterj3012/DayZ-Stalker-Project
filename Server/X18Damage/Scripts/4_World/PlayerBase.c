modded class PlayerBase
{
	const ref array<string> m_BleedingZones = { "Head", "Neck", "Pelvis", "Spine", "LeftShoulder", "LeftArm", "LeftArmRoll", "LeftForeArm", "RightShoulder", "RightArm", "RightArmRoll", "RightForeArm", "LeftForeArmRoll", "RightForeArmRoll", "LeftLeg", "LeftLegRoll", "LeftUpLeg", "LeftUpLegRoll", "RightLeg", "RightLegRoll", "RightUpLeg", "RightUpLegRoll", "LeftFoot", "LeftToeBase", "RightFoot", "RightToeBase" };
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		SendMessage("Source: " + source.GetType());
		SendMessage("Ammo: " + ammo);
		SendMessage("dmgZone: " + dmgZone);
		SendMessage("damageType: " + damageType);
		SendMessage("damageResult Health: " + damageResult.GetDamage(dmgZone, "Health"));
		SendMessage("GetHighestDamage Health: " + damageResult.GetHighestDamage("Health"));
		SendMessage("damageResult Shock: " + damageResult.GetDamage(dmgZone, "Shock"));
		SendMessage("GetHighestDamage Shock: " + damageResult.GetHighestDamage("Shock"));
		SendMessage("damageResult Blood: " + damageResult.GetDamage(dmgZone, "Blood"));
		SendMessage("GetHighestDamage Blood: " + damageResult.GetHighestDamage("Blood"));
		SendMessage("component: " + component);
	}
}