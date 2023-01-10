#pragma once
#include "structure.h"

namespace pkodev { namespace hook {

	// void CHeadSay::Render(D3DXVECTOR3& pos)
	void __fastcall CHeadSay__Render(void* This, void*, Vector3D<float>& Pos);
	
	// CCharacter*	stNetActorCreate::CreateCha()
	stCharacter* __fastcall stNetActorCreate__CreateCha(void* This, void*);

	// void NetActorDestroy(unsigned int nID, char chSeeType)
	void __cdecl NetActorDestroy(unsigned int nID, char chSeeType);

	// int CSystemProperties::readFromFile(const char * szIniFileName)
	int __fastcall CSystemProperties__readFromFile(void* This, void*, const char* szIniFileName);

	// int CSystemProperties::writeToFile(const char * szIniFileName)
	int __fastcall CSystemProperties__writeToFile(void* This, void*, const char* szIniFileName);

	// void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
	void __cdecl CSystemMgr___evtGameOptionFormBeforeShow(void* pForm, bool& IsShow);

	// void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
	void __cdecl CSystemMgr___evtGameOptionFormMouseDown(void* pSender, int nMsgType, int x, int y, DWORD dwKey);

	// void  CStartMgr::PopMenu(CCharacter* pCha)
	void __fastcall CStartMgr__PopMenu(void* This, void*, const stCharacter* pCha);


}}