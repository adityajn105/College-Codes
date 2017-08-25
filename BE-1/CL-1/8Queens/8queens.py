def solve(xs,k,cnt):
	for i in range(0,8):
		cnt+=1
		if isOk(xs,k,i):
			xs[k]=i
			if k==7:
				print(xs)
			else:
				solve(xs,k+1,cnt)

def isOk(xs,row,cpos):
	for i in range(row):
		if xs[i]==cpos or abs(xs[i]-cpos)==abs(i-row):
			return False
		else:
			continue
	return True

if __name__ == "__main__":
	pos=input("Enter First Position :")
	xs=[-1]*8
	xs[0]=int(pos)
	cnt=0
	solve(xs,1,cnt)
	print(cnt)