#ifndef LBRGB_H
#define LBRGB_H

#include <Arduino.h>

class LBRGB
{
	public:
		LBRGB(int r, int g, int b);
		void setColour(String c);
		void setPending(long b);
		void setOff();
        void setMode(String m);
		void setWorking();
		void setValue(int r, int g, int b);
};

#endif