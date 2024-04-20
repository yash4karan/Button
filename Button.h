#ifndef MyClass_h
#define MyClass_h

#include "Arduino.h"

class Button {
  private:
    const byte _pin;  // pin number of button
    byte _dt = 10; // debounce time (configurable)
    unsigned long _tbp = 0; // start time of the button being pressed
    bool _apt = 0; // awaiting press time. Start waiting for long press, but only while the button is pressed.
    bool _t = 0; // has the button been toggled already? Prevents repeated toggles when button remains pressed for longer.
    bool _bp = 0; // button pressed?
    bool _def = 1; // default position, LOW or HIGH. In this case, the default is HIGH, button press causes pin to go LOW

  public:
    // constructor
    Button(byte pin, bool def, byte dt);
    Button(byte pin, bool def);
    Button(byte pin);

    // live status of pin
    bool Status();

    // function that returns true when toggled. If the button is kept pressed, no not continually switch states.
    bool IsToggled();

    // function that returns true when long-pressed. If the button is kept pressed, no not continually switch states.
    bool IsLongPressed(unsigned long lpt);

    // implement a 'held down' function with debounce? Or is the Status() function good enough? It seems to be!
    // bool HeldDown();
};

#endif
