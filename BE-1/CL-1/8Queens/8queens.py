import json
class E8Queens():
	def __init__(self,config):
		self.sols=[]
		self.config=config

	def findSols(self):
		for i in range(8):
			if self.config[i] == -1:
				self.solve(i)
				break

	def solve(self,k):
		for i in range(0,8):
			if self.isOk(k,i):
				self.config[k]=i
				if k==7:
					self.addSolution()
				else:
					self.solve(k+1)

	def isOk(self,row,cpos):
		for i in range(row):
			if self.config[i]!=-1 and (self.config[i]==cpos or abs(self.config[i]-cpos)==abs(i-row)):
				return False
			else:
				continue
		return True

	def addSolution(self):
		self.sols.append([i for i in self.config])

	def getSolution(self):
		return self.sols

	def printBoard(self,board):
		for i in range(8):
			print("\t",end=" ")
			for j in range(8):
				if board[i]==j:
					print('X' ,end=" ")
				else:
					print('-',end=" ")
			print('')


if __name__ == "__main__":
	data = open("input.json","r")
	data = json.load(data)
	initial = data["pos"]
	problem = E8Queens(initial)
	print("Given 8 Queen Problem-")
	problem.printBoard(initial)
	problem.findSols()
	sol= problem.getSolution()
	cnt=0
	for i in sol:
		print("Solution "+str(cnt)+" :")
		problem.printBoard(i)
		cnt+=1
	if len(sol)==0:
		print("No solution to given problem.")
