/***************************************************************************
 Copyright (C) 2023 Steve Jeong <steve@how2flow.net>
 
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

/* sensing parameters */
#define SENSING_RANGE 50
#define SENSING_DELAY 10

/* adc */
#define ADC_MAX 4095 // 4KB - 1
#define ADC_MIN 0

#define ADC 29
#define LED 24

/* target:
 * ky-013, ky-018,
 * ky-024, ky-025,
 * ky-026, ky-033,
 * ky-035, ky-036,
 * ky-037, ky-038
 */

int main()
{
	int value, prev_value;
	int sensing;

	wiringPiSetup();
	pinMode(LED, OUTPUT);

	prev_value = analogRead(ADC);
	digitalWrite(LED, LOW);

	while (1) {
		value = analogRead(ADC);
		sensing = prev_value - value;
		prev_value = value;

		if (value >= ADC_MAX) {
			printf("turn volume to CW.\n");
			continue;
		}

		if (value < ADC_MIN) {
			printf("turn volume to CCW.\n");
			continue;
		}

		if (sensing >= SENSING_RANGE) {
			printf("signal catch! (value:%d)\n", value);
			digitalWrite(LED, HIGH);
			delay(50);
			digitalWrite(LED, LOW);
			delay(50);
		}

		/* debugging */
		// printf("analog value: %d\n", value);

		delay(SENSING_DELAY);
	}

	return 0;
}
