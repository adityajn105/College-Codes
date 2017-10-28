
/*

Problem Statement:  Developing a book recommender ( a book that the reader should read and is new) Expert system.

*/


from Tkinter import *
import tkMessageBox

p={"Sam":["BE","Engg","M","Nsk",["C++"],["SQL"]],
   "John":["BE","Engg","M","Pune",["HADOOP","OOP"],["MONGODB"]],
   "July":["LLB","Consultant","F","Pune",["CYBERLAW"],["LAW-KB"]],
   "Simon":["MD","Doc","M","Mum",["CARDIOLOGY"],["BONES AND FUNCTION"]],
   "Sherlyn":["BE","Engg","F","Nsk",["PYTHON","CASSENDRA","C++"],["JAVA"]],
   "Sofia":["MD","Doc","F","Pune",["SPINE-TECH"],["NEURON SYSTEM"]],
   "Victor":["LLB","Consultant","M","Nsk",["LAW 1-A"],["ABC OF LAW"]],
   "Jolly":["LLB","Consultant","M","Nsk",["HUMAN RIGHTS"],["LAW-CUSTOMER POLICIES"]],
   "Jane":["BE","Engg","F","Mum",["C#"],["ASP.NET","COMPUTER ARCH"]],
   "Jack":["MD","DOC","M","Nsk",["PATIENT-MON"],["HEALTH AND HERBS"]]}

uname=""  
def gname():
	uname=e1.get()

	samlist=p[uname]
	obook=[]
	obook.extend(samlist[4])
	obook.extend(samlist[5])
	rcom=[]
	
	for k in p.keys():
		if (k is not uname) and (samlist[0]==p[k][0] and samlist[1]==p[k][1]):
			rcom.extend(p[k][4])
			rcom.extend(p[k][5])
			
	rcom=list(set(rcom)-set(obook))
	rcom=str(rcom)
	rcom=rcom.replace('[','')
	rcom=rcom.replace(']','')
	rcom=rcom.replace("'",'')	
	tkMessageBox.showinfo("suggested books", rcom )

	e1.delete(0,END)

master=Tk()
master.title("Book Recommender application")
Label(master,text="Users").grid(row=0)

i=1
for k in p.keys():
	a=str(k)
	Label(master,text=k).grid(row=i)
	i=i+1
	
Label(master,text="--------------------").grid(row=12)
Label(master,text="Enter User name: ").grid(row=13)
e1 = Entry(master)
e1.insert(10,"")
e1.grid(row=14,column=0)


Button(master, text='Quit', command=master.quit).grid(row=15, column=0, sticky=W, pady=4)
Button(master, text='Submit', command=gname).grid(row=15, column=1, sticky=W, pady=4)

mainloop()
