class NaiveBayes():
	def __init__(self,table,heads):
		self.table=table
		self.heads= heads
		self.no = len(heads)
		self.tups = len(table)
		self.attributes = [set() for i in range(self.no)]
		for i in range(self.no):
			for j in range(self.tups):
				self.attributes[i].add(table[j][i])
		self.targetSum = dict()
		for i in self.table:
			if i[self.no-1] in self.targetSum:
				self.targetSum[i[self.no-1]]+=1
			else:
				self.targetSum[i[self.no-1]]=1
		self.probs = [dict() for i in range(self.no-1)]

	def trainClassifier(self):
		for i in self.table:
			for j in range(self.no-1):
				item = i[j]
				Class = i[self.no-1]
				indexTup = (item,Class)
				if indexTup in self.probs[j]:
					self.probs[j][indexTup]+=1
				else:
					self.probs[j][indexTup]=1
		for i in range(self.no-1):
			for j in self.probs[i].keys():
				self.probs[i][j] = self.probs[i][j]/self.targetSum[j[1]]

	def predictClass(self,sample):
		cprob = dict()
		for i in self.targetSum.keys():
			temp = self.targetSum[i]/self.tups
			for j in range(len(sample)):
				if (sample[j],i) in self.probs[j]:
					temp= temp*self.probs[j][(sample[j],i)]
				else:
					temp = 0
			cprob[i]=temp
		maxp=0
		for i in cprob.keys():
			if cprob[i]>maxp:
				maxp = cprob[i]
				bestC = i
		return bestC


if __name__ == '__main__':
	data=[]
	fp = open("input.txt","r")
	line = fp.readline()
	headings = line.split()
	line = fp.readline()
	while line:
		data.append(line.split())
		line = fp.readline()

	print("Given Data Set:")
	for i in headings:
		print("{:15}".format(i),end="")	
	print()
	for i in data:
		for j in i:
			print("{:15}".format(j),end="")
		print()

	nb = NaiveBayes(data,headings)
	nb.trainClassifier()
	while True:
		sample = input("Enter Sample to predict class : ").split()
		ans = nb.predictClass(sample)
		print("Predicted Class is {}".format(ans))
		if input('Try another sample?(y/n)')=='n':
			break