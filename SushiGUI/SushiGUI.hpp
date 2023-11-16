# pragma once
# include <Siv3D.hpp>

namespace s3d {
	namespace SushiGUI {

		using position_type = Vec2;
		using size_type = Vec2;


		void draw_button_label(const String &label, const Rect &rect, const Font &font);

		//template<class T, std::enable_if_t<std::is_same<T, Arg::topLeft_<position_type>>::value || std::is_same<T, Arg::topCenter_<position_type>>::value || std::is_same<T, Arg::topRight_<position_type>>::value ||
		//std::is_same<T, Arg::leftCenter_<position_type>>::value || std::is_same<T, Arg::center_<position_type>>::value || std::is_same<T, Arg::rightCenter_<position_type>>::value ||
		//std::is_same<T, Arg::bottomLeft_<position_type>>::value || std::is_same<T, Arg::bottomCenter_<position_type>>::value || std::is_same<T, Arg::bottomRight_<position_type>>::value>* = nullptr>
		//void button1(const StringView & label, const T & anchor, const Point & size);
		constexpr Color button1_color_release{ U"#EA4C89" };
		constexpr Color button1_color_mouseover{ U"#F082AC" };
		bool button1(const Font &font, const StringView &label, const Arg::topRight_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::topCenter_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::topRight_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::leftCenter_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::center_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::rightCenter_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::bottomLeft_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::bottomCenter_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView &label, const Arg::bottomRight_<position_type> &anchor, const size_type&size);
		bool button1(const Font &font, const StringView& label, const position_type& pos, const size_type& size);
	}
}
