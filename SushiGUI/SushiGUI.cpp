# pragma once
# include <Siv3D.hpp>
# include "SushiGUI.hpp"

namespace s3d {
	namespace SushiGUI {

		void draw_button_label(const StringView &label, const RectF &rectf, const Font& font) {
			int left = 0, right = 1000;
			while (Abs(right - left) > 1) {
				int mid = (left + right) / 2;
				if (font(label).draw(mid, rectf.stretched(Min(-rectf.h / 20, -rectf.w / 20)), HSV{0,0})) {
					left = mid;
				}else {
					right = mid;
				}
			}
			font(label).drawAt(left, rectf.center(), Palette::White);
		}

		//template<class T, std::enable_if_t<std::is_same<T, Arg::topLeft_<Point>>::value || std::is_same<T, Arg::topCenter_<Point>>::value || std::is_same<T, Arg::topRight_<Point>>::value ||
		//	std::is_same<T, Arg::leftCenter_<Point>>::value || std::is_same<T, Arg::center_<Point>>::value || std::is_same<T, Arg::rightCenter_<Point>>::value ||
		//	std::is_same<T, Arg::bottomLeft_<Point>>::value || std::is_same<T, Arg::bottomCenter_<Point>>::value || std::is_same<T, Arg::bottomRight_<Point>>::value>>
		//void button1(const StringView &label, const T &anchor, const Point &size) {
		//	Rect{ anchor, size }.draw(Palette::Blue);
		//}
		bool button1(const Font &font, const StringView &label, const Arg::topLeft_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x, anchor->y }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::topCenter_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x - size.x / 2, anchor->y }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::topRight_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x - size.x, anchor->y }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::leftCenter_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x, anchor->y - size.y / 2 }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::center_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x - size.x / 2, anchor->y - size.y / 2 }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::rightCenter_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x - size.x, anchor->y - size.y / 2 }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::bottomLeft_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x, anchor->y - size.y }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::bottomCenter_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x / 2, anchor->y - size.y }, size);
		}
		bool button1(const Font& font, const StringView &label, const Arg::bottomRight_<position_type> &anchor, const size_type &size) {
			return button1(font, label, position_type{ anchor->x - size.x, anchor->y - size.y }, size);
		}
		bool button1(const Font& font, const StringView &label, const position_type &pos, const size_type &size) {
			const RectF button_rectf{ pos, size };
			if (button_rectf.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
				button_rectf.rounded(Min(size.x / 5, size.y / 5)).draw(button1_color_mouseover);
				if (button_rectf.leftClicked()) {
					return true;
				}
			}else {
				button_rectf.rounded(Min(size.x / 5, size.y / 5)).draw(button1_color_release);
			}
			draw_button_label(label, button_rectf, font);
			return false;
		}
	}
}
