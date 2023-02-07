#include <wiringPi.h>
#include <stdio.h>

#define RPIN 3
#define GPIN 23
#define BPIN 24

#define DELAY 10

/* target:
 * ky-009, ky-016
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(RPIN, PWM_OUTPUT);
	pinMode(GPIN, PWM_OUTPUT);
	pinMode(BPIN, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);

	while (1) {
		for (value = 100; value > 0; value--) {
			pwmWrite(RPIN, value);
			pwmWrite(GPIN, (100 - value));
			pwmWrite(BPIN, 0);
			delay(DELAY);
		}

		for (value = 100; value > 0; value--) {
			pwmWrite(RPIN, (100 - value));
			pwmWrite(GPIN, 0);
			pwmWrite(BPIN, value);
			delay(DELAY);
		}

		for (value = 100; value > 0; value--) {
			pwmWrite(RPIN, 0);
			pwmWrite(GPIN, value);
			pwmWrite(BPIN, (100 - value));
			delay(DELAY);
		}
	}
	return 0;
}
