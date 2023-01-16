#include <wiringPi.h>
#include <stdio.h>

#define PIN 29 // adc0
#define LED 4

/* target:
 * ky-018, ky-033
 */ 

int main()
{
	int value;

	wiringPiSetup();
	pinMode(LED, OUTPUT);

	while (1) {
		value = analogRead(PIN);
		if (value > 512) {
			digitalWrite(LED, HIGH);
		}
		else {
			digitalWrite(LED, LOW);
		}
		delay(5);
	}
	return 0;
}
