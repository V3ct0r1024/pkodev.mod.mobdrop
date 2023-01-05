#include "address.h"
#include "import.h"
#include "Utils.h"
#include "TextLabel.h"

namespace pkodev { namespace gui {

	Vector2D<int> CTextLabel::GetTextSize(const std::string& text)
	{
		Vector2D<int> size{ 0, 0 };

		import::CMPFont__GetTextSize ( Utils::Get<void*>(address::MOD_EXE_VERSION::CMPFont),
			const_cast<char*>(text.c_str()), &size, 1.0f );

		return size;
	}

	CTextLabel::CTextLabel() :
		m_text{ "" },
		m_color{ Colors::White },
		m_background { Colors::Black }
	{

	}

	CTextLabel::CTextLabel(const std::string& text, const Colors& color,
			const Colors& background) :
		m_text{ text },
		m_color{ color },
		m_background{ background }
	{

	}

	void CTextLabel::SetColor(const Colors& color)
	{
		m_color = color;
	}

	const CTextLabel::Colors& CTextLabel::GetColor() const
	{
		return m_color;
	}

	void CTextLabel::SetBackgroundColor(const Colors& color)
	{
		m_background = color;
	}

	const CTextLabel::Colors& CTextLabel::GetBackgroundColor() const
	{
		return m_background;
	}

	void CTextLabel::SetText(const std::string& text)
	{
		m_text = text;
	}

	const std::string& CTextLabel::GetText() const
	{
		return m_text;
	}

	void CTextLabel::Render(int x, int y) const
	{
		import::CGuiFont_BRender( reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiFont),
			m_text.c_str(), x, y, static_cast<int>(m_color), static_cast<int>(m_background) );
	}

	void CTextLabel::Render(const std::string& str, int x, int y,
		const Colors& color, const Colors& background)
	{
		import::CGuiFont_BRender( reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiFont),
			str.c_str(), x, y, static_cast<int>(color), static_cast<int>(background));
	}

}}