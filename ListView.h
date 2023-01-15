#pragma once
#include "ItemObj.h"

namespace pkodev { namespace gui {

	class CItemRow final {
		public:
			CItemRow() = delete;
			void SetIndex(unsigned int index, CItemObj* ItemObj);
	};

	class CListItems final {
		public:
			CListItems() = delete;
			CItemRow* NewItem();
			void Clear();
		private:
			void* m_vtable;
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
			void Refresh();
		private:
			void* m_vtable;
			const char m_nop[0x9C];
			CList* m_list;
	};



} }
