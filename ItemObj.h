#pragma once
#include <string>
#include "structure.h"

namespace pkodev { namespace gui { 

	class CItemObj
	{

	};

	class CItemEx final : public CItemObj
	{
		public:
			static CItemEx* Create(const std::string& text, unsigned int color);
		private:
			CItemEx();
	};

	class CItemCommand final : public CItemObj
	{
		public:
			static CItemCommand* Create(const ItemRecord* item);
		private:
			CItemCommand(const ItemRecord* item);
	};

} }

