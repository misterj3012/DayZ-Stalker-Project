class MaterialEffect
{
	private Material m_Material;
	private ref map<string, float> param_values = new map<string, float>();
	void MaterialEffect(string material)
	{
		m_Material = GetGame().GetWorld().GetMaterial(material);
	}
	void ~MaterialEffect()
	{
		delete param_values;
	}
	private void _LerpParam(string param, float start, float finish, float duration)
	{
		int i = 0;
		m_Material.SetParam(param, start);
		while (i < duration * 1000) {
			m_Material.SetParam(param, Math.Lerp(start, finish, (1 / duration) * i / 1000));
			Sleep(1);
			i += 10;
		}
		m_Material.SetParam(param, finish);
		if (param_values) {
			param_values.Set(param, finish);
		}
	}
	void LerpParam(string param, float start, float finish, float duration)
	{
		thread _LerpParam(param, start, finish, duration);
	}
	void LerpParamTo(string param, float finish, float duration)
	{
		float start;
		if (param_values && !param_values.Find(param, start)) {
			param_values.Insert(param, 0);
		}
		LerpParam(param, start, finish, duration);
	}
	void SetParamValue(string param, float value[])
	{
		if (param_values) {
			param_values.Set(param, value);
		}
		m_Material.SetParam(param, value);
	}
	float GetParamValue(string param)
	{
		return param_values.Get(param);
	}
	void ResetParam(string param)
	{
		m_Material.ResetParam(param);
	}
	Material GetMaterial()
	{
		return m_Material;
	}
}