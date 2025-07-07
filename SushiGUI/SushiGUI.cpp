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

    inline RoundRect create_roundrect(const RectF& rectf, const ButtonStyle& style) {
      const double r = style.roundrect_rate.value_or(0.0);
      return RoundRect{ rectf, (r > 0) ? Min(rectf.w, rectf.h) / r : 0.0 };
    }

    void DefaultBehavior::draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const {
      const RoundRect roundrect = create_roundrect(rectf, style);
      Color color = style.color_release;
      if (enabled) {
        if (style.color_press and roundrect.leftPressed()) {
          color = *style.color_press;
        } else if (style.color_mouseover and roundrect.mouseOver()) {
          color = *style.color_mouseover;
        }
      }
      roundrect.draw(color);
      draw_button_label(label, rectf, font, style.color_label);
    }

    void FrameDecorator::draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const {
      behaivor_.draw(id, rectf, font, label, style, enabled);
      const RoundRect roundrect = create_roundrect(rectf, style);
      if (style.frame_color and style.frame_thickness_rate) {
        roundrect.drawFrame(Min(rectf.w, rectf.h) / *style.frame_thickness_rate, *style.frame_color);
      }
      if (enabled and roundrect.leftPressed() and style.frame_color_press and style.frame_thickness_rate_press) {
        roundrect.drawFrame(Min(rectf.w, rectf.h) / *style.frame_thickness_rate_press, *style.frame_color_press);
      }
    }

    void FloatingDecorator::update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const {
      if (style.float_duration) {
        if (not button_states.contains(id)) button_states.emplace(id, ButtonState{ *style.float_duration });
        auto& state = button_states.at(id);
        state.float_transition.update(enabled and rectf.mouseOver() and !rectf.leftPressed());
      }
      ButtonBehaviorDecorator::update(id, rectf, style, enabled);
    }
    void FloatingDecorator::draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const {
      RectF button_rect = rectf;
      double y_offset = 0.0;
      double float_value = 0.0;
      if (style.float_duration and style.float_rate and button_states.contains(id)) {
        const auto& state = button_states.at(id);
        float_value = state.float_transition.value();
        y_offset = rectf.h * *style.float_rate * float_value;
        button_rect.y -= y_offset;
        const RoundRect shardow_rect = create_roundrect(button_rect, style);
        shardow_rect.drawShadow(Vec2{ 0, y_offset }, float_value * button_shadow_spread, 0.0, style.float_shadow_color);
      }
      behaivor_.draw(id, button_rect, font, label, style, enabled);
    }

    void GradientDecorator::draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const {
      if (not (style.gradient_color_start and style.gradient_color_end)) {
        behaivor_.draw(id, rectf, font, label, style, enabled);
        return;
      }
      const RoundRect roundrect = create_roundrect(rectf, style);
      roundrect.draw(Arg::top(*style.gradient_color_start), Arg::bottom(*style.gradient_color_end));
      if (style.frame_color and style.frame_thickness_rate) {
        roundrect.drawFrame(Min(rectf.w, rectf.h) / *style.frame_thickness_rate, *style.frame_color);
      }
      draw_button_label(label, rectf, font, style.color_label);
    }


    bool Button::operator()(const Font& font, const StringView& label, const RectF& rectf, bool enabled) const {
      const uint64 id = Hash::FNV1a(rectf);
      const RoundRect interact_rect = create_roundrect(rectf, style_);
      if (style_.behavior) {
        style_.behavior->update(id, rectf, style_, enabled);
        const ScopedColorMul2D color_mul{ enabled ? ColorF{1.0} : ColorF{0.5} };
        style_.behavior->draw(id, rectf, font, label, style_, enabled);
      }
      return (enabled and is_click_button(interact_rect));
    }

  } // namespace SushiGUI
} // namespace s3d
