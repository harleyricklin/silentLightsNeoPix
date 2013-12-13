  void peakPattern() {
    
  int rndVar = random(16);
  switch (rndVar) {

    //blinkys
  case 1:
    initialize();
    blinky(strip1.Color(80, 40, 255), 5); //pink
    soundSampling();
    break;
  case 2:
    initialize();
    blinky(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;
  case 3:
    initialize();
    blinky(strip1.Color(0, 0, 255), 5); //blue
    soundSampling();
    break;

    //waves
  case 4:
    initialize();
    wave(strip1.Color(0, 0, 255), 5); //blue
    soundSampling();
    break;
  case 5:
    initialize();
    wave(strip1.Color(80, 40, 255), 5); //pink
    soundSampling();
    break;
  case 6:
    initialize();
    wave(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;

    //reverse waves
  case 7:
    // initialize();
    reverseWave(strip1.Color(80, 40, 255), 5); //pink
    soundSampling();
    break;
  case 8:
    // initialize();
    reverseWave(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;

    //backandforth waves  
  case 9:
    //initialize();
    reverseWave(strip1.Color(80, 40, 255), 5); //pink
    wave(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;

  case 10:
    initialize();
    wave(strip1.Color(0, 0, 255), 5); //blue
    reverseWave(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;

  case 11:
    initialize();
    wave(strip1.Color(0, 100, 255), 5); //cyan
    reverseWave(strip1.Color(80, 40, 255), 5); //pink
    soundSampling();
    break;

  case 12:
    initialize();
    wave(strip1.Color(80, 40, 255), 5); //pink
    reverseWave(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;

  case 13:
    initialize();
    wave(strip1.Color(80, 40, 255), 5); //pink
    reverseWave(strip1.Color(0, 0, 255), 5); //blue
    soundSampling();
    break; 

    //more blinkys
  case 14:
    initialize();
    blinky(strip1.Color(80, 40, 255), 5); //pink
    soundSampling();
    break;
  case 15:
    initialize();
    blinky(strip1.Color(0, 100, 255), 5); //cyan
    soundSampling();
    break;
  case 16:
    initialize();
    blinky(strip1.Color(0, 0, 255), 5); //blue
    soundSampling();
    break;


    }
  }
