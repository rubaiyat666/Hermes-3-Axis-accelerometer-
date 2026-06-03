#include <Wire.h>

#define MPU_ADDR 0x68

#define OLED_ADDR 0x3C



void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void initMPU() {

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.write(0x1B);
  Wire.write(0x00);
  
  Wire.endTransmission();

}


void read_gyro() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR , 6);

  int16_t gyroX = (Wire.read()<<8) | Wire.read();
  int16_t gyroY = (Wire.read()<<8) | Wire.read();
  int16_t gyroZ = (Wire.read()<<8) | Wire.read();

}

float rotaionZ=0;
unsigned long lasTime = 0;


void loop() {
  read_gyro();
  float rate = gyroZ / 132.0;
  unsigned long now = millis();
  float time = (now - lasTime)/1000.0;

  rotaionZ += rate*time;
  displayRotation(roattionZ);
  lasTime = now
  delay(10);
  
}








