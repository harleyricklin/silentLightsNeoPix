  
  //void loop() {
    // Some example procedures showing how to display to the pixels:
  //  colorWipe(strip1.Color(255, 0, 0), 50); // Red
  //  colorWipe(strip1.Color(0, 255, 0), 50); // Green
  //  colorWipe(strip1.Color(0, 0, 255), strip1.Color(0, 255, 255), 50); // Blue
  //  delay(1000);
  //  rainbow(20);
  //  rainbowCycle(20);
  //}
  
  
  //--------------------------------------------------------------------------------
  
  
  void colorWipe(uint32_t c, uint32_t c1, uint8_t wait) {
    for(uint16_t i=0; i<strip1.numPixels(); i++) {
        strip1.setPixelColor(i, c);
    }
  
    for(uint16_t i=0; i<strip2.numPixels(); i++) {
        strip2.setPixelColor(i, c1);
    }
  
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
        strip3.setPixelColor(i, c);
    }
  
    for(uint16_t i=0; i<strip4.numPixels(); i++) {
        strip4.setPixelColor(i, c1);
    }
  
    for(uint16_t i=0; i<strip5.numPixels(); i++) {
        strip5.setPixelColor(i, c);
    }
  
    strip1.show();
    strip2.show();
    strip3.show();
    strip4.show();
    strip5.show();
        
    delay(wait);
  }
  
  //--------------------------------------------------------------------------------
  
  void rainbow(uint8_t wait) {
    uint16_t i, j;
  
    for(j=0; j<256; j++) {
      for(i=0; i<strip1.numPixels(); i++) {
        strip1.setPixelColor(i, Wheel((i+j) & 255));
      }
      strip1.show();
      delay(wait);
    }
  }
  
  //--------------------------------------------------------------------------------
  
  // Slightly different, this makes the rainbow equally distributed throughout
  void rainbowCycle(uint8_t wait) {
    uint16_t i, j;
  
    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
      for(i=0; i< strip1.numPixels(); i++) {
        strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      }
      strip1.show();
      delay(wait);
    }
  }
  
  //--------------------------------------------------------------------------------
  
  // Input a value 0 to 255 to get a color value.
  // The colours are a transition r - g - b - back to r.
  uint32_t Wheel(byte WheelPos) {
    if(WheelPos < 85) {
     return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    } else if(WheelPos < 170) {
     WheelPos -= 85;
     return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
     WheelPos -= 170;
     return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
  }
  
  //--------------------------------------------------------------------------------
  
  

