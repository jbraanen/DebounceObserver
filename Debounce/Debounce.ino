#include <ArduinoSTL.h>
#include "Components.h"
#include <Servo.h>
using namespace std;
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
		servo.write(50);
	}
};
PaperAction paperAction;

class ScissorAction :public Slot {
	virtual void signaled(bool state) {
		servo.write(70);
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
	Serial.begin(9600);
	printf("Setup\n");

	pinMode(greenLed.getPin(), OUTPUT);
	pinMode(yellowLed.getPin(), OUTPUT);
	pinMode(redLed.getPin(), OUTPUT);

	pinMode(sw1.getPin(), INPUT);
	pinMode(sw2.getPin(), INPUT);
	pinMode(sw3.getPin(), INPUT);

	sw1.connect(&greenLed);
	sw1.connect(&rockAction);

	sw2.connect(&yellowLed);
	sw2.connect(&paperAction);

	sw3.connect(&redLed);
	sw3.connect(&scissorAction);

	servo.attach(2);
	servo.write(90);
	delay(40);
}

void loop() {
	sw1.update();
	sw2.update();
	sw3.update();
	delay(1);
}
