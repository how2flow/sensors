#include <wiringPi.h>
#include <stdio.h>

#define rPIN 3 // phy #15
#define gPIN 23  // phy #33
#define bPIN 24  // phy #35

#define DELAY 10

/* target:
 * ky-009, ky-016
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(rPIN, PWM_OUTPUT);
	pinMode(gPIN, PWM_OUTPUT);
	pinMode(bPIN, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);

	while (1) {
		for (value = 100; value > 0; value--) {
			pwmWrite(rPIN, value);
			pwmWrite(gPIN, (100 - value));
			pwmWrite(bPIN, 0);
			delay(DELAY);
		}

		for (value = 100; value > 0; value--) {
			pwmWrite(rPIN, (100 - value));
			pwmWrite(gPIN, 0);
			pwmWrite(bPIN, value);
			delay(DELAY);
		}

		for (value = 100; value > 0; value--) {
			pwmWrite(rPIN, 0);
			pwmWrite(gPIN, value);
			pwmWrite(bPIN, (100 - value));
			delay(DELAY);
		}
	}
	return 0;
}
