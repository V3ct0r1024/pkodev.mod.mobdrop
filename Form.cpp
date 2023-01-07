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


} }