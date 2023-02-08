#include <wiringPi.h>
#include <stdio.h>

#define APIN 29
#define DPIN 7
#define LED 24

/* target:
 * ky-024, ky-025,
 * ky-026, ky-036,
 * ky-037, ky-038
 */ 

int main()
{
	int value;

	wiringPiSetup();
	pinMode(DPIN, INPUT);
	pinMode(LED, OUTPUT);

	while (1) {
		value = analogRead(APIN);

		if (digitalRead(DPIN)) {
			digitalWrite(LED, HIGH);
		}
		else {
			digitalWrite(LED, LOW);
		}
		printf("analog value: %d\n", value);
		delay(5);
	}
	return 0;
}
