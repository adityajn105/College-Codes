#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main(){
    ifstream fifo;
    fifo.open("/tmp/myfifo.fifo",ifstream::in);
    string  line;
    cout<<"Reading FIFO   :";
    while (!fifo.eof())
    {
        if(getline(fifo, line))
        {
            cout << line << endl;
        }
    }
    fifo.clear();
    return 0;
}


