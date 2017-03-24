import math
import threading
import matplotlib.pyplot as plt

class Poles(threading.Thread):
	def __init__(self,X1,X2,X3,op,plt):
		threading.Thread.__init__(self)
		self.X1=float(X1)
		self.X2=float(X2)
		self.X3=float(X3)
		self.op=op
		self.plt=plt

	def run(self):
		if(math.pow(self.X2,2)-(4*self.X1*self.X3)<0):
			print "Root are imaginary"
		else:
			x= (-1*self.X2+math.sqrt( math.pow(self.X2,2)-(4*self.X1*self.X3) ))/(2*self.X1)
			y= (-1*self.X2-math.sqrt( math.pow(self.X2,2)-(4*self.X1*self.X3) ))/(2*self.X1)
			if(self.op==1):
				print "Num= "+str(x)+","+str(y)
				self.plt.scatter(x,0)
				self.plt.scatter(y,0)
			else:
				print "Den= "+str(x)+","+str(y) 
				self.plt.scatter(x,0)
				self.plt.scatter(y,0)

if __name__ == '__main__':
	print "Numerator ->  A1*(Z^2)+A2*(Z)+A3"
	A1=input("A1=")
	A2=input("A2=")
	A3=input("A3=")
	print "Denominator -> B1*(Z^2)+B2*(Z)+B3"
	B1=input("B1=")
	B2=input("B2=")
	B3=input("B3=")
	
	fig = plt.figure()
	ax = plt.axes()
	circle = plt.Circle((0, 0), 1,fill=False)
	plt.xlim(-3,3)
	plt.ylim(-3,3)
	ax.add_artist(circle)
	ax.grid(True, which='both')

	num= Poles(A1,A2,A3,1,plt)
	den= Poles(B1,B2,B3,2,plt)
	num.start()
	den.start()
	
	plt.show() 

