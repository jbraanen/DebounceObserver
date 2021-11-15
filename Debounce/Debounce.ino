/*
 Name:		Debounce.ino
 Created:	11/15/2021 11:33:03 AM
 Author:	familien
*/

#include <ArduinoSTL.h>
using namespace std;

// the setup function runs once when you press reset or power the board
void setup() {
	vector<int> ints;
	ints.push_back(10);

	Serial.begin(9600);
	printf("Hello World\n");
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
