import hashlib,sys


if(len(sys.argv)==1):
	print "Please pass Digital file name as first argument."
	exit()
a=open(sys.argv[1]).read()
h=hashlib.sha256(a).hexdigest()
print "Hash Value:"
print h

arr=list()
ehv=""
for i in range(0,len(h)):
	arr.append(int(ord(h[i]))+1)	
backwords= arr[::-1]
for i in range(0,len(h)):
	ehv=ehv+chr(backwords[i])
print "Encrypt Hash value :"
print ehv

file=open("inter.txt","w")
file.write(sys.argv[1]+" "+ehv)
file.close()


