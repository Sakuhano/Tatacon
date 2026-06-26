
extern JoyButton joystick;
extern U8GLIB_SSD1306_128X64 u8g;

const int NUM_ITEMS = 2;
const int MAX_ITEM_LENGTH = 20;
extern const unsigned char bitmap_item_sel_outline[];
extern const unsigned char* bitmap_icons[];
extern const unsigned char bitmap_scrollbar_background[];

extern int current_screen;

char menu_items [NUM_ITEMS] [MAX_ITEM_LENGTH] = {
  { "Controller" },
  { "Settings" },
 };

 int item_selected = 0;

int item_sel_previous;
int item_sel_next;

int selectbar=0;
void itemsMenu() {

  item_sel_previous = item_selected - 1;
  if (item_sel_previous < 0) {item_sel_previous = NUM_ITEMS - 1;}
  item_sel_next = item_selected + 1;
  if (item_sel_next >= NUM_ITEMS) {item_sel_next = 0;}

}

void drawMenu() {
if (item_selected==1) {
selectbar=21;
}
else {
  selectbar=0;
}

      u8g.drawBitmapP(0, 22+selectbar, 128/8, 21, bitmap_item_sel_outline);

      u8g.setFont(u8g_font_7x14B);
      u8g.drawStr(25, 15+20+2, menu_items[0]);
      u8g.drawBitmapP( 4, 24, 16/8, 16, bitmap_icons[0]);

      u8g.setFont(u8g_font_7x14);
      u8g.drawStr(25, 15+20+20+2+2, menu_items[1]);
      u8g.drawBitmapP( 4, 46, 16/8, 16, bitmap_icons[1]);

      u8g.drawBitmapP(128-8, 0, 8/8, 64, bitmap_scrollbar_background);

      u8g.drawBox(125, 64/NUM_ITEMS * item_selected, 3, 64/NUM_ITEMS);

      u8g.setFont(u8g_font_7x14);
      u8g.drawStr(30, 15, "TAIKO MENU");

    }
