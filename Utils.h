#pragma once

namespace pkodev {

	class Utils final
	{
		public:

			template <typename T, int Offset = 0x00>
			static T Get(void* ptr);

			template <typename T, int Offset = 0x00>
			static T Get(unsigned int address);
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

}

