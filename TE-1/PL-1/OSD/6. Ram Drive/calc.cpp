#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int a,b,ch;
	fstream input;
	input.open("input.txt",std::ios_base::in);
	input>>a;input>>b;
	input.close();
	fstream output;
	output.open("output.txt",std::ios_base::out);
	cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter Choice\t:";
	cin>>ch;
	switch(ch){
		case 1:
			output<<(a+b);
			break;
		case 2:
			output<<(a-b);
			break;
		case 3:
			output<<(a*b);
			break;
		case 4:
			output<<(a/b);
			break;		
	}
	output.close();
	return 0;
}
