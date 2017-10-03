class KMeans():
	def __init__(self,data):
		self.data = data
		self.nocoord = len(data[0])
		self.total = len(data)
		self.xys = [[] for i in range(self.nocoord)]
		for i in data:
			for j in range(self.nocoord):
				self.xys[j].append(i[j])
		self.clusters = []
		self.centroids=[]

	def train(self,k=2,seed=False,rand=[]):
		if not seed:
			divs = [(max(self.xys[i])-min(self.xys[i]))/(k-1) for i in range(self.nocoord)]
			rand = []
			for i in range(k):
				rand.append([min(self.xys[j])+divs[j]*i for j in range(self.nocoord)])
		prev = []
		next = []
		while True:
			self.clusters = [ set() for i in range(k) ]
			for sample in self.data:
				mind=9999
				no = 0
				for i in range(k):
					cdis = self.distance(sample,rand[i])
					if  cdis < mind:
						no=i
						mind=cdis
				self.clusters[no].add(sample)
			next=self.clusters
			if self.isSameCluster(prev,next):
				break;
			prev=self.copyCluster(next)
			for i in range(k):
				mean=[0 for i in range(self.nocoord)]
				for j in self.clusters[i]:
					for l in range(self.nocoord):
						mean[l]+=j[l]
				items = len(self.clusters[i])
				for l in range(self.nocoord):
					if mean[l]!=0:
						mean[l]=mean[l]/items		
				rand[i]=mean
		self.centroids=rand

	def getClusters(self):
		return self.clusters

	def isSameCluster(self,prev,next):
		if len(prev)!=len(next):
			return False
		for i in range(len(prev)):
			if prev[i]!=next[i]:
				return False
		return True

	def copyCluster(self,cluster):
		return [{j for j in i} for i in cluster]

	def distance(self,sample,coords):
		dis = 0
		col = 0
		for i in coords:
			dis += (i-sample[col])**2
			col += 1
		return dis**.5

if __name__=='__main__':
	fp = open('input.txt','r')
	coord = fp.readline()
	data = []
	while coord:
		tup = tuple(map(float,coord.split()))
		data.append(tup)
		coord = fp.readline()
	kmeans = KMeans(data)
	count = int(input("Number of Clusters : "))
	seeds=[]
	if input('Automate random seed?(y/n)')=='n':
		print("Give inital cluster mean(sepeate coordinate by blankspace)")
		seeds = [list(map(float,input("For cluster {} :".format(i+1)).split())) for i in range(count)]
		kmeans.train(k=count,seed=True,rand=seeds)
	else:
		kmeans.train(k=count)
	clusters = kmeans.getClusters()
	for i in range(count):
		print("In cluster {} :".format(i+1))
		print(clusters[i])

