#pragma once
#include "storebridge.h"

class CDrugStoreBridge :
	public CStoreBridge
{
protected:
	virtual void	WorldMatrix(INFO& rInfo);

public:
	//virtual void SortItem(INFO& rInfo);
	virtual void AddItem(INFO& rInfo);
	virtual void LoadData(void);
	//virtual void SetItem(INFO& rInfo);

	/*virtual CItem*	CreateWeapon(D3DXVECTOR3 vPos);
	virtual CItem*	CreateArmor(D3DXVECTOR3 vPos);
	virtual CItem*	CreateFood(D3DXVECTOR3 vPos);
	virtual CItem*	CreateEmpty(D3DXVECTOR3 vPos);*/

public:
	virtual HRESULT	Initialize(void);
	virtual void	Progress(INFO& rInfo);
	virtual void	Render(void);
	virtual void	Release(void);
	virtual int		Picking(void);
public:
	CDrugStoreBridge(void);
	~CDrugStoreBridge(void);
};