#include <wiringPi.h>
#include <stdio.h>

#define PIN 7
#define LED 4

/* target:
 * ky-002, ky-003,
 * ky-004, ky-010,
 * ky-017, ky-020,
 * ky-021, ky-031,
 * ky-032
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