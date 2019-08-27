#include "Arduino.h"
#undef ISR // remove the avr-gcc ISR version
extern "C" {
#include "tpl_app_config.h"
#include "tpl_os.h" //set the OSEK ISR version.
}

void setup() {

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}


TASK(blinkTaskPin8) {
  static unsigned char nb = 0;
  digitalWrite(8, nb++ & 0x01);
}

TASK(blinkTaskPin9) {
  static unsigned char nb = 0;
  digitalWrite(9, nb++ & 0x01);
}

TASK(blinkTaskPin10) {
  static unsigned char nb = 0;
  digitalWrite(10, nb++ & 0x01);
}

TASK(blinkTaskPin11) {
  static unsigned char nb = 0;
  digitalWrite(11, nb++ & 0x01);
}

TASK(blinkTaskPin12) {
  static unsigned char nb = 0;
  digitalWrite(12, nb++ & 0x01);
}

TASK(blinkTaskPin13) {
  static unsigned char nb = 0;
  digitalWrite(13, nb++ & 0x01);
}

