/*
	By - Aditya Jain
	Date - 8 January 2018
*/

#include <iostream>
#include <vector>
#define INF 999999;

using namespace std;
class Node{
	private: float value;
	private: int frequency;
	public : Node(float v,int f){
		this->value=v;
		this->frequency=f;
	}
	friend class OBST;
};

class OBST{
	private: vector<Node*> nodes;
	private: float** optCost;
	public: OBST(float* v,int* f,int n){
		optCost = new float*[n];
		for(int i=0;i<n;i++){
			nodes.push_back(new Node(v[i],f[i]));
			optCost[i] = new float[n];
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				optCost[i] = INF;
			}
		}
	}

	private: getCost(int i, int r){
		if(optCost[i][r]==INF){
			return NULL;
		}
		else{
			return optCost[i][r];
		}
	}

	public: solve(){
		for(int i=0;i<nodes;i++){
			for(int j=0;j<nodes;j++){
				
			}
		}
	}

	public: int totalNodes(){
		return nodes.size();
	}
};


int main(){
	int nodes;
	cout<<"Enter no of Nodes";cin>>nodes;
	float* v= new float[nodes];
	int* f= new int[nodes];
	cout<<"S/N 	value 	freq"<<endl;
	for(int i=0;i<nodes;i++){
		cout<<i<<'\t';
		cin>>v[i]>>f[i];
	}
	OBST obst(v,f,nodes);
	cout<<obst.totalNodes();
	return 0;
}