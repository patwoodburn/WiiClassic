#include <Wire.h>
#include <WiiClassic.h>

WiiClassic pro;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pro.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pro.update();
  Serial.print(pro.getLeftYValue());
  Serial.print(" ");
  Serial.print(pro.getLeftXValue());
  Serial.print(" ");
  Serial.print(pro.getRightYValue());
  Serial.print(" ");
  Serial.println(pro.getRightXValue());
  delay(100);
}
