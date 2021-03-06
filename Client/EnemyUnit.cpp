#include "StdAfx.h"
#include "EnemyUnit.h"

CEnemyUnit::CEnemyUnit(void)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
}
CEnemyUnit::CEnemyUnit(UNITDATA*	tUnit) :CUnit(tUnit)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	m_tUnitData = *tUnit;
}

CEnemyUnit::~CEnemyUnit(void)
{
	Release();
}

HRESULT CEnemyUnit::Initialize(void)
{
	//m_wstrObjKey = L"EnemyUnit";
	m_fSpeed = 30.f;
	m_vTargetPoint = D3DXVECTOR3(450.f, 350.f, 0.f);
	m_iOrder = OD_PATROL;
	m_tInfo.vSize = D3DXVECTOR3(130.f,140.f,0.f);

	return S_OK;
}

void CEnemyUnit::Progress(void)
{
	m_pBridge->Progress(m_tInfo);
}

void CEnemyUnit::Render(void)
{
	m_pBridge->Render();
}

void CEnemyUnit::Release(void)
{
	::Safe_Delete(m_pBridge);
}

