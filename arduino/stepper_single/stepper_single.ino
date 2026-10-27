#include <Stepper.h>

// 28BYJ-48（5V）の出力軸の約1回転分。減速比により多少異なります。
const int STEPS_PER_REVOLUTION = 2038;

// Arduino Uno -> ULN2003
const int IN1_PIN = 2;
const int IN2_PIN = 3;
const int IN3_PIN = 4;
const int IN4_PIN = 5;

// Stepperライブラリには IN1, IN3, IN2, IN4 の順で渡します。
//Stepper motor(STEPS_PER_REVOLUTION, IN1_PIN, IN3_PIN, IN2_PIN, IN4_PIN);
Stepper motor(STEPS_PER_REVOLUTION, A0, A2, A1, A3);

void setup() {
  motor.setSpeed(15);  // 約15回転/分
}

void loop() {
  motor.step(STEPS_PER_REVOLUTION);   // 一方向に約1回転
  delay(1000);

  motor.step(-STEPS_PER_REVOLUTION);  // 逆方向に約1回転
  delay(1000);
}
