#pragma once
#include "structure.h"

namespace pkodev { namespace gui {

	class CRender
	{
		public:

			static Vector2D<int> WorldToScreen(const Vector3D<float>& Pos);

	};

}}

