# By - Aditya Jain
# Roll No - 402059

from flask import Flask,render_template,request,redirect

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
	return render_template('quickSort.html',data = { 'inp':False,'status':False}, name=name) 


@app.route('/input', methods = ['POST'])
def sort(name=None):
	if request.method == 'POST':
		data = request.form # a multidict containing POST data
		array = data['array']

		seq = list(map(int,array.split(',')))
		sseq = quickSort(seq,0,len(seq)-1)
		print("Given Sequence is {}".format(sseq))
		return render_template("quickSort.html", data = { 'inp':True, 'status':False, 'seq': ",".join(map(str,sseq)) } )


@app.route('/search', methods = ['POST'] )
def search(name=None):
	if request.method == 'POST':
		data =  request.form
		no = int(data['no'])

		sseq = list(map(int,data['array'].split(',')))
		print("Searching {} in {}".format(no,sseq))
		
		low = 0
		high = len(sseq)-1
		while low<=high :
			mid = int((low+high)/2)
			if sseq[mid] == no :
				return render_template('quickSort.html',data = { 'inp':True, 'status':True, 'ans':'Element Found at pos {}'.format(mid+1),'seq':",".join(map(str,sseq)) } )
			elif sseq[mid] > no :
				high = mid-1
			else:
				low = mid+1

		return render_template('quickSort.html',data = { 'inp':True, 'status':True, 'ans':'Element Not Found', 'seq':",".join(map(str,sseq)) } )

if __name__ == '__main__':
	app.run(host = '0.0.0.0', port = 3000)
