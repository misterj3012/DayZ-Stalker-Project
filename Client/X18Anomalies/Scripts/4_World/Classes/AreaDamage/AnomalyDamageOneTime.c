class AnomalyDamageOneTime : AnomalyDamageBase
{
	override void OnEnter(Object obj)
	{
		PreDamageActions();
		EvaluateDamage(obj);
		PostDamageActions();
	}
}