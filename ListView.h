#pragma once
#include "ItemObj.h"

namespace pkodev { namespace gui {

	class CItemRow final {
		public:
			CItemRow() = delete;
			void SetIndex(unsigned int index, CItemObj* ItemObj);
			CItemObj* GetIndex(unsigned int index);
		private:
			void* m_vtable;
	};

	class CListItems final {
		public:
			CListItems() = delete;
			CItemRow* NewItem();
			CItemRow* GetItem(int index);
			void Clear();
			int	PointToRow(int x, int y) const;
		private:
			void* m_vtable;
			char m_nop0[0x20];
			int m_nX1;
			int	m_nX2;
			int	m_nY1;
			int	m_nY2;
			int	m_nHeight;
			char m_nop1[0x04];
			int m_dwFirstShowRow;
	};

	class CList final {
		public:
			CList() = delete;
			inline CListItems* GetItems() const { return m_items; }
			inline void SetIsChangeColor(bool v) { m_isChangeColor = v; }
		private:
			const char m_nop0[0xA4];
			CListItems* m_items;
			const char m_nop1[0x28];
			bool m_isChangeColor;
	};

	class CListView final
	{
		public:
			CListView() = delete;
			inline CList* GetList() const { return m_list; }
			inline bool GetIsShow() const { return m_bShow; }
			bool InRect(int x, int y);
			void Refresh();
			
		private:
			void* m_vtable;
			const char m_nop0[0x38];
			int	m_nX1;
			int m_nX2;
			int m_nY1;
			int m_nY2;
			bool m_bShow;
			const char m_nop[0x08];
			bool m_IsMouseIn;
			const char m_nop1[0x4A];
			CList* m_list;
	};



} }
