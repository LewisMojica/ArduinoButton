#include <Arduino.h>
#include <Button.h>
#include <Timer.h>

Button::Button(byte pin, byte anti_bounce, PullRes mode = FLOATING) {
  _pin_and_estAnt = pin;
  _anti_bounce = anti_bounce;
  if(mode == PULLUP) pinMode(pin,INPUT_PULLUP);
  else pinMode(pin,INPUT);

}

bool Button::rissing() {                                          //Funcion que retorna un 1 cuando se detecta un rissing en el pin <_pin>
  if ((digitalRead(getPin())) && (!getEstAnt())) {
    setEstAnt(true);
    delay(_anti_bounce);
    return true;
  }
  else {
    setEstAnt(digitalRead(getPin()));
    delay(_anti_bounce);
    return false;
  }
}

bool Button::falling() {
  if (!digitalRead(getPin()) && getEstAnt()) {
    setEstAnt(false);
    delay(_anti_bounce);
    return true;
  }
  else {
    setEstAnt(digitalRead(getPin()));
    delay(_anti_bounce);
    return false;
  }
}

bool Button::check(){                                             //Funcion que retorna el estado actual del pin <_pin>
  return digitalRead(getPin());
}

bool Button::longPush(unsigned long interval){
  static Timer timer(interval);
  timer.setInterval(interval);
  static bool released = true;

  if(digitalRead(getPin())){
    timer.end();
    released = true;
    return false;
  } else if (!timer.isRunning() && released){
    released = false;
    timer.init();
    return false;
  } else if (timer.read()){
    timer.end();
    released = false;

    return true;
  }
  return false;
}

byte Button::getPin(){
  return (_pin_and_estAnt & ~128);
}

bool Button::getEstAnt(){
  return (_pin_and_estAnt >> 7);
}
void Button::setEstAnt(bool input){
  if(input) _pin_and_estAnt |= (1 << 7);
  else _pin_and_estAnt &= ~(1 << 7);
}

