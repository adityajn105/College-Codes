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
    int** mingraph;
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
            	if(i==j) graph[i][j]=0;
            	else graph[i][j]=graph[j][i]=INF;
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

        displayGraph(graph);
    }

    void displayGraph(int** g){
    	std::setfill("0");
        cout<<setw(5)<<right<<"INDEX";
        for(int i=0;i<ncount;i++) cout<<right<<setw(5)<<"\t\t"<<i;
        cout<<endl;
        for(int i=0;i<ncount;i++){
            cout<<right<<setw(5)<<i;
            for(int j=0;j<ncount;j++){
                cout<<right<<setw(5)<<"\t"<<g[i][j];
            }
            cout<<endl;
        }
    }

    int prims(){
    	mingraph= new int*[ncount];
        for(int i=0;i<ncount;i++){
            mingraph[i]=new int[ncount];
        }

        for(int i=0;i<ncount;i++){
            for(int j=0;j<ncount;j++){
            	if(i==j) mingraph[i][j]=0;
            	else mingraph[i][j]=mingraph[j][i]=INF;
            }
        }
        bool incnode[ncount];
        for(int i=0;i<ncount;i++) incnode[i]=false;
        incnode[0]=true;
        bool loop=true;
        while(loop){
			int low=INF;int from=0;int to=0;
			for(int j=0;j<ncount;j++){
				if(incnode[j]){
					for(int i=0;i<ncount;i++){
						if(graph[j][i]<low && i!=j){ 
							low=graph[j][i];
							from = i;
							to=j;  		
						}
					}
				}
				else continue;
			}
			incnode[from]=true;
			mingraph[from][to]=mingraph[to][from]=graph[from][to];

			loop= false;;
			for(int i=0;i<ncount;i++){
				if(!incnode[i]) {loop=true;break;}
			}
			if(!loop) break;
 		}          
    }
};

int main() {
    Graph* graph=new Graph(4);
    graph->createGraph();
    graph->prims();

    return 0;
}
