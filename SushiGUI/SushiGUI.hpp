# pragma once
# include <Siv3D.hpp>

namespace s3d {
  namespace SushiGUI {

    using position_type = Vec2;
    using size_type = Vec2;

    constexpr double rect_stretch_rate = 20.0;
    constexpr double button_shadow_spread = 20.0;

    void draw_button_label(const StringView& label, const RectF& rectf, const Font& font, const Color& color);
    bool is_click_button(const RoundRect& roundrect);

    struct ButtonState {
      Transition float_transition;
      ButtonState(const Duration& float_transition)
        : float_transition{ float_transition } {}
    };
    // 状態を保持する静的ハッシュテーブル
    static HashTable<uint64, ButtonState> button_states;

    struct ButtonStyle;

    // ストラテジーパターン
    class IButtonBehavior {
    public:
      virtual ~IButtonBehavior() = default;
      virtual void update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const = 0;
      virtual void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const = 0;
    };
    /// @brief ホバーとプレスで色が変わるだけ
    class DefaultBehavior : public IButtonBehavior {
    public:
      void update([[maybe_unused]] const uint64 id, [[maybe_unused]] const RectF& rectf, [[maybe_unused]] const ButtonStyle& style, [[maybe_unused]] bool enabled) const override {};
      void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };
    // 浮かび上がる
    class FloatingBehavior : public IButtonBehavior {
    public:
      void update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const override;
      void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };


    // Behaviorのインスタンスを生成 (ButtonStyle定義の前に置く)
    inline constexpr DefaultBehavior defaultBehavior;
    inline constexpr FloatingBehavior floatingBehavior;


    /// @brief ボタンのスタイルを定義する構造体
    struct ButtonStyle {
      const IButtonBehavior* behavior = &defaultBehavior; // 振る舞いの指定
      Color color_release; // ボタンの背景色
      Optional<Color> color_mouseover = unspecified; // マウスホバー時のボタン背景色
      Optional<Color> color_press = unspecified; // プレス時のボタン背景色
      Color color_label; // ラベルの色
      Optional<Color> color_frame = unspecified; // ボタンフレームの色
      Optional<double> frame_thickness_rate = unspecified; // ボタンフレームの太さ
      Optional<double> roundrect_rate = unspecified; // 角丸の大きさ比率
      Optional<Duration> float_duration = unspecified; // 浮かびきる時間
      Optional<double> float_rate = unspecified; // 浮かぶ高さ比
      Color float_shadow_color{ U"#000000" }; // 浮かんでいるときの影の色
    };

    inline constexpr ButtonStyle button1_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#EA4C89" },
      .color_mouseover = Color{ U"#F082AC" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button2_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#F5F5F5" },
      .color_label = Color{ U"#333333" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button3_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#2EA44F" },
      .color_mouseover = Color{ U"#2C974B" },
      .color_press = Color{ U"#298E46" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button4_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#FAFBFC" },
      .color_mouseover = Color{ U"#F3F4F6" },
      .color_press = Color{ U"#EAECF0" },
      .color_label = Color{ U"#24292E" },
      .color_frame = Color{ U"#1b1f23" },
      .frame_thickness_rate = 50.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button5_style{
      .behavior = &floatingBehavior,
      .color_release = Color{ U"#FA6400" },
      .color_mouseover = Color{ U"#FB8332" },
      .color_press = Color{ U"#C85000" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 10.0,
      .float_duration = 0.25s,
      .float_rate = 0.05,
    };

    inline constexpr ButtonStyle button6_style{
      .behavior = &floatingBehavior,
      .color_release = Color{ U"#FFFFFF" },
      .color_press = Color{ U"#F0F0F1" },
      .color_label = ColorF{ 0, 0.85 },
      .color_frame = ColorF{ 0, 0.10 },
      .frame_thickness_rate = 50.0,
      .roundrect_rate = 10.0,
      .float_duration = 0.25s,
      .float_rate = 0.00,
    };

    inline constexpr ButtonStyle button7_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#0095FF" },
      .color_mouseover = Color{ U"#07c"},
      .color_press = Color{ U"#0064BD" },
      .color_label = Color{ U"#FFFFFF"},
      .roundrect_rate = 10.0,
    };

    inline constexpr ButtonStyle button8_style{
      .behavior = &defaultBehavior,
      .color_release = Color{ U"#E1ECF4" },
      .color_mouseover = Color{ U"#B3D3EA"},
      .color_press = Color{ U"#A0C7E4" },
      .color_label = Color{ U"#39739D" },
      .color_frame = Color{ U"#7AA7C7" },
      .frame_thickness_rate = 25.0,
      .roundrect_rate = 10.0,
    };

    inline constexpr ButtonStyle button9_style{
      .behavior = &floatingBehavior,
      .color_release = Color{ U"#405CF5" },
      .color_label = Color{ U"#FFFFFF" },
      .frame_thickness_rate = 25.0,
      .roundrect_rate = 5.0,
      .float_duration = 0.00s,
      .float_rate = 0.00,
      .float_shadow_color = Color{ 50, 50, 93 },
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
      bool operator()(const Font& font, const StringView& label, const RectF& rectf, bool enabled = true) const;
    };

    // 事前定義されたボタンオブジェクト
    inline constexpr Button Button1{ button1_style };
    inline constexpr Button Button2{ button2_style };
    inline constexpr Button Button3{ button3_style };
    inline constexpr Button Button4{ button4_style };
    inline constexpr Button Button5{ button5_style };
    inline constexpr Button Button6{ button6_style };
    inline constexpr Button Button7{ button7_style };
    inline constexpr Button Button8{ button8_style };
    inline constexpr Button Button9{ button9_style };

    // カスタムスタイル用のファクトリ関数
    inline Button button(const ButtonStyle& style) {
      return Button{ style };
    }

  } // namespace SushiGUI
} // namespace s3d
