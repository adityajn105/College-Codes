import sys
fd=open(sys.argv[1],"r")
ch=int(raw_input("Menu--->\n1.Search by Source\n2.Search by Destination\n3.Search by Service\n"))
if ch==1:
	inp=raw_input("Enter Source IP Address  :")
elif ch==2:
	inp=raw_input("Enter Destination IP Address  :")
elif ch==3:
	inp=raw_input("Enter Service  :")
print("Source IP    	Destination IP	Service/Port No")
for line in fd:
	if line[0:14].strip()==inp and ch==1:
		print line
	elif line[13:29].strip()==inp and ch==2:	#216.58.199.174
		print line
	elif line[29:35].strip()==inp and ch==3:
		print line
		
		
	
		

		
