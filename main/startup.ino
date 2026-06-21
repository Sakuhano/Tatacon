extern U8GLIB_SSD1306_128X64 u8g;



void startupAnim() {
   for (int i = 0; i < 3; i++) {
      delay(500);
      u8g.firstPage();
      do {
        
        u8g.drawBitmapP( 0, 0, 128/8, 64, bitmap_startup[i]);
     } while ( u8g.nextPage() );
     delay(250);
    }
}

