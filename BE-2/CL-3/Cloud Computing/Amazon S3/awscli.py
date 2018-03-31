import tkinter as tk
from tkinter import messagebox
import os
import re

uname = None
pwd = None

def login():
	if uname.get() == "aditya" and pwd.get() == "aditya":
		loginWindow.destroy()
		initialize_menu()
	else:
		messagebox.showerror("Invalid Login", "Please give right Credentials")

def initialize_menu():
	menu = tk.Tk()
	menu.title("Select A Operation")
	#Listing Buckets
	tk.Label(menu,text="List Bucket",font='Helvetica 12 bold').grid(row=0,columnspan=3,padx=10, pady=10)
	tk.Button(menu,text="List Buckets",width=25,bg="green",command=list_bucket).grid(row=2,columnspan=3,padx=10, pady=10)

	# Create Bucket
	tk.Label(menu,text="Create Bucket",font='Helvetica 12 bold').grid(row=0,column=3,columnspan=3,padx=10, pady=10)
	buc_name = tk.Entry(menu)
	tk.Label(menu,text="Bucket Name:").grid(row=1,column=3,columnspan=1,padx=10, pady=10)
	buc_name.grid(row=1,column=4,columnspan=2,padx=10, pady=10)
	tk.Button(menu,text="Create Bucket",width=25,bg="green",command=lambda: create_bucket(buc_name.get())).grid(row=2,column=3,columnspan=3,padx=10, pady=10)
	
	#List Content
	tk.Label(menu,text="List Content",font='Helvetica 12 bold').grid(row=3,column=0,columnspan=3,padx=10, pady=10)
	buc_name2 = tk.Entry(menu)
	tk.Label(menu,text="Bucket Name:").grid(row=4,column=0,columnspan=1,padx=10, pady=10)
	buc_name2.grid(row=4,column=1,columnspan=2,padx=10, pady=10)
	tk.Button(menu,text="List Content",width=25,bg="green",command=lambda: list_content(buc_name2.get())).grid(row=5,column=0,columnspan=3,padx=10, pady=10)
	
	#Delete Bucket
	tk.Label(menu,text="Delete Bucket",font='Helvetica 12 bold').grid(row=3,column=3,columnspan=3,padx=10, pady=10)
	buc_name3 = tk.Entry(menu)
	tk.Label(menu,text="Bucket Name:").grid(row=4,column=3,columnspan=1,padx=10, pady=10)
	buc_name3.grid(row=4,column=4,columnspan=2,padx=10, pady=10)
	tk.Button(menu,text="Delete Bucket",width=25,bg="red",command=lambda: delete_bucket(buc_name3.get())).grid(row=5,column=3,columnspan=3,padx=10, pady=10)

	# Logout
	tk.Button(menu,text="Log Out",width=25,bg="orange",command=lambda: menu.destroy()).grid(row=6,column=1,columnspan=4,padx=10, pady=10)


	menu.mainloop()

def list_bucket():
	print("listing bucket")
	res = os.popen('aws s3 ls').read()
	if res=="":
		messagebox.showwarning("No Buckets","Currently There are No buckets")
	else:
		lists = tk.Tk()
		lists.title("Buckets List")
		tk.Label(lists,text="Creation Date",font='Helvetica 10 bold').grid(row=0,column=0,padx=20)
		tk.Label(lists,text="Creation Time",font='Helvetica 10 bold').grid(row=0,column=1,padx=20)
		tk.Label(lists,text="Bucket Name",font='Helvetica 10 bold').grid(row=0,column=2,padx=20)
		lines = res.splitlines()
		print(lines)
		for i in range(len(lines)):
			fields = lines[i].split(" ")
			tk.Label(lists,text=fields[0]).grid(row=i+1,column=0,padx=20)
			tk.Label(lists,text=fields[1]).grid(row=i+1,column=1,padx=20)
			tk.Label(lists,text=fields[2]).grid(row=i+1,column=2,padx=20)
		lists.mainloop()

def create_bucket(bucket_name):
	if bucket_name == "":
		messagebox.showwarning("Invalid Bucket Name","Bucket Name Cant be blank or empty!!!")
	else:
		print("create bucket of {}".format(bucket_name))
		res = os.popen("aws s3 mb s3://{}".format(bucket_name)).read()
		if res.strip() == "make_bucket: {}".format(bucket_name).strip():
			messagebox.showinfo("Success","Bucket Created Successfully")
		else:
			messagebox.showerror("Failure","Bucket Creating Failed")

def list_content(bucket_name):
	if bucket_name == "":
		messagebox.showwarning("Invalid Bucket Name","Bucket Name Cant be blank or empty!!!")
	else:
		print("list content of {}".format(bucket_name))
		res = os.popen("aws s3 ls s3://{}".format(bucket_name)).read()
		if res=="":
			messagebox.showwarning("No Content","Currently There is no content in bucket")
		else:
			lists = tk.Tk()
			lists.title("Buckets Content")
			tk.Label(lists,text="Creation Date",font='Helvetica 10 bold').grid(row=0,column=0,padx=20)
			tk.Label(lists,text="Creation Time",font='Helvetica 10 bold').grid(row=0,column=1,padx=20)
			tk.Label(lists,text="File Size",font='Helvetica 10 bold').grid(row=0,column=2,padx=20)
			tk.Label(lists,text="File Name",font='Helvetica 10 bold').grid(row=0,column=3,padx=20)
			lines = res.splitlines()
			for i in range(len(lines)):
				lines[i] = " ".join(lines[i].split())
				fields = lines[i].split(" ")
				tk.Label(lists,text=fields[0]).grid(row=i+1,column=0,padx=20)
				tk.Label(lists,text=fields[1]).grid(row=i+1,column=1,padx=20)
				tk.Label(lists,text=fields[2]).grid(row=i+1,column=2,padx=20)
				tk.Label(lists,text=fields[3]).grid(row=i+1,column=3,padx=20)
			lists.mainloop()		

def delete_bucket(bucket_name):
	if bucket_name == "":
		messagebox.showwarning("Invalid Bucket Name","Bucket Name Cant be blank or empty!!!")
	else:
		print("Deleting Bucket : {}".format(bucket_name))
		res = os.popen("aws s3 rb s3://{} --force".format(bucket_name)).read()
		if res.strip() == "remove_bucket: {}".format(bucket_name).strip():
			messagebox.showinfo("Success","Bucket Deleted Successfully")
		else:
			messagebox.showerror("Failure","Bucket Deleting Failed")

if __name__ == "__main__":
	loginWindow = tk.Tk()
	loginWindow.title("Login to AWS")
	tk.Label(loginWindow,text="Username").grid(row=0,padx=10, pady=10)
	tk.Label(loginWindow,text="Password").grid(row=1,padx=10, pady=10)
	uname = tk.Entry(loginWindow)
	uname.grid(row=0,column=1,padx=10, pady=10)
	pwd = tk.Entry(loginWindow,show='*')
	pwd.grid(row=1,column=1,padx=10, pady=10)
	tk.Button(loginWindow,text="Login",bg="green",width=25,command=login).grid(row=2,columnspan=2,padx=10, pady=10)

	loginWindow.mainloop()