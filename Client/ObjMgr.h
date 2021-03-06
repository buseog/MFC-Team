#pragma once

#include "Bigheader.h"

class CObj;
class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)

private:
	list<CObj*>		m_ObjList[SC_END][OBJ_END];
	SCENEID			m_eSceneID;

public:
	void		AddObject(OBJID eObjID, CObj* pObj);
	void		SetSceneID(SCENEID	dID);				// 해당하는 씬으로 옮길때마다 작동하는 리스트 배열을 바꾸기위함
	void		BattleFieldClear(void);

	const		vector<TILE2*>*		GetTile(void);
	const		CObj*				GetObj(OBJID _eID);
	list<CObj*>*	GetObjList(SCENEID eSCID, OBJID _eID);

public:
	HRESULT			Initialize(void);
	void			Progress(void);
	void			Render(void);
	void			Release();
	int				Picking(void);

private:
	CObjMgr(void);
	~CObjMgr(void);
};
