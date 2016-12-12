import shelve

fs=shelve.open("filesys.vfs",writeback=True)
curr_dir=[]	#stores list of dir start from root which gave current path

def install(fs):
	if len(fs[""])==0:
		print "vfs: File System installed"	
		user1=raw_input("Please enter first user :")
		fs[""]={"System":{},"Users":{user1:{}}}
	else:
		print "vfs: Welcome again "

def curr_files():	#returns dictionary of current directory 
	d=fs[""]	#start from root
	for key in curr_dir:	
		d=d[key]	#go towards opened directory
	return d	#return dictionary of files in current dir

def ls(args):
	if len(args)>0:
		print "ls: Too many arguments"
	else:
		for key in curr_files():
			if isinstance(curr_files()[key], str):
				print "-  "+key
			else:
				print "d  "+key
		
def cd(args):
	if len(args)>1 or len(args)==0:
		print "cd: 1 argument required."
		print "Usage: cd <argument>"
	elif args[0]=="..":
		if not len(curr_dir)==0:
			curr_dir.pop()
	elif args[0] not in curr_files():		
		print "cd:  Directory not found"
	elif isinstance(curr_files()[args[0]], str):
		print "cd :"+args[0]+" is not a Directory."
	else:
		curr_dir.append(args[0])
		
def mkdir(args):
	if len(args)>1 or len(args)==0:
		print "mkdir: 1 argument required"
		print "Usage: mkdir <directory>"	
	elif args[0] in curr_files():
		print  "mkdir: Directory already Exists"
	else:
		curr_files()[args[0]]={}
		
def touch(args):
	if len(args)<1:
		print "touch: 2 argument required"
		print "Usage: mkdir <file> <content>"	
	elif args[0] in curr_files():
		print  "mkdir: Directory already Exists"
	else:
		curr_files()[args[0]]=" ".join(args[1:])

def cat(args):
	if len(args)<1 or len(args)>1:
		print "cat: 1 argument required"
		print "Usage: cat <file>"
	elif isinstance(curr_files()[args[0]], str):
		print curr_files()[args[0]]
	else:
		print "cat:  "+args[0]+" is a Directory"
		
def rmdir(args):
	if len(args)>1 or len(args)==0:
		print "rmdir: 1 argument required"
		print "Usage: rmdir <directory>"	
	elif args[0] not in curr_files():
		print "rmdir: Directory do not exist"
	else:
		curr_files().pop(args[0])
def pwd(args):
	if len(args)>0:
		print "pwd: Too many arguments"
	else:
		print "/"+"/".join(curr_dir)  #"-".join({"a","b","c"}) =a-b-c

def quit(args):
	if len(args)>0:
		print "exit: Too many arguments"
	else:
		fs.sync()
		exit()

def tree(args,level=0,dict={}):
	level+=1
	if(level==1):
		dict=curr_files()
		args=curr_dir[len(curr_dir)-1]
	print(args)
	for key in dict:
		for i in range(level-1):
			print "      ",
		print "   |--",
		if not isinstance(dict[key],str):
			tree(key,level,dict=dict[key])
		else:
			print key 
	
def adduser(args):
	if len(args)>1 or len(args)==0:
		print "adduser: 1 argument is required"
		print "Usage: adduser <username>"
	elif args[0]=="":
		print "Usage: adduser <username>"
	elif args[0] in fs[""]["Users"]:
		print "adduser: User with same name exist"
	else:
		fs[""]["Users"][args[0]]={}
		print "vfs: User added"
		

def rename(args):
	if len(args)>2 or len(args)<2:
		print "rename: 2 argument are required" 
		print "Usage: rename <oldname> <newname>"
	elif args[0] not in curr_files():
		print "rename: File not found"
	elif args[1] in curr_files():
		print "rename: File with same name already exists"
	else:
		curr_files()[args[1]]=curr_files().pop(args[0])
	
	
COMMANDS={"rmdir":rmdir,"mkdir":mkdir,"cd":cd,"adduser":adduser,"pwd":pwd,"ls":ls,"tree":tree,
				"exit":quit,"rename":rename,"cat":cat,"touch":touch}		
install(fs)
while(True):
	cmd=raw_input("vfs@python:  /"+"/".join(curr_dir)+"\n>").split(" ")
	if len(cmd)==0:
		print "",
	elif cmd[0] not in COMMANDS:
		print "vfs: Command not found: "+cmd[0]
	else:
		COMMANDS[cmd[0]](cmd[1:])
