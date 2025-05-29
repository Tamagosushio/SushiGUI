#include <Siv3D.hpp>

/// @brief 単振り子のシミュレーション
class SimplePendulum {
protected:
  const double g = 9.8; // 重力加速度
  const double length0 = 1.0; // 振り子の長さ
  double theta0 = 0.5_pi; // 角度の初期値
  double theta0_v = 0.0; // 角速度
  double theta0_a = 0.0; // 角加速度
public:
  // 振り子パラメターの初期化
  SimplePendulum(double theta = 0.5_pi, double length = 1.0, double gravity = 9.8);
  // 振り子を更新
  Vec2 update(void);
};

/// @brief 二重振り子のシミュレーション
class DoublePendulum : protected SimplePendulum {
protected:
  const double mass0 = 1.0;
  const double mass1 = 1.0;
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
    double gravity = 9.8
  );
  void update(void);
  Vec2 get_coordinate0(void) const;
  Vec2 get_coordinate1(void) const;
};
