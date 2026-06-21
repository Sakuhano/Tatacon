//Menu to make readability easier for entire data structure, classifies all menu stuff into functions

extern JoyButton joystick;
extern U8GLIB_SSD1306_128X64 u8g;

const int NUM_ITEMS = 2; // number of items in the list and also the number of screenshots and screenshots with QR codes (other screens)
const int MAX_ITEM_LENGTH = 20; // maximum characters for the item name
extern const unsigned char bitmap_item_sel_outline[];
extern const unsigned char* bitmap_icons[];
extern const unsigned char bitmap_scrollbar_background[];

extern int current_screen;


char menu_items [NUM_ITEMS] [MAX_ITEM_LENGTH] = {  // array with item names
  { "Controller" }, 
  { "Settings" }, 
 };

 int item_selected = 0; // which item in the menu is selected

int item_sel_previous; // previous item - used in the menu screen to draw the item before the selected one
int item_sel_next; // next item - used in the menu screen to draw next item after the selected one



int selectbar=0;
void itemsMenu() {

  item_sel_previous = item_selected - 1;
  if (item_sel_previous < 0) {item_sel_previous = NUM_ITEMS - 1;} // previous item would be below first = make it the last
  item_sel_next = item_selected + 1;  
  if (item_sel_next >= NUM_ITEMS) {item_sel_next = 0;} // next item would be after last = make it the first



}


void drawMenu() {
if (item_selected==1) {
selectbar=21;
}
else {
  selectbar=0;
}
      // selected item background
      u8g.drawBitmapP(0, 22+selectbar, 128/8, 21, bitmap_item_sel_outline);

      /*  // draw previous item as icon + label
      u8g.setFont(u8g_font_7x14);
      u8g.drawStr(25, 15, menu_items[item_sel_previous]); 
      u8g.drawBitmapP( 4, 2, 16/8, 16, );  */        
  
      // draw selected item as icon + label in bold font
      u8g.setFont(u8g_font_7x14B);    
      u8g.drawStr(25, 15+20+2, menu_items[0]);   
      u8g.drawBitmapP( 4, 24, 16/8, 16, bitmap_icons[0]);     

      // draw next item as icon + label
      u8g.setFont(u8g_font_7x14);     
      u8g.drawStr(25, 15+20+20+2+2, menu_items[1]);   
      u8g.drawBitmapP( 4, 46, 16/8, 16, bitmap_icons[1]);  

      // draw scrollbar background
      u8g.drawBitmapP(128-8, 0, 8/8, 64, bitmap_scrollbar_background);

      // draw scrollbar handle
      u8g.drawBox(125, 64/NUM_ITEMS * item_selected, 3, 64/NUM_ITEMS); 

      // draw don
      u8g.setFont(u8g_font_7x14);     
      u8g.drawStr(30, 15, "TAIKO MENU");
      //u8g.drawBitmapP( 4, 2, 16/8, 16, bitmap_taiko_icon);         
      

    } 
    

