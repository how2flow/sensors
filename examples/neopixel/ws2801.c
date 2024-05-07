/***************************************************************************
 Copyright (C) 2024 Steve Jeong <steve@how2flow.net>
 
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

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static const char *device = "/dev/spidev0.0";

static uint8_t bits = 8;
static uint8_t mode = SPI_MODE_0;
static uint32_t speed = 1000000;

static void transfer(int fd)
{
	int ret;
	uint8_t tx[] = { /* lsb first */
		0x00, 0x00, 0xff,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
		0x00, 0x00, 0x00,
};
	uint8_t rx[ARRAY_SIZE(tx)] = {0, };
	struct spi_ioc_transfer tr;

	memset(&tr, 0, sizeof(tr));
	tr.tx_buf = (unsigned long)tx;
	tr.rx_buf = (unsigned long)rx;
	tr.len = ARRAY_SIZE(tx);
	tr.speed_hz = speed;
	tr.delay_usecs = 0;
	tr.bits_per_word = bits;
	tr.cs_change = 0;

		ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1) {
		perror("can't send spi message");
		abort();
	}

	for (ret = 0; ret < ARRAY_SIZE(tx); ret++) {
		if (!(ret % 6))
			puts("");
		printf("%.2X ", tx[ret]);
	}
	puts("");
}

int main()
{
	int fd, ret;

	fd = open(device, O_RDWR); 
	if (fd < 0) {
		perror("can't open device");
		abort();
	}

	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0) {
		perror("can't set spi mode");
		abort();
	}

//	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
//	if (ret < 0) {
//		perror("can't get spi mode");
//		abort();
//	}

	/*** bits per word ***/
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret < 0) {
		perror("can't set bits per word");
		abort();
	}

//	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
//	if (ret < 0) {
//		perror("can't set bits per word");
//		abort();
//	}

	/*** max speed hz ***/
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0) {
		perror("can't set bits per word");
		abort();
	}

	transfer(fd);
	close(fd);

	return ret;

}
