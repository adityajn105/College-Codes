class TSDynamic():
	def __init__(self,graph):
		self.graph=graph
		self.no=len(graph)
		self.nodes = {i for i in range(0,self.no)}
		self.costs = dict()

	def findPath(self,start):
		return self.cost(start,self.nodes-{start},start)

	def cost(self,start,via,end):
		tup = (start,tuple(i for i in via),end)
		if not tup in self.costs:
			minc = 99999;
			mintup = ()
			for i in via:
				temp = self.cost(i,via-{i},end)
				mincost = (self.graph[start][i]+temp[0] ,[start]+[j for j in temp[1]])
				if mincost[0] < minc:
					minc = mincost[0]
					mintup = mincost
			if len(via) == 0:
				self.costs[tup] = (self.graph[start][end],[start,end])
			else:
				self.costs[tup] = mintup
		return self.costs[tup]

if __name__=='__main__':
	nodes = int(input("Enter no of nodes :"))
	# graph = [[0,24,11,10,9],
	#  		[8,0,2,5,11],
	#  		[26,12,0,8,7],
	#  		[11,23,24,0,6],
	#  		[5,4,8,11,0]]
	graph=[[ 0 for i in range(nodes) ] for j in range(nodes)]
	print("Enter Edges")	
	for i in range(nodes):
		for j in range(nodes):
			if i!=j:
				graph[i][j] = input("Edge Length {} -> {} :".format(i,j))
	print("Given Problem\n----------------------------------")
	for i in range(nodes):
		for j in range(nodes):
			if i!=j:
				print(graph[i][j],end="\t")
			else:
				print("-",end="\t")
		print("\n----------------------------------")
	problem = TSDynamic(graph)
	path = problem.findPath(0)
	print("Minimum Cost : {}".format(path[0]) )
	print("Optimal Path : {}".format("->".join(list(map(lambda i : str(i+1) , path[1])))))

