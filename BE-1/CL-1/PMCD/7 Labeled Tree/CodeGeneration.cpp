//Code Generation
#include<iostream>
#include <cstring>

using namespace std;

class Node{
    private:
        Node* left;
        Node* right;
        int flag;
        int label;
        char key;
    public:
        Node(char a){
            this->key = a;
            this->flag = 0;
            this->label = 0;
            this->left = NULL;
            this->right = NULL;
        }
        Node(char a,Node* l,Node* r){
            this->key = a;
            this->flag = 0;
            this->label = 0;
            this->left = l;
            this->left->flag = 1;
            this->right = r;
            this->right->flag = 0;
        }
        friend class CGTree;
};

class RegisterStack{
    private:
        int stack[2] = {1,2};
        int index = 1;
    public:
        int pop(){
            int top= stack[index];
            index--;
            return top;
        }
        void push(int r){
            index++;
            stack[index]=r;
        }
        void push(){
            if(index > 1){
                if(peek()==1){
                    index++;
                    stack[index] = 2;
                }
                else{
                    index++;
                    stack[index] = 1;
                }
            }
            else{
                cout<<"Register Stack Full";
            }
        }
        int peek(){
            return stack[index];
        }
        void swap(){
            int temp = stack[1];
            stack[1] = stack[0];
            stack[0]=temp;
        }
};

class Stack{
    private:
        Node* stack[20];
        int index;
        int length;
    public:
        Stack(int len) {
            this->index = -1;
            this->length = len - 1;
        }
        Node* pop(){
            if(index==-1) return NULL;
            else{
                Node* ret = this->stack[index];
                index--;
                return ret;
            }
        }
        void push(Node* a){
            index++;
            this->stack[index] = a;
        }
        Node* peek(){
            return this->stack[index];
        }
};

class CGTree{
    private:
        Node* root;
        Stack* stk;
        RegisterStack* regStk=new RegisterStack();

    public:
        CGTree(int len,char post[]){
            stk = new Stack(len);
            for(int i=0;i<(int)strlen(post);i++){
                if(post[i]=='-' || post[i]=='+' || post[i]=='*' || post[i]=='/'){
                    Node* r = stk->pop();
                    Node* l = stk->pop();
                    stk->push(new Node(post[i],l,r));
                }
                else stk->push(new Node(post[i]));
            }
            root = stk->pop();
            performLabelling(root);
        }

        void performLabelling(Node* node){
            if(node!=NULL){
                performLabelling(node->left);
                performLabelling(node->right);
                if(node->left == NULL)
                    node->label=node->flag;
                else{
                    if(node->left->label == node->right->label)
                        node->label = node->left->label+1;
                    else{
                        if(node->left->label > node->right->label)
                            node->label = node->left->label;
                        else
                            node->label= node->right->label;
                    }
                }

            }
        }
        void printInfix(){
            printInorder(root);
        }
        void printInorder(Node* node){
            if(node!=NULL){
                cout<<" ( ";
                printInorder(node->left);
                cout<<node->key<<"|"<<node->label;
                printInorder(node->right);
                cout<<" ) ";
            }
        }
        void printIntermediateCode(){
            codeGen(root);
        }
        void codeGen(Node* node){
            if(node!=NULL){
                if( node->left==NULL && node->flag==1 ){
                    cout<<"MOV "<<node->key<<" , R"<<regStk->peek()<<endl;
                }
                else if(node->right->label==0){
                    codeGen(node->left);
                    switch(node->key){
                        case '+':   cout<<"ADD ";break;
                        case '-':   cout<<"SUB ";break;
                        case '*':   cout<<"MUL ";break;
                        case '/':   cout<<"DIV ";break;
                    }
                    cout<<node->right->key<<" , R"<<regStk->peek()<<endl;
                }
                else if(node->right->label > node->left->label){
                    regStk->swap();
                    codeGen(node->right);
                    int r= regStk->pop();
                    codeGen(node->left);
                    switch(node->key){
                        case '+':   cout<<"ADD ";break;
                        case '-':   cout<<"SUB ";break;
                        case '*':   cout<<"MUL ";break;
                        case '/':   cout<<"DIV ";break;
                    }
                    cout<<"R"<<r<<" , "<<"R"<<regStk->peek()<<endl;
                    regStk->push(r);
                    regStk->swap();
                }
                else if(node->left->label >= node->right->label){
                    codeGen(node->left);
                    int r=regStk->pop();
                    codeGen(node->right);
                    switch(node->key){
                        case '+':   cout<<"ADD ";break;
                        case '-':   cout<<"SUB ";break;
                        case '*':   cout<<"MUL ";break;
                        case '/':   cout<<"DIV ";break;
                    }
                    cout<<"R"<<regStk->peek()<<" , R"<<r<<endl;
                    regStk->push(r);
                }
            }
        }
};

int main(){
    char post[20];
    cout<<"Enter PostFix Notation :";
    cin>>post;
    CGTree* tree = new CGTree(20,post);
    cout<<"Infix Notation : "<<endl;tree->printInfix();cout<<endl;
    cout<<"Intermediate Code :"<<endl;
    tree->printIntermediateCode();cout<<endl;
    return 0;
}
