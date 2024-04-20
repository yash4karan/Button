#include "Arduino.h"
#include "Button.h"

Button::Button(const byte pin, const bool def, const byte dt) {
    _pin = pin;
    _def = def;
    _dt = dt;
    pinMode(pin, INPUT);
}

Button::Button(const byte pin, const bool def) {
    _pin = pin;
    _def = def;
    pinMode(pin, INPUT);
}

Button::Button(const byte pin) {
    _pin = pin;
    pinMode(pin, INPUT);
}

bool Button::Status() { // current state of the button pin: 0 is not pressed, 1 is pressed
    return (digitalRead(_pin) != _def); // of digitalRead == _def, the button is not pressed
}

bool Button::IsToggled() { // returns true when there is a toggle i.e. a state change, does NOT return the state of the toggle
    return IsLongPressed(_dt);
}

bool Button::IsLongPressed(unsigned long lpt) { // need to make either long press or toggle option available?
    if (digitalRead(_pin) == !_def) { // button pressed
        if (_bp == 0) {
            _tbp = millis();
            _bp = 1;
            _apt = 1;
            return false;
        }
        else if (!_t && _apt && millis() >= _tbp + lpt) {
            _t = 1;
            _apt = 0;
            //Serial.println(millis());
            return true;
        }
        else {
            return false;
        }
    }
    else { // button not pressed/released
        if (!_apt || millis() >= _tbp + _dt) {
            _bp = 0;
            _apt = 0;
            _t = 0;
            return false;
        }
    }
}
