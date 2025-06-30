# pragma once
# include <Siv3D.hpp>

namespace s3d {
	namespace SushiGUI {

		using position_type = Vec2;
		using size_type = Vec2;

		constexpr double rect_stretch_rate = 20;
		void draw_button_label(const StringView& label, const RectF& rectf, const Font& font, const Color& color);
		bool is_click_button(const RectF& rectf);
		bool is_click_button(const RoundRect& roundrect);

		struct ButtonStyle {
			Color color_release;
			Optional<Color> color_mouseover;
			Optional<Color> color_press;
			Color color_label;
			Optional<Color> color_frame;
      Optional<double> roundrect_rate;
      Optional<double> frame_thickness_rate;
		};

		inline constexpr ButtonStyle button1_style{
			.color_release = Color{ U"#EA4C89" },
			.color_mouseover = Color{ U"#F082AC" },
			.color_press = unspecified,
			.color_label = Color{ U"#FFFFFF" },
			.color_frame = unspecified,
			.roundrect_rate = 5.0,
			.frame_thickness_rate = unspecified,
		};

		inline constexpr ButtonStyle button2_style{
			.color_release = Color{ U"#F5F5F5" },
			.color_mouseover = unspecified,
			.color_press = unspecified,
			.color_label = Color{ U"#333333" },
			.color_frame = unspecified,
			.roundrect_rate = 5.0,
			.frame_thickness_rate = unspecified,
		};

		inline constexpr ButtonStyle button3_style{
			.color_release = Color{ U"#2EA44F" },
			.color_mouseover = Color{ U"#2C974B" },
			.color_press = Color{ U"#298E46" },
			.color_label = Color{ U"#FFFFFF" },
			.color_frame = unspecified,
			.roundrect_rate = 5.0,
			.frame_thickness_rate = unspecified,
		};

		inline constexpr ButtonStyle button4_style{
			.color_release = Color{ U"#FAFBFC" },
			.color_mouseover = Color{ U"#F3F4F6" },
			.color_press = Color{ U"#EAECF0" },
			.color_label = Color{ U"#24292E" },
			.color_frame = Color{ U"#1b1f23" },
			.roundrect_rate = 5.0,
			.frame_thickness_rate = 50.0,
		};

		bool button(const Font& font, const StringView& label, const position_type& pos, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
		bool button(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled = true);
    bool button(const Font& font, const StringView& label, const RectF button_rectf, const ButtonStyle& style, bool enabled = true);

		bool button1(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button1(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true);
    bool button1(const Font& font, const StringView& label, const RectF button_rectf, bool enabled = true);

		bool button2(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button2(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true);
    bool button2(const Font& font, const StringView& label, const RectF button_rectf, bool enabled = true);

		bool button3(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button3(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true);
    bool button3(const Font& font, const StringView& label, const RectF button_rectf, bool enabled = true);

		bool button4(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled = true);
		bool button4(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true);
    bool button4(const Font& font, const StringView& label, const RectF button_rectf, bool enabled = true);

	}
}
