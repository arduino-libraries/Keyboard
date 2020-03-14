//Example to understand the basic working of the Keyboard.write() function

#include <Keyboard.h>

void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  //if the button is pressed
  if (digitalRead(2) == LOW) {
    //Send an ASCII 'A',
    Keyboard.write(65);
  }
}
