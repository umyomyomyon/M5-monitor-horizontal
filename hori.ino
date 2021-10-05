#include <M5StickC.h>
#include <math.h>

#define SAMPLE_SIZE 160
float data[SAMPLE_SIZE];
int count = 0;
int idx = 0;

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

void drawGraph(float data[]) {
  M5.Lcd.fillScreen(BLACK);
  drawBaseLine();
  int16_t height = M5.Lcd.height();
  int16_t offset = height / 2;
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    float value = data[i];
    float y = offset - value / 0.03;
    M5.Lcd.drawPixel(i, y, GREEN);
  }
}

void loop() {
  M5.IMU.getAccelData(&accx, &accy, &accz);
  idx = count % 160;
  data[idx] = accy;
  drawGraph(data);
  delay(20);
  count++;
}
