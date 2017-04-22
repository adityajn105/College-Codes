from __future__ import print_function
import Adafruit_BBIO.GPIO as g
import time as t
import itertools as it

def onoff(signal, onoff):
	 for k in signal:
		g.output(k, onoff)

signals = {
'signal1': [["P8_12", "P8_14"], ["P8_16"], ["P8_18"]],
'signal2': [["P8_17", "P8_15"], ["P8_13"], ["P8_11"]],
'signal3': [["P9_24", "P9_15"], ["P9_13"], ["P9_11"]],
'signal4': [["P9_12", "P9_14"], ["P9_16"], ["P9_23"]]
}

for key, val in signals.iteritems():
	for i in val:
		for k in i:
			g.setup(k, g.OUT)
			g.output(k, g.LOW)

t.sleep(1)

while True:
	for i in it.cycle(signals):
		cur_signal = signals[i]
		# Green On
		onoff(cur_signal[0], g.HIGH)
		# Red yellow off
		onoff(cur_signal[1] + cur_signal[2], g.LOW)
		#Other signals Red
		for key, val in signals.iteritems():
			if key != i:
				onoff(val[2], g.HIGH) #red
				onoff(val[1], g.LOW) #yellow
		t.sleep(3)
		onoff(cur_signal[0], g.LOW)
		onoff(cur_signal[1], g.HIGH)
		t.sleep(1)