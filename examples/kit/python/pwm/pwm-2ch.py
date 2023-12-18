# Copyright (C) Steve Jeong <steve@how2flow.net>

# target:
# ky-011, ky-029

import time
import board
import pwmio

Green_pin = pwmio.PWMOut(board.D15, duty_cycle = 2 ** 14, frequency=100)
Red_pin = pwmio.PWMOut(board.D33, duty_cycle = 2 ** 14, frequency=100)
