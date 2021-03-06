#pragma once

#include "Bigheader.h"
#include "Bridge.h"


class CUi
{
protected:
	static D3DXVECTOR3		m_vScroll;
	INFO					m_tInfo;
	wstring					m_wstrObjKey;
	CBridge*				m_pBridge;
	bool					m_bView;
	int						m_iIndexKey; // 은지 추가
		

public:
	void	SetView(bool bView);
	const INFO*		GetInfo(void) const;
	void			SetPos(const D3DXVECTOR3& vPos);
	void			SetPos(float fX, float fY);
	void			SetBridge(CBridge* pBridge);
	CBridge*		GetBridge(void);
	const wstring&	GetObjKey(void);
	const RECT		GetRect(void);
	int				Picking(void);
	void			SetSize(D3DXVECTOR3 vSize);					// 렉트 충돌하기위한 사이즈 지정함수
public:	// 은지 추가 - 피킹 관련 인덱스 추가
	int				GetIndexKey(void);
	void			SetIndexKey(int _iIndex);


public:
	virtual HRESULT	Initialize(void)PURE;
	virtual void	Progress(void)PURE;
	virtual void	Render(void)PURE;
	virtual void	Release(void)PURE;


public:
	CUi(void);
	virtual ~CUi(void);
};
