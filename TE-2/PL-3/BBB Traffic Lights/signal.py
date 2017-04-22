from __future__ import print_function
import Adafruit_BBIO.GPIO as g
import time as t

green1 = ["P9_24", "P9_15", "P8_12", "P8_14"]
yellow1 = ["P9_13", "P8_16"]
red1 = ["P9_11", "P8_18"]

green2 = ["P9_14", "P9_12", "P8_17", "P8_15"]
yellow2 = ["P9_16", "P8_13"]
red2 = ["P9_23", "P8_11"]

for i in list(green1 + red1 + yellow1 + green2 + red2 + yellow2):
	g.setup(i, g.OUT)
	g.output(i, g.LOW)

t.sleep(1)

while True:
	for i in list(green1 + red2):
		g.output(i, g.HIGH)
	for i in list(yellow1 + yellow2 + green2 + red1):
		g.output(i, g.LOW)
	t.sleep(5)
	for i in green1:
		g.output(i, g.LOW)
	for i in list(yellow1 + red2):
		g.output(i, g.HIGH)
	t.sleep(1)
	for i in list(red1 + green2):
		g.output(i, g.HIGH)
	for i in list(red2 + green1 + yellow1 + yellow2):
		g.output(i, g.LOW)
	t.sleep(5)
	for i in green2:
		g.output(i, g.LOW)
	for i in list(yellow2 + red1):
		g.output(i, g.HIGH)
	t.sleep(1)