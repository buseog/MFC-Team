#pragma once
#include "item.h"

class CHelmet :
	public CItem
{
public:
	CHelmet(void);
	CHelmet(ITEM*	tItem);
	~CHelmet(void);
public:
	virtual HRESULT Initialize(void);
	virtual void Progress(void);
//	virtual void Render(void);
	virtual void Release(void);
};
