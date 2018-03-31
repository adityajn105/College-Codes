from flask import Flask, render_template, request, jsonify
import functools
from multiprocessing.pool import ThreadPool

app = Flask(__name__)

def compare_exchange(a, i1, i2):
	if a[i1] > a[i2]:
		a[i1], a[i2] = a[i2], a[i1]
		return False
	return True

def sort_array(b):
	"""
		Parameters:
			b: List to sort
		Returns:
			Sorted list
"""
	a = b[:]
	sorted = False
	pool = ThreadPool(processes=4)
	while not sorted:
		sorted = True
		
		# Even
		results = []
		for i in range(0, len(a)-1, 2):
			results.append(pool.apply_async(compare_exchange, args=(a, i, i + 1)))
		sorted = functools.reduce(lambda x, y: x and y, map(lambda x: x.get(), results))
		
		# Odd
		results = []
		for i in range(1, len(a)-1, 2):
			results.append(pool.apply_async(compare_exchange, args=(a, i, i + 1)))
		sorted = functools.reduce(lambda x, y: x and y, map(lambda x: x.get(), results))
	return a


@app.route('/')
def home(name=None):
	return render_template('oddeven.html',data = {'status':False}, name=name) 

@app.route('/sort', methods = ['POST'])
def sort():
	if request.method == 'POST':
		data = request.form # a multidict containing POST data
		array = data['array']

		seq = list(map(int,array.split(',')))

		print("Given Sequence is {}".format(seq))
		ans = list(map(str,sort_array(seq)))
		return render_template("oddeven.html", data = { 'status':True, 'ans' : ",".join(ans) } )

if __name__ == '__main__':
	app.run(host = '0.0.0.0', port = int(5000))