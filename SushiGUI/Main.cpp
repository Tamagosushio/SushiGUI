# include <Siv3D.hpp> // Siv3D v0.6.12
# include "SushiGUI.hpp"

void Main() {

	Font font{ 100 };

	while (System::Update()) {
		Arg::leftCenter_<Vec2> anchor = Vec2{ Scene::Center().x, Scene::Center().y };
		SushiGUI::button1(font, U"う～んそうだねそういう油の安定系あのαみたいな", anchor, Vec2{ 100, 50 });
		SushiGUI::button1(font, U"きもちよく～", Arg::topRight(150, 150), Vec2{100, 50});
		//SushiGUI::button1(U"ｵﾛ", Point{Scene::Center().x, Scene::Center().y}, Size{ 100, 200 });
	}
	Circle{ Arg::bottomCenter(100, 100 ), 50};

}
