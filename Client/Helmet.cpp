#include "StdAfx.h"
#include "Helmet.h"

CHelmet::CHelmet(void)
{
}

CHelmet::~CHelmet(void)
{
	Release();
}
HRESULT CHelmet::Initialize(void)
{
	return S_OK;
}
int CHelmet::Progress(void)
{
	return 0;
}
void CHelmet::Render(void)
{
}
void CHelmet::Release(void)
{
}