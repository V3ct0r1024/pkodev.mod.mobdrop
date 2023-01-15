#include "Menu.h"
#include "Utils.h"

namespace pkodev { namespace gui {

	void CMenu::SetIsShow(bool show)
	{
		typedef void (__thiscall* CMenu__SetIsShow__Ptr)(void*, bool);
		CMenu__SetIsShow__Ptr proc = Utils::Get<CMenu__SetIsShow__Ptr, 0x50>(m_vtable);
		proc(this, show);
	}

} }