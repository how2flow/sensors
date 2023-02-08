#include <wiringPi.h>
#include <stdio.h>

#define PIN 7
#define PWM 23

/* target:
 * ky-027
 */

int main()
{
	int value;
	int brightness;

	wiringPiSetup();
	pinMode(PIN, INPUT);
	pinMode(PWM, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);

	while (1) {
		value = digitalRead(PIN);
		if (value) {
			if (brightness < 100)
				brightness++;
		}
		else {
			if (brightness > 0)
				brightness--;
		}
		pwmWrite(PWM, brightness);
	}

	return 0;
}
