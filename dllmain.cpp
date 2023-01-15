#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <algorithm>

#include <Windows.h>
#include <detours.h>

#include "loader.h"
#include "address.h"
#include "hook.h"
#include "structure.h"
#include "import.h"

#include "Utils.h"

#include "Render.h"

#include "TextLabel.h"
#include "GuiPic.h"
#include "UIInterface.h"
#include "Form.h"
#include "Menu.h"
#include "Label.h"
#include "ListView.h"

#include "Loot.h"


const unsigned int MAX_RENDER_NAME_LEN = 24;
const unsigned int MAX_FORM_NAME_LEN = 20;
const unsigned int MAX_FORM_CHANAME_LEN = 20;

pkodev::Loot g_Loot;
float g_DropRate = 1.0f;
bool g_ShowDrop = false;

template<typename ColorType>
using PaletteType = std::map<float, ColorType, std::greater<float>>;

const PaletteType<pkodev::gui::CTextLabel::Colors> g_RenderPalette = {
    { 75.0f, pkodev::gui::CTextLabel::Colors::Green}, { 50.0f, pkodev::gui::CTextLabel::Colors::Yellow },
    { 25.0f, pkodev::gui::CTextLabel::Colors::Orange }, { 0.0f, pkodev::gui::CTextLabel::Colors::Red }
};

const PaletteType<unsigned int> g_FormPalette = {
    { 75.0f, 0xFF177245}, { 50.0f, 0xFFF4A900 },
    { 25.0f, 0xFFFF8000}, { 0.0f, 0xFFFF0000 }
};


void __cdecl OnMonsterMenuPopup(pkodev::gui::CMenu* pSender, int x, int y, unsigned int key);

float GetDropRate(const std::string& path);

template<typename ColorType>
ColorType GetColor(float percentage, const PaletteType<ColorType>& palette);


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    return TRUE;
}

void GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

void Start(const char* path)
{
    using namespace pkodev;

    char cfg_path[MAX_PATH]{ 0x00 };
    sprintf_s(cfg_path, sizeof(cfg_path), "%s\\%s.cfg", path, TOSTRING(MOD_NAME));

    g_DropRate = GetDropRate(cfg_path);

    const char patch[] = { 0x6A , 0x00 };
    Utils::Patch<address::MOD_EXE_VERSION::HitSelectCharacter__nSelect>(patch);

    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)import::CHeadSay__Render, hook::CHeadSay__Render);
    DetourAttach(&(PVOID&)import::stNetActorCreate__CreateCha, hook::stNetActorCreate__CreateCha);
    DetourAttach(&(PVOID&)import::NetActorDestroy, hook::NetActorDestroy);
    DetourAttach(&(PVOID&)import::CSystemProperties__readFromFile, hook::CSystemProperties__readFromFile);
    DetourAttach(&(PVOID&)import::CSystemProperties__writeToFile, hook::CSystemProperties__writeToFile);
    DetourAttach(&(PVOID&)import::CSystemMgr___evtGameOptionFormBeforeShow, hook::CSystemMgr___evtGameOptionFormBeforeShow);
    DetourAttach(&(PVOID&)import::CSystemMgr___evtGameOptionFormMouseDown, hook::CSystemMgr___evtGameOptionFormMouseDown);
    DetourAttach(&(PVOID&)import::CStartMgr__PopMenu, hook::CStartMgr__PopMenu);
    DetourTransactionCommit();
}

void Stop()
{
    using namespace pkodev;

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)import::CHeadSay__Render, hook::CHeadSay__Render);
    DetourDetach(&(PVOID&)import::stNetActorCreate__CreateCha, hook::stNetActorCreate__CreateCha);
    DetourDetach(&(PVOID&)import::NetActorDestroy, hook::NetActorDestroy);
    DetourDetach(&(PVOID&)import::CSystemProperties__readFromFile, hook::CSystemProperties__readFromFile);
    DetourDetach(&(PVOID&)import::CSystemProperties__writeToFile, hook::CSystemProperties__writeToFile);
    DetourDetach(&(PVOID&)import::CSystemMgr___evtGameOptionFormBeforeShow, hook::CSystemMgr___evtGameOptionFormBeforeShow);
    DetourDetach(&(PVOID&)import::CSystemMgr___evtGameOptionFormMouseDown, hook::CSystemMgr___evtGameOptionFormMouseDown);
    DetourDetach(&(PVOID&)import::CStartMgr__PopMenu, hook::CStartMgr__PopMenu);
    DetourTransactionCommit();

    const char patch[] = { 0x6A , 0x02 };
    Utils::Patch<address::MOD_EXE_VERSION::HitSelectCharacter__nSelect>(patch);
}

// void CHeadSay::Render(D3DXVECTOR3& pos)
void __fastcall pkodev::hook::CHeadSay__Render(void* This, 
    void* NotUsed, Vector3D<float>& Pos)
{
    const bool ShowName = Utils::Get<bool, 0x49>(This);

    if ( (g_ShowDrop == false) || (ShowName == false) ) {
        import::CHeadSay__Render(This, Pos);
        return;
    }

    const stCharacter* MainCha = Utils::Get<stCharacter*>(address::MOD_EXE_VERSION::CGameScene___pMainCha);
    const stCharacter* OtherCha = Utils::Get<stCharacter*, 0x28>(This);

    if ( (MainCha == OtherCha) || (OtherCha->IsMonster() == false) ) {
        import::CHeadSay__Render(This, Pos);
        return;
    }

    const auto it = g_Loot.find(OtherCha->Info->id);

    if ( (it == g_Loot.end()) || (it->second.loot.empty() == true) ) {
        import::CHeadSay__Render(This, Pos);
        return;
    }

    const Vector2D<int> screen = gui::CRender::WorldToScreen(Pos);

    unsigned int i = 0;
    static char text[128]{0x00};

    for (const auto& item : it->second.loot)
    {
        if (item.name.length() > MAX_RENDER_NAME_LEN) {
            sprintf_s( text, sizeof(text), "%.2f%% %s...",
                item.chance, item.name.substr(0, MAX_RENDER_NAME_LEN - 3).c_str() );
        }
        else {
            sprintf_s(text, sizeof(text), "%.2f%% %s",
                item.chance, item.name.c_str() );
        }

        const int x = screen.x + ( (i < 5) ? -180 : 64 );
        const int y = screen.y + 20 - 64 + (16 * ( (i < 5) ? i : (i - 5) ) );

        item.icon.Render( (x - item.icon.GetWidth() - 4), (y - 4) );

        gui::CTextLabel::Render(text, x, y, GetColor(item.chance, g_RenderPalette));
       
        ++i;
    }

    pkodev::import::CHeadSay__Render(This, Pos);
}

// CCharacter* stNetActorCreate::CreateCha()
pkodev::stCharacter* __fastcall pkodev::hook::stNetActorCreate__CreateCha(
    void* This, void* NotUsed)
{
    const stCharacter* Cha = import::stNetActorCreate__CreateCha(This);

    if ( (Cha == nullptr) || (Cha->IsMonster() == false) ) {
        return const_cast<stCharacter*>(Cha);
    }

    const auto it = g_Loot.find(Cha->Info->id);

    if (it != g_Loot.end()) {
        ++(it->second.counter);
        return const_cast<stCharacter*>(Cha);
    }

    LootPair items;

    for (unsigned int i = 0; i < MAX_ITEMS; ++i)
    {
        if (Cha->Info->items[i].id == -1) { break; }

        LootItem item;
        item.info = import::GetItemRecordInfo(Cha->Info->items[i].id);
        item.chance = Cha->Info->items[i].Chance(g_DropRate);

        if (item.info != nullptr) {
            item.name = item.info->name;
            item.icon.Load(gui::CGuiPic::GetIconFile(item.info->icon), 32, 32, 0.5f, 0.5f);
        }
        else {
            item.name = "Unknown item";
            item.icon.Load(gui::CGuiPic::GetIconFile("error"), 32, 32, 0.5f, 0.5f);
        }

        items.loot.push_back(std::move(item));
    }

    items.counter = 1;

    std::sort( items.loot.begin(), items.loot.end(), 
        [](const auto& a, const auto& b) -> bool { return (a.chance > b.chance); } );
    
    g_Loot.insert({ Cha->Info->id, std::move(items) });

    return const_cast<stCharacter*>(Cha);
}

// void NetActorDestroy(unsigned int nID, char chSeeType)
void __cdecl pkodev::hook::NetActorDestroy(unsigned int nID, char chSeeType)
{
    const stCharacter* Cha = import::CGameScene__SearchByID(
        Utils::Get<void*>(address::MOD_EXE_VERSION::CGameApp___pCurScene), nID);

    if ( (chSeeType == 0) && (Cha != nullptr) && (Cha->IsMonster() == true) )
    {
        const auto it = g_Loot.find(Cha->Info->id);
        if ( ( it != g_Loot.end() ) && ( --(it->second.counter) == 0) ) {
            g_Loot.erase(it);
        }
    }

    import::NetActorDestroy(nID, chSeeType);
}

// int CSystemProperties::readFromFile(const char * szIniFileName)
int __fastcall pkodev::hook::CSystemProperties__readFromFile(void* This,
    void*, const char* szIniFileName)
{
    const int ret = import::CSystemProperties__readFromFile(This, szIniFileName);

    if (ret == 0) {
        const int DEFAULT_NUM = -2;
        const int num = GetPrivateProfileIntA("gameOption", "dropInfo", DEFAULT_NUM, szIniFileName);
        if (num == DEFAULT_NUM) { return DEFAULT_NUM; }
        g_ShowDrop = ( (num == 0) ? false : true );
    }

    return ret;
}

// int CSystemProperties::writeToFile(const char * szIniFileName)
int __fastcall pkodev::hook::CSystemProperties__writeToFile(void* This,
    void*, const char* szIniFileName)
{
    const int ret = import::CSystemProperties__writeToFile(This, szIniFileName);

    if (ret == 0) {
        char szBuf[8]{ 0x00 };
        sprintf_s(szBuf, sizeof(szBuf), "%d", ( (g_ShowDrop == true) ? 1 : 0) );
        if (WritePrivateProfileStringA("gameOption", "dropInfo", szBuf, szIniFileName) == false) {
            return -1;
        }
    }

    return ret;
}

// void CSystemMgr::_evtGameOptionFormBeforeShow(CForm* pForm, bool& IsShow)
void __cdecl pkodev::hook::CSystemMgr___evtGameOptionFormBeforeShow(void* pForm,
    bool& IsShow)
{
    import::CSystemMgr___evtGameOptionFormBeforeShow(pForm, IsShow);

    gui::CForm* frmGame = gui::CUIInterface::Instance().FindForm("frmGame");
    if (frmGame != nullptr) {
        void* cbxDropInfo = frmGame->Find<void*>("cbxDropInfo");
        if (cbxDropInfo != nullptr) {
            import::CCheckGroup__SetActiveIndex(cbxDropInfo, ( (g_ShowDrop == false) ? 0 : 1) );
        }
    }
}

// void CSystemMgr::_evtGameOptionFormMouseDown(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
void __cdecl pkodev::hook::CSystemMgr___evtGameOptionFormMouseDown(void* pSender,
    int nMsgType, int x, int y, DWORD dwKey)
{
    auto ExtractString = [](void* std__string) -> std::string 
    {
        if (Utils::Get<unsigned int, 0x28>(std__string) < 16u) {
            return std::string(reinterpret_cast<const char *>(
                reinterpret_cast<unsigned int>(std__string) + 0x14));
        }

        return std::string(*reinterpret_cast<const char**>(
                reinterpret_cast<unsigned int>(std__string) + 0x14));
    };

    if ( ExtractString(pSender) == "btnYes" ) {
        gui::CForm* frmGame = gui::CUIInterface::Instance().FindForm("frmGame");
        if (frmGame != nullptr) {
            void* cbxDropInfo = frmGame->Find<void>("cbxDropInfo");
            if (cbxDropInfo != nullptr) {
                const int idx = Utils::Get<int, 0xBC>(cbxDropInfo);
                g_ShowDrop = ( (idx == 0) ? false : true );
            }
        }
    }

    pkodev::import::CSystemMgr___evtGameOptionFormMouseDown(pSender, nMsgType, x, y, dwKey);
}

// void  CStartMgr::PopMenu(CCharacter* pCha)
void __fastcall pkodev::hook::CStartMgr__PopMenu(void* This, void*, const stCharacter* pCha)
{
    if (pCha->IsMonster() == false) {
        import::CStartMgr__PopMenu(This, pCha);
        return;
    }

    static gui::CForm* pMain800 = gui::CUIInterface::Instance().FindForm("frmMain800");
    if (pMain800 == nullptr) {
        return;
    }

    static gui::CMenu* mobMouseRight = gui::CUIInterface::Instance().FindMenu("mobMouseRight");
    if (mobMouseRight == nullptr) {
        return;
    }
    
    const Vector2D<int> screen = gui::CRender::WorldToScreen({ pCha->x, pCha->y, pCha->z });
    
    mobMouseRight->OnMouseDown(&OnMonsterMenuPopup);
    mobMouseRight->SetPointer(pCha);
    
    pMain800->PopMenu(mobMouseRight, screen.x, screen.y);
}

void __cdecl OnMonsterMenuPopup(pkodev::gui::CMenu* pSender, int x, int y, unsigned int key)
{
    using namespace pkodev;

    pSender->SetIsShow(false);

    const stCharacter* pCha = pSender->GetPointer<stCharacter>();
    if (pCha == nullptr) {
        return;
    }

    static gui::CForm* frmMobDrops = gui::CUIInterface::Instance().FindForm("frmMobDrops");
    if (frmMobDrops == nullptr) {
        return;
    }

    static gui::CLabel* labMobDropsItemName = frmMobDrops->Find<gui::CLabel>("labMobDropsItemName");
    if (labMobDropsItemName != nullptr) 
    {
        const std::string chaName(pCha->Info->name);
        labMobDropsItemName->SetCaption(
            ( chaName.length() > MAX_FORM_CHANAME_LEN ) 
                ? chaName.substr(0, MAX_FORM_CHANAME_LEN - 3).append("...")
                : chaName
        );
    }

    static gui::CListView* lstItemDrop = frmMobDrops->Find<gui::CListView>("lstItemDrop");
    if (lstItemDrop != nullptr)
    {
        lstItemDrop->GetList()->SetIsChangeColor(false);
        lstItemDrop->GetList()->GetItems()->Clear();

        const auto it = g_Loot.find(pCha->Info->id);
        if (it != g_Loot.end()) 
        {
            static char text[128]{ 0x00 };
            for (const auto& item : it->second.loot)
            {
                if (item.info == nullptr) { continue; }

                if (item.name.length() > MAX_FORM_NAME_LEN) {
                    sprintf_s(text, sizeof(text), "%s...\n%.2f%%",
                        item.name.substr(0, MAX_FORM_NAME_LEN - 3).c_str(), item.chance);
                }
                else {
                    sprintf_s(text, sizeof(text), "%s\n%.2f%%",
                        item.name.c_str(), item.chance);
                }

                gui::CItemRow* row = lstItemDrop->GetList()->GetItems()->NewItem();
                row->SetIndex(0, gui::CItemCommand::Create(item.info));
                row->SetIndex(1, gui::CItemEx::Create(text, GetColor(item.chance, g_FormPalette)));

                lstItemDrop->Refresh();
            }
        }
    }

    frmMobDrops->Show();
}

float GetDropRate(const std::string& path)
{
    float ret = 1.0f;

    std::ifstream file(path, std::ios::in);

    if (file.is_open() == false) { return ret; }

    file >> ret;

    if (!file) {  ret = 1.0f; }

    file.close();
    
    return ret;
}

template<typename ColorType>
ColorType GetColor(float percentage, const PaletteType<ColorType>& palette)
{
    if (palette.empty() == true) {
        return static_cast<ColorType>(0xFFFFFFFF);
    }

    for (const auto& [threshold, color] : palette) {
        if (percentage >= threshold) {
            return color;
        }
    }

    return palette.cend()->second;
}