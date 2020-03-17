/*
  Programmed External Keys (Keyboard)
  
  For the Arduino Leonardo/any other arduino board with usb interface
  
  Reads a key from push button & acts as a CTRL+C (Copy).
  Reads another key from push button & acts as a CTRL+V (Paste).
  

  The circuit:
  
  The push button has 2 connectors. 
  We must connect gnd and the second will be connected to any I/O pin. 

connect register between (button & gnd)& then set pinMode() as INPUT.

  created 18 March 2020
  
  by Prathamesh Sahasrabhojane (TheShubham99)

*/

#include "Keyboard.h"

const int btnPin[] = {2, 3, 4, 5};
int pincount = 4;
int btnState[] = {0, 0, 0, 0};
int prevbtnState[] = {HIGH, HIGH, HIGH, HIGH};

long lastDebounceTime[] = {0, 0, 0, 0};
long debounceDelay = 50;
void setup() {
  for (int thisPin = pincount - 1; thisPin >= 0; thisPin--) {
    pinMode(btnPin[thisPin], INPUT);
    digitalWrite(btnPin[thisPin], HIGH);
  }
  Keyboard.begin();
}

// Place the actions needed after pin press here
int outputAction(int currentButton) {
    if (currentButton == 1) {
      Keyboard.press(ctrlKey);
      Keyboard.press('c');
      delay(100);
      Keyboard.releaseAll();
    }
    if (currentButton + 1 == 2) {
      Keyboard.press(ctrlKey);
      Keyboard.press('v');
      delay(100);
      Keyboard.releaseAll();
    }
}
void loop() {
  for (int thisPin = pincount - 1; thisPin >= 0; thisPin--) {
    btnState[thisPin] = digitalRead(btnPin[thisPin]);

    if ((btnState[thisPin] != prevbtnState[thisPin]) && (btnState[thisPin] == HIGH)) {
      if ((millis() - lastDebounceTime[thisPin]) > debounceDelay) {
        outputAction(thisPin);
        lastDebounceTime[thisPin] = millis();
      }
    }

    prevbtnState[thisPin] = btnState[thisPin];
  }
}