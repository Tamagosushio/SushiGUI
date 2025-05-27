#include <Siv3D.hpp>
#include "SushiGUI.hpp"
#include "Pendulum.hpp"
#include "MakeGif.hpp"


void Main() {

  Scene::SetBackground(Palette::Lightblue);

  SimplePendulum pendulum1{};
  SimplePendulum pendulum2{ 0.25_pi, 0.5 };
  SimplePendulum pendulum3{ 0.75_pi, 2.0, 9.8*2 };
  SimplePendulum pendulum4{ 0.50_pi, 1.0, 9.8*2 };

  MakeGif makegif{ U"./output.gif" };

  while (System::Update()) {
    Circle{ Scene::CenterF() + 100 * pendulum1.update(), 5.0 }.draw(Palette::Red);
    Circle{ Scene::CenterF() + 100 * pendulum2.update(), 5.0 }.draw(Palette::Green);
    Circle{ Scene::CenterF() + 100 * pendulum3.update(), 5.0 }.draw(Palette::Blue);
    Circle{ Scene::CenterF() + 100 * pendulum4.update(), 5.0 }.draw(Palette::Black);

    if (SimpleGUI::Button(U"start!", Vec2{ 0.0, 0.0 })) {
      makegif.start();
    }
    makegif.capture();
    if (SimpleGUI::Button(U"end!", Vec2{ 100.0, 0.0 })) {
      makegif.end();
    }
  }
}
