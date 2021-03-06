#include "StdAfx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ObjMgr.h"
#include "UIMgr.h"
#include "Start.h"
#include "Field.h"
#include "Village.h"
#include "BattleField.h"
#include "InVillage.h"


IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr(void)
: m_pScene(NULL)
{
	ZeroMemory(&m_arScene, sizeof(CScene) * SC_END);
}

CSceneMgr::~CSceneMgr(void)
{
	Release();
}
void CSceneMgr::SetScene(SCENEID _eScene)
{
	if (_eScene == SC_FIELD)
	{
		::Safe_Delete(m_pScene);
	}

	CObjMgr::GetInstance()->SetSceneID(_eScene);
	if(FAILED(CObjMgr::GetInstance()->Initialize()))
	{
		ERR_MSG(L"ObjMgr Init Failed");
		return;
	}

	CUIMgr::GetInstance()->SetSceneID(_eScene);
	if(FAILED(CUIMgr::GetInstance()->Initialize()))
	{
		ERR_MSG(L"UIMgr Init Failed");
		return;
	}

	switch(_eScene)
	{
	case SC_START:
			m_pScene = new CStart;
			m_pScene->Initialize();

		break;

	case SC_FIELD:
		if (m_arScene[SC_FIELD] == NULL)
		{
			m_pScene = new CField;
			m_arScene[SC_FIELD] = m_pScene;
			m_pScene->Initialize();
		}
		else
		{
			CUIMgr::GetInstance()->BattleFIeldClear();
			CObjMgr::GetInstance()->BattleFieldClear();	
			m_pScene = m_arScene[SC_FIELD];
			list<CObj*>* pBackList = CObjMgr::GetInstance()->GetObjList(SC_FIELD, OBJ_BACK);
			CObj* pBack = pBackList->front();
			D3DXVECTOR3 vScroll = pBack->GetOriginScroll();
			pBack->SetScroll(vScroll.x, vScroll.y);
		}
		break;
	
	case SC_VILLAGE:
		if (m_arScene[SC_VILLAGE] == NULL)
		{
			m_pScene = new CVillage;
			m_arScene[SC_VILLAGE] = m_pScene;
			m_pScene->Initialize();
		}
		else
			m_pScene = m_arScene[SC_VILLAGE];
		break;

	case SC_BATTLEFIELD:
		{
		m_pScene = new CBattleField;
		m_pScene->Initialize();

		list<CObj*>* pBackList = CObjMgr::GetInstance()->GetObjList(SC_FIELD, OBJ_BACK);
		CObj* pBack = pBackList->front();
		pBack->SetScroll(0.f, 0.f);
		}
		break;

	case SC_INVILLAGE:
		m_pScene = new CInVillage;
		m_pScene->Initialize();
		break;
	}
}

void CSceneMgr::Progress(void)
{
	m_pScene->Progress();

	
	m_tFrame.fFrame += m_tFrame.fCount * CTimeMgr::GetInstance()->GetTime() * 1.5f;

	if(m_tFrame.fFrame > m_tFrame.fMax)
	{
		wstrMouse = L"Hand_Stand";
		SetMouse(L"Hand_Stand");
	}

}

void CSceneMgr::Render(void)
{
	m_pScene->Render();

	const TEXINFO*	pTexture = CTextureMgr::GetInstance()->GetTexture(L"Mouse",  wstrMouse, (const int)m_tFrame.fFrame);

	if (pTexture == NULL)
		return;
		
	D3DXMATRIX matTrans;

	float fX = pTexture->tImgInfo.Width / 2.f;
	float fY = pTexture->tImgInfo.Height / 2.f;

	D3DXVECTOR3	vMouse = ::GetMouse();

	D3DXMatrixTranslation(&matTrans, vMouse.x, vMouse.y, 0.f);
	CDevice::GetInstance()->GetSprite()->SetTransform(&matTrans);
	CDevice::GetInstance()->GetSprite()->Draw(pTexture->pTexture, 
		NULL, &D3DXVECTOR3(fX, fY, 0.f), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

}

void CSceneMgr::Release(void)
{
	for (int i = 0; i < SC_END; ++i)
	{
		if (m_arScene[i])
			::Safe_Delete(m_arScene[i]);
	}
	m_pScene = NULL;
}

void CSceneMgr::SetMouse(const wstring& wstrMouseKey)
{
	if (wstrMouse == L"Sword_Click" || wstrMouse == L"Hand_Click")
		return;

	wstrMouse = wstrMouseKey;

	m_tFrame.fFrame = 0.f;
	m_tFrame.fCount = (float)CTextureMgr::GetInstance()->GetImgCount(L"Mouse", wstrMouseKey); 
	m_tFrame.fMax = m_tFrame.fCount;
}

const wstring	CSceneMgr::GetMouse(void)
{
	return wstrMouse;
}

const CScene* CSceneMgr::GetScene( SCENEID _SceneId )
{
	return m_arScene[_SceneId];
}
