# By - Aditya Jain
# Roll No - 402059

from flask import Flask,render_template,request,redirect
import os

app = Flask(__name__)


def quickSort(seq,low,high):
	if low<high:
		nseq,partn = partition(seq,low,high)
		seq1 = quickSort(nseq[low:partn],0,partn-1)
		seq2 = quickSort(nseq[partn+1:high+1],0,high-partn-1)
		return seq1+[seq[partn]]+seq2
	else:
		return seq

def partition(seq,low,high):
	pivot = seq[high]
	j=-1;
	for i in range(low,high):
		if seq[i]<seq[high]:
			j += 1
			temp=seq[i]
			seq[i]=seq[j]
			seq[j]=temp
	j+=1
	temp=seq[j]
	seq[j]=seq[high]
	seq[high]=temp
	return (seq,j)


@app.route('/')
def home(name=None):
	return render_template('quickSort.html',data = {'status':False}, name=name) 

@app.route('/sort', methods = ['POST'])
def sort():
	if request.method == 'POST':
		data = request.form # a multidict containing POST data
		array = data['array']

		seq = list(map(int,array.split(',')))

		print("Given Sequence is {}".format(seq))
		ans = list(map(str,quickSort(seq,0,len(seq)-1)))
		return render_template("quickSort.html", data = { 'status':True, 'ans' : ",".join(ans) } )

if __name__ == '__main__':
	port = os.getenv('VCAP_APP_PORT', '5000')
	app.run(host = '0.0.0.0', port = int(port))
