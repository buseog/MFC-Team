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

	m_tUnitData.wstrName = L"��ž�ī����";
	m_tUnitData.tDetail.iLevel = 1;
	m_tUnitData.iAttack = 10;
	m_tUnitData.iDeffence = 5;
	m_tUnitData.iHealthPoint = 100;
	m_tUnitData.tDetail.iExperience = 0;
	m_tUnitData.tDetail.iBonusPoint = 0;
	m_tUnitData.tDetail.iWeight = 0;
	
	return S_OK;
}

void CPlayer::Progress(void)
{
	m_pBridge->Progress(m_tInfo);
}

void CPlayer::Render(void)
{
	m_pBridge->Render();
}

void CPlayer::Release(void)
{
	::Safe_Delete(m_pBridge);
}
