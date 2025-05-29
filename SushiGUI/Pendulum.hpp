#include <Siv3D.hpp>

/// @brief 単振り子のシミュレーション
class SimplePendulum {
protected:
  const double g = 9.8; // 重力加速度
  const double length0 = 1.0; // 振り子の長さ
  double theta0 = 0.5_pi; // 角度の初期値
  double theta0_v = 0.0; // 角速度
  double theta0_a = 0.0; // 角加速度
  Vec2 coordinate{ 0.0, 0.0 }; // 振り子のx,y座標
  double scale = 1.0; // 振り子のスケール
  Vec2 offset{ 0.0, 0.0 }; // 振り子のオフセット座標
public:
  // 振り子パラメターの初期化
  SimplePendulum(
    double theta = 0.5_pi, double length = 1.0, double gravity = 9.8,
    double scale = 1.0, Vec2 offset = Vec2{ 0.0, 0.0 }
  );
  // 振り子を更新
  void update(void);
  // 振り子のx,y座標を取得
  Vec2 get_coordinate(void) const;
  void set_scale(double scale);
  double get_scale(void) const;
  void set_offset(const Vec2& offset);
  Vec2 get_offset(void) const;
};

/// @brief 二重振り子のシミュレーション
class DoublePendulum : public SimplePendulum {
protected:
  const double mass0 = 1.0; // 0番目の振り子の質量
  const double mass1 = 1.0; // 1番目の振り子の質量
  const double length1 = 1.0;
  double theta1 = 0.5_pi;
  double theta1_v = 0.0;
  double theta1_a = 0.0;
  Vec2 coordinate0{ 0.0, 0.0 };
  Vec2 coordinate1{ 0.0, 0.0 };
public:
  DoublePendulum(
    double theta0 = 0.5_pi, double length0 = 1.0, double mass0 = 1.0,
    double theta1 = 0.5_pi, double length1 = 1.0, double mass1 = 1.0,
    double gravity = 9.8,
    double scale = 1.0, Vec2 off_set = Vec2{ 0.0, 0.0 }
  );
  // 振り子を更新
  void update(void);
  // 0番目の振り子のx,y座標を取得
  Vec2 get_coordinate0(void) const;
  // 1番目の振り子のx,y座標を取得
  Vec2 get_coordinate1(void) const;
};
