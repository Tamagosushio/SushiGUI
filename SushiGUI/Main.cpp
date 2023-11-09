# include <Siv3D.hpp> // Siv3D v0.6.12
# include "SushiGUI.hpp"

void Main(){

	while (System::Update()) {
		Rect{ 100,100 }.draw(Arg::topCenter(Point{ 100,100 }), Palette::Black);
		SushiGUI::draw_rect();
	}

}
