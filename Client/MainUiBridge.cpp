#include "StdAfx.h"
#include "MainUiBridge.h"
#include "UIMgr.h"
#include "Ui.h"

CMainUiBridge::CMainUiBridge(void)
{
}

CMainUiBridge::~CMainUiBridge(void)
{
	Release();
}

HRESULT CMainUiBridge::Initialize(void)
{
	return S_OK;
}

void CMainUiBridge::Progress(INFO& rInfo)
{
	WorldMatrix(rInfo);
}

void CMainUiBridge::Render(void)
{
	
	const TEXINFO*		pTexture = CTextureMgr::GetInstance()->GetTexture(m_wstrStateKey);

	if(pTexture == NULL)
		return;

	float fX = pTexture->tImgInfo.Width  / 2.f;
	float fY = pTexture->tImgInfo.Height / 2.f;

	CDevice::GetInstance()->GetSprite()->SetTransform(&m_pUi->GetInfo()->matWorld);
	CDevice::GetInstance()->GetSprite()->Draw(pTexture->pTexture, 
		NULL, &D3DXVECTOR3(fX, fY, 0.f), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CMainUiBridge::Release(void)
{
	
}

void	CMainUiBridge::WorldMatrix(INFO& rInfo)
{
	
	D3DXMATRIX	matTrans;


	D3DXMatrixTranslation(&matTrans, 
		rInfo.vPos.x , 
		rInfo.vPos.y, 
		0.f);

	rInfo.matWorld = matTrans;

}