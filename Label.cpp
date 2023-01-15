#include "Label.h"
#include "Utils.h"

namespace pkodev { namespace gui {

	void CLabel::SetCaption(const std::string& caption)
	{
		typedef void(__thiscall* CLabel__SetCaption__Ptr)(void*, const char*);
		CLabel__SetCaption__Ptr proc = Utils::Get<CLabel__SetCaption__Ptr, 0x3C>(m_vtable);
		proc(this, caption.c_str());
	}

} }