# Copyright (C) Steve Jeong <steve@how2flow.net>

# target:
# ky-040
# 
# servo:
# MG996R

import time
import board
import digitalio

import pwmio
servo = pwmio.PWMOut(board.D11, duty_cycle = ((2 ** 14) / 10), frequency=100)

MIN = ((2 ** 14) / 10)
MAX = 2 ** 13

dt = digitalio.DigitalInOut(board.D13)
sw = digitalio.DigitalInOut(board.D15)
clk = digitalio.DigitalInOut(board.D7)

dt.direction = digitalio.Direction.INPUT
sw.direction = digitalio.Direction.INPUT
clk.direction = digitalio.Direction.INPUT

prev_clk = 0
prev_dt = 0

while True:
  cur_clk = clk.value
  cur_dt = dt.value

  if (cur_clk and cur_dt == 1):
    if (!(prev_clk) and prev_dt == 1):
      servo.duty_cycle -= (2 ** 14 / 50)
    elif (prev_clk and !(prev_dt)):
      servo.duty_cycle += (2 ** 14 / 50)

  if (servo.duty_cycle < MIN):
    servo.duty_cycle = MIN
  if (servo.duty_cycle > MAX):
    servo.duty_cycle = MAX

  prev_clk = cur_clk
  prev_dt = cur_dt

