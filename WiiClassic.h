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
    bool isDownDPaddPressed();
  private:
    byte getByte(int byte);
    void zero();
    byte buffer[6];
};
