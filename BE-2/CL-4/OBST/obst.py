# By : Aditya Jain (402059)
# Date : 19 Jan 2018
from itertools import permutations
from multiprocessing import Pool
import timeit

class OBST():
    def __init__(self, elem, p, q, no):
        self.elem = elem
        self.p = p
        self.q = q
        self.no = no
        self.arr = list(self.__findAllPermutations())
        self.map = dict()

    # Helper function returns all possible tree elements tuples
    def __findAllPermutations(self):
        return permutations(self.elem, self.no)


    # Perfrom Serial Execution
    # returns a tuple which has minimum cost, and its tree tuple
    def serialFindBestTree(self):
        for tup in self.arr:
            tree = Tree(tup)    #initialize tree
            tree.constructTree() # construct tree
            cost = self.__costOfTree(tree, tree.root, 1)
            self.map[cost] = tree.tup;  # insert cost, tree tuple in map

        #print(self.map)
        minCost = min(self.map.keys())      # get minimum possible cost
        return minCost,self.map[minCost]    #get tree tuple corresponding to minimum cost


    # Parrallize the bottleneck fucntion
    # returns a tuple which has minimum cost, and its tree tuple
    def parallelFindBestTree(self):
        pool = Pool(len(self.arr))
        costs = pool.map(self.costFinderWorker,self.arr)
        i =0
        for cost in costs:
            self.map[cost] = self.arr[i]
            i+=1
        #print(self.map)
        minCost = min(self.map.keys())     # get minimum possible cost
        return minCost, self.map[minCost]  # get tree tuple corresponding to minimum cost

    # Helper function to calulate cost of tree from it its tuple
    def costFinderWorker(self,tup):
        try:
            tree = Tree(tup)  # initialize tree
            tree.constructTree()  # construct tree
            cost = self.__costOfTree(tree, tree.root, 1)
            return cost
        except:
            print("Some Error Occured")

    # Function accepts tree and its node and its level and returns cost of its subTree
    def __costOfTree(self, tree, node, lvl):
        """
            Cost = pi * lvl(ai) + qi * (lvl(Ei)-1) for i in 0 to no

            ai - ith Tree node
            Ei - ith External Node (preorder)
            pi - probability of Successfull Search
            qi - probability of Unsuccessfull Search
            lvl(ai) - Level of ith Tree Node (tuple)
            lvl(Ei) - Level of ith External Node (preorder)
        """

        cost = 0
        if node.val == None:
            cost = cost + self.q[tree.d] * (lvl - 1)
            tree.d = tree.d + 1
        else:
            index = self.elem.index(node.val)
            cost = cost + self.p[index] * lvl

        if node.left != None:
            cost = cost + self.__costOfTree(tree, node.left, lvl + 1)
        if node.right != None:
            cost = cost + self.__costOfTree(tree, node.right, lvl + 1)
        return cost


class Node():
    def __init__(self,val,left,right):
        self.val = val
        self.left = left
        self.right = right


class Tree():
    def __init__(self, tup):
        self.tup =tup
        self.root = Node(tup[0], None, None) # initialize root node
        self.d = 0

    # Simple function to construct a binary search tree with self.root as root node
    def constructTree(self):
        # start adding from second node in tuple coz first is root
        for val in self.tup[1:]:
            node = self.root
            while True:
                if node.val > val:
                    if node.left == None:
                        node.left = Node(val, None, None)
                        break
                    else:
                        node = node.left
                else:
                    if node.right == None:
                        node.right = Node(val, None, None)
                        break
                    else:
                        node = node.right
        #insert external node for easy calculation
        self.__insertExternalNodes(self.root)

    #Function appends external node to all children nodes of its argument node
    def __insertExternalNodes(self, node):
        #If left child is None append external node else explore left child
        if node.left == None:
            node.left = Node(None, None, None)
        else:
            self.__insertExternalNodes(node.left)

        #If right child is None append external node else explore right child
        if node.right == None:
            node.right = Node(None, None, None)
        else:
            self.__insertExternalNodes(node.right)

if __name__ == "__main__":
    no = int(input("Enter No of Nodes : "))
    #no=3
    print("Enter Elements")
    elem = [input("{} : ".format(i)) for i in range(1, no + 1)]
    #elem = ["do","if","while"]
    print("Enter Success(p) : ")
    #p = [.5,.1,.05]
    p = [float(input("{} : ".format(i))) for i in range(1, no + 1)]
    print("Enter Failure(q) : ")
    #q = [.15,.1,.05,.05]
    q = [float(input("{} : ".format(i))) for i in range(0, no + 1)]
    obst = OBST(elem,p,q,no)

    print("Firstly Performing Serial Execution : ")
    start_time = timeit.default_timer()
    cost, tree = obst.serialFindBestTree(); # Perform Serial Execution
    elapsed = timeit.default_timer()
    print("{} is Optimal Binary Search Tree with Cost {} in {}".format(tree, cost, elapsed - start_time))

    print("Now Performing Concurrent Execution : ")
    start_time = timeit.default_timer()
    cost, tree = obst.parallelFindBestTree(); # Perform Parallel Execution
    elapsed = timeit.default_timer()
    print("{} is Optimal Binary Search Tree with Cost {} in {}".format(tree, cost, elapsed - start_time))