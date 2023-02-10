#include <wiringPi.h>
#include <stdio.h>

#define PIN 7
#define PWM 23

#define MAX 100000
#define DIV (MAX / 100)

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

	brightness = MAX;

	while (1) {
		value = digitalRead(PIN);
		if (!value) {
			if (brightness <= MAX)
				brightness--;
		}
		else {
			if (brightness >= 0)
				brightness++;
		}
		if (brightness < 0)
			brightness = 0;
		pwmWrite(PWM, brightness);
	}

	return 0;
}
