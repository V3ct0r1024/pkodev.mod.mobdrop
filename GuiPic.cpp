#include "address.h"
#include "import.h"
#include "Utils.h"
#include "GuiPic.h"

namespace pkodev { namespace gui {

	CGuiPic::CGuiPic() :
		m_width(0),
		m_height(0),
		m_scalex(1.0f),
		m_scaley(1.0f),
		m_path("")
	{
		import::CGuiPic__CGuiPic(m_data, nullptr, 0);
	}

	CGuiPic::~CGuiPic()
	{
		import::operator_delete_array(Utils::Get<void*>(m_data));
	}

	CGuiPic::CGuiPic(const CGuiPic& ob) :
		m_width(ob.m_width),
		m_height(ob.m_height),
		m_scalex(ob.m_scalex),
		m_scaley(ob.m_scaley),
		m_path(ob.m_path)
	{
		import::CGuiPic__CGuiPic(m_data, nullptr, 0);
		import::CGuiPic__LoadImage(m_data, m_path.c_str(),
			m_width, m_height, 0, 0, 0, m_scalex, m_scaley);
	}

	CGuiPic::CGuiPic(CGuiPic&& ob) noexcept :
		m_width(ob.m_width),
		m_height(ob.m_height),
		m_scalex(ob.m_scalex),
		m_scaley(ob.m_scaley),
		m_path(ob.m_path)
	{
		std::memcpy(m_data, ob.m_data, sizeof(m_data));
		std::memset(ob.m_data, 0x00, sizeof(ob.m_data));

		ob.m_width = 0; ob.m_height = 0;
		ob.m_scalex = 1.0f; ob.m_scaley = 1.0f;
		ob.m_path = "";
	}

	CGuiPic& CGuiPic::operator=(const CGuiPic& ob)
	{
		if (this == &ob) { return *this; }

		m_width = ob.m_width; m_height = ob.m_height;
		m_scalex = ob.m_scalex; m_scaley = ob.m_scaley;
		m_path = ob.m_path;

		import::CGuiPic__CGuiPic(m_data, nullptr, 0);
		import::CGuiPic__LoadImage(m_data, m_path.c_str(),
			m_width, m_height, 0, 0, 0, m_scalex, m_scaley);

		return *this;
	}

	CGuiPic& CGuiPic::operator=(CGuiPic&& ob) noexcept
	{
		std::memcpy(m_data, ob.m_data, sizeof(m_data));
		std::memset(ob.m_data, 0x00, sizeof(ob.m_data));

		m_width = ob.m_width; m_height = ob.m_height;
		m_scalex = ob.m_scalex; m_scaley = ob.m_scaley;
		m_path = ob.m_path;

		ob.m_width = 0; ob.m_height = 0;
		ob.m_scalex = 1.0f; ob.m_scaley = 1.0f;
		ob.m_path = "";

		return *this;
	}

	bool CGuiPic::Load(const std::string& path, unsigned int w,
		unsigned int h, float scalex, float scaley)
	{
		m_width = w; m_height = h;
		m_scalex = scalex; m_scaley = scaley;
		m_path = path;

		return import::CGuiPic__LoadImage( m_data, path.c_str(),
			w, h, 0, 0, 0, scalex, scaley );
	}

	void CGuiPic::Unload(int frame)
	{
		import::CGuiPic__UnloadImage(m_data, frame);
	}

	void CGuiPic::Render(int x, int y) const
	{
		import::CGuiPic__Render( reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiPic),
			x, y, Utils::Get<unsigned int>(m_data) + Utils::Get<unsigned int, 0x04>(m_data) );
	}

	std::string CGuiPic::GetIconFile(const std::string& icon)
	{
		static char buf[64]{ 0x00 };
		sprintf_s(buf, sizeof(buf), "texture/icon/%s.tga", icon.c_str());

		return std::string(buf);
	}

}}
