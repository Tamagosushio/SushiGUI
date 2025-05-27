#include <Siv3D.hpp>

/// @brief 単振り子のシミュレーション
class SimplePendulum {
private:
  const double g = 9.8; // 重力加速度
  const double length = 1.0; // 振り子の長さ
  double theta = 0.5_pi; // 角度の初期値
  double theta_v = 0.0; // 角速度
  double theta_a = 0.0; // 角加速度
public:
  // 振り子パラメターの初期化
  SimplePendulum(double theta = 0.5_pi, double length = 1.0, double gravity = 9.8);
  // 振り子を更新
  Vec2 update(void);
};
