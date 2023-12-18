# Copyright (C) Steve Jeong <steve@how2flow.net>

# target:
# ky-008, ky-012
# ky-034

import time
import board
import digitalio

pin = digitalio.DigitalInOut(board.D7)
pin.direction = digitalio.Direction.OUTPUT

while True:
  pin.value = True
  time.sleep(0.5)
  pin.value = False
  time.sleep(0.5)
