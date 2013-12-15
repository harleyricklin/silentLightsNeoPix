
  
  void initialize(){
    
    strip1.begin();
    strip2.begin();
    strip3.begin();
    strip4.begin();
    strip5.begin();
    
    colorWipe(strip1.Color(0, 0, 0), strip1.Color(0, 0, 0), 0);  // Initialize all pixels to 'off'
    
  }
  
   //--------------------------------------------------------------------------------
  
  void alternate(){
    
    colorWipe(strip1.Color(0, 0, 255), strip1.Color(0, 255, 255), 50); //we use strip1.Color here, but it applies to all the strips 
    
  }
  
   //--------------------------------------------------------------------------------
   
  void colorFromVolume(){
    
    //values for cyan
    int red = hueChange;
    int grn = 0;
    int blu = (255-hueChange);
    
    //ceiling for green and floor for blue so we don't get too green
    
//    if (blu < 80) { 
//      blu = 150;
//    }
    
    if (grn > 200) {
      grn = 200;
    }
 
    if (red > 200) {
      red = 200;
    }
     
    //pass the color in 
     colorWipe(strip1.Color(red, grn, blu), strip1.Color(red, grn, blu), 200);  
     
  }
  
   //--------------------------------------------------------------------------------
    
  void wave(uint32_t c, uint8_t wait) {

    
    ////////////
    // GATE 1 //
    ///////////
      
    //TOP + BOTTOM
    for(int i=0; i< 120; i++) {
        strip1.setPixelColor(i, c);
        strip1.setPixelColor(240-i, c);
        strip1.show();
        delay(wait);
    }
  
    ////////////
    // GATE 2 //
    ///////////  

    //TOP + BOTTOM
    for(int i=0; i< 120; i++) {
        strip2.setPixelColor(i, c);
        strip2.setPixelColor(240-i, c);
        strip2.show();
        delay(wait);
    }
    
    ////////////
    // GATE 3 //
    ///////////
    
    //TOP + BOTTOM
    for(int i=0; i < 110; i++){
        strip3.setPixelColor(i, c);
        strip3.setPixelColor(215-i, c);
        strip3.show();
        delay(wait);
    }
    
    //BOTTOM OVERLAP
    for(int i=240; i > 215; i--) {
        strip3.setPixelColor(i, c);
        strip3.show();
    }
    
    ////////////
    // GATE 4 //
    ///////////
    
    //TOP + BOTTOM
    for(int i=0; i < 110; i++){
        strip4.setPixelColor(i, c);
        strip4.setPixelColor(215-i, c);
        strip4.show();
        delay(wait);
    }
    
    //BOTTOM OVERLAP
    for(int i=240; i > 215; i--) {
        strip4.setPixelColor(i, c);
        strip4.show();
    }
    
    ////////////
    // GATE 5 //
    ///////////
      
    //TOP + BOTTOM
    for(int i=0; i< 120; i++) {
        strip5.setPixelColor(i, c);
        strip5.setPixelColor(240-i, c);
        strip5.show();
        delay(wait);
    }
    
  }
  
     //--------------------------------------------------------------------------------
    
  void reverseWave(uint32_t c, uint8_t wait) {
    
    ////////////
    // GATE 5 //
    ///////////
      
    //TOP + BOTTOM
    for(int i=0; i< 150; i++) {
        strip5.setPixelColor(90 - i, c);
        strip5.setPixelColor(90 + i, c);
        strip5.show();
        delay(wait);
    }
    
    ////////////
    // GATE 4 //
    ///////////
    
    //TOP + BOTTOM
    for(int i=0; i < 160; i++){
        strip4.setPixelColor(80 - i, c);
        strip4.setPixelColor(80 + i, c);
        strip4.show();
        delay(wait);
    }
      
    ////////////
    // GATE 3 //
    ///////////
       
    //TOP + BOTTOM
    for(int i=0; i < 160; i++){
        strip3.setPixelColor(80 - i, c);
        strip3.setPixelColor(80 + i, c);
        strip3.show();
        delay(wait);
    }  
    
    ////////////
    // GATE 2 //
    ///////////  

    //TOP + BOTTOM
    for(int i=0; i< 160; i++) {
        strip2.setPixelColor(80 - i, c);
        strip2.setPixelColor(80 + i, c);
        strip2.show();
        delay(wait);
    }
    
    ////////////
    // GATE 1 //
    ///////////
      
    //TOP + BOTTOM
    for(int i=0; i< 160; i++) {
        strip1.setPixelColor(80 - i, c);
        strip1.setPixelColor(80 + i, c);
        strip1.show();
        delay(wait);
    }
    
  }
  
  //--------------------------------------------------------------------------------
  
  void blinky(uint32_t c, uint8_t wait) {

    for (int i=0; i<150; i++){
  
      int rand = random(0, 240);
      strip1.setPixelColor(rand, c);
      strip1.show();
      strip2.setPixelColor(rand, c);
      strip2.show();
      strip3.setPixelColor(rand, c);
      strip3.show();
      strip4.setPixelColor(rand, c);
      strip4.show();
      strip5.setPixelColor(rand, c);
      strip5.show();
      delay(wait);
    }
    
  }
 
  //--------------------------------------------------------------------------------
  void expansion(uint32_t c, uint8_t wait) {
    
    // turn on the center gate
    for(uint16_t i=0; i<strip3.numPixels(); i++) {
        strip3.setPixelColor(i, c);
    }
    
    //ripple out to nearby gates
    for(int i=0; i< 160; i++) {
        strip2.setPixelColor(80 - i, c);
        strip2.setPixelColor(80 + i, c);
        strip2.show();
        if (i < 110) {
          strip4.setPixelColor(i, c);
          strip4.setPixelColor(215-i, c);
          strip4.show();
        } else if ( i == 110 ) {
        for(int p=240; p > 215; p--) {
            strip4.setPixelColor(p, c);
            strip4.show();
        }
    }
        
        delay(wait);
    }

    //ripple out to outer gates
    for(int i=0; i< 160; i++) {
        strip1.setPixelColor(80 - i, c);
        strip1.setPixelColor(80 + i, c);
        strip1.show();
        if ( i< 120 ) {
          strip5.setPixelColor(i, c);
          strip5.setPixelColor(240-i, c);
          strip5.show();
        }        
        delay(wait);
    }    

  }
