#include <Arduino.h>
class WiiClassic{
  public:
    WiiClassic();
    void begin();
    void update();
    bool isButtonPressed(int byteLayer, byte button);
    bool isAButtonPressed();
    bool isBButtonPressed();
    bool isXButtonPressed();
    bool isYButtonPressed();
    bool isZLButtonPressed();
    bool isZRButtonPressed();
    bool isLeftDPadPressed();
    bool isDownDPadPressed();
    bool isRightDPadPressed();
    bool isUpDPadPressed();
    bool isLeftTriggerPressed();
    bool isMinusButtonPressed();
    bool isHomeButtonPressed();
    bool isPlusButtonPressed();
    bool isRightTriggerPressed();
    int getLeftYValue();
    int getLeftXValue();
    int getRightYValue();
    int getRightXValue();
    byte getByte(int byte);
  private:
    void zero();
    byte buffer[6];
};
