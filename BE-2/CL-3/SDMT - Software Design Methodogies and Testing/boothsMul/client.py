# By - Aditya Jain
# Roll No - 402059

from bitstring import BitArray
from flask import Flask,render_template,request,redirect
app = Flask(__name__)


@app.route('/')
def home(name=None):
	return render_template('Booths-Multiplier.html',data = {'status':False}, name=name) 

def booth(m, r, x, y):
	# Initialize
	totalLength = x + y + 1
	mA = BitArray(int = m, length = totalLength)
	rA = BitArray(int = r, length = totalLength)
	A = mA << (y+1)
	S = BitArray(int = -m, length = totalLength)  << (y+1)
	P = BitArray(int = r, length = y)
	P.prepend(BitArray(int = 0, length = x))
	P = P << 1
	print("Initial values")
	print("A", A.bin)
	print("S", S.bin)
	print("P", P.bin)
	print("Starting calculation")
	for i in range(1,y+1):
		if P[-2:] == '0b01':
			P = BitArray(int = P.int + A.int, length = totalLength)
			print("P +  A:", P.bin)
		elif P[-2:] == '0b10':
			P = BitArray(int = P.int +S.int, length = totalLength)
			print("P +  S:", P.bin)
		P = arith_shift_right(P, 1)
		print("P >> 1:", P.bin)
	P = arith_shift_right(P, 1)
	print("P >> 1:", P.bin)
	return P.int

def arith_shift_right(x, amt):
	l = x.len
	x = BitArray(int = (x.int >> amt), length = l)
	return x

@app.route('/multiply', methods = ['POST'])
def calculate():
	if request.method == 'POST':
		data = request.form # a multidict containing POST data
		one = int(data['no1'])
		two = int(data['no2'])
		bone = bin(one)[2:];btwo = bin(two)[2:] 
		print("Given numbers are {} and {}".format(one,two))
		ans = booth(one,two,len(bone)+1,len(btwo)+1)
		return render_template("Booths-Multiplier.html", data = { 'status':True, 'ans' : ans } )

if __name__ == '__main__':
    app.run(host = '0.0.0.0', port = 3000)
