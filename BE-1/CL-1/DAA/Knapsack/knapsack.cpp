#include<iostream>
#include<vector>
using namespace std;
class Node{
	private:
		int cost;
		int value;
		vector<int> items;
		int level;
		int upperbound;
		Node* lchild;
		Node* rchild;

    public:
        Node(int value,int cost,int level,Node* parent){
            this->cost=cost;
            this->value=value;
            this->level=level;
            this->lchild=NULL;
            this->rchild=NULL;
            if(parent!=NULL) {
                int s = parent->getItems().size();
                for (int i = 0; i < s; i++) {
                    this->items.push_back(parent->getItems()[i]);
                }
            }
        }
        void addItem(int item){ items.push_back(item); }
        vector<int> getItems(){ return items; }
        void setLchild(Node* l){ this->lchild=l; }
        void setRchild(Node* r){ this->rchild=r; }
        Node* getLchild(){ return this->lchild; }
        Node* getRchild(){ return  this->rchild; }
        int getCurrentLevel(){ return this->level; }
        int getUB(){ return this->upperbound; }
        void setUB(int a){ this->upperbound=a; }
        int getCost(){ return this->cost; }
        int getValue(){ return this->value; }
};

class Knapsack{
	private:
		vector<int> costs;
		vector<int> values;
		int maxcost;
		int items;
		vector<Node*> active;
        int bestValue=0;
        Node* bestNode;
        vector<int> indexes;

	public:
		Knapsack(vector<int> costs,vector<int> values,int maxcost,int items){
			this->costs=costs;
			this->values=values;
			this->maxcost=maxcost;
			this->items=items;
			for(int i=0;i<items;i++){
                indexes.push_back(i);
            }
            for(int i=0;i<items-1;i++){
				for(int j=0;j<items-1;j++){
					if((((double)this->values[j])/((double)this->costs[j])) 
						< (((double)this->values[j+1])/((double)this->costs[j+1]))){
						int temp = this->values[j];
						this->values[j] = this->values[j+1];
						this->values[j+1]=temp;
						temp = this->costs[j];
						this->costs[j] = this->costs[j+1];
						this->costs[j+1]=temp;
                        temp = this->indexes[j];
                        this->indexes[j]=this->indexes[j+1];
                        this->indexes[j+1]=temp;
					}
				}
			}
		}

        Node* giveSolution(){
            Node* root = new Node(0,0,0,NULL);
            root->setUB(calculateUB(root));
            this->active.push_back(root);

            while(this->active.size()!=0){
                Node* best = popBestNode();
                int level = best->getCurrentLevel();
                if(level==this->items) continue;
                if(bestNode!=NULL && best->getUB()< bestNode->getValue()) continue;
                int val = best->getValue();
                int cost =best->getCost();
                Node* lchild = new Node(val,cost,level+1,best);
                lchild->setUB(calculateUB(lchild));
                Node *rchild=NULL;
                if(cost+this->costs[level]<=this->maxcost) {
                    rchild = new Node(val + this->values[level], 
                    	cost + this->costs[level], level+1, best);
                    rchild->setUB(calculateUB(rchild));
                    rchild->addItem(this->indexes[level]);
                }
                if(level+1==this->items){
                    if(rchild!=NULL){
                        if(rchild->getValue() > bestValue){
                            this->bestValue=rchild->getValue();
                            this->bestNode = rchild;
                        }
                        best->setRchild(rchild);
                        best->setLchild(lchild);
                    }
                    else{
                        if(lchild->getValue() > bestValue){
                            this->bestValue=lchild->getValue();
                            this->bestNode = lchild;
                        }
                        best->setLchild(lchild);
                    }
                }
                else{
                    if(rchild!=NULL){
                        best->setRchild(rchild);this->active.push_back(rchild);
                    }
                    best->setLchild(lchild);this->active.push_back(lchild);
                }
            }
            return bestNode;
        }

        Node* popBestNode(){
            int size = this->active.size();
            int index=0;
            Node* cbest = this->active[0];
            for(int i=1;i<size;i++){
                if(cbest->getUB() < this->active[i]->getUB()){
                    index=i;
                    cbest=this->active[i];
                }
            }
            this->active.erase(this->active.begin()+index);
            return cbest;
        }

        int calculateUB(Node* node){
            int ub = node->getValue();
            int cost = node->getCost();
            for(int i=node->getCurrentLevel();i<this->items;i++){
                if( cost+this->costs[i] <= this->maxcost){
                    ub= ub+this->values[i];
                    cost+=this->costs[i];
                }
                else{
                    ub = ub + ((this->maxcost-cost)*this->values[i])/this->costs[i];
                    break;
                }
            }
            return ub;
        }
};

int main(){
	int items;cout<<"Number of Items :";cin>>items;
	vector<int> costs;
	vector<int> values;
	vector<int> ratio;
	cout<<"Enter\nNo\t: Cost Value (seperated by space)"<<endl;
	int c,v;
	for(int i=0;i<items;i++){
        cout<<i+1<<"\t: ";
		cin>>c;costs.push_back(c);
		cin>>v;values.push_back(v);
	}
	int maxcost;
	cout<<"Enter Maximum Cost: ";cin>>maxcost;
	Knapsack* problem = new Knapsack(costs,values,maxcost,items);
    Node* sol = problem->giveSolution();

	cout<<"Best Solution"<<endl;
	cout<<"Cost : "<<sol->getCost()<<endl;
	cout<<"Value : "<<sol->getValue()<<endl;
	cout<<"Items Included :";
	for(int i=0;i<sol->getItems().size();i++){
		cout<<sol->getItems()[i]+1<<" ";
	}
	cout<<endl;
	return 0;
}