extern JoyButton joystick;
extern U8GLIB_SSD1306_128X64 u8g;
extern int current_screen;

int xpos=20;
int ypos=1;
int position =21;
int lastposition = 21;

int xcoord=55; 
int ycoord=23;
int current_screen=0;
int selectorframe = 0;
unsigned long prevframetime = 0;

bool inputSent = false;

void circleselector() {

joystick.update();

int x= joystick.readX();
int y= joystick.readY();

if (x>=700) { xpos=30; }
else if (x<=300) { xpos=10; }
else {xpos = 20;}

if (y>=700) { ypos=2; }
else if (y<=300) { ypos=0; }
else {ypos = 1;}

position = xpos+ypos;

switch (position) {
case 10: xcoord = 51; ycoord= 36; break;
case 11: xcoord = 50; ycoord = 27; break;
case 12: xcoord = 52; ycoord =19; break;
case 20: xcoord=59; ycoord=37; break;
case 22: xcoord=59; ycoord=18; break;
case 30: xcoord=68; ycoord=36; break;
case 31: xcoord=69; ycoord=27; break;
case 32: xcoord=68; ycoord=19; break;
}

if (position != lastposition) {
selectorframe=0;
lastposition=position;
inputSent = false;
}

if (position==21) {
selectorframe = 4;
xcoord=55;
ycoord=23;
return;
}

if (millis()-prevframetime > 80) {
selectorframe = (selectorframe+1) % 4;
prevframetime=millis();
}

if (selectorframe == 3 && !inputSent && position != 21) {

if (position == 12) Serial1.println("BTN A");
if (position == 22) Serial1.println("HAT U");
if (position == 32) Serial1.println("BTN B");
if (position == 11) Serial1.println("HAT L");
if (position == 31) Serial1.println("HAT R");
if (position == 10) Serial1.println("BTN CAP");
if (position == 20) Serial1.println("HAT D");
if (position == 30) Serial1.println("BTN HOME");

inputSent = true;
}

if (position == 21 && selectorframe == 4 && !inputSent) {
current_screen = 0;
inputSent = true;
}

}

void drawControllerMenu()  {

circleselector();

u8g.firstPage();
do {
u8g.drawBitmapP(0, 0, 128/8, 64, emulator_screen_radial_menu);

if (position==21) {
u8g.drawBitmapP(55, 23, 3, 18, back_select);
}
else {
u8g.drawBitmapP(xcoord, ycoord, 2, 9, selector_circle_animation[selectorframe]);
}

u8g.drawBitmapP(57, 25, 2, 14, bitmap_backbutton);

} while ( u8g.nextPage() );

}
