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
#define LED 24

/* target:
 * ky-002, ky-003,
 * ky-004, ky-010,
 * ky-017, ky-020,
 * ky-021, ky-024,
 * ky-025, ky-026,
 * ky-031, ky-032,
 * ky-036, ky-037,
 * ky-038
 */

int main()
{
	int value;

	wiringPiSetup();
	pinMode(PIN, INPUT);
	pinMode(LED, OUTPUT);
	while (1) {
		value = digitalRead(PIN);
		printf("value: %d\n", value);
		if (value) {
			digitalWrite(LED, HIGH);
		}
		else {
			digitalWrite(LED, LOW);
		}
	}
}
