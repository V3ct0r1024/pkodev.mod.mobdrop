#pragma once
#include <functional>

namespace pkodev { namespace gui {

	class CMenu final
	{
		public:
			typedef void(__cdecl* OnMouseDownHandler__Ptr)(CMenu*, int, int, unsigned int);

			CMenu() = delete;
			void SetIsShow(bool show = true);

			template<typename T>
			void SetPointer(const T* ptr);

			template<typename T>
			T* GetPointer() const;

			inline void OnMouseDown(OnMouseDownHandler__Ptr handler) { m_onMouseDownHandler = handler; }
			
		private:
			void* m_vtable;
			char m_nop0[0x70];
			void* m_pointer;
			char m_nop1[0x04];
			OnMouseDownHandler__Ptr m_onMouseDownHandler;
	};

	template<typename T>
	void CMenu::SetPointer(const T* ptr)
	{
		m_pointer = reinterpret_cast<void*>(const_cast<T*>(ptr));
	}

	template<typename T>
	T* CMenu::GetPointer() const
	{
		return reinterpret_cast<T*>(m_pointer);
	}

} }

