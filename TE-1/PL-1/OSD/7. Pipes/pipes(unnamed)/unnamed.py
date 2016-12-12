import os,sys
fd0,fd1=os.pipe()
ch=os.fork()
if ch:
	os.close(fd0)
	w=os.fdopen(fd1,'w')
	w.write(raw_input("Input Message to be sent: "))
else:
	os.close(fd1)
	r=os.fdopen(fd0,'r')
	print("Message recieved by child is: "+ r.read())
