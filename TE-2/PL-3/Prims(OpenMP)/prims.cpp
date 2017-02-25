#include <iostream>
#include<vector>
#include<string.h>
#include <iomanip>

#define INF 9999;
using namespace std;

class Graph{
    private:
    int ncount;
    int** graph;
    vector<string> nodes;

    public:
    Graph(int ncount){
        this->ncount=ncount;
        cout<<"Enter Nodes Names ("<<ncount<<") :";
        for(int i=0;i<ncount;i++){
            string name;cin>>name;
            nodes.push_back(name);
        }
    }
    int createGraph(){
        cout<<"Nodes indexes are :"<<endl;
        for(int i=0;i<ncount;i++){
            cout<<nodes[i]<<"  : "<<i<<endl;
        }

        graph= new int*[ncount];
        for(int i=0;i<ncount;i++){
            graph[i]=new int[ncount];
        }

        for(int i=0;i<ncount;i++){
            for(int j=0;j<ncount;j++){
                graph[i][j]=graph[j][i]=INF;
            }
        }

        cout << "Enter node's indexes and distance between them separted by space" << endl;
        while(true) {
            cout<<"Enter :";
            int i,j,w;cin>>i>>j>>w;char ans='Y';
            graph[i][j]=graph[j][i]=w;
            bool f;cout<<"Enter new path (Y/n) :";cin>>ans;
            f = ans=='y' || ans =='Y' ? true:false;
            if(!f) break;
        }

        std::setfill("0");
        cout<<setw(5)<<right<<"INDEX";
        for(int i=0;i<ncount;i++) cout<<right<<setw(5)<<"\t\t"<<i;
        cout<<endl;
        for(int i=0;i<ncount;i++){
            cout<<right<<setw(5)<<i;
            for(int j=0;j<ncount;j++){
                cout<<right<<setw(5)<<"\t"<<graph[i][j];
            }
            cout<<endl;
        }
    }

    int prims(){
                
    }

};
int main() {
    Graph *graph=new Graph(4);
    graph->createGraph();

    return 0;
}