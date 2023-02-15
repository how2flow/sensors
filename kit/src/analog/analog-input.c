#include <wiringPi.h>
#include <stdio.h>

#define SENSING_RANGE 50

#define ADC_MAX 4095 // 4KB - 1
#define ADC_MIN (SENSING_RANGE + 5)

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

	while (1) {
		value = analogRead(ADC);
		sensing = prev_value - value;

		if (value >= ADC_MAX) {
			printf("turn volume to CW.\n");
			continue;
		}

		if (value < ADC_MIN) {
			printf("turn volume to CCW.\n");
			continue;
		}

		if (sensing >= SENSING_RANGE) {
			printf("signal detected.\n");
		}

		/* debugging */
		// printf("analog value: %d\n", value);

		prev_value = value;
		delay(10);
	}

	return 0;
}
