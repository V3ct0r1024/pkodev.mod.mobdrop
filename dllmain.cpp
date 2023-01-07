#include <fstream>
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

#include "Loot.h"


const unsigned int MAX_NAME_LEN = 24;

pkodev::Loot g_Loot;
float g_DropRate = 1.0f;
bool g_ShowDrop = false;


float GetDropRate(const std::string& path);


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
    char cfg_path[MAX_PATH]{ 0x00 };
    sprintf_s(cfg_path, sizeof(cfg_path), "%s\\%s.cfg", path, TOSTRING(MOD_NAME));

    g_DropRate = GetDropRate(cfg_path);

    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::import::CHeadSay__Render, pkodev::hook::CHeadSay__Render);
    DetourAttach(&(PVOID&)pkodev::import::stNetActorCreate__CreateCha, pkodev::hook::stNetActorCreate__CreateCha);
    DetourAttach(&(PVOID&)pkodev::import::NetActorDestroy, pkodev::hook::NetActorDestroy);
    DetourAttach(&(PVOID&)pkodev::import::CSystemProperties__readFromFile, pkodev::hook::CSystemProperties__readFromFile);
    DetourAttach(&(PVOID&)pkodev::import::CSystemProperties__writeToFile, pkodev::hook::CSystemProperties__writeToFile);
    DetourTransactionCommit();
}

void Stop()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::import::CHeadSay__Render, pkodev::hook::CHeadSay__Render);
    DetourDetach(&(PVOID&)pkodev::import::stNetActorCreate__CreateCha, pkodev::hook::stNetActorCreate__CreateCha);
    DetourDetach(&(PVOID&)pkodev::import::NetActorDestroy, pkodev::hook::NetActorDestroy);
    DetourDetach(&(PVOID&)pkodev::import::CSystemProperties__readFromFile, pkodev::hook::CSystemProperties__readFromFile);
    DetourDetach(&(PVOID&)pkodev::import::CSystemProperties__writeToFile, pkodev::hook::CSystemProperties__writeToFile);
    DetourTransactionCommit();
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
    static gui::CTextLabel::Colors color{ gui::CTextLabel::Colors::White };

    for (const auto& item : it->second.loot)
    {
        if (item.name.length() > MAX_NAME_LEN) {
            sprintf_s( text, sizeof(text), "%.2f%% %s...",
                item.chance, item.name.substr(0, MAX_NAME_LEN - 3).c_str() );
        }
        else {
            sprintf_s(text, sizeof(text), "%.2f%% %s",
                item.chance, item.name.c_str() );
        }
        
        if      (item.chance >= 75.0f) { color = gui::CTextLabel::Colors::Green;  }
        else if (item.chance >= 50.0f) { color = gui::CTextLabel::Colors::Yellow; }
        else if (item.chance >= 25.0f) { color = gui::CTextLabel::Colors::Orange; }
        else                           { color = gui::CTextLabel::Colors::Red;    }

        const int x = screen.x + ( (i < 5) ? -180 : 64 );
        const int y = screen.y + 20 - 64 + (16 * ( (i < 5) ? i : (i - 5) ) );

        item.icon.Render( (x - item.icon.GetWidth() - 4), (y - 4) );

        gui::CTextLabel::Render(text, x, y, color);
       
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

        const ItemRecord* info = import::GetItemRecordInfo(Cha->Info->items[i].id);
     
        if (info != nullptr) {
            item.name = info->name;
            item.icon.Load(gui::CGuiPic::GetIconFile(info->icon), 32, 32, 0.5f, 0.5f);
        }
        else {
            item.name = "Unknown item";
            item.icon.Load(gui::CGuiPic::GetIconFile("error"), 32, 32, 0.5f, 0.5f);
        }

        item.chance = Cha->Info->items[i].Chance(g_DropRate);

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