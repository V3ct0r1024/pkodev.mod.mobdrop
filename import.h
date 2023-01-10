#pragma once
#include <Windows.h>
#include "structure.h"
#include "UIInterface.h"
#include "Form.h"

namespace pkodev {

	class import final
	{
		public:

			// void CHeadSay::Render(D3DXVECTOR3& pos)
			typedef void(__thiscall* CHeadSay__Render__Ptr)(void*, Vector3D<float>&);
			static CHeadSay__Render__Ptr CHeadSay__Render;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			typedef ItemRecord* (__cdecl* GetItemRecordInfo__Ptr)(int);
			static GetItemRecordInfo__Ptr GetItemRecordInfo;

			// void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
			typedef void(__thiscall* CGuiFont_BRender_Ptr)(void*, const char*, int, int, int, int);
			static CGuiFont_BRender_Ptr CGuiFont_BRender;

			// BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
			typedef bool(__thiscall* MPRender__WorldToScreen__Ptr)(void*, float, float, float, int*, int*);
			static MPRender__WorldToScreen__Ptr MPRender__WorldToScreen;

			// SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize, float fScale = 1.0f);
			typedef Vector2D<int>* (__thiscall* CMPFont__GetTextSize__Ptr)(void*, char*, Vector2D<int>*, float);
			static CMPFont__GetTextSize__Ptr CMPFont__GetTextSize;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			typedef void(__thiscall* CGuiPic__CGuiPic__Ptr)(void*, void*, unsigned int);
			static CGuiPic__CGuiPic__Ptr CGuiPic__CGuiPic;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			typedef bool(__thiscall* CGuiPic__LoadImage__Ptr)(void*, const char*, int, int, int, int, int, float, float);
			static CGuiPic__LoadImage__Ptr CGuiPic__LoadImage;

			// inline void CGuiPic::Render( int x, int y )
			typedef void(__thiscall* CGuiPic__Render__Ptr)(void*, int, int, int);
			static CGuiPic__Render__Ptr CGuiPic__Render;

			// void	CGuiPic::UnLoadImage( int frame=-1 )
			typedef void(__thiscall* CGuiPic__UnloadImage__Ptr)(void*, int);
			static CGuiPic__UnloadImage__Ptr CGuiPic__UnloadImage;

			// CCharacter*	stNetActorCreate::CreateCha()
			typedef stCharacter*(__thiscall* stNetActorCreate__CreateCha__Ptr)(void*);
			static stNetActorCreate__CreateCha__Ptr stNetActorCreate__CreateCha;

			// void NetActorDestroy(unsigned int nID, char chSeeType)
			typedef void(__cdecl* NetActorDestroy__Ptr)(unsigned int, char);
			static NetActorDestroy__Ptr NetActorDestroy;

			// CCharacter* CGameScene::SearchByID(unsigned long id)
			typedef stCharacter* (__thiscall* CGameScene__SearchByID__Ptr)(void*, unsigned int);
			static CGameScene__SearchByID__Ptr CGameScene__SearchByID;

			// void operator delete[](void *p)
			typedef int (__cdecl* operator_delete_array_Ptr)(void*);
			static operator_delete_array_Ptr operator_delete_array;

			// int CSystemProperties::readFromFile(const char * szIniFileName)
			typedef int(__thiscall* CSystemProperties__readFromFile__Ptr)(void*, const char*);
			static CSystemProperties__readFromFile__Ptr CSystemProperties__readFromFile;

			// int CSystemProperties::writeToFile(const char * szIniFileName)
			typedef int(__thiscall* CSystemProperties__writeToFile__Ptr)(void*, const char*);
			static CSystemProperties__writeToFile__Ptr CSystemProperties__writeToFile;

			// void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
			typedef void(__cdecl* CSystemMgr___evtGameOptionFormBeforeShow__Ptr)(void*, bool&);
			static CSystemMgr___evtGameOptionFormBeforeShow__Ptr CSystemMgr___evtGameOptionFormBeforeShow;

			// void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
			typedef void(__cdecl* CSystemMgr___evtGameOptionFormMouseDown__Ptr)(void*, int, int, int, DWORD);
			static CSystemMgr___evtGameOptionFormMouseDown__Ptr CSystemMgr___evtGameOptionFormMouseDown;
	
			// CForm* CUIInterface::_FindForm(const char * frmName)
			typedef gui::CForm* (__thiscall* CUIInterface___FindForm__Ptr)(void*, const char*);
			static CUIInterface___FindForm__Ptr CUIInterface___FindForm;

			// CCompent* CForm::Find(const char* str )
			typedef void* (__thiscall* CForm__Find__Ptr)(void*, const char*);
			static CForm__Find__Ptr CForm__Find;

			// void CCheckGroup::SetActiveIndex(int n)  
			typedef void (__thiscall* CCheckGroup__SetActiveIndex__Ptr)(void*, int);
			static CCheckGroup__SetActiveIndex__Ptr CCheckGroup__SetActiveIndex;

			// void  CStartMgr::PopMenu(CCharacter* pCha)
			typedef void(__thiscall* CStartMgr__PopMenu__Ptr)(void*, const stCharacter* pCha);
			static CStartMgr__PopMenu__Ptr CStartMgr__PopMenu;
				
			// void CForm::PopMenu( CMenu* pMenu, int x, int y )
			typedef void(__thiscall* CForm__PopMenu__Ptr)(gui::CForm*, void*, int, int);
			static CForm__PopMenu__Ptr CForm__PopMenu;

			// static CMenu* CMenu::FindMenu(const char* name)
			typedef void*(__cdecl* CMenu__FindMenu__Ptr)(const char*);
			static CMenu__FindMenu__Ptr CMenu__FindMenu;

	};

}

