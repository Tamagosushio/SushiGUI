# pragma once
# include <Siv3D.hpp>
# include "SushiGUI.hpp"

namespace s3d {
	namespace SushiGUI {

		void draw_button_label(const StringView& label, const RectF& rectf, const Font& font, const Color& color) {
			int left = 0, right = 1000;
			while (Abs(right - left) > 1) {
				int mid = (left + right) / 2;
				if (font(label).draw(mid, rectf.stretched(-rectf.w / rect_stretch_rate, -rectf.h / rect_stretch_rate), HSV{ 0,0 })) {
					left = mid;
				}else {
					right = mid;
				}
			}
			font(label).drawAt(left, rectf.center(), color);
		}
		bool is_click_button(const RectF& rectf) {
			if (rectf.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			return rectf.leftClicked();
		}
		bool is_click_button(const RoundRect& roundrect) {
			if (roundrect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			return roundrect.leftClicked();
		}
		
		bool button(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x, anchor->y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x / 2, anchor->y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x, anchor->y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x, anchor->y - size.y / 2 }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x / 2, anchor->y - size.y / 2 }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x, anchor->y - size.y / 2 }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x, anchor->y - size.y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x / 2, anchor->y - size.y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, const ButtonStyle& style, bool enabled) {
			return button(font, label, position_type{ anchor->x - size.x, anchor->y - size.y }, size, style, enabled);
		}
		bool button(const Font& font, const StringView& label, const position_type& pos, const size_type& size, const ButtonStyle& style, bool enabled) {
			const RectF button_rectf{ pos, size };
      return button(font, label, button_rectf, style, enabled);
		}
    bool button(const Font& font, const StringView& label, const RectF button_rectf, const ButtonStyle& style, bool enabled) {
      const RoundRect button_roundrect = button_rectf.rounded(
        style.roundrect_rate ? Min(button_rectf.w, button_rectf.h) / *style.roundrect_rate : 0.0
      );
      const ScopedColorMul2D colorMul{ enabled ? ColorF{ 1.0 } : ColorF{ 0.5 } };
      if (enabled) {
        if (style.color_press and button_roundrect.leftPressed()) button_roundrect.draw(style.color_press.value());
        else if (style.color_mouseover and button_roundrect.mouseOver()) button_roundrect.draw(style.color_mouseover.value());
        else button_roundrect.draw(style.color_release);
      }
      else button_roundrect.draw(style.color_release);
      if (style.color_frame and style.frame_thickness_rate) button_roundrect.drawFrame(Min(button_rectf.w, button_rectf.h) / *style.frame_thickness_rate, *style.color_frame);
      draw_button_label(label, button_rectf, font, style.color_label);
      return (enabled and is_click_button(button_roundrect));
    }

		bool button1(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button1_style, enabled);
		}
		bool button1(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled) {
			return button(font, label, pos, size, button1_style, enabled);
		}
    bool button1(const Font& font, const StringView& label, const RectF button_rectf, bool enabled) {
      return button(font, label, button_rectf, button1_style, enabled);
    }


		bool button2(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button2_style, enabled);
		}
		bool button2(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled) {
			return button(font, label, pos, size, button2_style, enabled);
		}
    bool button2(const Font& font, const StringView& label, const RectF button_rectf, bool enabled) {
      return button(font, label, button_rectf, button2_style, enabled);
    }


		bool button3(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button3_style, enabled);
		}
		bool button3(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled) {
			return button(font, label, pos, size, button3_style, enabled);
		}
    bool button3(const Font& font, const StringView& label, const RectF button_rectf, bool enabled) {
      return button(font, label, button_rectf, button3_style, enabled);
    }


		bool button4(const Font& font, const StringView& label, const Arg::topLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::topCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::topRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::leftCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::center_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::rightCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::bottomLeft_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::bottomCenter_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const Arg::bottomRight_<position_type>& anchor, const size_type& size, bool enabled) {
			return button(font, label, anchor, size, button4_style, enabled);
		}
		bool button4(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled) {
			return button(font, label, pos, size, button4_style, enabled);
		}
    bool button4(const Font& font, const StringView& label, const RectF button_rectf, bool enabled) {
      return button(font, label, button_rectf, button4_style, enabled);
    }

	}
}
