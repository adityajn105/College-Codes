from queue import PriorityQueue as pq

def printState(state):
	print("+---+---+---+")
	for i in state:
		print("{} {} {}".format("|"," | ".join(i),"|"))
		print("+---+---+---+")

def manhattenDistance(state):
	manhatten=0;
	for j in range(3):
		for i in range(3):
			num=state[i][j]
			if not num == '-':
				ox=int((int(num)-1)%3)
				oy=int((int(num)-1)/3)
				manhatten=manhatten+abs(ox-j)+abs(oy-i)
	return manhatten

def getXY(state):
	for i in range(3):
		for j in range(3):
			if state[i][j]=='-':
				return (i,j)

def copy(state):
	newS=[ [state[j][i] for i in range(3) ] for j in range(3) ]
	return newS

def isThere(state,ls):
    for item in ls:
        diff=False
        for i in range(3):
            for j in range(3):
                if not state[i][j] == item[i][j]:
                    diff=True
                    break
            if diff:
                break
        if diff:
            continue
        else:
            return True
    return False


if __name__ =="__main__":
	print("Give initial state(1-8 and \'-\')")
	initial = [ input().split(" ") for j in range(3) ]
	openq = pq()
	closeq = list()
	openq.put((manhattenDistance(initial),0,initial))
	while True:
		if openq.empty():
			print("No Solution to Problem")
			break
		tup = openq.get()
		closeq.append(tup)
		if tup[0]==0:
			print("Solution Reached")
			for i in closeq:
				printState(i[2])
			break
		else:
			(x,y)=getXY(tup[2])
			moves = [[+1,0],[-1,0],[0,-1],[0,+1]]
			for i in moves:
				if x+i[0] >=0 and x+i[0]<=2 and y+i[1]>=0 and y+i[1]<=2:
					newS = copy(tup[2])
					temp = newS[x+i[0]][y+i[1]]
					newS[x+i[0]][y+i[1]]='-'
					newS[x][y]=temp
					if not isThere(newS,closeq):
						openq.put((manhattenDistance(newS),0,newS))