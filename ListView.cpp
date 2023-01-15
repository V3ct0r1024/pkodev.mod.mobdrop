#include "ListView.h"
#include "import.h"
#include "Utils.h"

namespace pkodev { namespace gui {

	void CItemRow::SetIndex(unsigned int index, CItemObj* data)
	{
		import::CItemRow__SetIndex(this, index, data);
	}

	CItemRow* CListItems::NewItem()
	{
		return import::CListItems__NewItem(this);
	}

	void CListItems::Clear()
	{
		typedef void(__thiscall* CListItems__Clear__Ptr)(void*);
		CListItems__Clear__Ptr CListItems__Clear = Utils::Get<CListItems__Clear__Ptr, 0x0C>(m_vtable);
		CListItems__Clear(this);
	}

	void CListView::Refresh()
	{
		typedef void(__thiscall* CListView__Refresh__Ptr)(void*);
		CListView__Refresh__Ptr CListView__Refresh = Utils::Get<CListView__Refresh__Ptr, 0x14>(m_vtable);
		CListView__Refresh(this);
	}

} }