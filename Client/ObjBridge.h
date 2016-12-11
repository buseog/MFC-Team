#pragma once
#include "bridge.h"

class CObjBridge :
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
	CObjBridge(void);
	CObjBridge(CObj* pObj);
	virtual ~CObjBridge(void);
};
