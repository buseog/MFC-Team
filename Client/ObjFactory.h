#pragma once

#include "Obj.h"

template <typename T, typename T2>
class CObjFactory
{
public:
		static CObj*	CreateObj(const wstring& wstrState, float _fX = 0, float _fY = 0)
	{
		CObj*	pObj = new T;
		CBridge* pBridge = new T2;

		pObj->SetBridge(pBridge);
		pObj->Initialize();
		pObj->SetPos(_fX, _fY);
		pObj->SetTargetPoint(pObj->GetInfo()->vPos);

		pBridge->Initialize();
		pBridge->SetObj(pObj);
		pBridge->SetFrame(wstrState);
		

		return pObj;
	}

	static CObj*	CreateObj(const wstring& wstrState, D3DXVECTOR3 vPos)
	{
		CObj*	pObj = new T;
		CBridge* pBridge = new T2;

		pObj->SetBridge(pBridge);
		pObj->Initialize();
		pObj->SetPos(vPos);
		pObj->SetTargetPoint(pObj->GetInfo()->vPos);

		pBridge->Initialize();
		pBridge->SetObj(pObj);
		pBridge->SetFrame(wstrState);
		
		

		return pObj;
	}

public:
	CObjFactory(void){	}
	~CObjFactory(void){	}
};
