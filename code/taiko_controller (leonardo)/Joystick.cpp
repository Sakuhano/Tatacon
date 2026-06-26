#include "Joystick.h"
#include "HIDReportData.h"
// Adapted from progmem/Switch-Fightstick (https://github.com/progmem/Switch-Fightstick) — kept per its license terms.
static const uint8_t _hidReportDescriptor[] PROGMEM = {
  HID_RI_USAGE_PAGE(8,1),
  HID_RI_USAGE(8,5),
  HID_RI_COLLECTION(8,1),

    HID_RI_REPORT_ID(8,3),

    HID_RI_LOGICAL_MINIMUM(8,0),
    HID_RI_LOGICAL_MAXIMUM(8,1),
    HID_RI_PHYSICAL_MINIMUM(8,0),
    HID_RI_PHYSICAL_MAXIMUM(8,1),

    HID_RI_REPORT_SIZE(8,1),
    HID_RI_REPORT_COUNT(8,16),
    HID_RI_USAGE_PAGE(8,9),
    HID_RI_USAGE_MINIMUM(8,1),
    HID_RI_USAGE_MAXIMUM(8,16),
    HID_RI_INPUT(8,2),

    HID_RI_USAGE_PAGE(8,1),
    HID_RI_LOGICAL_MAXIMUM(8,7),
    HID_RI_PHYSICAL_MAXIMUM(16,315),
    HID_RI_REPORT_SIZE(8,4),
    HID_RI_REPORT_COUNT(8,1),
    HID_RI_UNIT(8,20),
    HID_RI_USAGE(8,57),
    HID_RI_INPUT(8,66),

    HID_RI_UNIT(8,0),
    HID_RI_REPORT_COUNT(8,1),
    HID_RI_INPUT(8,1),

    HID_RI_LOGICAL_MAXIMUM(16,255),
    HID_RI_PHYSICAL_MAXIMUM(16,255),
    HID_RI_USAGE(8,48),
    HID_RI_USAGE(8,49),
    HID_RI_USAGE(8,50),
    HID_RI_USAGE(8,53),
    HID_RI_REPORT_SIZE(8,8),
    HID_RI_REPORT_COUNT(8,4),
    HID_RI_INPUT(8,2),

    HID_RI_USAGE_PAGE(16,65280),
    HID_RI_USAGE(8,32),
    HID_RI_REPORT_COUNT(8,1),
    HID_RI_INPUT(8,2),

    HID_RI_USAGE(16,9761),
    HID_RI_REPORT_COUNT(8,8),
    HID_RI_OUTPUT(8,2),
  HID_RI_END_COLLECTION(0),
};

Joystick_::Joystick_()
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().PrependDescriptor(&node);
}

void Joystick_::sendState()
{
	HID().SendRaw(this, 8);
}

Joystick_ Joystick;
