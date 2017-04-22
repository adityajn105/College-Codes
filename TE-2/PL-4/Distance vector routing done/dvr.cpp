#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

#define INF 9999

class Node {

private:
    int name;
    vector<int> to;
    vector<int> next;
    vector<int> cost;

public:

    Node() {

    }

    Node(int name) {
        this->name = name;
    }

    Node(int name, int tableSize) {
        this->name = name;
        this->to = vector<int>((unsigned long) tableSize);
        for(int i = 0; i < tableSize; i++) {
            to[i] = i;
        }
        this->next = vector<int>((unsigned long) tableSize, -1);
        this->cost = vector<int>((unsigned long) tableSize, INF);
        cost[name] = 0;
    }

    void addNodeToTable(int to, int next, int cost) {

        this->to[to] = to;
        this->next[to] = next;
        this->cost[to] = cost;

/*        if(find(this->to.begin(), this->to.end(), to) == this->to.end()) {
            this->to.push_back(to);
            this->next.push_back(next);
            this->cost.push_back(cost);
        }*/
    }

    void printTable() {
        // Print table
        vector<int>::iterator ti = this->to.begin();
        vector<int>::iterator ci = this->cost.begin();
        vector<int>::iterator ni = this->next.begin();

        cout << "\nNode " << this->name << endl;
        printf("%-5s | %-10s | %-10s |\n", "To", "Next", "Cost");
        // cout << setw(10) << "To" << setw(10) << "| Next" << setw(10) << "| Cost" << "|" <<endl;
        cout << setw(33) << setfill('-') << "" << endl; //"----------------------------" << endl
        for (; ti != this->to.end(); ti++, ci++, ni++) {
            printf("%-5d | %-10s | %-10s |\n", *ti, (*ni == -1 ? "-" : to_string(*ni).c_str()) , (*ci == INF ? "Inf" : to_string(*ci).c_str()));
        }
        cout << endl;
    }

    void updateTable(Node &another) {
        vector<int> otherCost = another.cost;
        vector<int> otherTo = another.to;
        vector<int> otherNext = another.next;

        vector<int>::iterator ti = otherTo.begin();

        int toAnotherCost = this->cost[another.name];

        for (; ti != otherTo.end(); ti++) {
            int newCost = toAnotherCost + otherCost[*ti];
            if(newCost < this->cost[*ti]) {
                this->cost[*ti] = newCost;
                this->next[*ti] = another.name;
            }
        }
    }

    bool isNeighbour(Node &another) {
    	return this->cost[another.name] != INF;
    } 
};

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<Node *> nodes;

    for(int i = 0; i < n; i++) {
        Node *node = new Node(i, n);
        nodes.push_back(node);
    }

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    int n1, n2, w = INF;
    for(int i = 0; i < edges; i++) {
        cout << "Enter edge (Node 1, Node 2,  weight): ";
        cin >> n1 >> n2 >> w;
        nodes[n1]->addNodeToTable(n2, -1, w);
        nodes[n2]->addNodeToTable(n1, -1, w);
    }

    cout << "Before Broadcasts: \n";
    for(Node *node: nodes) {
        node->printTable();
    }

    for(int i = 0; i < n; i++) { // n broadcasts of all nodes

        for(int j = 0; j < n; j++) {
            Node *node = nodes[i];
            for(int k = 0; k < n; k++) {
                if(k != j && node->isNeighbour(*nodes[k]))
                    node->updateTable(*nodes[k]);
            }
        }
    }

    cout << "After 5 broadcasts of each node: \n";
    for(Node *node: nodes) {
        node->printTable();
    }

    return 0;
}

/** Test Input
5
6
0 1 4
0 2 5
0 4 3
1 2 2
1 3 3
2 3 2
 */

/* Test Output
Enter number of nodes: 5
Enter number of edges: 6
Enter edge (Node 1, Node 2,  weight): 0 1 4
0 2 5
0 4 3
1 2 2
1 3 3
2 3 2
Enter edge (Node 1, Node 2,  weight): Enter edge (Node 1, Node 2,  weight): Enter edge (Node 1, Node 2,  weight): Enter edge (Node 1, Node 2,  weight): Enter edge (Node 1, Node 2,  weight): Before Broadcasts:

Node 0
To    | Next       | Cost       |
---------------------------------
0     | -          | 0          |
1     | -          | 4          |
2     | -          | 5          |
3     | -          | Inf        |
4     | -          | 3          |


Node 1
To    | Next       | Cost       |
---------------------------------
0     | -          | 4          |
1     | -          | 0          |
2     | -          | 2          |
3     | -          | 3          |
4     | -          | Inf        |


Node 2
To    | Next       | Cost       |
---------------------------------
0     | -          | 5          |
1     | -          | 2          |
2     | -          | 0          |
3     | -          | 2          |
4     | -          | Inf        |


Node 3
To    | Next       | Cost       |
---------------------------------
0     | -          | Inf        |
1     | -          | 3          |
2     | -          | 2          |
3     | -          | 0          |
4     | -          | Inf        |


Node 4
To    | Next       | Cost       |
---------------------------------
0     | -          | 3          |
1     | -          | Inf        |
2     | -          | Inf        |
3     | -          | Inf        |
4     | -          | 0          |

After 5 broadcasts of each node:

Node 0
To    | Next       | Cost       |
---------------------------------
0     | -          | 0          |
1     | -          | 4          |
2     | -          | 5          |
3     | 1          | 7          |
4     | -          | 3          |


Node 1
To    | Next       | Cost       |
---------------------------------
0     | -          | 4          |
1     | -          | 0          |
2     | -          | 2          |
3     | -          | 3          |
4     | 0          | 7          |


Node 2
To    | Next       | Cost       |
---------------------------------
0     | -          | 5          |
1     | -          | 2          |
2     | -          | 0          |
3     | -          | 2          |
4     | 0          | 8          |


Node 3
To    | Next       | Cost       |
---------------------------------
0     | 1          | 7          |
1     | -          | 3          |
2     | -          | 2          |
3     | -          | 0          |
4     | 1          | 10         |


Node 4
To    | Next       | Cost       |
---------------------------------
0     | -          | 3          |
1     | 0          | 7          |
2     | 0          | 8          |
3     | 0          | 10         |
4     | -          | 0          |

 */