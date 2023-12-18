# Copyright (C) Steve Jeong <steve@how2flow.net>

# target:
# ky-002, ky-003,
# ky-004, ky-010,
# ky-017, ky-020,
# ky-021, ky-024,
# ky-025, ky-026,
# ky-027, ky-031,
# ky-032, ky-036,
# ky-037, ky-038

import board
import digitalio

pin = digitalio.DigitalInOut(board.D7)
led = digitalio.DigitalInOut(board.D35)

pin.direction = digitalio.Direction.INPUT
led.direction = digitalio.Direction.OUTPUT

while True:
  value = pin.value
  print("value: {}".format(pin.value))
  if (value):
    led.value = True
  else:
    led.value = False
