#include <Siv3D.hpp>
#include "Pendulum.hpp"

/// @brief 単振り子パラメータの初期化
/// @param theta 初期角度 (初期値: pi/2)
/// @param length 振り子の長さ (初期値: 1.0)
/// @param gravity 重力加速度 (初期値: 9.8)
SimplePendulum::SimplePendulum(double theta, double length, double gravity)
  : theta0(theta), length0(length), g(gravity) {}

/// @brief 振り子を更新
/// @return 振り子のx,y座標
Vec2 SimplePendulum::update(void) {
  this->theta0_a = -g * Sin(theta0);
  this->theta0_v += theta0_a * Scene::DeltaTime();
  this->theta0 += theta0_v * Scene::DeltaTime();
  Vec2 coordinate{ length0 * Sin(theta0), length0 * Cos(theta0) };
  return coordinate;
}

/// @brief 二重振り子のパラメータの初期値
/// @param theta0 0番目の振り子の初期角度 (初期値: pi/2)
/// @param length0 0番目の振り子の長さ (初期値: 1.0)
/// @param theta1 1番目の振り子の初期角度 (初期値: pi/2)
/// @param length1 1番目の振り子の長さ (初期値: 1.0)
/// @param gravity 重力加速度 (初期値: 9.8) 
DoublePendulum::DoublePendulum(
    double theta0, double length0, double mass0,
    double theta1, double length1, double mass1,
    double gravity
): SimplePendulum(theta0, length0, gravity), mass0(mass0), theta1(theta1), length1(length1), mass1(mass1) {}
void DoublePendulum::update(void) {

  double delta_time = Scene::DeltaTime();

  theta0_a = (-g * (2 * mass0 + mass1) * Sin(theta0) - mass1 * g * Sin(theta0 - theta1) - 2 * Sin(theta0 - theta1) * mass1 * (Pow(theta1_v, 2) * length1 + Pow(theta0_v, 2) * length0 * Cos(theta0 - theta1))) / (length0 * (2 * mass0 + mass1 - mass1 * Cos(2 * theta0 - 2 * theta1)));
  theta1_a = (2 * Sin(theta0 - theta1) * (Pow(theta0_v, 2) * length0 * (mass0 + mass1) + g * (mass0 + mass1) * Cos(theta0) + Pow(theta1_v, 2) * length1 * mass1 * Cos(theta0 - theta1))) / (length1 * (2 * mass0 + mass1 - mass1 * Cos(2 * theta0 - 2 * theta1)));

  theta0_v += theta0_a * delta_time;
  theta1_v += theta1_a * delta_time;

  theta0 += theta0_v * delta_time;
  theta1 += theta1_v * delta_time;

  this->coordinate0 = Vec2{
    length0 * Sin(theta0),
    length0 * Cos(theta0)
  };

  this->coordinate1 = Vec2{
    length0 * Sin(theta0) + length1 * Sin(theta1),
    length0 * Cos(theta0) + length1 * Cos(theta1)
  };
}


Vec2 DoublePendulum::get_coordinate0(void)const {
  return this->coordinate0;
}
Vec2 DoublePendulum::get_coordinate1(void)const {
  return this->coordinate1;
}

