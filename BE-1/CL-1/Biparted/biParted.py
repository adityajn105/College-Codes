class Graph:
	def __init__(self,array):
		self.l=len(array[0])
		self.array=array
		self.colors=[-1]*self.l

	def can(self,i):
		near=[ j for j in range(l) if j!=i and array[i][j] ]
		possible=True
		for color in range(2):
			for j in near:
				if self.colors[j]==color:
					possible=False
					break
				else:
					continue
			if possible:
				self.colors[i]=color
				return True
			elif color==0:
				possible=True
				continue
			else:
				return False

	def isBiparted(self):
		for i in range(self.l):
			if self.can(i):
				continue
			else:
				return False
		return True

	def giveColors(self):
		return self.colors

if __name__ == "__main__":
	l=int(input("How many Nodes : "))
	array= [[False for x in range(l)] for y in range(l)]
	while True:
		inp=list(map(int,input("Enter node1 node2  : ").split()))
		array[inp[0]][inp[1]]=array[inp[1]][inp[0]]=True
		if input("Enter more edges?(y/n)  : ")=='y':
			continue
		else :
			break
	graph=Graph(array)
	if graph.isBiparted(): 
		print("Graph is biparted. Colors Can be given to graph as : {}".format(graph.giveColors())) 
	else: 
		print("Graph is not biparted.")