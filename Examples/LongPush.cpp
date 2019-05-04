#include <Arduino.h>
#include <Button.h>

#define interval 1000
#define led 13

Button but(14,30,Button::PULLUP);

void setup(){
    pinMode(led,OUTPUT);
}

void loop(){
    if(but.longPush(interval))digitalWrite(led,!digitalRead(led));
}