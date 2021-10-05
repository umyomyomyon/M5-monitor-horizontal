#include <M5StickC.h>
#include <math.h>

#define TARGET_ANGLE 1
#define ANGLE_THRESHOLD 3
#define DELAY 20
#define RC_FILTER_COEFFICIENT 0.9

float accx = 0.0F;
float accy = 0.0F;
float accz = 0.0F;

void drawBaseLine() {
  int16_t width = M5.Lcd.width();
  int16_t height = M5.Lcd.height();
  M5.Lcd.drawFastVLine(width / 2, 0, height, WHITE);
  M5.Lcd.drawFastHLine(0, height / 2, width, WHITE);
}

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.begin();
  M5.Lcd.setRotation(3);
  drawBaseLine();
}

int chooseColor(uint angle) {
  if (angle > ANGLE_THRESHOLD) {
    return RED;
  }
  if (angle <= TARGET_ANGLE) {
    return BLUE;
  }
  return GREEN;
}

void drawAngleDiff(float accx, float accy) {
  M5.Lcd.fillScreen(BLACK);
  drawBaseLine();

  int offset = M5.Lcd.height() / 2;
  float radianAngle = atan(accy / accx) * (-1);
  int y = round(M5.Lcd.width() / 2 * tan(radianAngle));
  float angle = radianAngle * 180 / PI;
  int color = chooseColor(abs(angle));

  M5.Lcd.drawLine(0, offset - y * (-1), M5.Lcd.width(), offset - y, color);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("angle: %4.2f\n", angle);
}

float RCFilter(float coefficient, float* exValue, float value) {
  float filteredValue = coefficient * (*exValue) + (1 - coefficient) * value;
  *exValue = filteredValue;
  return filteredValue;
}

void loop() {
  static float exAccX = 0;
  static float exAccY = 0;

  M5.IMU.getAccelData(&accx, &accy, &accz);
  float filteredAccX = RCFilter(RC_FILTER_COEFFICIENT, &exAccX, accx);
  float filteredAccY = RCFilter(RC_FILTER_COEFFICIENT, &exAccY, accy);
  drawAngleDiff(filteredAccX, filteredAccY);

  delay(DELAY);
}