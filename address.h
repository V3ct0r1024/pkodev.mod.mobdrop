#pragma once

namespace pkodev {  namespace address {

        // Game.exe 0 (1222073761)
        namespace GAME_13X_0
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x00470690;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067052C;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D640;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FDC0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D3D0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049ED60;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0046FF70;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x005069C0;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502B00;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CF7E0;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664C9C;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B48C0;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x00484AD0;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484C80;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x00484820;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x00486030;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A288;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E390;

            // CCompent* CForm::Find(const char* str )
            const unsigned int CForm__Find = 0x00494040;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426A50;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047CDE0;

            /*
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CD958;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493580;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x00493FD0;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x00499400;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B410;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DE00;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059C988;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00446310;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x004898E0;
        }

        // Game.exe 1 (1243412597)
        namespace GAME_13X_1
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x004706D0;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D750;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FED0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D4E0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EE70;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0046FFB0;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x00506AD0;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502C10;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CF8F0;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664C9C;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4A00;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x00484B90;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484D40;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x004848E0;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x004860F0;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A288;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E4A0;

            // CCompent* CForm::Find(const char* str)
            const unsigned int CForm__Find = 0x00494150;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426A50;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047CEA0;

            /* 
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CDA68;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493690;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x004940E0;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x00499510;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B410;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DE00;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059CAC8;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00446310;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x004899A0;
        }

        // Game.exe 2 (1252912474)
        namespace GAME_13X_2
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x00470770;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D7F0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FF70;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D580;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EF10;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x00470050;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x00506BA0;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502CE0;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CF9C0;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664C9C;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4AC0;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x00484C30;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484DE0;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x00484980;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x00486190;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A288;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E540;

            // CCompent* CForm::Find(const char* str )
            const unsigned int CForm__Find = 0x004941F0;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426A50;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047CF40;

            /*
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CDB38;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493730;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x00494180;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x004995B0;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B410;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DE00;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059CB88;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00446310;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x00489A40;
        }

        // Game.exe 3 (1244511158)
        namespace GAME_13X_3
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x00470760;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D7E0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FF60;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D570;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EF00;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x00470040;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x00506B90;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502CD0;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CF9B0;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664C9C;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4AC0;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x00484C20;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484DD0;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x00484970;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x00486180;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A288;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E530;

            // CCompent* CForm::Find(const char* str )
            const unsigned int CForm__Find = 0x004941E0;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426A50;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047CF30;

            /*
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CDB28;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493720;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x00494170;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x004995A0;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B410;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DE00;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059CB88;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00446310;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x00489A30;
        }

        // Game.exe 4 (1585009030)
        namespace GAME_13X_4
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x004707D0;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x00670634;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654008;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D9F0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x004A0230;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D780;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049F110;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CF90;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A748;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x00470150;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A758;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x00506DB0;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502EF0;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CFBF0;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664C9C;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4E20;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x00484DA0;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484F50;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x00484AF0;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x00486300;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A2A0;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E740;

            // CCompent* CForm::Find(const char* str )
            const unsigned int CForm__Find = 0x004943F0;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426B80;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047D0B0;

            /*
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CDD08;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493930;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x00494380;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x004997B0;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B540;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DF30;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059CF08;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00446440;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x00489C30;
        }

        // Game.exe 5 (1207214236)
        namespace GAME_13X_5
        {
            // void CHeadSay::Render(D3DXVECTOR3& pos)
            const unsigned int CHeadSay__Render = 0x00470360;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x00670534;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D440;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FBC0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D1D0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EB60;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE80;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A738;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0046FC40;

            // MPRender
            const unsigned int MPRender = 0x006007DC;

            // BOOL MPRender::WorldToScreen(float fX, float fY, float fZ, int *pnX, int *pnY)
            const unsigned int MPRender__WorldToScreen = 0x00600658;

            // CMPFont
            const unsigned int CMPFont = 0x0066A748;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // CCharacter*	stNetActorCreate::CreateCha()
            const unsigned int stNetActorCreate__CreateCha = 0x00506830;

            // void NetActorDestroy(unsigned int nID, char chSeeType)
            const unsigned int NetActorDestroy = 0x00502970;

            // CCharacter* CGameScene::SearchByID(unsigned long id)
            const unsigned int CGameScene__SearchByID = 0x004CF610;

            // static CGameScene* CGameApp::_pCurScene
            const unsigned int CGameApp___pCurScene = 0x00664CA4;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4740;

            // int CSystemProperties::readFromFile(const char * szIniFileName)
            const unsigned int CSystemProperties__readFromFile = 0x004847A0;

            // int CSystemProperties::writeToFile(const char * szIniFileName)
            const unsigned int CSystemProperties__writeToFile = 0x00484950;

            // void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
            const unsigned int CSystemMgr___evtGameOptionFormBeforeShow = 0x004844F0;

            // void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
            const unsigned int CSystemMgr___evtGameOptionFormMouseDown = 0x00485D00;

            // CUIInterface
            const unsigned int CUIInterface = 0x0066A290;

            // CForm* CUIInterface::_FindForm(const char * frmName)
            const unsigned int CUIInterface___FindForm = 0x0049E190;

            // CCompent* CForm::Find(const char* str )
            const unsigned int CForm__Find = 0x00493E40;

            // void CCheckGroup::SetActiveIndex(int n)  
            const unsigned int CCheckGroup__SetActiveIndex = 0x00426A40;

            // void  CStartMgr::PopMenu(CCharacter* pCha)
            const unsigned int CStartMgr__PopMenu = 0x0047CAB0;

            /*
                void CWorldScene::_FrameMove(DWORD dwTimeParam)
                pCha = HitSelectCharacter( nMouseX, nMouseY, enumSC_PLAYER )
                6A 00 | push 0
            */
            const unsigned int HitSelectCharacter__nSelect = 0x004CD788;

            // void CForm::PopMenu( CMenu* pMenu, int x, int y )
            const unsigned int CForm__PopMenu = 0x00493380;

            // void CForm::Show()
            const unsigned int CForm__Show = 0x00493DD0;

            // static CMenu* CMenu::FindMenu(const char* name)
            const unsigned int CMenu__FindMenu = 0x00499200;

            // inline void CItemRow::SetIndex(unsigned int v, CItemObj* p)
            const unsigned int CItemRow__SetIndex = 0x0042B400;

            // CItemRow* CListItems::NewItem()
            const unsigned int CListItems__NewItem = 0x0042DDF0;

            // T* operator new(unsigned int size)
            const unsigned int operator_new = 0x0059C808;

            // CItemEx::CItemEx(const char* str, DWORD c)
            const unsigned int CItemEx__CItemEx = 0x00445FB0;

            // CItemCommand::CItemCommand(CItemRecord* pItem)
            const unsigned int CItemCommand__CItemCommand = 0x004895B0;
        }
    
}}