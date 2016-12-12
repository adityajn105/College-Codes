import socket,sys
s=socket.socket()
#host=socket.gethostname()
port=28901  #port between 1024 and 49151
s.bind((sys.argv[1],port))
s.listen(4)
c,addr=s.accept()
print "Connected to:",addr

f1=open(sys.argv[2],"r") #open file in read mode
bytes=f1.read(1024)	#read 1024 bytes
while(bytes):		
	c.send(bytes)	#send read bytes
	bytes=f1.read(1024)	#read next 1024 bytes	
f1.close()
c.close()
