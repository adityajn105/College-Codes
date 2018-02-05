from xml.dom import minidom

class QuickSorter():
	def __init__(self,arr,n):
		self.seq = arr
		self.n=n

	def sort(self):
		self.__quickSort(0,self.n-1)

	def __quickSort(self,low,high):
		if low<high:
			partn = self.__partition(low,high)
			self.__quickSort(low,partn-1)
			self.__quickSort(partn+1,high)

	def __partition(self,low,high):
		pivot = self.seq[high]
		j=low-1;
		for i in range(low,high):
			if self.seq[i]<self.seq[high]:
				j += 1
				temp=self.seq[i]
				self.seq[i]=self.seq[j]
				self.seq[j]=temp
		j+=1
		temp=self.seq[j]
		self.seq[j]=self.seq[high]
		self.seq[high]=temp
		return j

	def getSeq(self):
		return self.seq


if __name__ == "__main__":
    xmldoc = minidom.parse('input.xml')
    inp = xmldoc.getElementsByTagName('item')
    seq = [ int(item.firstChild.nodeValue) for item in inp ]
    print("Given Sequence is : {}".format(seq))
    quickSorter = QuickSorter(seq,len(seq));
    quickSorter.sort()
    res = quickSorter.getSeq()
    print("Sorted Sequence is : {}".format(" ".join(list(map(str,res)))))