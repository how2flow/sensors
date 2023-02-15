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

/* target:
 * ky-008, ky-012
 * ky-034
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(PIN, OUTPUT);
	while (1) {
		digitalWrite(PIN, HIGH);
		delay(500);
		digitalWrite(PIN, LOW);
		delay(500);
	}
}
