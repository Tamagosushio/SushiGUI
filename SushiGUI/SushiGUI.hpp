# pragma once
# include <Siv3D.hpp>

namespace s3d {
	namespace SushiGUI {

		void draw_button1(const StringView &label, const Vec2 &pos, const Size &size);
		void draw_button1(const StringView &label, const Arg::topLeft_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::topCenter_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::topRight_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::leftCenter_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::center_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::rightCenter_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::bottomLeft_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::bottomCenter_<Vec2> anchor, const Size &size);
		void draw_button1(const StringView &label, const Arg::bottomRight_<Vec2> anchor, const Size &size);

		Rect
	}
}
