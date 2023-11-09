# pragma once
# include <Siv3D.hpp>
# include "SushiGUI.hpp"

namespace s3d {
	namespace SushiGUI {
		void draw_rect(void) {
			Rect{ 100,100 }.draw(Palette::Black);
		}
	}
}
