#pragma once
#include <string>

namespace pkodev { namespace gui {

	class CForm final
	{
		public:
			CForm(void* This = nullptr);
			~CForm() = default;
			void* Find(const std::string& name);
			void PopMenu(void* menu, int x, int y);

		private:
			void* m_This;
	};

} }

