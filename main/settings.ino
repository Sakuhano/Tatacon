#include "U8glib.h"
#include "JoystickButton.h"
#include "bitmaps.h"

extern U8GLIB_SSD1306_128X64 u8g;
extern JoyButton joystick;
extern int current_screen;

#define SW_PIN 8

int sensitivity = 40;
int threshold_value = 22;
int settings_pos = 0;

void settingsMenu() {

    joystick.update();
    int x = joystick.readX();
    int y = joystick.readY();

    if (y >= 700) settings_pos = 0;
    else if (y <= 300) settings_pos = 2;
    else settings_pos = 1;

    if (settings_pos == 0) {
        if (x >= 700) sensitivity++;
        if (x <= 300) sensitivity--;
        if (sensitivity < 1) sensitivity = 1;
        Serial1.print("SET SENS ");
        Serial1.println(sensitivity);
    }

    if (settings_pos == 1) {
        if (x >= 700) threshold_value++;
        if (x <= 300) threshold_value--;
        if (threshold_value < 1) threshold_value = 1;
        Serial1.print("SET THRESH ");
        Serial1.println(threshold_value);
    }

    if (settings_pos == 2) {
        if (digitalRead(SW_PIN) == LOW) {
            current_screen = 0;
        }
    }
}

void drawSettingsMenu() {

    settingsMenu();

    u8g.firstPage();
    do {

        u8g.drawBitmapP(0, 0, 128/8, 64, settings_menu_bitmap);

        if (settings_pos == 0) u8g.drawBitmapP(0, 0, 128/8, 21, bitmap_item_sel_outline);
        if (settings_pos == 1) u8g.drawBitmapP(0, 21, 128/8, 21, bitmap_item_sel_outline);
        if (settings_pos == 2) u8g.drawBitmapP(0, 42, 128/8, 21, bitmap_item_sel_outline);

        u8g.setFont(u8g_font_7x14);

        u8g.drawStr(20, 15, "Sensitivity");
        u8g.drawStr(96, 15, String(sensitivity).c_str());

        u8g.drawStr(20, 36, "Threshold");
        u8g.drawStr(96, 36, String(threshold_value).c_str());

        u8g.drawStr(20, 57, "Back");

    } while (u8g.nextPage());
}
