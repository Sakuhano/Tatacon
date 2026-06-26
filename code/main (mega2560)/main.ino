#include "bitmaps.h"
#include "U8glib.h"
#include "JoystickButton.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

extern int item_selected;
extern const int NUM_ITEMS;
extern int current_screen;
int current_screen=0;
#define VRX_PIN A1
#define VRY_PIN A0
#define SW_PIN 8

JoyButton joystick(VRX_PIN, VRY_PIN, SW_PIN, NUM_ITEMS);

void setup() {
  delay(300);
pinMode(11, OUTPUT);
digitalWrite(11, HIGH);
pinMode(10, OUTPUT);
digitalWrite(10, HIGH);
  u8g.setColorIndex(1);
  Serial.begin(9600);
  Serial1.begin(9600);
  joystick.setup();
  startupAnim();
}

void loop() {

  joystick.update();

  item_selected = joystick.ItemSelected();
  current_screen = joystick.CurrentScreen();

  u8g.firstPage();
  do {

    if (current_screen == 0) {
      itemsMenu();
      drawMenu();
    }
    else if (current_screen == 1) {
      drawControllerMenu();
    }
    else if (current_screen == 2) {
      drawSettingsMenu();
    }

  } while (u8g.nextPage());
}
