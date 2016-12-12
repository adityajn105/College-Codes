import os
ch=raw_input("1. System logs \n2.Network Logs \n3.Exit")
if(ch=="1"):
	os.system("ls -l /var/log")
	fil=raw_input("Enter file to be displayed   :")
	os.system("cat /var/log/"+fil)
elif(ch=="2"):
	fil=raw_input("Enter file with captured packed data  :")
	fd=open(fil,"r")
	packets=list()
	packet=""
	for each_line in fd:
		if(each_line[0:3]=="No."):
			packets.append(packet)
			packet=""
		packet=packet+"\n"+each_line
	print(str(len(packets))+" packets found")
	choice=raw_input("1. Source Address\n2. Destination Address\n3. Protocol")
	if(choice=="1"):
		add=raw_input("Enter source address  :")
		for pack in packets:
			if(pack[113:135].strip()==add):
				print(pack)
	elif(choice=="2"):
		add=raw_input("Enter destination address  :")
		for pack in packets:
			if(pack[135:157].strip()==add):
				print(pack)
	elif(choice=="3"):
		add=raw_input("Enter Protocol to be searched  :")
		for pack in packets:
			if(pack[157:166].strip()==add):
				print(pack)
else:
	exit()
