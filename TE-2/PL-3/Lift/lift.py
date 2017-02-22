import time as t
import Adafruit_BBIO.GPIO as g
press = 0
prev = 0
l=['P9_23','P9_24','P9_11','P9_12','P9_13','P9_14','P9_15','P9_16']
zero=['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16']
one=['P8_12','P8_13']
two=['P8_11','P8_12','P8_17','P8_15','P8_14']
three=['P8_11','P8_12','P8_17','P8_13','P8_14']
all1=['P8_11','P8_12','P8_13','P8_14','P8_15','P8_16','P8_17']
buttons=['P8_7','P8_8','P8_9','P8_10']
segdisp=[zero,one,two,three]
YLED = ['P9_24','P9_11','P9_13','P9_15']
GLED = ['P9_23','P9_12','P9_14','P9_16']

def displist(n):
        clear()
        for i in n:
                g.output(i,g.LOW)

def animate(press):
        if(press==prev):
                displist(segdisp[press])
	if(press<prev):
                for i in GLED:
                        g.output(i,g.HIGH)
                for i in range(prev,press-1,-1):
                        displist(segdisp[i])
                        t.sleep(0.5)
                for i in GLED:
                        g.output(i,g.LOW)


        if(press>prev):
                for i in YLED:
                        g.output(i,g.HIGH)
                for i in range(prev,press+1):
                        displist(segdisp[i])
                        t.sleep(0.5)
                for i in YLED:
                        g.output(i,g.LOW)

def clear():
        for i in range(0,len(all1)):
                g.output(all1[i],g.HIGH)

for i in range(0,len(l)):
        g.setup(l[i],g.OUT)
        g.output(l[i],g.LOW)
for i in range(0,len(all1)):
        g.setup(all1[i],g.OUT)
        g.output(all1[i],g.HIGH)
for i in range(0,len(buttons)):
        g.setup(buttons[i],g.IN)

while(True):
        if(g.input('P8_7')==0):
                print "3 was pressed"
                press1=3;
                clear()
                t.sleep(0.2)
                animate(press1)
                prev=3
        if(g.input('P8_8')==0):
                print "1 was pressed"
                press1=1;
                clear()
                t.sleep(0.2)
                animate(press1)
                prev=1
        if(g.input('P8_9')==0):
                print "2 was pressed"
                press1=2;
                clear()
                t.sleep(0.2)
                animate(press1)
                prev=2
        if(g.input('P8_10')==0):
                print "0 was pressed"
                press1=0
                clear()
                t.sleep(0.2)
                animate(press1)
                prev=0


