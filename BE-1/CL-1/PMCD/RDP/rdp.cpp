/*
E -> TE'
E'-> +TE'|e
T -> FT'
T'-> *FT'|e
F -> id|(E)
*/
#include <iostream>
using namespace std;
 
void Edash(char* v);
void E(char* v);
void Tdash(char* v);
void T(char* v);
void F(char* v);
void Fdash(char* v);
void advance(char* v);
int counter=0;
 
int main(int argc , char *argv[]){
    if(argc==1){
        cout<<"Error: Please pass a string as a argument : ./a.out \"id+id\""<<endl;
        return -1;
    }else{
        E(argv[1]);
        return 0;
    }
}
void advance(){
    counter++;
}
 
void E(char* v){
    T(v);
    Edash(v);
    if(v[counter]=='\0'){
        cout<<"String Accepted"<<endl;
    }
}
void Edash(char* v){
    if(v[counter]=='+'){
        advance();
        T(v);
        Edash(v);
    }
}
void T(char* v){
    F(v);
    Tdash(v);
}
void Tdash(char* v){
    if(v[counter] == '*'){
        advance();
        F(v);
        Tdash(v);
    }
}
void F(char* v){
    if(v[counter]=='i' && v[counter+1]=='d'){
        advance();
        advance();
    }
    else{
        if(v[counter]=='('){
            advance();
            E(v);
            if(v[counter]==')'){
                advance();
            }
            else{
                cout<<"Error at line 0:"<<counter<<endl;
            }
        }
        else{
            cout<<"Error at line 0:"<<counter<<endl;
        }
    }
}