import sys;
def hanoiRecursive(disk,src,dest,aux):
    if len(src)==0 or disk<=0:
        return
    hanoi(disk-1,src,aux,dest)
    top = src.pop();dest.append(top)
    print("src :{} aux:{}  dest:{}".format(src,aux,dest))
    hanoi(disk-1,aux,dest,src)
 
def hanoiIterative(disk,src,dest,aux):
    totalmoves=(2**disk)-1;
    print("Total Moves : {}".format(totalmoves))
    if disk%2==0:
        temp=aux;
        aux=dest;
        dest=temp
    for i in range(1,totalmoves+1):
        if i%3 == 0:
            move(aux,dest)
        if i%3 == 1:
            move(src,dest)
        if i%3 == 2:
            move(aux,src)  
        print("src :{} aux:{}  dest:{} i:{}".format(src,aux,dest,i))

def move(pole1,pole2):
    if len(pole2)==0:
        pole2.append(pole1.pop())
    elif len(pole1)==0:
        pole1.append(pole2.pop())
    elif pole1[-1]<pole2[-1]:
        pole2.append(pole1.pop())
    else:
        pole1.append(pole2.pop())
 
if __name__ == "__main__":
    dest,aux= list(),list()
    n = int(input("Enter Number of disks :"))
    src = [i for i in range(n,0,-1)]
    choice=int(input("1. Recursive\t2.Iterative\n"))
    if choice==1:
        sys.setrecursionlimit(999999);
        hanoiRecursive(n,src,dest,aux)
    else:
        hanoiIterative(n,src,dest,aux)