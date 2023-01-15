#include "address.h"
#include "import.h"
#include "UIInterface.h"

namespace pkodev { namespace gui {

	CUIInterface::CUIInterface() :
		m_this(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CUIInterface))
	{

	}

	CUIInterface& CUIInterface::Instance()
	{
		static CUIInterface instance;
		return instance;
	}

	CForm* CUIInterface::FindForm(const std::string& name)
	{
		return import::CUIInterface___FindForm(m_this, name.c_str());
	}

	gui::CMenu* CUIInterface::FindMenu(const std::string& name)
	{
		return import::CMenu__FindMenu(name.c_str());
	}

} }
