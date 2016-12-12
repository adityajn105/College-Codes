import hashlib,sys

if(len(sys.argv)==1):
	print "Please pass intermediate file as first argument."
	exit()
file=open(sys.argv[1],"r")
line=file.readline()

fn,ehv=line.split(" ")

a=open(fn).read()
h=hashlib.sha256(a).hexdigest()
print "Hash Value :"+h

arr=list()
dhv=""
for i in range(0,len(ehv)):
	arr.append(int(ord(ehv[i]))-1)
backwords=arr[::-1]
for i in range(0,len(h)):
	dhv=dhv+chr(backwords[i])
print "Decrypt Hash value :"+dhv

if(dhv==h):
	print "Sender is Authenticated Successfully. No tempering of digital Signature"
else:
	print "Sender is Not Authenticated Successfully. Tempering of digital Signature"


