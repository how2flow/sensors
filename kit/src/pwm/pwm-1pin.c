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

#define PIN 7
#define PWM 23

#define MAX 100000
#define DIV (MAX / 100)

/* target:
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
