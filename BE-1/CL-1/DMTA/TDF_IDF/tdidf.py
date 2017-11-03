#TF-IDF - Term Frequency- Inverse Document Frequency
"""
TF-IDF is weight used in information retrieval and text mining.
This weight shows how important is a word to document for collection.
importance = number of times word appears in document.

TF = probabilty of a word in a doc = no of times word in a doc / no of words in that doc
IDF = loge( total no of doc / no of doc having that word )
Cosine Similarity = 

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
		self.computeTf();print("TF : {}".format(self.tf),end="\n")
		self.computeIdf();print("IDF : {}".format(self.idf),end="\n")
		for doci in range(len(self.docs)):
			item = dict()
			for word in self.docs[doci]:
				item[word] = self.tf[doci][word]*self.idf[word]
			self.tfidf.append(item)
		print(self.tfidf,end="\n")

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

	def findSimilarity(self,query):
		terms = query.split()
		uniqTerms = set(terms)
		tfidf = list()
		for i in range(self.nodocs):		
			temp = dict()
			for term in uniqTerms:
				if term in self.tfidf[i]:
					temp[term] = self.tfidf[i][term]
				else:
					temp[term] = 0
			print("For doc {} : {}".format(i,temp),end="\n");tfidf.append(temp)
		qtfidf = dict()
		for term in uniqTerms:
			total = 0
			for i in terms:
				if i==term:
					total+=1
			qtfidf[term] = total/len(terms) * self.idf[term]
		print("For Query :{}".format(qtfidf),end="\n")
		print("Cosine Similarities : ",end="\n")
		min_cosine = -1
		min_doc = -1
		for i in range(self.nodocs):
			cos = 0
			for term in uniqTerms:
				cos += tfidf[i][term]*qtfidf[term]
			total1,total2 = 0,0
			for term in uniqTerms:
				total1 += tfidf[i][term]**2
				total2 += qtfidf[term]**2
			if total1!=0:
				cos = cos/(total1**.5)
			if total2!=0:
				cos = cos/(total2**.5)
			if cos>min_cosine:
				min_cosine=cos
				min_doc = i
			print("For doc {} : {}".format(i,cos))
		return (min_doc,min_cosine)

if __name__ == '__main__':
	doclist = [ "doc1.txt","doc2.txt","doc3.txt"]
	docs = list()
	for i in doclist:
		doc = open(i,"r").read().lower()
		docs.append(doc.split())
	tfidf = TfIdf(docs)
	tfidf.compute()
	query = input("Enter the query? :")
	best = tfidf.findSimilarity(query)
	print(best)