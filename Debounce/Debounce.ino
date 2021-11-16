#include <ArduinoSTL.h>
#include "Components.h"
#include <Servo.h>

Servo servo;

DebounceSwitch sw1(8);
DebounceSwitch sw2(9);
DebounceSwitch sw3(10);

LED greenLed(11);
LED yellowLed(12);
LED redLed(13);

class RockAction :public Slot { public:virtual void signaled(bool state) { servo.write(0); } };
RockAction rockAction;

class PaperAction :public Slot { virtual void signaled(bool state) { servo.write(167); } };
PaperAction paperAction;

class ScissorAction :public Slot { virtual void signaled(bool state) { servo.write(53); } };
ScissorAction scissorAction;

void setup() {
	pinMode(yellowLed.getPin(), OUTPUT);
	pinMode(sw2.getPin(), INPUT);

	sw2.connect(&yellowLed);
	sw2.connect(&scissorAction);

	servo.attach(2);
	delay(40);
}

void loop() {
	sw1.update();
	sw2.update();
	sw3.update();
	delay(1);
}
