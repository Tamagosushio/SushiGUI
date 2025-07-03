# include "SushiGUI.hpp"

namespace s3d {
  namespace SushiGUI {

    void draw_button_label(const StringView& label, const RectF& rectf, const Font& font, const Color& color) {
      int left = 0, right = 1000;
      while (Abs(right - left) > 1) {
        const int mid = (left + right) / 2;
        if (font(label).draw(mid, rectf.stretched(-rectf.w / rect_stretch_rate, -rectf.h / rect_stretch_rate), HSV{ 0,0 })) {
          left = mid;
        } else {
          right = mid;
        }
      }
      font(label).drawAt(left, rectf.center(), color);
    }

    bool is_click_button(const RoundRect& roundrect) {
      if (roundrect.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
      return roundrect.leftClicked();
    }

    bool Button::operator()(const Font& font, const StringView& label, const RectF& rect, bool enabled) const {
      // ボタンの長方形
      RectF button_rect = rect;
      RoundRect button_roundrect;
      // ボタンの識別子
      const uint64 id = Hash::FNV1a(rect);
      // ボタンにアニメーションがあるとき
      if (style_.float_duration and enabled) {
        // 状態管理テーブルにidがなければ新しく生成
        if (not button_states.contains(id)) button_states.emplace(id, ButtonState{*style_.float_duration});
        ButtonState& state = button_states.at(id);
        state.float_transition.update(rect.mouseOver() and not rect.leftPressed());
        const double float_value = state.float_transition.value();
        const double y_offset = rect.h * button_float_rate * float_value;
        button_rect = rect.movedBy(0, -y_offset);
        button_roundrect = button_rect.rounded(
          style_.roundrect_rate ? Min(button_rect.w, button_rect.h) / *style_.roundrect_rate : 0.0
        );
        button_roundrect.drawShadow(Vec2{ 0, y_offset }, float_value * button_shadow_spread);
      } else {
        button_roundrect = button_rect.rounded(
          style_.roundrect_rate ? Min(button_rect.w, button_rect.h) / *style_.roundrect_rate : 0.0
        );
      }
      const ScopedColorMul2D color_mul{ enabled ? ColorF{ 1.0 } : ColorF{ 0.5 } };
      if (enabled) {
        if (style_.color_press and button_roundrect.leftPressed()) {
          button_roundrect.draw(style_.color_press.value());
        } else if (style_.color_mouseover and button_roundrect.mouseOver()) {
          button_roundrect.draw(style_.color_mouseover.value());
        } else {
          button_roundrect.draw(style_.color_release);
        }
      } else {
        button_roundrect.draw(style_.color_release);
      }
      if (style_.color_frame and style_.frame_thickness_rate) {
        button_roundrect.drawFrame(Min(button_rect.w, button_rect.h) / *style_.frame_thickness_rate, *style_.color_frame);
      }
      draw_button_label(label, button_rect, font, style_.color_label);
      return (enabled and is_click_button(button_roundrect));
    }

  } // namespace SushiGUI
} // namespace s3d
