import sys
fpo=open(sys.argv[1],"rb")
fpc=open(sys.argv[2],"rb")
bytes1=fpo.read(1024)
bytes2=fpc.read(1024)
boole=True
while(bytes1 and bytes2):
	if bytes1==bytes2:
		boole=True
	else:
		boole=False
		break
	bytes1=fpo.read(1024)
	bytes2=fpc.read(1024)
if(boole):
	print "File is original"
else:
	print "File is tempered"
