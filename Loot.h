#pragma once
#include <string>
#include <unordered_map>

#include "GuiPic.h"

namespace pkodev {

    struct LootItem final
    {
        float chance{ 0.0f };
        std::string name;
        gui::CGuiPic icon;
    };

    using LootEnum = std::vector<LootItem>;
    struct LootPair final 
    {
        unsigned int counter;
        LootEnum loot;

        LootPair() : counter(0)
        {
            loot.reserve(MAX_ITEMS);
        }
    };

    using Loot = std::unordered_map<int, pkodev::LootPair>;

}

