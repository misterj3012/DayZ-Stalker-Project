ref MedicalOptions MedicalConfig = new MedicalOptions();
class MedicalOptions
{
	int Version = 1;
	int ShieldGivenByB190 = 50;
	int B190Duration = 300;
	int ShieldGivenByPC1 = 35;
	int PC1Duration = 300;
	float DecreaseRadiationByMexamine = 200;
	int DecreaseRadiationByMexamineDuration = 60;
	float DecreaseRadiationByMexamineStick = 800;
	int DecreaseRadiationByMexamineStickDuration = 60;
	float DecreaseRadiationByVodka = 75;
	int DecreaseRadiationByVodkaDuration = 60;
	float DecreaseRadiationByJoint = 45;
	int DecreaseRadiationByJointDuration = 60;
	float DecreaseRadiationByCigarette = 20;
	int DecreaseRadiationByCigaretteDuration = 60;
	int Tier1_MediKitDuration = 60;
	float Tier1_MediKitHealth = 20;
	float Tier1_MediKitWater = 0;
	float Tier1_MediKitEnergy = 0;
	float Tier1_MediKitBlood = 0;
	float Tier1_MediKitRadiation = 0;
	int Tier1_MediKitCuts = 1;
	int Tier2_MediKitDuration = 60;
	float Tier2_MediKitHealth = 40;
	float Tier2_MediKitWater = 0;
	float Tier2_MediKitEnergy = 0;
	float Tier2_MediKitBlood = 500;
	float Tier2_MediKitRadiation = 0;
	int Tier2_MediKitCuts = 2;
	int Tier3_MediKitDuration = 60;
	float Tier3_MediKitHealth = 60;
	float Tier3_MediKitWater = 0;
	float Tier3_MediKitEnergy = 0;
	float Tier3_MediKitBlood = 500;
	float Tier3_MediKitRadiation = 800;
	int Tier3_MediKitCuts = 2;
	int StalkerEnergyDuration = 30;
};