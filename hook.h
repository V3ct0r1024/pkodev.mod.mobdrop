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

}}