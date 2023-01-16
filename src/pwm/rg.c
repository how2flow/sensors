#include <wiringPi.h>
#include <stdio.h>

#define rPIN 23 // phy #33
#define gPIN 3  // phy #15

/* target:
 * ky-011, ky-029
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(rPIN, PWM_OUTPUT);
	pinMode(gPIN, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);

	for (value = 100; value > 0; value--) {
		pwmWrite(rPIN, value);
		pwmWrite(gPIN, (100 - value));
		delay(5);
	}
	return 0;
}
