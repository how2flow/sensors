#include <wiringPi.h>
#include <stdio.h>

#define PIN 7
#define LED 4 // phy #16

/* target:
 * ky-003, ky-004
 * ky-017, ky-020
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(PIN, INPUT);
	pinMode(LED, OUTPUT);
	while (1) {
		value = digitalRead(PIN);
		printf("value: %d\n", value);
		if (value) {
			digitalWrite(LED, HIGH);
		}
		else {
			digitalWrite(LED, LOW);
		}
	}
}
