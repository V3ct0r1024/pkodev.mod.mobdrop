#include "ListView.h"
#include "import.h"
#include "Utils.h"

namespace pkodev { namespace gui {

	void CItemRow::SetIndex(unsigned int index, CItemObj* data)
	{
		import::CItemRow__SetIndex(this, index, data);
	}

	CItemObj* CItemRow::GetIndex(unsigned int index)
	{
		return *reinterpret_cast<CItemObj**>( (index * 0x04) + Utils::Get<unsigned int>(this) );
	}

	CItemRow* CListItems::NewItem()
	{
		return import::CListItems__NewItem(this);
	}

	CItemRow* CListItems::GetItem(int index)
	{
		return import::CListItems__GetItem(this, index);
	}

	void CListItems::Clear()
	{
		typedef void(__thiscall* CListItems__Clear__Ptr)(void*);
		CListItems__Clear__Ptr CListItems__Clear = Utils::Get<CListItems__Clear__Ptr, 0x0C>(m_vtable);
		CListItems__Clear(this);
	}

	int	CListItems::PointToRow(int x, int y) const
	{
		if ( (x >= m_nX1) && (x <= m_nX2) && (y >= m_nY1) && (y <= m_nY2) ) {
			return (y - m_nY1) / m_nHeight + m_dwFirstShowRow;
		}
		return -1;
	}

	bool CListView::InRect(int x, int y)
	{
		return (m_IsMouseIn = (x >= m_nX1) && (x <= m_nX2) && (y >= m_nY1) && (y <= m_nY2) );
	}

	void CListView::Refresh()
	{
		typedef void(__thiscall* CListView__Refresh__Ptr)(void*);
		CListView__Refresh__Ptr CListView__Refresh = Utils::Get<CListView__Refresh__Ptr, 0x14>(m_vtable);
		CListView__Refresh(this);
	}

} }