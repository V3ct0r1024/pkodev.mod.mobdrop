#pragma once
#include <string>
#include "structure.h"

namespace pkodev { namespace gui {

	class CGuiPic final
	{
		public:

			CGuiPic();
			~CGuiPic();

			CGuiPic(const CGuiPic& ob);
			CGuiPic(CGuiPic&& ob) noexcept;

			CGuiPic& operator=(const CGuiPic& ob);
			CGuiPic& operator=(CGuiPic&& ob) noexcept;

			bool Load(const std::string& path, unsigned int w, unsigned int h,
				float scalex = 1.0f, float scaley = 1.0f);
			void Unload(int frame = -1);
			
			void Render(int x, int y) const;

			unsigned int GetWidth() const { return static_cast<unsigned int>(m_width * m_scalex); }
			unsigned int GetHeight() const { return static_cast<unsigned int>(m_height * m_scaley); }

			float GetScaleX() const { return m_scalex; }
			float GetScaleY() const { return m_scaley; }

			Vector2D<unsigned int> GetSize() const { return { GetWidth(), GetHeight() }; }
			Vector2D<float> GetScale() const { return { m_scalex, m_scaley }; }

			const std::string& GetPath() const { return m_path; }

			static std::string GetIconFile(const std::string& icon);

		private:

			unsigned int m_width;
			unsigned int m_height;

			float m_scalex;
			float m_scaley;

			std::string m_path;

			mutable char m_data[0x14];
	};

}}
