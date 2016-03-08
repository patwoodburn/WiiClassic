#include <Arduino.h>
#include <WiiClassic.h>
#include <Wire.h>

WiiClassic::WiiClassic(){
  for(int i = 0; i < 6; i++){
    buffer[i] = (byte) 0x00;
  }
}

void WiiClassic::begin(){
  Wire.beginTransmission(0x52);
  Wire.write((byte) 0xF0);
  Wire.write((byte) 0x55);
  Wire.write((byte) 0xFB);
  Wire.write((byte) 0x00);
  Wire.endTransmission();
}

void WiiClassic::update(){
  Wire.requestFrom(0x52, 6);
  int i = 0;
  while (Wire.available() && i < 6) {
    buffer[i] = Wire.read();
    i = i + 1;
  }
  zero();
}

bool WiiClassic::isButtonPressed(int byteLayer, byte button){
  return (~(getByte(byteLayer)) & button);
}

bool WiiClassic::isAButtonPressed(){
  return isButtonPressed(5, 0x10);
}

bool WiiClassic::isBButtonPressed(){
  return isButtonPressed(5, 0x40);
}

bool WiiClassic::isYButtonPressed(){
  return isButtonPressed(5, 0x20);
}

bool WiiClassic::isXButtonPressed(){
  return isButtonPressed(5, 0x8);
}

bool WiiClassic::isZLButtonPressed(){
  return isButtonPressed(5, 0x80);
}

bool WiiClassic::isZRButtonPressed(){
  return isButtonPressed(5, 0x04);
}

bool WiiClassic::isLeftDPadPressed(){
  return isButtonPressed(5, 0x02);
}

bool WiiClassic::isUpDPadPressed(){
  return isButtonPressed(5, 0x01);
}

bool WiiClassic::isDownDPadPressed(){
  return isButtonPressed(4, 0x40);
}

bool WiiClassic::isRightDPadPressed(){
  return isButtonPressed(4, 0x80);
}

bool WiiClassic::isLeftTriggerPressed(){
  return isButtonPressed(4, 0x20);
}

bool WiiClassic::isMinusButtonPressed(){
  return isButtonPressed(4, 0x10);
}

bool WiiClassic::isHomeButtonPressed(){
  return isButtonPressed(4, 0x8);
}

bool WiiClassic::isPlusButtonPressed(){
  return isButtonPressed(4, 0x4);
}

bool WiiClassic::isRightTriggerPressed(){
  return isButtonPressed(4, 0x2);
}

int WiiClassic::getLeftXValue(){
  return (int) (getByte(0) & ~0xC0);
}

int WiiClassic::getLeftYValue(){
  return (int) (getByte(1) & ~0xC0);
}

int WiiClassic::getRightYValue(){
  return (int) (getByte(2) & ~0xE0);
}

int WiiClassic::getRightXValue(){
  byte highBits = getByte(0) & 0xC0;
  byte midBits = (getByte(1) & 0xC0) >> 2;
  byte lowBit = (getByte(2) & 0x80) >> 4;
  return (highBits | midBits | lowBit) >> 3;
}

byte WiiClassic::getByte(int byte){
  return buffer[byte];
}

void WiiClassic::zero(){
  Wire.beginTransmission(0x52);
  Wire.write(0x00);
  Wire.endTransmission();
}
