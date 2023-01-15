#pragma once
#include <string>

namespace pkodev { namespace gui {
	class CForm;
	class CFindMethodProxy final {
		public: 
			static void* Find(CForm* form, const char* name);
	};
} }