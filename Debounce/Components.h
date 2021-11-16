
#ifndef _Components_h
#define _Components_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#endif

#include <ArduinoSTL.h>

using namespace std;

class Slot {
public:
	virtual void signaled(bool state) = 0;
};

class Signal {
public:
	void emit(bool value) {
		for (auto& slot : slots) {
			slot->signaled(value);
		}
	}
	void connect(Slot* slot) {
		slots.push_back(slot);
	}
private:
	vector<Slot*> slots;
};


//debouncing switch
//fire event immediately if changed, then wait some time until allowed to fire again
class DebounceSwitch : public Signal {
	int pin = 0;
	bool stableState = false;
	int minWait = 5;
	int fireTime = 0;
public:
	DebounceSwitch(int pin) {
		this->pin = pin;
		this->stableState = digitalRead(pin);
	}

	int getPin() { return pin; }

	bool state() { return stableState; }

	void update() {
		bool currentState = digitalRead(pin);
		if (currentState != stableState) {
			int now = millis();
			int delta = now - fireTime;
			if (delta > minWait) {
				stableState = currentState;
				emit(stableState);
				fireTime = now;
			}
		}
	}
};

class LED :public Slot {
	int pin;
public:
	LED(int pin) { this->pin = pin; }
	int getPin() { return pin; }
	virtual void signaled(bool state) {
		digitalWrite(pin, state);

		Serial.print("LED pin set to ");
		Serial.println(state);
	}
};