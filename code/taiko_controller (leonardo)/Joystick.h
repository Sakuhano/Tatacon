#ifndef JOYSTICK_h
#define JOYSTICK_h
// Adapted from progmem/Switch-Fightstick (https://github.com/progmem/Switch-Fightstick) — kept per its license terms.
#include <HID.h>

typedef enum {
  SWITCH_BTN_NONE    = 0x00,
  SWITCH_BTN_Y       = 0x01,
  SWITCH_BTN_B       = 0x02,
  SWITCH_BTN_A       = 0x04,
  SWITCH_BTN_X       = 0x08,
  SWITCH_BTN_L       = 0x10,
  SWITCH_BTN_R       = 0x20,
  SWITCH_BTN_ZL      = 0x40,
  SWITCH_BTN_ZR      = 0x80,
  SWITCH_BTN_SELECT  = 0x100,
  SWITCH_BTN_START   = 0x200,
  SWITCH_BTN_LCLICK  = 0x400,
  SWITCH_BTN_RCLICK  = 0x800,
  SWITCH_BTN_HOME    = 0x1000,
  SWITCH_BTN_CAPTURE = 0x2000,
} JoystickButtons_t;

typedef enum {
  SWITCH_HAT_U  = 0x00,
  SWITCH_HAT_UR = 0x01,
  SWITCH_HAT_R  = 0x02,
  SWITCH_HAT_DR = 0x03,
  SWITCH_HAT_D  = 0x04,
  SWITCH_HAT_DL = 0x05,
  SWITCH_HAT_L  = 0x06,
  SWITCH_HAT_UL = 0x07,
  SWITCH_HAT_CENTER = 0x08,
} JoystickHats_t;

struct Joystick_
{
  uint16_t Button = SWITCH_BTN_NONE;
  uint8_t  HAT = SWITCH_HAT_CENTER;
  uint8_t  LX = 128;
  uint8_t  LY = 128;
  uint8_t  RX = 128;
  uint8_t  RY = 128;
  uint8_t  VendorSpec = 0;

  Joystick_();
	void sendState();
};

extern Joystick_ Joystick;

#endif
