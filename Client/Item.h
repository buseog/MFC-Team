#pragma once
#include "BigHeader.h"

class CBridge;
class CItem
{
protected:
	INFO					m_tInfo;
	wstring					m_wstrObjKey;
	CBridge*				m_pBridge;
	ITEM					m_tItem;
	

private:
	bool					m_bEmpty;

public:
	INFO*				GetInfo(void) ;
	void				SetPos(const D3DXVECTOR3& vPos);
	void				SetPos(float fX, float fY);
	RECT				GetRect(void);
	bool				GetEmpty(void);
	void				SetFoodPlus(int iCount);
	void				SetFoodMinus(int iCount);
	void				SetFoodZero(void);
	ITEM*				GetItemInfo(void);
	CBridge*			GetBridge(void);
	const wstring		GetObjKey(void);

	void	SetItemProperty(wstring _Name, ITEMID _eType,int _iOption,int _iPrice, int _iWeight);
		
public:
	virtual HRESULT	Initialize(void)PURE;
	virtual void	Progress(void)PURE;
	virtual void	Render(void);
	virtual void	Release(void)PURE;
public:
	void    WorldMatrix(void);


public:
	CItem(void);
	CItem(ITEM*	tItem);
	virtual ~CItem(void);





// INFO*	GetInfo(void);
	
//	void SetPos(D3DXVECTOR3 _vPos);
};
