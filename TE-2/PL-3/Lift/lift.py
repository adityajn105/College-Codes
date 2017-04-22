import Adafruit_BBIO.GPIO as g
import time as t

led=['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16','P8_17']
button=['P8_7','P8_8','P8_9','P8_10']
zero=['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16']
one=['P8_12','P8_13']
two=['P8_11','P8_12','P8_17','P8_15','P8_14']
three=['P8_11','P8_12','P8_13','P8_14','P8_17']
curr=0
next=0
floor=[zero,one,two,three]

for i in led:
        g.setup(i,g.OUT)
        g.output(i,g.HIGH)
def setup():
        for i in button:
                g.setup(i,g.IN)

def glow(arr):
        for i in arr:
                g.output(i,g.LOW)

def clear():
        for i in led:
                g.output(i,g.HIGH)



glow(zero)

def animate(curr,next):
        if(curr<next):
                for i in range(curr,next):
                        clear()
                        t.sleep(0.1)
                        glow(floor[i+1])
                        t.sleep(0.5)
        else:
                for i in range(curr,next,-1):
                        clear()
                        t.sleep(0.1)
                        glow(floor[i-1])
                        t.sleep(0.5)

while True:
        setup()
        if(g.input('P8_7')==0 and curr!=3):
                print "3 is pressed"
                next=3
                animate(curr,next)
                curr=next
        elif(g.input('P8_9')==0 and curr!=2):
                print "2 is pressed"
                next=2
                animate(curr,next)
                curr=next
        elif(g.input('P8_8')==0 and curr!=1):
                print "1 is pressed"
                next=1
                animate(curr,next)
                curr=next
        elif(g.input('P8_10')==0 and curr!=0):
                print "0 is pressed"
                next=0
                animate(curr,next)
                curr=next

