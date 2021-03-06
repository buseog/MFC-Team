#include "StdAfx.h"
#include "Player.h"

CPlayer::CPlayer(void)
{
}

CPlayer::~CPlayer(void)
{
	Release();
}

HRESULT CPlayer::Initialize(void)
{
	m_wstrObjKey = L"Player";

	m_tUnitData.wstrName = L"쥬신아카데미";
	m_tUnitData.tDetail.iLevel = 2;
	m_tUnitData.iAttack = 10;
	m_tUnitData.iDeffence = 5;
	m_tUnitData.iHealthPoint = 100;
	m_tUnitData.iMaxHelathPoint = 100;
	m_tUnitData.tDetail.iExperience = 0;
	m_tUnitData.tDetail.iBonusPoint = 5;
	m_tUnitData.tDetail.iWeight = 0;
	m_tUnitData.tDetail.iStr = 10;
	m_tUnitData.tDetail.iDex = 10;
	m_tUnitData.tDetail.iVital = 10;
	m_tUnitData.tDetail.iInt = 10;
	m_tUnitData.iLAttack = 100;
	m_tUnitData.iSAttack = 150;

	m_fSpeed = 300.f;
	
	return S_OK;
}

void CPlayer::Progress(void)
{
	m_pBridge->Progress(m_tInfo);

	// 만약 플레이어의 레벨이 1이라면 보너스 스텟은 0
	if(m_tUnitData.tDetail.iLevel == 1) 
	{
		m_tUnitData.tDetail.iBonusPoint = 0; 
	}

}


void CPlayer::Render(void)
{
	m_pBridge->Render();
}

void CPlayer::Release(void)
{
	::Safe_Delete(m_pBridge);
}

void CPlayer::SetStat(int _iIndex)
{
	switch(_iIndex)
	{
	case 0: 
		++m_tUnitData.tDetail.iStr;
		--m_tUnitData.tDetail.iBonusPoint;
		m_tUnitData.iAttack = m_tUnitData.iAttack + int(m_tUnitData.tDetail.iStr * 0.4f) + int(m_tUnitData.tDetail.iLevel * 0.6f);
		break;

	case 1: 
		++m_tUnitData.tDetail.iDex;
		--m_tUnitData.tDetail.iBonusPoint;
		m_tUnitData.iDeffence = m_tUnitData.tDetail.iLevel * int(m_tUnitData.tDetail.iDex * 1.5f);
		break;

	case 2:
		++m_tUnitData.tDetail.iVital;
		--m_tUnitData.tDetail.iBonusPoint;
		break;

	case 3:
		++m_tUnitData.tDetail.iInt;
		--m_tUnitData.tDetail.iBonusPoint;
		break;
	
	}
}
 
void CPlayer::SetPlusAttack(int _iAttack)
{
	m_tUnitData.iLAttack += _iAttack;
	m_tUnitData.iSAttack += _iAttack;
}

void CPlayer::SetPlusDefence(int _iDefence)
{
	m_tUnitData.iDeffence += _iDefence;
}

void CPlayer::SetMinusAttack(int _iAttack)
{
	m_tUnitData.iLAttack -= _iAttack;
	m_tUnitData.iSAttack -= _iAttack;
}

void CPlayer::SetMinusDefence(int _iDefence)
{
	m_tUnitData.iDeffence -= _iDefence;
}

void CPlayer::SetPlusHP(int _iHP)
{
	m_tUnitData.iMaxHelathPoint += _iHP;
	m_tUnitData.iHealthPoint	+= _iHP;
}

void CPlayer::SetMinusHP(int _iHP)
{
	m_tUnitData.iMaxHelathPoint -= _iHP;
	m_tUnitData.iHealthPoint	-= _iHP;
}

void CPlayer::SetRecoveryHP(int _iHP)
{
	

	if(m_tUnitData.iHealthPoint == m_tUnitData.iMaxHelathPoint)
		return;
	
	m_tUnitData.iHealthPoint	+= _iHP;

	if(m_tUnitData.iHealthPoint > m_tUnitData.iMaxHelathPoint)
		m_tUnitData.iHealthPoint = m_tUnitData.iMaxHelathPoint;

}

int CPlayer::GetHP(void)
{
	return m_tUnitData.iHealthPoint;
}	

int	CPlayer::GetMaxHP(void)
{
	return m_tUnitData.iMaxHelathPoint;
}