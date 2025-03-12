class AntiRadAgent : AgentBase
{
	override void Init()
	{
		m_Type = X18MedicalAgents.ANTIRAD;
		m_Invasibility = 0;//increase the agent count by this number per second if potent enough to grow
		m_TransferabilityIn = 0;//to the player
		m_TransferabilityOut = 0;//from the player
		m_AntibioticsResistance = 0.75;//[0..1], 0 means antibiotics have full effect, 1 means no effect
		m_MaxCount = 15; // Effects at around 5
		m_Potency = EStatLevels.CRITICAL;//grow when player's immune system is at this level or lower
		m_DieOffSpeed = 0.0035; //how fast the agent dies off when not potent enough to grow(per sec) // 0,88 after 1 minute
		m_AutoinfectProbability = CalculateAutoinfectProbability(0); // [0..1], 0 = zero chance, 1 = 100% chance of getting this agent once per hour
	}
}