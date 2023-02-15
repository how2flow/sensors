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
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

#define LED1 4
#define LED2 5
#define LED3 6
#define ON 1
#define OFF 0

void ledPattern (int value);

int main(int argc, char *argv[])
{
	const char* lircd_path;
	struct lirc_config *config;
	int buttonTimer = millis();
	char *code;
	int cnt;

	wiringPiSetup();
	pinMode (LED1, OUTPUT);
	pinMode (LED2, OUTPUT);
	pinMode (LED3, OUTPUT);

	if (lirc_init("lirc",1) == -1) {
		return -1;
	}

	cnt = 1;
	lircd_path = "/etc/lirc/lircd.conf.d/hk.lircd.conf";
	if (lirc_readconfig(lircd_path, &config, NULL) == 0) {
		while (lirc_nextcode(&code) == 0) {
			if(code == NULL)
				continue; 
			if (millis() - buttonTimer  > 400) {
				if (strstr(code,"KEY_POWER")) {
					digitalWrite(LED1, HIGH);
					digitalWrite(LED2, HIGH);
					digitalWrite(LED3, HIGH);
					delay(500);
					digitalWrite(LED1, LOW);
					digitalWrite(LED2, LOW);
					digitalWrite(LED3, LOW);
					buttonTimer = millis();
				}
				else if (strstr(code,"KEY_VOLUMEDOWN")) {
					printf("MATCH on VD\n");
					cnt = cnt >> 1;
					if (cnt <= 0x001)
						cnt = 0x001;
					ledPattern(cnt);
					buttonTimer = millis();
				}
				else if (strstr(code,"KEY_VOLUMEUP")) {
					printf("MATCH on VU\n");
					cnt = cnt << 1;
					if (cnt >= 0x100)
						cnt = 0x100;
					ledPattern(cnt);
					buttonTimer = millis();
				}
			}
			free(code);
		}
		lirc_freeconfig(config);
	}

	lirc_deinit();
	return 0;
}

void ledPattern (int value)
{
	switch (value) {
		case 0x001:
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, LOW);
			break;
		case 0x010:
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, LOW);
			break;
		case 0x100:
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, HIGH);
			break;
	}
}
