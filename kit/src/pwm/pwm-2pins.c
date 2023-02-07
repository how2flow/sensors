#include <wiringPi.h>
#include <stdio.h>

#define RPIN 23
#define GPIN 3

/* target:
 * ky-011, ky-029
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(RPIN, PWM_OUTPUT);
	pinMode(GPIN, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);

	for (value = 100; value > 0; value--) {
		pwmWrite(RPIN, value);
		pwmWrite(GPIN, (100 - value));
		delay(5);
	}
	return 0;
}
