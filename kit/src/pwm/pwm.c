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

#define PWM 23
#define DUTY 50

/* target:
 */

int main()
{
	wiringPiSetup();
	pinMode(PWM, PWM_OUTPUT);
	pwmSetClock(2400);
	pwmSetRange(100);
	pwmWrite(PWM, DUTY);

	return 0;
}
