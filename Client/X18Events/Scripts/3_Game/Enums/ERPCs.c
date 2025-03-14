enum X18EventsRPCs : X18RPCs
{
	RPC_SETISINSIDE = 31500
}

enum X18EmissionRPCs : X18RPCs
{
	EMISSION_RPC_CREATE_EMISSION = 32000,
	EMISSION_RPC_CREATE_EMISSION_FINAL,
	EMISSION_RPC_COLOR_SKY,
	EMISSION_RPC_BRIGHTNESS,
	EMISSION_RPC_HIT_PHASE,
};

enum X18PsiEmissionRPCs : X18RPCs
{
	PSIEMISSION_RPC_CREATE_PSIEMISSION = 32500,
	PSIEMISSION_RPC_CREATE_PSIEMISSION_FINAL,
	PSIEMISSION_RPC_COLOR_SKY,
	PSIEMISSION_RPC_EFFECT,
	PSIEMISSION_RPC_BRIGHTNESS,
	PSIEMISSION_RPC_HIT_PHASE,
};