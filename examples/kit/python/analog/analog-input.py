# Copyright (C) 2023 Steve Jeong <steve@how2flow.net>

# target:
# ky-013, ky-018,
# ky-024, ky-025,
# ky-026, ky-033,
# ky-035, ky-036,
# ky-037, ky-038

import time
import board
import digitalio
from analogio import AnalogIn

ADC_MAX = 4095
ADC_MIN = 0
SENSING_RANGE = 50

def get_voltage(pin):
  return (pin.value * 1.8) / (ADC_MAX + 1)

ADC = AnalogIn(board.A0)
LED = digitalio.DigitalInOut(board.D35)
LED.direction = digitalio.Direction.OUTPUT
LED.value = False

prev_value = get_voltage(ADC)

while True:
  value = get_voltage(ADC)
  sensing = abs(prev_value - value)
  prev_value = value

  if (value >= ADC_MAX):
    print("turn volume to CW")
    continue

  if (value < ADC_MIN):
    print("turn volume to CCW")
    continue

  if (sensing >= SENSING_RANGE):
    print("signal catch! (value:{})".format(value))
    LED.value = True
    time.sleep(0.5)
    LED.value = False
    time.sleep(0.5)
