#pragma once
#include <Windows.h>
#include <iostream>

namespace pkodev {

	class Utils final
	{
		public:

			template <typename T, int Offset = 0x00>
			static T Get(void* ptr);

			template <typename T, int Offset = 0x00>
			static T Get(unsigned int address);

			template <DWORD Address, typename T>
			static bool Patch(const T& data);
	};

	template <typename T, int Offset>
	T Utils::Get(void* ptr)
	{
		return *reinterpret_cast<T*>(reinterpret_cast<unsigned int>(ptr) + Offset);
	}

	template <typename T, int Offset>
	T Utils::Get(unsigned int address)
	{
		return Get<T, Offset>( reinterpret_cast<void*>(address) );
	}

	template <DWORD Address, typename T>
	bool Utils::Patch(const T& data)
	{
		DWORD access = PAGE_EXECUTE_READWRITE;
		std::cout << sizeof(data) << std::endl;
		if (VirtualProtect(reinterpret_cast<LPVOID>(Address), sizeof(data), access, &access) == FALSE) {
			return false;
		}

		if (WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(Address),
				reinterpret_cast<LPCVOID>(&data), sizeof(data), nullptr) == FALSE) {
			return false;
		}

		if (VirtualProtect(reinterpret_cast<LPVOID>(Address), sizeof(data), access, &access) == FALSE) {
			return false;
		}

		return true;
	}

}

