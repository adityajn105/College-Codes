#INPUT=========================================================================

#Tree.py
#Created on: 21-Aug-2015
#Author: Aditya

class node():
	def __init__(self,info):
		self.info=info
		self.left=None
		self.right=None
		
class tree():
	stk=[None]*30
	top=-1
	def __init__(self):
		self.root=None
	def nr_create(self):
			if self.root==None:	#if root=None
				val=raw_input("Enter Data for root node   :")
				self.root=node(val)	#make root with info val
			else:
				temp=node(None)
				temp=self.root		#temp will be root
				while (1):	#infinite loop
					ch=raw_input("Enter left(1) or right(2) node for node or no node(3) to "+temp.info+"  ")
					if ch=='1':
						if temp.left==None:	#if temp's left is none the make it
							val=raw_input("Enter data for this node   :")
							temp.left=node(val)
							
						else:		#else temp will temp's right
							temp=temp.left
					elif ch=='2':
						if temp.right==None:	#if temp's right is none the make it
							val=raw_input("Enter data for this node    :")

							temp.right=node(val)
						else:
							temp=temp.right	
					else:	#if temp is leaf node then jump out of loop
						break
						print "================Tree Is Created=================="
	def push(self,nd):
		temp=nd		
		if self.top==29:
			print "Stack is full"
		else:
			self.top=self.top+1
			self.stk[self.top]=temp
				
	def pop(self):
		t=self.stk[self.top]
		self.top=self.top-1
		return	t
		 
	def nr_inorder(self):
		self.top=-1
		temp=self.root
		while (1):
			while temp!=None:
				self.push(temp)
				temp=temp.left
			if(self.top==-1):
				break
			else:
				temp=self.pop()
				print temp.info,
				temp=temp.right


	def nr_postorder(self):
		self.top=-1
		temp=self.root
		while (1):
			while temp!=None:
				self.push(temp)
				temp=temp.left
			if(self.stk[self.top].right==None):
				temp=self.pop()
				print temp.info,
				while(self.top!=-1 and self.stk[self.top].right==temp):
					temp=self.pop()
					print temp.info,
			if(self.top!=-1 and self.stk[self.top].right!=None):
				temp=self.stk[self.top].right
			if(self.top==-1):
				break

		
	def nr_preorder(self):
		self.top=-1
		temp=self.root
		while(1):
			while(temp!=None):
				while(temp!=None):
					self.push(temp)
					print temp.info,
					temp=temp.left
				temp=self.pop()
				temp=temp.right
			if self.top!=-1:		
				temp=self.pop()
			if temp!=None:
				temp=temp.right
			if(self.top==-1 and temp==None):
				break	
					
	
	def r_create(self):
		val=raw_input("Enter data for root node")
		self.root=node(val)
		self.r_create1(self.root)
	def r_create1(self,nd):
		temp=nd 
		ch1=raw_input("Do you want to add left node to  "+temp.info+"(y or n) :")		
		if ch1=='y':
			if temp.left==None:
				val=raw_input("Enter data for this node:   ")			
				temp.left=node(val)
				self.r_create1(temp.left)
			else:
				self.r_create1(temp.left)
		else:
			ch2=raw_input("Do you want to add right node(y or n)  "+temp.info+"          ")
			if ch2=='y':
				if temp.right==None:	
					val=raw_input("Enter data for this node:    ")
					temp.right=node(val)
					self.r_create1(temp.right)
				else:
					self.r_create1(temp.right)
			else:
				ch=raw_input("Do you want to add more nodes(y or n)")
				if ch=='y':
					self.r_create1(self.root)
				else:
					print "===========Tree is created============"

	
			
	def r_preorder(self,node):
		temp=node
		if temp!=None:
			print temp.info,
			self.r_preorder(temp.left)
			self.r_preorder(temp.right)
	def r_inorder(self,node):
		temp=node
		if temp!=None:
			self.r_inorder(temp.left)
			print temp.info,
			self.r_inorder(temp.right)
	def r_postorder(self,node):
		temp=node
		if temp!=None:
			self.r_postorder(temp.left)
			self.r_postorder(temp.right)
			print temp.info,

	def bfs(self):
		queue=[]
		queue.append(self.root)
		while(len(queue)!=0):
			temp=queue.pop(0)
			print temp.info,
			if temp.left!=None:
				queue.append(temp.left)
			if temp.right!=None:
				queue.append(temp.right)
			b=self.root
			while(b!=None):
				if(temp==b):
					print "\n"
					break
				else:
					b=b.right
					
		
		
		
		
				
s=tree()
ch='y'
ch2='0'
print "Techniques to create tree"
print "1.Non-Recurrsive Create(w)"
print "2.Recurrsive Create(w)"
ch0=raw_input("Enter technique number: ")
if ch0=='1':
	while ch=='y':
		s.nr_create()
		ch=raw_input("enter another node(y or n)")
elif ch0=='2':
	s.r_create()

while(ch2!='8'):
	print "\nTechniques to display tree"
	print "1.Recurssive Preorder(w)"
	print "2.Recurssive Inorder(w)"
	print "3.Recurssive Postorder(w)"
	print "4.Non-Recurrsive Preorder(w)"
	print "5.Non-Recurrsive Inorder(w)"
	print "6.Non-Recurrsive Postorder(w)"
	print "7.Breadth First Search(w)"
	print "8.Exit(w)"
	ch2=raw_input("Display tree via technique?")
	if ch2=='1':
		s.r_preorder(s.root)
	elif ch2=='2':
		s.r_inorder(s.root)
	elif ch2=='3':
		s.r_postorder(s.root)
	elif ch2=='4':
		s.nr_preorder()
	elif ch2=='5':
		s.nr_inorder()
	elif ch2=='6':
		s.nr_postorder()
	elif ch2=='7':
		s.bfs()
	elif ch2=='8':
		break
	elif ch2>8 or ch2<1:
		print "Wrong choice entered \n"
