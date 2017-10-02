#include<iostream>
#include<vector>
using namespace std;
class Node{
	private:
		int cost;
		int value;
		vector<int> items;
		int level;
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
        void addItem(int item){
            items.push_back(item);
        }
        vector<int> getItems(){
            return items;
        }
        void setLchild(Node* l){
            this->lchild=l;
        }
        void setRchild(Node* r){
            this->rchild=r;
        }
        int getCurrentLevel(){
            return this->level;
        }
        int getCost(){
            return this->cost;
        }
        int getValue(){
            return this->value;
        }

};

Node* giveBestSolution(Node* curr,vector<int> costs,vector<int> values,int maxcost,int items){
	if(curr->getCurrentLevel()==items){
		return curr;
	}
	else{
		int level = curr->getCurrentLevel();
		Node* left= new Node(curr->getValue(),curr->getCost(),level+1,curr);
		Node* right=new Node(curr->getValue() + values[level], curr->getCost() + costs[level], level+1,curr);
		right->addItem(level);
		if(right->getCost() > maxcost){
			curr->setLchild(left);
			return giveBestSolution(left,costs,values,maxcost,items);
		}
		else{
			curr->setLchild(left);
            curr->setRchild(right);
			Node* l= giveBestSolution(left,costs,values,maxcost,items);
			Node* r= giveBestSolution(right,costs,values,maxcost,items);
			if(l->getValue() > r->getValue()) return l;
			else return r;
		}
	}
}

int main(){
	int items;cout<<"Number of Items :";cin>>items;
	vector<int> costs;
	vector<int> values;
	cout<<"Enter\nNo\t: Cost Value (seperated by space)"<<endl;
	int c,v;
	for(int i=0;i<items;i++){
        cout<<i+1<<"\t: ";
		cin>>c;costs.push_back(c);
		cin>>v;values.push_back(v);
	}
	int maxcost;
	cout<<"Enter Maximum Cost: ";cin>>maxcost;
	Node* root= new Node(0,0,0,NULL);
	Node* sol = giveBestSolution(root,costs,values,maxcost,items);

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