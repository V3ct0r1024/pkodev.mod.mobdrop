#pragma once
#include <string>
#include "Form.h"

namespace pkodev { namespace gui {

	class CUIInterface final
	{
		public:
			~CUIInterface() = default;
			static CUIInterface& Instance();
			CForm* FindForm(const std::string& name);
			CMenu* FindMenu(const std::string& name);

		private:
			CUIInterface();
			void* m_this;
	};

} }

