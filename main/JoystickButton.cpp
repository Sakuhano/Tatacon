#include "JoystickButton.h"
#include "Arduino.h"


JoyButton::JoyButton(int VRX_PIN, int VRY_PIN, int SW_PIN, int NUM_ITEMS)
:  _button(SW_PIN)
{
   _VRX_PIN = VRX_PIN;
   _VRY_PIN = VRY_PIN;
   _SW_PIN = SW_PIN;

     _NUM_ITEMS = NUM_ITEMS;

    _item_selected = 0;
    _current_screen = 0;

    _button_select_clicked = 0;
    _button_up_clicked = 0;
    _button_down_clicked = 0;

}
void JoyButton::setup() {
 pinMode(_VRX_PIN, INPUT);
 pinMode(_VRY_PIN, INPUT);
 pinMode(_SW_PIN, INPUT_PULLUP);

 _button.setDebounceTime(50);
}

void JoyButton::update() {
_button.loop();

int X = analogRead(_VRX_PIN);
int Y = analogRead(_VRY_PIN);

Serial.print("X=");
Serial.println(X);
Serial.print("Y=");
Serial.println(Y);
Serial.print("Button");
Serial.println(digitalRead((_SW_PIN)));

  if (_button.isPressed()) {
    if ((digitalRead(_SW_PIN) == LOW) && (_button_select_clicked == 0)) {
     _button_select_clicked = 1;

     if (_current_screen == 0) {
        if (_item_selected == 0) _current_screen = 1;
        else if (_item_selected == 1) _current_screen = 2;
     }
     else {
        _current_screen = 0;
     }
  }
  }

  if (_button.isReleased()) {
   _button_select_clicked = 0;
  }

    if (Y>700) { 
      _button_up_clicked = 1;
    }
    else if (Y<300) { 
      _button_down_clicked=1;
    }

    if (X>700) { 
      _button_up_clicked = 1;
    }
    else if (X<300) { 
      _button_down_clicked=1;
    }

 if ((_button_up_clicked == 1) && (Y>700)) {
 switch (_current_screen) {
 case 0:
        _item_selected = _item_selected - 1;
      
        if (_item_selected < 0) {
          _item_selected = 0;
          delay(650);
          }
    break;
      
  }
 }
  else if ((_button_up_clicked == 1) && (Y<700)) {
    _button_up_clicked = 0;
}

if ((_button_down_clicked == 1) && (Y<300)) {
 switch (_current_screen) {
 case 0:
        _item_selected = _item_selected + 1;
        _button_down_clicked = 1;
        if (_item_selected >= _NUM_ITEMS) {
          _item_selected = _NUM_ITEMS-1;
    _button_up_clicked = 0;
}
          delay(650);
    break;
     }
  }
  else if ((_button_down_clicked == 1) && (X>300)) {
    _button_down_clicked = 0;
}

if ((_button_up_clicked == 1) && (X>700)) {
 switch (_current_screen) {
 case 0:
    break;
    }
      
  }
  else if ((_button_up_clicked == 1) && (X<700)) {
    _button_up_clicked = 0;
}

if ((_button_down_clicked == 1) && (X<300)) {
 switch (_current_screen) {
 case 0:
    break;
     }
  }
  else if ((_button_down_clicked == 1) && (X>300)) {
    _button_down_clicked = 0;
}

}
int JoyButton::ItemSelected() {

return _item_selected;
}

int JoyButton::CurrentScreen() {

return _current_screen;
}

int JoyButton::readX() {

return analogRead(_VRX_PIN);
}

int JoyButton::readY() {

return analogRead(_VRY_PIN);

}
