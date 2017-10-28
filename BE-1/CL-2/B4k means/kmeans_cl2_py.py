py
'''
ASSIGNMENT No:
PROBLEM STATEMENT: Implement k-means for clustering data of children belonging to different age groups to perform some
specifc activities. Formulate the Feature vector for following parameters:
i. height
ii. weight
iii. age
iv. IQ
Formulate the data for 40 children to form 3 clusters. 
CLASS:BE-A
BATCH:
ROLL NO:

'''

import math
import csv

def disp_data(Student,centroid):
	n=len(Student)
	
	for i in range(0,n):
		if centroid[i]==1:
			print Student[i]
	
def edist(Student,centroid,i):
	ed=0
	s=0
	ht=0
	wt=0
	age=0
	iq1=0
	n=len(Student)
	
	ht=Student[i][0]-centroid[0]
	wt=Student[i][1]-centroid[1]
	age=Student[i][2]-centroid[2]
	iq1=Student[i][3]-centroid[3]
	
	s=ht*ht+wt*wt+age*age+iq1*iq1
	
	ed=math.sqrt(s)
	
	return ed
	
def updateCentroid(Student,c1,n):
	ht=0
	wt=0
	age=0
	iq1=0
	cnt=0
	c2=[]

	for i in range(0,n):
		if c1[i]==1:
			ht=ht+Student[i][0]
			wt=wt+Student[i][1]
			age=age+Student[i][2]
			iq1=iq1+Student[i][3]
			cnt+=1
			
	ht=ht/cnt
	wt=wt/cnt
	age=age/cnt
	iq1=iq1/cnt
	
	c2.append(ht)
	c2.append(wt)
	c2.append(age)
	c2.append(iq1)
	
	return c2
	
def kmean(old_c1,old_c2,old_c3,Student,n,cnt=1):
	new_c1=[]
	new_c2=[]
	new_c3=[]

	c1_dist=[]
	c2_dist=[]
	c3_dist=[]
		
	for i in range(0,n):
		ed_c1=edist(Student,old_c1,i)
		ed_c2=edist(Student,old_c2,i)
		ed_c3=edist(Student,old_c3,i)
		
		c1_dist.append(ed_c1)
		c2_dist.append(ed_c2)
		c3_dist.append(ed_c3)
	
	for i in range(0,n):
		if(min(c1_dist[i],c2_dist[i],c3_dist[i])==c1_dist[i]):
			c1_dist[i]=1
			c2_dist[i]=0
			c3_dist[i]=0
		elif(min(c1_dist[i],c2_dist[i],c3_dist[i])==c2_dist[i]):
			c2_dist[i]=1
			c1_dist[i]=0
			c3_dist[i]=0
		else:
			c1_dist[i]=0
			c2_dist[i]=0
			c3_dist[i]=1

	new_c1=updateCentroid(Student,c1_dist,n)
	new_c2=updateCentroid(Student,c2_dist,n)
	new_c3=updateCentroid(Student,c3_dist,n)

	print old_c1,old_c2,old_c3,new_c1,new_c2,new_c3
	
	if(old_c1!=new_c1 or old_c2!=new_c2 or old_c3!=new_c3): 
	
		kmean(new_c1,new_c2,new_c3,Student,n,cnt+1)
		
	else:
		print "\n------KMeans Clustering algorithm using python------"
		print "Iteration",cnt
		print "\nCentroid 1 : ",new_c1
		disp_data(Student,c1_dist)
		print "\nCentroid 2 : ",new_c2
		disp_data(Student,c2_dist)
		print "\nCentroid 3 : ",new_c3		
		disp_data(Student,c3_dist)

Student=[]

with open('input.csv', 'rb') as f:
  
    reader = csv.reader(f)
    header = next(reader)
    for row in reader:
    	r=map(int,row)
        Student.append((r))
 
    
print Student
n=len(Student)
centroid=[]

old_c1=Student[11]
old_c2=Student[12]
old_c3=Student[13]

kmean(old_c1,old_c2,old_c3,Student,n)

'''
OUTPUT:
------KMeans Clustering algorithm using python------
Iteration 5

Centroid 1 :  [159, 48, 14, 3]
[152, 46, 13, 3]
[153, 49, 13, 3]
[160, 50, 14, 5]
[161, 53, 14, 4]
[162, 56, 15, 3]
[163, 59, 16, 3]
[160, 38, 14, 5]
[161, 39, 14, 4]
[162, 40, 15, 3]
[163, 41, 16, 3]
[152, 48, 13, 3]
[153, 49, 13, 3]
[160, 50, 14, 5]
[161, 51, 14, 4]
[162, 52, 15, 3]
[163, 53, 16, 3]

Centroid 2 :  [141, 32, 10, 3]
[140, 30, 11, 5]
[141, 33, 11, 4]
[142, 36, 10, 3]
[140, 30, 11, 5]
[141, 31, 11, 4]
[142, 32, 10, 3]
[143, 33, 10, 3]

Centroid 3 :  [146, 42, 11, 4]
[143, 39, 10, 3]
[150, 40, 12, 5]
[151, 43, 12, 4]
[150, 34, 12, 5]
[151, 35, 12, 4]
[152, 36, 13, 3]
[153, 37, 13, 3]
[140, 42, 11, 5]
[141, 43, 11, 4]
[142, 44, 10, 3]
[143, 45, 10, 3]
[150, 46, 12, 5]
[151, 47, 12, 4]
[140, 54, 11, 5]
[141, 55, 11, 4]
'''

