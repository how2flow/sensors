/***************************************************************************
Copyright (C) 2023 Steve Jeong <how2soft@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
****************************************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define SERVO 1
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
