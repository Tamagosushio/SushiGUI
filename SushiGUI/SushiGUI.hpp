# pragma once
# include <Siv3D.hpp>

namespace s3d {
  namespace SushiGUI {

    using position_type = Vec2;
    using size_type = Vec2;

    constexpr double rect_stretch_rate = 20;

    void draw_button_label(const StringView& label, const RectF& rectf, const Font& font, const Color& color);
    bool is_click_button(const RoundRect& roundrect);

    struct ButtonStyle {
      Color color_release; // ボタンの背景色
      Optional<Color> color_mouseover = unspecified; // マウスホバー時のボタン背景色
      Optional<Color> color_press = unspecified; // プレス時のボタン背景色
      Color color_label; // ラベルの色
      Optional<Color> color_frame = unspecified; // ボタンフレームの色
      Optional<double> frame_thickness_rate = unspecified; // ボタンフレームの太さ
      Optional<double> roundrect_rate = unspecified; // 角丸の大きさ比率
    };

    inline constexpr ButtonStyle button1_style{
      .color_release = Color{ U"#EA4C89" },
      .color_mouseover = Color{ U"#F082AC" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button2_style{
      .color_release = Color{ U"#F5F5F5" },
      .color_label = Color{ U"#333333" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button3_style{
      .color_release = Color{ U"#2EA44F" },
      .color_mouseover = Color{ U"#2C974B" },
      .color_press = Color{ U"#298E46" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button4_style{
      .color_release = Color{ U"#FAFBFC" },
      .color_mouseover = Color{ U"#F3F4F6" },
      .color_press = Color{ U"#EAECF0" },
      .color_label = Color{ U"#24292E" },
      .color_frame = Color{ U"#1b1f23" },
      .frame_thickness_rate = 50.0,
      .roundrect_rate = 5.0,
    };



    class Button {
    private:
      const ButtonStyle style_;
    public:
      explicit constexpr Button(const ButtonStyle& style) : style_{ style } {}
      bool operator()(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true) const {
        return (*this)(font, label, RectF{ pos, size }, enabled);
      }
      template <class AnchorType>
      bool operator()(const Font& font, const StringView& label, const AnchorType& anchor, const size_type& size, bool enabled = true) const {
        return (*this)(font, label, RectF{ anchor, size }, enabled);
      }
      bool operator()(const Font& font, const StringView& label, const RectF& rect, bool enabled = true) const;
    };

    // 事前定義されたボタンオブジェクト
    inline constexpr Button Button1{ button1_style };
    inline constexpr Button Button2{ button2_style };
    inline constexpr Button Button3{ button3_style };
    inline constexpr Button Button4{ button4_style };

    // カスタムスタイル用のファクトリ関数
    inline Button button(const ButtonStyle& style) {
      return Button{ style };
    }

  } // namespace SushiGUI
} // namespace s3d
