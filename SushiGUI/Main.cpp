#include <Siv3D.hpp>
#include "SushiGUI.hpp"
#include "Pendulum.hpp"
#include "MakeGif.hpp"


void Main() {

  Scene::SetBackground(Palette::White);
  Window::Resize(1280, 720);
  Font font_button(48, Typeface::Bold);

  MakeGif makegif{ U"./output.gif" };

  while (System::Update()) {

    if (SushiGUI::Button1(font_button, U"button1", Arg::topRight(Scene::CenterF().withY(50)), Size{ 150, 50 })) {
      Print << U"button1";
    }
    if (SushiGUI::Button2(font_button, U"button2", Arg::topRight(Scene::CenterF().withY(110)), Size{ 150, 50 })) {
      Print << U"button2";
    }
    if (SushiGUI::Button3(font_button, U"button3", Arg::topRight(Scene::CenterF().withY(170)), Size{ 150, 50 })) {
      Print << U"button3";
    }
    if (SushiGUI::Button4(font_button, U"button4", Arg::topRight(Scene::CenterF().withY(230)), Size{ 150, 50 })) {
      Print << U"button4";
    }
    if (SushiGUI::Button5(font_button, U"button5", Arg::topRight(Scene::CenterF().withY(290)), Size{ 150, 50 })) {
      Print << U"button5";
    }
    if (SushiGUI::Button6(font_button, U"button6", Arg::topRight(Scene::CenterF().withY(350)), Size{ 150, 50 })) {
      Print << U"button6";
    }
    if (SushiGUI::Button7(font_button, U"button7", Arg::topRight(Scene::CenterF().withY(410)), Size{ 150, 50 })) {
      Print << U"button7";
    }
    if (SushiGUI::Button8(font_button, U"button8", Arg::topRight(Scene::CenterF().withY(470)), Size{ 150, 50 })) {
      Print << U"button8";
    }
    if (SushiGUI::Button9(font_button, U"button9", Arg::topRight(Scene::CenterF().withY(530)), Size{ 150, 50 })) {
      Print << U"button9";
    }
    if (SushiGUI::Button10(font_button, U"button10", Arg::topRight(Scene::CenterF().withY(590)), Size{ 150, 50 })) {
      Print << U"button10";
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
