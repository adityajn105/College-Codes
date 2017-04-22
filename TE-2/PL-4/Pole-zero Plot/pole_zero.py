from __future__ import print_function
import cmath
import matplotlib.pyplot as plt
import threading


class ThreadClass(threading.Thread):
	def __init__(self,a,b,c,callback):
		super(ThreadClass,self).__init__()
		self.a = a
		self.b = b
		self.c = c
		self.callback = callback
	
	def run(self):
		roots = get_roots(self.a,self.b,self.c)
		self.callback(roots)

def get_roots(a,b,c):
	numerator = b**2 - 4*a*c
	is_complex = False
	roots = list()
	
	numerator = cmath.sqrt(numerator)
	roots.append((-b + numerator) / (2*a))
	roots.append((-b - numerator) / (2*a))
	
	return roots
		

def main():
	print("For Poles")
	a1,b1,c1 = map(float,raw_input("Enter values of a b and c\n> ").split())
	print("For Zeros")
	a2,b2,c2 = map(float,raw_input("Enter values of a b and c\n> ").split())
	
	zeros = list()
	poles = list()

	t1 = ThreadClass(a1,b1,c1, callback = lambda roots: zeros.extend(roots))
	t2 = ThreadClass(a2,b2,c2, callback = lambda roots: poles.extend(roots))
	
	t1.start()
	t2.start()
	t1.join()
	t2.join()
	
	maxx = max([abs(x.real) for x in zeros+poles])
	maxy = max([abs(x.imag) for x in zeros+poles])
	
	plt.xlabel("Real")
	plt.ylabel("Imaginary")
	plt.grid(True)
	
	for root in zeros:
		plt.plot(root.real,root.imag,marker='o')
	for root in poles:
		plt.plot(root.real, root.imag,marker='x')
	plt.xlim(2*maxx, -2*maxx)
	plt.ylim(2*maxy, -2*maxy)
	
	plt.show()
	
	
if __name__ == '__main__':
	main()
	
