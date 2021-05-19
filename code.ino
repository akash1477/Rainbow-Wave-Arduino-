#include <FastLED.h>

#define PIN 4 // Connect this to the data pin of the LED strip
#define NUM_LEDS 270 // Number of LED in the strip
#define BRIGHTNESS = 255; 
#define SATURATION = 255;

CRGB leds[NUM_LEDS];   //leds is an array of size NUM_LEDS and used to address each LED in the strip 

void setup(){
 FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS); //<LED type, data pin, RGB order(optional)>
}

void loop(){
  const int k = NUM_LEDS - 1;
  for(int j = 0; j < 255; j++){
  for (int i = 0; i< NUM_LEDS; i++)  // Here, hue = (i*255/k) will range from 0 to 255(max).     
  leds[i] = CHSV((i*255/k)-j, SATURATION, BRIGHTNESS);  //This will make a static and even distribution of hue throughout the strip
  FastLED.show();                                       //The 'j' value changes and the static hue starts moving
  delay(25);}                        // The speed of the wave can be adjusting appropriate value of delay in milliseconds
}
                                                  
