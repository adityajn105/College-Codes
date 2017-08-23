import sys;
def hanoiRecursive(disk,src,dest,aux):
    if len(src)==0 or disk<=0:
        return
    hanoiRecursive(disk-1,src,aux,dest)
    top = src.pop();dest.append(top)
    print("src :{} aux:{}  dest:{}".format(src,aux,dest))
    hanoiRecursive(disk-1,aux,dest,src)
 
def hanoiIterative(disk,src,dest,aux):
    totalmoves=(2**disk)-1;
    print("Total Moves : {}".format(totalmoves))
    even=False
    if disk%2==0:
        temp=aux;
        aux=dest;
        dest=temp
        even=True
    mov=""
    for i in range(1,totalmoves+1):
        if i%3 == 0:
            sit,top=move(aux,dest)
            if sit==1:
                mov=("Move {} from aux to dest".format(top),"Move {} from dest to aux".format(top))[even]
            else:
                mov=("Move {} from dest to aux".format(top),"Move {} from aux to dest".format(top))[even]
        if i%3 == 1:
            sit,top=move(src,dest)
            if sit==1:
                mov=("Move {} from src to dest".format(top),"Move {} from aux to src".format(top))[even]
            else:
                mov=("Move {} from dest to src".format(top),"Move {} from src to aux".format(top))[even]
        if i%3 == 2:
            sit,top=move(aux,src)
            if sit==1:
                mov=("Move {} from aux to src".format(top),"Move {} from dest to src".format(top))[even]
            else:
                mov=("Move {} from src to aux".format(top),"Move {} from srx to dest".format(top))[even]
        print(mov)

def move(pole1,pole2):
    if len(pole2)==0:
        temp=pole1.pop()
        pole2.append(temp)
        return (1,temp)
    elif len(pole1)==0:
        temp=pole2.pop()
        pole1.append(temp)
        return (2,temp)
    elif pole1[-1]<pole2[-1]:
        temp=pole1.pop()
        pole2.append(temp)
        return (1,temp)
    else:
        temp=pole2.pop()
        pole1.append(temp)
        return (2,temp)
 
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