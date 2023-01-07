#include "address.h"
#include "import.h"

namespace pkodev {

	import::CHeadSay__Render__Ptr import::CHeadSay__Render = reinterpret_cast<import::CHeadSay__Render__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CHeadSay__Render));
	import::GetItemRecordInfo__Ptr import::GetItemRecordInfo = reinterpret_cast<import::GetItemRecordInfo__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::GetItemRecordInfo));
	import::CGuiFont_BRender_Ptr import::CGuiFont_BRender = reinterpret_cast<import::CGuiFont_BRender_Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiFont__BRender));
	import::MPRender__WorldToScreen__Ptr import::MPRender__WorldToScreen = reinterpret_cast<import::MPRender__WorldToScreen__Ptr>(*reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::MPRender__WorldToScreen));
	import::CMPFont__GetTextSize__Ptr import::CMPFont__GetTextSize = reinterpret_cast<import::CMPFont__GetTextSize__Ptr>(*reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CMPFont__GetTextSize));
	import::CGuiPic__CGuiPic__Ptr import::CGuiPic__CGuiPic = reinterpret_cast<import::CGuiPic__CGuiPic__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__CGuiPic));
	import::CGuiPic__LoadImage__Ptr import::CGuiPic__LoadImage = reinterpret_cast<import::CGuiPic__LoadImage__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__LoadImage));
	import::CGuiPic__UnloadImage__Ptr import::CGuiPic__UnloadImage = reinterpret_cast<import::CGuiPic__UnloadImage__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__UnloadImage));
	import::CGuiPic__Render__Ptr import::CGuiPic__Render = reinterpret_cast<import::CGuiPic__Render__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__Render));
	import::stNetActorCreate__CreateCha__Ptr import::stNetActorCreate__CreateCha = reinterpret_cast<import::stNetActorCreate__CreateCha__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::stNetActorCreate__CreateCha));
	import::NetActorDestroy__Ptr import::NetActorDestroy = reinterpret_cast<import::NetActorDestroy__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::NetActorDestroy));
	import::CGameScene__SearchByID__Ptr import::CGameScene__SearchByID = reinterpret_cast<import::CGameScene__SearchByID__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGameScene__SearchByID));
	import::operator_delete_array_Ptr import::operator_delete_array = reinterpret_cast<import::operator_delete_array_Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::operator_delete_array));
	import::CSystemProperties__readFromFile__Ptr import::CSystemProperties__readFromFile = reinterpret_cast<import::CSystemProperties__readFromFile__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CSystemProperties__readFromFile));
	import::CSystemProperties__writeToFile__Ptr import::CSystemProperties__writeToFile = reinterpret_cast<import::CSystemProperties__writeToFile__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CSystemProperties__writeToFile));
}