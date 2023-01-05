#pragma once
#include "structure.h"

namespace pkodev { namespace hook {

	// void CHeadSay::Render(D3DXVECTOR3& pos)
	void __fastcall CHeadSay__Render(void* This, void* NotUsed, Vector3D<float>& Pos);
	
	// CCharacter*	stNetActorCreate::CreateCha()
	stCharacter* __fastcall stNetActorCreate__CreateCha(void* This, void* NotUsed);

	// void NetActorDestroy(unsigned int nID, char chSeeType)
	void __cdecl NetActorDestroy(unsigned int nID, char chSeeType);

}}