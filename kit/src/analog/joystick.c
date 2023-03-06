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

/* adc */
#define ADC_MAX 4095 // 4kb - 1
#define ADC_X 29
#define ADC_Y 25
#define SW 24

/* axis */
#define AXIS_1 (ADC_MAX / 3)
#define AXIS_2 ((ADC_MAX * 2) / 3)

/* target:
 * ky-023
 */

int main()
{
	int pos_x, pos_y, sw;
	int position;

	wiringPiSetup();

	while (1) {
		pos_x = analogRead(ADC_X);
		pos_y = analogRead(ADC_Y);
		sw = digitalRead(SW);

		if (pos_x < AXIS_1) {
			if (pos_y < AXIS_1) {
				printf("NW\n");
			}
			else if (pos_y >= AXIS_1 && pos_y < AXIS_2) {
				printf("W\n");
			}
			else {
				printf("SW\n");
			}
		}
		else if (pos_x >= AXIS_1 && pos_x < AXIS_2) {
			if (pos_y < AXIS_1) {
				printf("N\n");
			}
			else if (pos_y >= AXIS_1 && pos_y < AXIS_2) {
				printf("center\n");
			}
			else {
				printf("S\n");
			}
		}
		else {
			if (pos_y < AXIS_1) {
				printf("NE\n");
			}
			else if (pos_y >= AXIS_1 && pos_y < AXIS_2) {
				printf("E\n");
			}
			else {
				printf("SE\n");
			}
		}

		/* debug */
		// printf("x: %4d y: %4d sw: %d\n", pos_x, pos_y, sw);

		delay(50);
	}

	return 0;
}
