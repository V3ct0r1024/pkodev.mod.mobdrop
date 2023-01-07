#pragma once
#include <string>

namespace pkodev { namespace gui {

	class CForm final
	{
		public:
			CForm(void* This = nullptr);
			~CForm() = default;
			void* Find(const std::string& name);

		private:
			void* m_This;
	};

} }

