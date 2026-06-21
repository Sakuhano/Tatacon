#ifndef Joystick_Button_h
#define Joystick_Button_h


#include "Arduino.h"
#include <ezButton.h>

class JoyButton
{
  public:
    JoyButton(int VRX_PIN, int VRY_PIN, int SW_PIN, int NUM_ITEMS);
    void  setup();
    void update();
    
    int ItemSelected();
    int CurrentScreen();

    int readX();
    int readY();

  private:
    int _VRY_PIN;
    int _VRX_PIN;
    int _SW_PIN;
    int _NUM_ITEMS;
    
    int _item_selected;
    int _current_screen;

int _button_up_clicked;
int _button_select_clicked;
int _button_down_clicked;

ezButton _button;
};

#endif