#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
private:
  byte _anti_bounce;
  byte _pin_and_estAnt;
  byte getPin();
  bool getEstAnt();
  void setEstAnt(bool);


public:
  enum PullRes : bool {FLOATING = false, PULLUP = true,};
  Button(byte pin, byte anti_bounce, PullRes = FLOATING);
  bool falling();
  bool rissing();
  bool check();
  bool longPush(unsigned long interval);
};
#endif
