#include <ArduinoSTL.h>
using namespace std;
#include "Components.h"

DebounceSwitch sw(8);
LED led(13);

// the setup function runs once when you press reset or power the board
void setup() {
	vector<int> ints;
	ints.push_back(10);

	Serial.begin(9600);
	printf("Hello World\n");

	pinMode(led.getPin(), OUTPUT);
	pinMode(sw.getPin(), INPUT);

	sw.connect(&led);
}

// the loop function runs over and over again until power down or reset
void loop() {
	sw.update();  
	delay(1);
}
