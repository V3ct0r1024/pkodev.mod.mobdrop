#include "import.h"
#include "Form.h"

namespace pkodev { namespace gui { 

	CForm::CForm(void* This) :
		m_This(This)
	{

	}

	void* CForm::Find(const std::string& name)
	{
		return import::CForm__Find(this, name.c_str());
	}

	void CForm::PopMenu(void* menu, int x, int y)
	{
		return import::CForm__PopMenu(this, menu, x, y);
	}

} }