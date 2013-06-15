#include <LBRGB.h>

LBRGB rgb(4,6,5);



void setup() {
  
  rgb.setMode("C_CATHODE"); //rgb.setMode("C_ANODE");
  rgb.setPending(50);
  
}

void loop() {
  
  rgb.setColour("red");
  delay(2000);
  rgb.setColour("green");
  delay(2000);
  rgb.setColour("blue");
  delay(2000);
  rgb.setValue(255,255,0); //yellow
  delay(2000);
  rgb.setValue(255,255,255); //white
  delay(2000);
  rgb.setWorking();
}

