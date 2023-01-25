#include <wiringPi.h>
#include <stdio.h>

#define SERVO 1 // phy #12
#define DT 2
#define SW 3
#define CLK 7

#define MIN 5
#define MAX 25

/* target:
 * ky-040
 *
 * servo:
 * MG996R
 */

int main()
{
	static int duty = 0;
	static int prev_clk = 0, prev_dt = 0, cur_clk = 0, cur_dt = 0;

	wiringPiSetup();
	pinMode(SW, INPUT);
	pinMode(DT, INPUT);
	pinMode(CLK, INPUT);
	pinMode(SERVO, PWM_OUTPUT);
	pwmSetClock(2400); // 100hz
	pwmSetRange(100);
	pwmWrite(SERVO, MIN);

	while (1) {
		cur_clk = digitalRead(CLK);
		cur_dt = digitalRead(DT);
		if (cur_clk & cur_dt == 1) {
			// CW
			if (!(prev_clk) & prev_dt == 1) {
				duty -= 1;
			}
			// CCW
			else if (prev_clk & !(prev_dt) == 1) {
				duty += 1;
			}
		}

		if (duty < MIN)
			duty = MIN;
		if (duty > MAX)
			duty = MAX;
		pwmWrite(SERVO, duty);

		prev_clk = cur_clk;
		prev_dt = cur_dt;
	}

	return 0;
}
