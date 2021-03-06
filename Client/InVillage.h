#pragma once
#include "scene.h"

class CInVillage :
	public CScene
{
public:
	virtual HRESULT	Initialize(void);
	virtual void	Progress(void);
	virtual void	Render(void);
	virtual void	Release(void);
	virtual void	LoadPNG(void);

public:
	CInVillage(void);
	~CInVillage(void);
};
