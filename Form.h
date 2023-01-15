#pragma once
#include <string>
#include "Menu.h"
#include "FindMethodProxy.h"

namespace pkodev { namespace gui {

	class CForm final
	{
		public:
			CForm() = delete;

			template<typename T>
			T* Find(const std::string& name);

			void PopMenu(const CMenu* menu, int x, int y);
			void Show();
	};

	template<typename T>
	T* CForm::Find(const std::string& name)
	{
		return reinterpret_cast<T*>(CFindMethodProxy::Find(this, name.c_str()));
	}

} }

