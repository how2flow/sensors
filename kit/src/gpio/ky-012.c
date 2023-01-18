#include <wiringPi.h>
#include <stdio.h>

#define PIN 7

/* target:
 * ky-008, ky-012
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(PIN, OUTPUT);
	while (1) {
		digitalWrite(PIN, HIGH);
		delay(500);
		digitalWrite(PIN, LOW);
		delay(500);
	}
}
