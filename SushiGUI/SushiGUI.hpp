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

    inline RoundRect create_roundrect(const RectF& rectf, const ButtonStyle& style);

    /// @brief ボタンの振る舞いのインターフェース
    class IButtonBehavior {
    public:
      virtual ~IButtonBehavior() = default;
      virtual void update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const = 0;
      virtual void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const = 0;
    };
    /// @brief 基本的な描画を行うボタンの振る舞い
    class DefaultBehavior : public IButtonBehavior {
    public:
      void update([[maybe_unused]] const uint64 id, [[maybe_unused]] const RectF& rectf, [[maybe_unused]] const ButtonStyle& style, [[maybe_unused]] bool enabled) const override {};
      void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };

    /// @brief 振る舞いを修飾するクラスの基底クラス
    class ButtonBehaviorDecorator : public IButtonBehavior {
    protected:
      const IButtonBehavior& behaivor_;
    public:
      explicit constexpr ButtonBehaviorDecorator(const IButtonBehavior& behavior) : behaivor_{ behavior } {}
      void update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const override {
        behaivor_.update(id, rectf, style, enabled);
      }
    };
    /// @brief 枠線表示を追加
    class FrameDecorator : public ButtonBehaviorDecorator {
    public:
      using ButtonBehaviorDecorator::ButtonBehaviorDecorator;
      void draw(const uint64 it, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };
    /// @brief 浮かび上がる効果を追加
    class FloatingDecorator : public ButtonBehaviorDecorator {
    public:
      using ButtonBehaviorDecorator::ButtonBehaviorDecorator;
      void update(const uint64 id, const RectF& rectf, const ButtonStyle& style, bool enabled) const override;
      void draw(const uint64 id, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };
    /// @brief グラデーション効果を追加
    class GradientDecorator : public ButtonBehaviorDecorator {
    public:
      using ButtonBehaviorDecorator::ButtonBehaviorDecorator;
      void draw(const uint64 it, const RectF& rectf, const Font& font, const StringView& label, const ButtonStyle& style, bool enabled) const override;
    };
    

    // Behaviorのインスタンスを生成 (ButtonStyle定義の前に置く)
    inline constexpr DefaultBehavior default_behavior;
    inline constexpr FrameDecorator frame_behaivor{ default_behavior };
    inline constexpr FloatingDecorator floating_frame_behavior{ frame_behaivor };
    inline constexpr GradientDecorator gradient_behavior{ default_behavior };
    inline constexpr FrameDecorator frame_gradient_behavior{ gradient_behavior };
    inline constexpr FloatingDecorator floating_frame_gradient_behavior{ frame_gradient_behavior };

    /// @brief ボタンのスタイルを定義する構造体
    struct ButtonStyle {
      const IButtonBehavior* behavior = &default_behavior; // 振る舞いの指定
      Color color_release; // ボタンの背景色
      Optional<Color> color_mouseover = unspecified; // マウスホバー時のボタン背景色
      Optional<Color> color_press = unspecified; // プレス時のボタン背景色
      Color color_label; // ラベルの色
      Optional<Color> frame_color = unspecified; // ボタンフレームの色
      Optional<Color> frame_color_press = unspecified; // ボタンフレームの色
      Optional<double> frame_thickness_rate = unspecified; // ボタンフレームの太さ
      Optional<double> frame_thickness_rate_press = unspecified; // プレス時のボタンフレームの太さ
      Optional<double> roundrect_rate = unspecified; // 角丸の大きさ比率
      Optional<Duration> float_duration = unspecified; // 浮かびきる時間
      Optional<double> float_rate = unspecified; // 浮かぶ高さ比
      Color float_shadow_color{ U"#000000" }; // 浮かんでいるときの影の色
      Optional<Color> gradient_color_start = unspecified; // グラデーションの上部の色
      Optional<Color> gradient_color_end = unspecified; // グラデーションの下部の色
    };

    inline constexpr ButtonStyle button1_style{
      .behavior = &default_behavior,
      .color_release = Color{ U"#EA4C89" },
      .color_mouseover = Color{ U"#F082AC" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button2_style{
      .behavior = &default_behavior,
      .color_release = Color{ U"#F5F5F5" },
      .color_label = Color{ U"#333333" },
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button3_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#2EA44F" },
      .color_mouseover = Color{ U"#2C974B" },
      .color_press = Color{ U"#298E46" },
      .color_label = Color{ U"#FFFFFF" },
      .frame_color = Color{ U"#2B9148"},
      .frame_thickness_rate = 25.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button4_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#FAFBFC" },
      .color_mouseover = Color{ U"#F3F4F6" },
      .color_press = Color{ U"#EAECF0" },
      .color_label = Color{ U"#24292E" },
      .frame_color = Color{ U"#D9DBDB" },
      .frame_thickness_rate = 50.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button5_style{
      .behavior = &floating_frame_behavior,
      .color_release = Color{ U"#FA6400" },
      .color_mouseover = Color{ U"#FB8332" },
      .color_press = Color{ U"#C85000" },
      .color_label = Color{ U"#FFFFFF" },
      .roundrect_rate = 10.0,
      .float_duration = 0.25s,
      .float_rate = 0.05,
    };

    inline constexpr ButtonStyle button6_style{
      .behavior = &floating_frame_behavior,
      .color_release = Color{ U"#FFFFFF" },
      .color_press = Color{ U"#F0F0F1" },
      .color_label = ColorF{ 0, 0.85 },
      .frame_color = ColorF{ 0, 0.10 },
      .frame_thickness_rate = 50.0,
      .roundrect_rate = 10.0,
      .float_duration = 0.25s,
      .float_rate = 0.00,
    };

    inline constexpr ButtonStyle button7_style{
      .behavior = &default_behavior,
      .color_release = Color{ U"#0095FF" },
      .color_mouseover = Color{ U"#07c"},
      .color_press = Color{ U"#0064BD" },
      .color_label = Color{ U"#FFFFFF"},
      .roundrect_rate = 10.0,
    };

    inline constexpr ButtonStyle button8_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#E1ECF4" },
      .color_mouseover = Color{ U"#B3D3EA"},
      .color_press = Color{ U"#A0C7E4" },
      .color_label = Color{ U"#39739D" },
      .frame_color = Color{ U"#7AA7C7" },
      .frame_thickness_rate = 25.0,
      .roundrect_rate = 10.0,
    };

    inline constexpr ButtonStyle button9_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#405CF5" },
      .color_label = Color{ U"#FFFFFF" },
      .frame_color_press = Color{ U"#B1CBE0" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 10.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button10_style{
      .behavior = &frame_gradient_behavior,
      .color_label = Color{ U"#FFFFFF" },
      .frame_color_press = Color{ U"#9CB5EC" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 10.0,
      .roundrect_rate = 5.0,
      .gradient_color_start = Color{ U"#4B91F7" },
      .gradient_color_end = Color{ U"#367AF6" },
    };

    inline constexpr ButtonStyle button11_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#FFFFFF" },
      .color_label = Color{ U"#3D3D3D" },
      .frame_color_press = Color{ U"#9CB5EC" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 10.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button12_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#6E6D70" },
      .color_label = Color{ U"#DFDEDF" },
      .frame_color_press = Color{ U"#9CB5EC" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 10.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button13_style{
      .behavior = &frame_behaivor,
      .color_release = Color{ U"#FFFFFF" },
      .color_label = Color{ U"#0F1111" },
      .frame_color = Color{ U"#D5D9D9" },
      .frame_color_press = Color{ U"#008296" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 25.0,
      .roundrect_rate = 5.0,
    };

    inline constexpr ButtonStyle button14_style{
      .behavior = &floating_frame_gradient_behavior,
      .color_label = Color{ U"#0F1111" },
      .frame_color = Color{ U"#D5D9D9" },
      .frame_color_press = Color{ U"#E77600" },
      .frame_thickness_rate = 25.0,
      .frame_thickness_rate_press = 25.0,
      .roundrect_rate = 5.0,
      .float_duration = 0.00s,
      .float_rate = 0.00,
      .float_shadow_color = Color{ 228, 121, 17 },
      .gradient_color_start = Color{ U"#F7F8FA" },
      .gradient_color_end = Color{ U"#E7E9EC" },
    };

    class Button {
    private:
      const ButtonStyle style_;
    public:
      explicit constexpr Button(const ButtonStyle& style) : style_{ style } {}
      /// @brief 左上座標を指定してボタン描画
      /// @param font 文字列描画に使用するFont
      /// @param label ボタン内に描画する文字列
      /// @param pos 左上座標
      /// @param size ボタンの大きさ
      /// @param enabled ボタンが有効か
      /// @return 
      bool operator()(const Font& font, const StringView& label, const position_type& pos, const size_type& size, bool enabled = true) const {
        return (*this)(font, label, RectF{ pos, size }, enabled);
      }
      /// @brief アンカーを指定してボタン描画
      /// @tparam AnchorType 
      /// @param font 文字列描画に使用するFont
      /// @param label ボタン内に描画する文字 
      /// @param anchor アンカーの種類と座標
      /// @param size ボタンの大きさ
      /// @param enabled ボタンが有効か
      /// @return 
      template <class AnchorType>
      bool operator()(const Font& font, const StringView& label, const AnchorType& anchor, const size_type& size, bool enabled = true) const {
        return (*this)(font, label, RectF{ anchor, size }, enabled);
      }
      /// @brief 長方形を指定してボタン描画
      /// @param font 文字列描画に使用するFont
      /// @param label ボタン内に描画する文字 
      /// @param rectf ボタンに使用する長方形
      /// @param enabled ボタンが有効か
      /// @return 
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
    inline constexpr Button Button10{ button10_style };
    inline constexpr Button Button11{ button11_style };
    inline constexpr Button Button12{ button12_style };
    inline constexpr Button Button13{ button13_style };
    inline constexpr Button Button14{ button14_style };

    // カスタムスタイル用のファクトリ関数
    inline Button button(const ButtonStyle& style) {
      return Button{ style };
    }

  } // namespace SushiGUI
} // namespace s3d
