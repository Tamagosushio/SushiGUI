#include <Siv3D.hpp>
#include "SushiGUI.hpp"
#include "Pendulum.hpp"
#include "MakeGif.hpp"


void Main() {

  Scene::SetBackground(Palette::Lightblue);

  DoublePendulum d_pendulum1{
    0.500000_pi, 1.5, 2.0,
    0.00_pi, 0.5, 0.5,
    9.8, 100.0, Scene::CenterF()
  };
  DoublePendulum d_pendulum2{
    0.499999_pi, 1.5, 2.0,
    0.00_pi, 0.5, 0.5,
    9.8, 100.0, Scene::CenterF()
  };

  MakeGif makegif{ U"./output.gif" };

  Array<Vec2> points1;
  Array<Vec2> points2;

  while (System::Update()) {

    d_pendulum1.update();
    d_pendulum2.update();

    Circle{ d_pendulum1.get_coordinate0(), 5.0}.draw(Palette::Black);
    Circle{ d_pendulum1.get_coordinate1(), 5.0 }.draw(Palette::Black);
    Line{ d_pendulum1.get_offset() , d_pendulum1.get_coordinate0()}.draw(Palette::Black);
    Line{ d_pendulum1.get_coordinate0(), d_pendulum1.get_coordinate1() }.draw(Palette::Black);
    points1 << d_pendulum1.get_coordinate1();
    for (const Vec2& point : points1) {
      Circle{ point, 1.0 }.draw(Palette::Red);
    }

    Circle{ d_pendulum2.get_coordinate0(), 5.0 }.draw(Palette::Black);
    Circle{ d_pendulum2.get_coordinate1(), 5.0 }.draw(Palette::Black);
    Line{ d_pendulum2.get_offset(), d_pendulum2.get_coordinate0()}.draw(Palette::Black);
    Line{ d_pendulum2.get_coordinate0(), d_pendulum2.get_coordinate1() }.draw(Palette::Black);
    points2 << d_pendulum2.get_coordinate1();
    for (const Vec2& point : points2) {
      Circle{ point, 1.0 }.draw(Palette::Blue);
    }


    if (SimpleGUI::Button(U"start!", Vec2{ 0.0, 0.0 })) {
      makegif.start();
    }
    makegif.capture();
    if (SimpleGUI::Button(U"end!", Vec2{ 100.0, 0.0 })) {
      makegif.end();
    }
  }
}
