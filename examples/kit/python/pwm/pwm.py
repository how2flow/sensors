# Copyright (C) Steve Jeong <steve@how2flow.net>

import time
import board
import pwmio

pwm = pwmio.PWMOut(board.D33, duty_cycle = ((2 ** 14) / 10), frequency=100)
