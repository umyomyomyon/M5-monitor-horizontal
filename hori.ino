#include <M5StickC.h>
#include <math.h>

float gx = 0.0F;
float gy = 0.0F;
float gz = 0.0F;
float accx = 0.0F;
float accy = 0.0F;
float accz = 0.0F;

void drawBaseLine() {
  M5.Lcd.drawLine(0, 40, 160, 40, WHITE);
  M5.Lcd.drawLine(80, 0, 80, 80, WHITE);
}

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(3);
  drawBaseLine();
}

float culcVec(float x, float y, float z) {
  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void loop() {
  M5.IMU.getGyroData(&gx, &gy, &gz);
  M5.IMU.getAccelData(&accx, &accy, &accz);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("gyroX: %4.2f\ngyroY: %4.2f\ngyroZ: %4.2f\n", gx, gy, gz);
  M5.Lcd.printf("accX: %4.2f\naccY: %4.2f\naccZ: %4.2f\n", accx, accy, accz);
  M5.Lcd.printf("vecMag: %4.2f", culcVec(accx, accy, accz));
}
