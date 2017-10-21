#TF-IDF - Term Frequency- Inverse Document Frequency
"""
TF-IDF is weight used in information retrieval and text mining.
This weight shows how important is a word to document for collection.
importance = number of times word appears in document.

"""
import math
class TfIdf():
	def __init__(self,docs):
		self.docs = docs
		self.nodocs = len(docs)
		self.uniqdocs = list()
		for i in docs:
			self.uniqdocs.append(set(i))
		self.tf = list()
		self.idf = dict()
		self.tfidf = list()

	def compute(self):
		self.computeTf();
		self.computeIdf();
		for doci in range(len(self.docs)):
			item = dict()
			for word in self.docs[doci]:
				item[word] = self.tf[doci][word]*self.idf[word]
			self.tfidf.append(item)
		print(self.tfidf)

	def computeTf(self):
		for i in range(len(self.uniqdocs)):
			item = dict()
			for j in self.uniqdocs[i]:
				times = 0
				for k in self.docs[i]:
					if j == k:
						times+=1
				item[j] = times/len(self.docs[i])
			self.tf.append(item)

	def computeIdf(self):
		completeSet = { i for doc in self.docs for i in doc }
		for i in completeSet:
			times = 0
			for doc in self.docs:
				if i in doc:
					times+=1
			self.idf[i] = 1 + math.log(self.nodocs/times)

if __name__ == '__main__':
	doclist = [ "doc1.txt","doc2.txt","doc3.txt"]
	docs = list()
	for i in doclist:
		doc = open(i,"r").read().lower()
		docs.append(doc.split())
	tfidf = TfIdf(docs)
	tfidf.compute()