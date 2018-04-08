from threading import Thread
from xml.etree import ElementTree


def sort(seq):
	quicksort(seq,0,len(seq)-1)
	return seq

def quicksort(seq, low, high):
	if low<high:
		partn = partition(seq,low,high)
		t1 = Thread(target=quicksort,args=(seq,low,partn-1))
		t1.start()
		t1.join()

		t2 = Thread(target=quicksort,args=(seq,partn+1,high))
		t2.start()
		t2.join()

def partition(seq,low,high):
	ind = low
	curr = low
	pivot = seq[high]
	while curr<high:
		if seq[curr]<pivot:
			seq[curr],seq[ind] = seq[ind],seq[curr]
			ind+=1
		curr+=1
	seq[ind],seq[high]=seq[high],seq[ind]
	return ind

if __name__ == "__main__":
	doc = ElementTree.parse('input.xml')
	root= doc.getroot()
	seq = []
	#print(root.iter('integer'))
	for value in root.iter('integer'):
		seq.append(int(value.text))
	print(sort(seq))