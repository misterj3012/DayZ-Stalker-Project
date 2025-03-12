class PsiPlugin extends PluginBase
{
	protected ref ScriptInvoker m_ScriptInvoker = new ScriptInvoker;
	protected bool m_IsInPsi = false;
	protected bool m_WasInPsi = false;
	protected float m_PsiSourceDistance = 0.0;
	protected float m_PsiSourceRadius = 0.0;
	protected vector m_PsiSourceLocation = "0 0 0";

	protected float m_TimeActive;
	protected EffectSound m_EffectLoopSound;
	protected PlayerBase m_Player;
	ref protected PPERequester_Psi m_Requester;
	ref protected PPERequester_PsiColor m_RequesterColor;
	void ~PsiPlugin()
	{
		ClearVisual();
	}
	protected void ClearVisual()
	{
		StopSound();
		m_Requester.Stop();
		m_RequesterColor.Stop();
	}
	override void OnInit()
	{
		if (!GetGame().IsDedicatedServer())
		{
			Class.CastTo(m_Player, GetGame().GetPlayer());
			Class.CastTo(m_Requester, PPERequesterBank.GetRequester(PPERequester_Psi));
			Class.CastTo(m_RequesterColor, PPERequesterBank.GetRequester(PPERequester_PsiColor));
		}
	}
	override void OnUpdate(float delta_time)
	{
		if (Class.CastTo(m_Player, GetGame().GetPlayer()) && !m_Player.IsAdminActive() && m_Player.GetFaction() != EFactions.Sin)
		{
			m_TimeActive += delta_time;
			m_IsInPsi = false;
			float m_Coef = 0.0;
			m_ScriptInvoker.Invoke();
			if (m_IsInPsi)
			{
				m_Requester.Start();
				m_RequesterColor.Start();

				m_Coef = 1.0 - (m_PsiSourceDistance / m_PsiSourceRadius);

				if (m_RequesterColor.IsRequesterRunning())
					m_RequesterColor.Update(m_Coef);


				SetColorization(m_Coef * 4);
				PlaySound();
				m_WasInPsi = true;
				if (m_TimeActive >= 1.0)
				{
					GetGame().RPCSingleParam(m_Player, PsiRPC.SETPSISTRENGTH, new Param1<float>(m_Coef), true, m_Player.GetIdentity());
					m_TimeActive = 0.0;
				}
			}
			else if (m_WasInPsi)
			{
				m_WasInPsi = false;
				ClearVisual();
			}
			if (m_TimeActive >= 1.5 && m_Player.GetPlayVoices())
			{
				if (m_Coef <= 0.0)
				{
					m_Coef = Math.Clamp(m_Player.GetPsiStrength() / 4, 0.1, 0.5);
					GetGame().RPCSingleParam(m_Player, PsiRPC.SETPSISTRENGTH, new Param1<float>(-m_Coef), true, m_Player.GetIdentity());
				}
				m_TimeActive = 0.0;
			}
		}
		else
			m_Player = PlayerBase.Cast(GetGame().GetPlayer());
	}
	protected void PlaySound()
	{
		if (m_EffectLoopSound)
			return;

		m_EffectLoopSound = SEffectManager.CreateSound("X18Psi_" + m_PsiSourceRadius + "_SoundSet", m_PsiSourceLocation);
		m_EffectLoopSound.SetSoundWaveKind(WaveKind.WAVEEFFECTEX);
		m_EffectLoopSound.SetSoundFadeIn(4);
		m_EffectLoopSound.SetSoundFadeOut(2);
		m_EffectLoopSound.SetSoundLoop(true);
		m_EffectLoopSound.SoundPlay();
	}

	protected void StopSound()
	{
		if (m_EffectLoopSound)
			m_EffectLoopSound.SoundStop();
		m_EffectLoopSound = null;
	}
	protected void SetColorization(float color_val)
	{
		array<float> overlay_color = { 0, 0, 0, 0 };

		overlay_color[0] = Math.Lerp(0, 6, color_val);
		overlay_color[1] = Math.Lerp(0, 4, color_val);
		overlay_color[2] = Math.Lerp(0, -1, color_val);

		if (m_Requester && m_Requester.IsRequesterRunning())
			m_Requester.UpdateColorization(overlay_color);
	}
	void ApplyForClosestPsi(vector sourceLocation, float distance, float radius)
	{
		if (!m_IsInPsi)
		{
			m_PsiSourceDistance = distance;
			m_PsiSourceLocation = sourceLocation;
			m_PsiSourceRadius = radius;
		}
		else if (distance < m_PsiSourceDistance)
		{
			m_PsiSourceDistance = distance;
			m_PsiSourceLocation = sourceLocation;
			m_PsiSourceRadius = radius;
		}
		m_IsInPsi = true;
	}
	ScriptInvoker GetScriptInvoker()
	{
		return m_ScriptInvoker;
	}
}