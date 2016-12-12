import getpass,poplib
import email.parser

user=raw_input("Your Email  :")
pswd = getpass.getpass('Password  :')

Mailbox = poplib.POP3_SSL('pop.gmail.com')
Mailbox.user(user)
Mailbox.pass_(pswd)
fd=open("email.txt","w")
numMessages = 1                
for i in range(numMessages):	
	text=Mailbox.retr(i+4)[1]	
	emailinfo=""
	for l in range(len(text)):
		fd.write(text[l]+"\n")
		emailinfo=emailinfo+text[l]     	
		if ':' in text[l]:
			parts=text[l].strip().split(":",2)
			p1=parts[0]
			p2=parts[1]			
			if(p1=="Date"):
				print("Date-         "+p2)
			elif(p1=="From"):
				print("From-         "+p2)
			elif(p1=="To"):
				print("To-           "+p2)
			elif(p1=="Message-ID"):
				print("Message-id-   "+p2)
			elif(p1=="Subject"):
				print("Subject-      "+p2)
			elif(p1=="Mime-Version"):
				print("Mime-Version- "+p2)
			elif(p1=="Content-Type"):
				print("Content-Type- "+p2)
				break
Mailbox.quit()
