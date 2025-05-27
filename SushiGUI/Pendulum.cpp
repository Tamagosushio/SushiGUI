#include <Siv3D.hpp>
#include "Pendulum.hpp"

/// @brief 単振り子パラメータの初期化
/// @param theta 初期角度 (初期値: pi/2)
/// @param length 振り子の長さ (初期値: 1.0)
/// @param gravity 重力加速度 (初期値: 9.8)
SimplePendulum::SimplePendulum(double theta, double length, double gravity)
  : theta(theta), length(length), g(gravity) {}

/// @brief 振り子を更新
/// @return 振り子のx,y座標
Vec2 SimplePendulum::update(void) {
  this->theta_a = -g * Sin(theta);
  this->theta_v += theta_a * Scene::DeltaTime();
  this->theta += theta_v * Scene::DeltaTime();
  Vec2 coordinate{ length * Sin(theta), length * Cos(theta) };
  return coordinate;
}
