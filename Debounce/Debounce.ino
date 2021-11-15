#include <ArduinoSTL.h>
using namespace std;
#include "Components.h"
#include <Servo.h>
Servo servo;

DebounceSwitch sw1(8);
DebounceSwitch sw2(9);
DebounceSwitch sw3(10);

LED greenLed(11);
LED yellowLed(12);
LED redLed(13);

class RockAction :public Slot {
public:
	RockAction() {

	}
	virtual void signaled(bool state) {
		servo.write(0);
	}
};
RockAction rockAction;

class PaperAction :public Slot {
	virtual void signaled(bool state) {
		servo.write(167);
	}
};
PaperAction paperAction;

class ScissorAction :public Slot {
	virtual void signaled(bool state) {
		servo.write(53);
	}
};
ScissorAction scissorAction;

class EmptyAction :public Slot {
	virtual void signaled(bool state) {
		servo.write(180);
	}
};
EmptyAction emptyAction;

void setup() {
	//vector<int> ints;
	//ints.push_back(10);

	Serial.begin(9600);
	//printf("Hello World\n");

	pinMode(greenLed.getPin(), OUTPUT);
	pinMode(yellowLed.getPin(), OUTPUT);
	pinMode(redLed.getPin(), OUTPUT);

	pinMode(sw1.getPin(), INPUT);
	pinMode(sw2.getPin(), INPUT);
	pinMode(sw3.getPin(), INPUT);

	sw1.connect(&greenLed);
	sw1.connect(&paperAction);

	sw2.connect(&yellowLed);
	sw2.connect(&scissorAction);

	sw3.connect(&redLed);
	sw3.connect(&rockAction);

	servo.attach(2);
	servo.write(90);
	delay(40);
}

// the loop function runs over and over again until power down or reset
void loop() {
	sw1.update();
	sw2.update();
	sw3.update();
	delay(1);
}
