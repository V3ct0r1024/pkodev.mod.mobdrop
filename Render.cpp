#include "address.h"
#include "import.h"
#include "Utils.h"
#include "Render.h"

namespace pkodev { namespace gui {

	Vector2D<int> CRender::WorldToScreen(const Vector3D<float>& Pos)
	{
        Vector2D<int> screen{ 0, 0 };

        import::MPRender__WorldToScreen( Utils::Get<void*>(pkodev::address::MOD_EXE_VERSION::MPRender),
            Pos.x, Pos.y, Pos.z, &screen.x, &screen.y );

        return screen;
	}

}}