#include <Adafruit_NeoPixel.h>

#define PIN1 3
#define PIN2 4
#define PIN3 5
#define PIN4 6
#define PIN5 7

// Parameter 1 = number of pixels in strip1
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(240, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(240, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(240, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(240, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(240, PIN5, NEO_GRB + NEO_KHZ800);

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

double bits = 0;
int threshold1 = 1;
//  int threshold2 = 2.1;
int threshold2 = 650;
float hueChange = 0;

//--------------------------------------------------------------------------------

void setup() {
  //  Serial.begin(9600);

  initialize();

  // alternate();
  //  delay(5000);

}

//--------------------------------------------------------------------------------


void loop() {



  while (bits < threshold2) {
    soundSampling();
    colorFromVolume();
  }

  peakPattern();

}

//--------------------------------------------------------------------------------



