# Copyright (C) Steve Jeong <steve@how2flow.net>

# target:
# ky-009, ky-016

import time
import board
import pwmio

Red_pin = pwmio.PWMOut(board.D15, duty_cycle = 2 ** 14, frequency=100)
Green_pin = pwmio.PWMOut(board.D33, duty_cycle = 2 ** 14, frequency=100)
Blue_pin = pwmio.PWMOut(board.D35, duty_cycle = 2 ** 14, frequency=100)
