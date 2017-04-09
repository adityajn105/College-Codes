#include <iostream>
#include <stdlib.h>
#include <omp.h>
#define INF 9999
#define NODES 5

using namespace std;
class Graph{
	private:
		int graph[NODES][NODES];
		int spanTree[NODES][NODES];
	public:
		Graph();
		void displayGraph();
		void prims();
		void displaySpanningTree();
};

Graph::Graph(){
	for (int i = 0; i < NODES; ++i){
		for (int j = 0; j < NODES; ++j){
			graph[i][j]=INF;
			spanTree[i][j]=INF;
		}
	}
	/*int a,b,d;
	while(true){
		cout<<"Enter nodes and distance between the respectively : ";cin>>a>>b>>d;
		graph[a][b]=graph[b][a]=d;
		char ans;
		cout<<"Do you want to enter more path(s) (y/n) : ";cin>>ans;
		if(ans=='n') break;
	}*/
	graph[0][1]=graph[1][0]=2;
	graph[0][2]=graph[2][0]=2;
	graph[0][3]=graph[3][0]=2;
	graph[1][3]=graph[3][1]=1;
	graph[1][4]=graph[4][1]=4;
	graph[2][4]=graph[4][2]=3;

}

void Graph::displaySpanningTree(){
	cout<<"N/N\t";
	for(int i=0;i<NODES;i++){
		cout<<i<<"\t";
	}
	cout<<endl<<endl;
	for(int i=0;i<NODES;i++){
		cout<<i<<"\t";
		for (int j = 0; j < NODES; ++j){
			if(spanTree[j][i]==INF) cout<<"-"<<"\t";
			else cout<<spanTree[j][i]<<"\t";
		}
		cout<<endl;
	}
}

void Graph::displayGraph(){
	cout<<"N/N\t";
	for(int i=0;i<NODES;i++){
		cout<<i<<"\t";
	}
	cout<<endl<<endl;
	for(int i=0;i<NODES;i++){
		cout<<i<<"\t";
		for (int j = 0; j < NODES; ++j){
			if(graph[j][i]==INF) cout<<"-"<<"\t";
			else cout<<graph[j][i]<<"\t";
		}
		cout<<endl;
	}
}

void Graph::prims(){
	bool vertexinc[NODES],cont;
	for(int i=0;i<NODES;i++) vertexinc[i]=false;
	vertexinc[0]=true;
	double sstime=omp_get_wtime();
	int cost=0,mincost=0;
	int s,d;
	do{
		int curr=INF;
		#pragma omp parallel for shared(cost,mincost)
		for(int i=0; i<NODES;i++){
			if(vertexinc[i]){
				for(int j=0;j<NODES;j++){
					#pragma omp critical
					{
						if(!vertexinc[j] && graph[i][j]<curr){
							s=i;d=j;
							curr=graph[i][j];	
						}
					}
				}	
			}
		}
		spanTree[s][d]=spanTree[d][s]=graph[d][s];
		mincost+=graph[d][s];
		vertexinc[d]=true;
		cont=false;
		for(int i=0;i<NODES;i++) if(!vertexinc[i]) {cont=true;continue;}
	}while(cont);
	cout<<endl<<"Spanning Tree Completed."<<endl;
	cout<<"Execution Time :"<<omp_get_wtime()-sstime<<endl;
	cout<<"Minimium cost :"<<mincost<<endl;
}



int main(){
	Graph *graph=new Graph();
	graph->displayGraph();
	graph->prims();
	graph->displaySpanningTree();
}
