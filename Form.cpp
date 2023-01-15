#include "import.h"
#include "Form.h"

namespace pkodev { namespace gui { 

	void CForm::PopMenu(const CMenu* menu, int x, int y)
	{
		return import::CForm__PopMenu(this, menu, x, y);
	}

	void CForm::Show()
	{
		return import::CForm__Show(this);
	}

	void* CFindMethodProxy::Find(CForm* form, const char* name) {
		return import::CForm__Find(form, name);
	};

} }