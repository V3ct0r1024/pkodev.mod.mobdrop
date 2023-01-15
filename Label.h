#pragma once
#include <string>

namespace pkodev { namespace gui {

	class CLabel final
	{
		public:
			CLabel() = delete;
			void SetCaption(const std::string& caption);

		private:
			void* m_vtable;
	};

} }

