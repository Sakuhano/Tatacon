#include "U8glib.h"
#include "JoystickButton.h"
#include "bitmaps.h"
#include "EEPROM.h"

extern U8GLIB_SSD1306_128X64 u8g;
extern JoyButton joystick;
extern int current_screen;

#define SW_PIN 8

#define EEPROM_THRESH_ADDR  0
#define EEPROM_SENS0_ADDR   1
#define EEPROM_SENS1_ADDR   2
#define EEPROM_SENS2_ADDR   3
#define EEPROM_SENS3_ADDR   4

int threshold_value = (EEPROM.read(EEPROM_THRESH_ADDR) == 255) ? 15 : EEPROM.read(EEPROM_THRESH_ADDR);

int sens_val[4] = {
  (EEPROM.read(EEPROM_SENS0_ADDR) == 255) ? 10 : EEPROM.read(EEPROM_SENS0_ADDR),
  (EEPROM.read(EEPROM_SENS1_ADDR) == 255) ? 10 : EEPROM.read(EEPROM_SENS1_ADDR),
  (EEPROM.read(EEPROM_SENS2_ADDR) == 255) ? 10 : EEPROM.read(EEPROM_SENS2_ADDR),
  (EEPROM.read(EEPROM_SENS3_ADDR) == 255) ? 10 : EEPROM.read(EEPROM_SENS3_ADDR)
};

int settings_pos = 0;
#define SETTINGS_COUNT 6

bool showSavedPopup = false;
unsigned long popupStartTime = 0;

unsigned long lastInputTime = 0;
#define INPUT_DEBOUNCE_MS 200

void sendSettingsToController() {

  Serial1.write('T');
  Serial1.write((byte)threshold_value);

  for (int i = 0; i < 4; i++) {
    Serial1.write('W');
    Serial1.write((byte)i);
    Serial1.write((byte)sens_val[i]);
  }
}

void settingsMenu() {

    joystick.update();
    int x = joystick.readX();
    int y = joystick.readY();

    if (showSavedPopup) {
        if (millis() - popupStartTime > 700) {
            showSavedPopup = false;
            current_screen = 0;
        }
        return;
    }

    if (millis() - lastInputTime < INPUT_DEBOUNCE_MS) return;

    if (y >= 700) {
        settings_pos--;
        if (settings_pos < 0) settings_pos = 0;
        lastInputTime = millis();
    }
    else if (y <= 300) {
        settings_pos++;
        if (settings_pos >= SETTINGS_COUNT) settings_pos = SETTINGS_COUNT - 1;
        lastInputTime = millis();
    }

    if (settings_pos == 0) {
        if (x >= 700) { threshold_value++; lastInputTime = millis(); }
        if (x <= 300) { threshold_value--; lastInputTime = millis(); }
        if (threshold_value < 1) threshold_value = 1;
        if (threshold_value > 255) threshold_value = 255;
    }

    if (settings_pos >= 1 && settings_pos <= 4) {
        int idx = settings_pos - 1;
        if (x >= 700) { sens_val[idx]++; lastInputTime = millis(); }
        if (x <= 300) { sens_val[idx]--; lastInputTime = millis(); }
        if (sens_val[idx] < 1)  sens_val[idx] = 1;
        if (sens_val[idx] > 50) sens_val[idx] = 50;
    }

    if (settings_pos == 5) {
        if (digitalRead(SW_PIN) == LOW) {
            EEPROM.update(EEPROM_THRESH_ADDR, (byte)threshold_value);
            EEPROM.update(EEPROM_SENS0_ADDR, (byte)sens_val[0]);
            EEPROM.update(EEPROM_SENS1_ADDR, (byte)sens_val[1]);
            EEPROM.update(EEPROM_SENS2_ADDR, (byte)sens_val[2]);
            EEPROM.update(EEPROM_SENS3_ADDR, (byte)sens_val[3]);

            sendSettingsToController();

            showSavedPopup = true;
            popupStartTime = millis();
        }
    }
}

void drawSettingsMenu() {

    settingsMenu();

    if (showSavedPopup) {
        u8g.firstPage();
        do {
            u8g.setFont(u8g_font_6x10);
            u8g.drawStr(30, 32, "Saved + Sent!");
        } while (u8g.nextPage());
        return;
    }

    u8g.firstPage();
    do {

        if (settings_pos == 0) u8g.drawBitmapP(0, 0,  128/8, 10, bitmap_item_sel_outline);
        if (settings_pos == 1) u8g.drawBitmapP(0, 10, 128/8, 10, bitmap_item_sel_outline);
        if (settings_pos == 2) u8g.drawBitmapP(0, 20, 128/8, 10, bitmap_item_sel_outline);
        if (settings_pos == 3) u8g.drawBitmapP(0, 30, 128/8, 10, bitmap_item_sel_outline);
        if (settings_pos == 4) u8g.drawBitmapP(0, 40, 128/8, 10, bitmap_item_sel_outline);
        if (settings_pos == 5) u8g.drawBitmapP(0, 54, 128/8, 10, bitmap_item_sel_outline);

        u8g.setFont(u8g_font_6x10);

        u8g.drawStr(2, 9, "Threshold");
        u8g.drawStr(90, 9, String(threshold_value).c_str());

        char buf[6];
        const char* labels[4] = {"Sens L", "Sens R", "Sens DL", "Sens DR"};
        for (int i = 0; i < 4; i++) {
            u8g.drawStr(2, 9 + (i+1)*10, labels[i]);

            sprintf(buf, "%d.%d", sens_val[i]/10, sens_val[i]%10);
            u8g.drawStr(90, 9 + (i+1)*10, buf);
        }

        u8g.drawStr(2, 63, "Save + Back");

    } while (u8g.nextPage());
}
