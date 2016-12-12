import socket,sys

s=socket.socket()
#host=socket.gethostname()
port=28901 #between 1024 and 49151  
s.connect((sys.argv[1],port))

f1=open(sys.argv[2],"w")	#open file in write mode
data_received=s.recv(1024)		#receive data
data=""
while(data_received):
	data=data+data_received
	data_received=s.recv(1024)
print data
f1.write(data)
f1.close()
s.close()
