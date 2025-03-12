ref RadiationOptions RadiationConfig = new RadiationOptions();
class RadiationOptions
{
	int Version = 1;
	int DecreaseRadiationByItself = 10;
	int DecreaseRadiationByItselfDuration = 60;
	int RadWaterDrainVomit = 800;
	int RadEnergyDrainVomit = 600;
	float RadChanceDepletingStamina = 0.5;
	float RadChanceVomit = 0.30;
	float RadChanceBleeding = 0.25;
	float RadChanceUnconscious = 0.30;
	float RadChanceBlindness = 0.30;
	int RadBloodLossDamage = 100;
	float RadHealthDamage = 2;
	float RadHighMultiplier = 2.5;
};