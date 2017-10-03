#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <omp.h>
using namespace std;

class Cost{
	public:
		int start;
		set<int> nodes;
		int end;
		int cost;
		vector<int> path;
		Cost(int start,set<int> nodes,int end){
			this->start=start;
			this->nodes=nodes;
			this->end=end;
		}
		bool compare(int s,set<int> is,int e){
			if(s==start && end==e && is==nodes ) return true;
			else return false;
		}

};

class TSDynamic{
	private:
		int** graph;
		int no;
		set<int> nodes;
		vector<Cost*> costs;
	public:
		TSDynamic(int** graph,int no){
			this->graph=graph;
			this->no=no;
			for(int i=0;i<no;i++){
				this->nodes.insert(i);
			}
		}

		Cost* findPath(int start){
			return cost(start,giveSet(this->nodes,start),start);
		}

		Cost* cost(int start,set<int> via,int end){
			Cost* c = isCostThere(start,via,end);
			if(c==NULL){
				c = new Cost(start,giveSet(via,start),end);
				int minc = 9999;
				Cost* minCost;
				set<int>::iterator it;
				
				for(it=via.begin();it!=via.end();++it){
					Cost* ctemp = cost(*it,giveSet(via,*it),end);
					int ccost = graph[start][*it] + ctemp->cost;
					if(ccost<minc){
						minc=ccost;
						minCost = ctemp;
					}
				}
				if(via.size()==0){
					c->cost = graph[start][end];
					c->path.push_back(start);
					c->path.push_back(end); 
				}
				else{
					c->cost= minc;
					c->path.push_back(start);
					c->path.insert(c->path.end(),minCost->path.begin(),minCost->path.end());
				}
			}
			return c;	
		}

		set<int> giveSet(set<int> prev,int discard){
			set<int> newSet;
			set<int>::iterator it;
			for(it=prev.begin();it!=prev.end();++it){
				if(*it != discard)
					newSet.insert(*it);
			}
			return newSet;
		}

		Cost* isCostThere(int start,set<int> via,int end){
			int len = costs.size();
			Cost* ans = NULL;
			#pragma omp parallel for
			for(int i=0;i<len;i++){
				Cost* c = costs[i];
				if(c->compare(start,via,end)){
					ans=c;
				}
			}
			return ans;
		}
};

int main(){
	int nodes;cout<<"Number of Nodes :";cin>>nodes;
	int** graph = new int*[nodes];
	for(int i=0;i<nodes;i++){
		graph[i]= new int[nodes];
	}

	cout<<"Enter Problem Matrix (seperate rows by linebreak and col by blankspace)"<<endl;
	for(int i =0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			cin>>graph[i][j];
		}
	}

	TSDynamic* problem =  new TSDynamic(graph,nodes);
	double start = omp_get_wtime(); 
	Cost* sol = problem->findPath(0);
	double end = omp_get_wtime();
	cout<<"Time taken for execution :"<<end-start<<endl;
	cout<<"Minimum Cost :"<<sol->cost<<endl;
	cout<<"Optimal Path :";cout<<sol->path[0]+1;
	for(int i=1;i<sol->path.size();i++){
		cout<<"->"<<sol->path[i]+1;
	}

	cout<<endl;
	return 1;
}