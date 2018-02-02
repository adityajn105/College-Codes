# By : Aditya Jain (402059)
# Date : 02 Feb 2018

from multiprocessing import Pool
from functools import reduce

class OddEvenSorter():
	def __init__(self,arr):
		self.arr = arr
		self.no = len(arr)

	def swapper(self,index):
		if self.arr[index] > self.arr[index+1]:
			temp = self.arr[index]
			self.arr[index] =self.arr[index+1]
			self.arr[index+1]=temp
		return [self.arr[index],self.arr[index+1]]

	def __sortOddP(self):
		indexes = list(range(0,self.no-1,2))
		pool = Pool(processes=8)
		ls = pool.map(self.swapper,indexes)
		print(indexes[-1])
		self.arr[0:indexes[-1]+1] = reduce(lambda x,y: x+y,ls)

	def __sortEvenP(self):
		indexes = list(range(1,self.no-1,2))
		pool = Pool(processes=8)
		ls = pool.map(self.swapper,indexes)
		print(indexes[-1])
		self.arr[1:indexes[-1]+1] = reduce(lambda x,y: x+y,ls)

	def __sortOdd(self):
		for i in range(0,self.no-1,2):
			if self.arr[i] > self.arr[i+1]:
				temp = self.arr[i]
				self.arr[i] =self.arr[i+1]
				self.arr[i+1]=temp

	def __sortEven(self):
		for i in range(1,self.no-1,2):
			if self.arr[i] > self.arr[i+1]:
				temp = self.arr[i]
				self.arr[i] =self.arr[i+1]
				self.arr[i+1]=temp

	def __verify(self):
		print("")

	def sortP(self):
		for i in range(1,self.no):
			if i%2 == 1:
				self.__sortOddP()
			else:
				self.__sortEvenP()
		print(self.arr)
		return self.arr

	def sortS(self):
		for i in range(1,self.no):
			if i%2 == 1:
				self.__sortOdd()
			else:
				self.__sortEven()
		print(self.arr)
		return self.arr



if __name__ == "__main__":
	no = input("Enter Number of Elements : ")
	arr = list()
	print("Give Numbers")
	#for i in range(no):
	#	arr.append(input("{} : ".format(i)))
	arr = [6,4,9,0,1,3,8,2,32,10]
	print(arr)
	oddeven = OddEvenSorter(arr)
	oddeven.sortP()