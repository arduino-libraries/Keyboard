/*
  Programmed External Keys (Keyboard)

  For native USB Arduino boards (e.g., Leonardo, Micro, MKR, Nano 33 IoT, Zero, Due)

  When the first button is pressed, the Ctrl + C keyboard shortcut (copy) is emulated.
  When the second button is pressed, the Ctrl + V keyboard shortcut (paste) is emulated.

  The circuit:
  The push buttons have 2 connectors.
  Connect one to GND and the other to the I/O pin defined in the btnPin array.

  created 18 March 2020
  by Prathamesh Sahasrabhojane (TheShubham99)
*/

#include <Keyboard.h>

const int btnPin[] = {2, 3};
const int pinCount = 2;
int btnState[pinCount];
int prevBtnState[] = {HIGH, HIGH}; 

unsigned long lastDebounceTime[] = {0, 0};
unsigned long debounceDelay = 50;

void setup() {
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    pinMode(btnPin[thisPin], INPUT_PULLUP);
  }
  Keyboard.begin();
}

// Place the actions needed after pin press here
void outputAction(int currentButton) {
  if (currentButton == 0) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
  }
  else if (currentButton == 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
  }
}

void loop() {
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    btnState[thisPin] = digitalRead(btnPin[thisPin]);

    if ((btnState[thisPin] != prevBtnState[thisPin]) && (btnState[thisPin] == LOW)) {
      if ((millis() - lastDebounceTime[thisPin]) > debounceDelay) {
        outputAction(thisPin);
        lastDebounceTime[thisPin] = millis();
      }
    }

    prevBtnState[thisPin] = btnState[thisPin];
  }
}

