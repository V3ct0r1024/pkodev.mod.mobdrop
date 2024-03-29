#pragma once

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#include <string>
#include <vector>


namespace pkodev {

	const unsigned int MAX_ITEMS = 10;

	template<typename T>
	struct Vector2D {
		T x;
		T y;
	};

	template<typename T>
	struct Vector3D {
		T x;
		T y;
		T z;
	};

	struct ItemPair final {
		const int id;
		const int coeff;

		float Chance(float rate = 1.0f) const {
			return min( rate * ( (100.0f / coeff) * 1.0f) * 100.0f, 100.0f);
		}
	};

	struct ChaRecord final {
		const char nop0[0x04];
		const int id;
		const char name[0x0028];
		const char nop1[0x0160];
		const ItemPair items[MAX_ITEMS];
	};

	struct ItemRecord final {
		const char nop0[0x04];
		const int id;
		const char name[0x48];
		const char nop1[0x70];
		const char icon[17];
	};

	struct stCharacter final {
		const char nop0[0x1F8];
		const float x;
		const float y;
		const char nop1[0x0104];
		const float z;
		const char nop2[0x010C];
		const ChaRecord* Info;
		const char nop3[0x08C0];
		const int type;

		bool IsMonster() const {
			return (type >= 5 && type <= 9);
		}
	};

}