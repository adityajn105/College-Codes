import hashlib
while(True):
	print "1.Image File \n2.Audio File\n3.Exit"
	choice=int(raw_input("Enter choice :"))
	if(choice==1):
		org=open(raw_input("Enter Original Image File :")).read()
		cfile=raw_input("Enter Image File to be checked :")
		check=open(cfile).read()
		original=hashlib.md5(org).hexdigest()
		checked=hashlib.md5(check).hexdigest()
	elif(choice==2):
		org=open(raw_input("Enter Original Audio File :")).read()
		cfile=raw_input("Enter Audio File to be checked :")
		check=open(cfile).read()
		original=hashlib.sha256(org).hexdigest()
		checked=hashlib.sha256(check).hexdigest()
	else:
		break
	print("Original Hash :"+original)
	print("Obtained Hash :"+checked)
	if(original==checked):
		print cfile+" is not tempered."
	else:
		print cfile+" is tempered."
		

