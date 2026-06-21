Taiko E‑Box
A custom controller project for Taiko no Tatsujin, built from scratch through hardware prototyping, firmware development, CAD modeling, and a lot of late‑night debugging.

Overview
This project documents the development of a fully custom Taiko no Tatsujin e‑box: the electronics, firmware, and interface that drive a drum controller. What began as a simple prototype evolved into a complete system involving Arduino programming, menu design, joystick input handling, OLED graphics, piezo sensor electronics, PCB planning, and mechanical design.

The goal was not only to build a functional controller, but to understand every layer of the process and create something original rather than following an existing tutorial.

Features
Radial joystick‑controlled menu system

Custom joystick input library

SSD1306 OLED interface with custom pixel art

Piezo‑based hit detection with adjustable thresholds

Modular e‑box architecture designed for future PCB integration

CAD‑modeled drum components based on community‑standard Tatacon geometry

Fully documented development process

Hardware
Core Components
Arduino Mega 2560 R3 (menu, UI, sensor logic)

Arduino Leonardo (USB HID output)

SSD1306 128×64 I²C OLED

Analog joystick (VRx, VRy, SW)

Piezo sensors

Bridge rectifiers and filtering components

Custom drum components modeled and fabricated during the build

Wiring Summary
OLED: SDA → 20, SCL → 21

Joystick: VRx → A1, VRy → A0, SW → D8

Piezo sensors: analog inputs with rectifier/filtering

Mega to Leonardo: Serial1

Shared ground required

Software
Menu System
The project began with a complex menu example, but a clearer tutorial inspired a complete redesign. The menu eventually evolved into a radial system controlled entirely by joystick direction. Custom pixel art was created for each menu section.

Joystick Library
A dedicated library was written to handle directional input, debouncing, edge detection, and button logic. This library made the menu code significantly cleaner and was uploaded to the Arduino Library Manager for use across multiple machines.

OLED Rendering
The SSD1306 display uses U8glib. Early issues with broken bitmaps were traced to incorrect parameters in a tutorial. After correction, the display system became stable and supported the radial menu graphics.

Hit Detection
Initial piezo sensors were degraded and produced extremely low voltages. After replacing them and improving soldering technique, the hit detection system became reliable. Thresholds and sensitivity values were tuned through testing.

Development Journey
This README condenses months of journals into a structured timeline.

Phase 1: Learning and Planning
Learned C++ fundamentals through W3Schools

Explored KiCad for the first time

Created early schematics and preliminary PCB concepts

Modeled drum components in Tinkercad

Built the first bill of materials

Shifted project focus from drum construction to designing a custom e‑box

Phase 2: Menu and UI Development
Studied menu examples and tutorials

Built a scrollable menu

Switched to joystick input for navigation

Wrote a joystick library

Created pixel art for UI elements

Transitioned to a radial menu based on a suggestion

Debugged bitmap rendering issues

Successfully tested the UI in an emulator

Phase 3: Hardware Prototyping
Built the first drum prototype

Diagnosed failing piezo sensors

Replaced and rewired all sensors

Improved soldering technique

Integrated bridge rectifiers

Tested inputs on a Nintendo Switch

Debugged inconsistent triggers and sensitivity issues

Phase 4: CAD and PCB Work
Modeled drum components using community DXF files

Designed a custom connector concept

Cleaned and labeled KiCad schematics

Added footprints and parts for future PCB fabrication

Phase 5: Final Push
Worked across multiple locations due to schedule constraints

Coded during events and travel

Uploaded libraries for cross‑device development

Fixed last‑minute bugs

Completed journals and documentation under time pressure

Lessons Learned
Piezo sensors degrade significantly with use

Proper soldering tools make a major difference

Menu systems are more complex than they appear

The Mega 2560 R3 uses pins 20 and 21 for I²C, not A4/A5

Debugging graphics requires patience

CAD is easier with reference geometry

KiCad is powerful but requires careful organization

Consistent progress, even in small amounts, adds up

Future Work
Final PCB design and fabrication

Improved enclosure for the e‑box

Enhanced filtering for piezo signals

USB‑C integration

Additional menu features

Per‑hit statistics tracking

Firmware refactoring

Full open‑source release

Acknowledgements
Friends who provided workspace and feedback

The tutorial that inspired the menu system

Hack Club for providing the environment to build this

The Taiko hardware community for shared knowledge and resources
