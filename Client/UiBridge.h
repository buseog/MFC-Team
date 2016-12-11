#pragma once
#include "bridge.h"

class CUiBridge :
	public CBridge
{
protected:
	virtual void	WorldMatrix(INFO& rInfo);

public:
	virtual HRESULT	Initialize(void);
	virtual void	Progress(INFO& rInfo);
	virtual void	Render(void);
	virtual void	Release(void);

public:
	CUiBridge(void);
	CUiBridge(CObj*	pObj);
	virtual ~CUiBridge(void);
};
