#include "StdAfx.h"
#include "Inventory.h"
#include "Bridge.h"
#include "Item.h"
#include "Weapon.h"

CInventory::CInventory(void)
{
}

CInventory::~CInventory(void)
{
	Release();
}


HRESULT	CInventory::Initialize(void)
{
	m_wstrObjKey = L"Inventory";	
		
	return S_OK;
}

void	CInventory::Progress(void)
{
	
	m_pBridge->Progress(m_tInfo);	
	


}

void	CInventory::Render(void)
{

	m_pBridge->Render();


}

void	CInventory::Release(void)
{
	::Safe_Delete(m_pBridge);
}

void	CInventory::AddItem(void)
{

}

void	CInventory::Picking(void)
{

}


CItem* CInventory::CreateItem(float _fX, float _fY,float _fCX, float _fCY, string strITName)
{
	CItem*	pItem = new CWeapon;
	return pItem;
}
