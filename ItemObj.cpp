#include "ItemObj.h"
#include "import.h"

namespace pkodev { namespace gui { 

	CItemEx* CItemEx::Create(const std::string& text, unsigned int color)
	{
		void* mem = import::operator_new(0xB4);
		if (mem != nullptr) {
			import::CItemEx__CItemEx(mem, text.c_str(), color);
		}
		return reinterpret_cast<CItemEx*>(mem);
	}

	CItemCommand* CItemCommand::Create(const ItemRecord* item)
	{
		void* mem = import::operator_new(0xEC);
		if (mem != nullptr) {
			import::CItemCommand__CItemCommand(mem, item);
		}
		return reinterpret_cast<CItemCommand*>(mem);
	}

} }