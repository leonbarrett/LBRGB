/*
* LBRGB
* 
* Use this code to control RGB Leds
*/

#include "LBRGB.h"

// pins for colors
int r_pin;
int g_pin;
int b_pin;

String led_mode = "C_CATHODE";

// saves current state (color)
int curr_r = 0;
int curr_g = 0;
int curr_b = 0;

int var = 0;


// constructor; saves the pins
LBRGB::LBRGB(int r, int g, int b){
	r_pin = r;
	g_pin = g;
	b_pin = b;
}

void LBRGB::setMode(String m){
    
    led_mode = m;
    
}

// Set LED-color to custom color instantely
void LBRGB::setColour(String c){
	
	int r = 255;
	int g = 255;
	int b = 255;
	
	if(c == "red"){
		r = 255;
		g = 0;
		b = 0;
	}
	
	if(c == "green"){
		r = 0;
		g = 255;
		b = 0;
	}
	
	if(c == "blue"){
		r = 0;
		g = 0;
		b = 255;
	}
			
			
	LBRGB::setValue(r, g, b);

}

void LBRGB::setValue(int r, int g, int b){
	// set color of LED
    if(led_mode == "C_CATHODE"){
        analogWrite(r_pin,255-r);
        analogWrite(g_pin,255-g);
        analogWrite(b_pin,255-b);
    }
    
    if(led_mode == "C_ANODE"){
        analogWrite(r_pin,r);
        analogWrite(g_pin,g);
        analogWrite(b_pin,b);
    }
	// save state
	curr_r = r;
	curr_g = g;
	curr_b = b;
}

void LBRGB::setPending(long b){
	
	var = 0;
	
    while(var < 15){
        LBRGB::setValue(255, 255, 0);
        delay(b);
        LBRGB::setValue(0, 0, 0);
        delay(b);
        var ++;
    }
        
	
}

void LBRGB::setWorking(){
   LBRGB::setColour("blue");
   delay(100);
   LBRGB::setOff();
   delay(100);
   LBRGB::setColour("blue");
   delay(100);
   LBRGB::setOff();
   delay(100);
   LBRGB::setColour("blue");
   delay(100);
   LBRGB::setOff();
   delay(100);
   LBRGB::setColour("blue");
   delay(100);
   LBRGB::setOff();

}

void LBRGB::setOff(){
	LBRGB::setValue(0, 0, 0);
}