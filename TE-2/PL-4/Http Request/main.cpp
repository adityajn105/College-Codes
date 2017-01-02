#include<iostream>
#include <string.h>
#include <sstream>
#include<sys/resource.h>
#include<unistd.h>
using namespace std;

string exec(const char*);
int main()
{
    cout<<"----Http Request----"<<endl;
    cout<<"Request Line "<<endl;
    string method="Method :GET";
    string url="http://google.com";
    string httpv="HTTP Version :1.1";

    cout<<method<<endl<<"URL :"+url<<endl<<httpv<<endl<<endl;
    cout<<"Header "<<endl;
    string accept="Accept :text/plain";
    string ctype="Content-Type :text/html";
    //cout<<accept<<endl<<ctype<<endl<<endl;
    cout<<"Body \nNot Required"<<endl<<endl;
    string cmd="curl -i -H \""+accept+"\" -H \""+ctype+"\" "+url;

    string response=exec(cmd.c_str());
    istringstream output(response);

    cout<<"----Http Response----"<<endl;
    string body="";
    string line;
    int no=1;
    /*while (std::getline(output, line)) {

    }*/



    while (getline(output, line)) {
        if(no==1){
            string statusline = line;
            std::cout<<"Status Line :"<<line<<std::endl;
            std::cout<<"Version :"<<line.substr(0,8)<<std::endl;
            std::cout<<"Status Code :"<<line.substr(9,11)<<std::endl;
            std::cout<<"Phrase :"<<line.substr(13,13)<<std::endl<<std::endl;
            std::cout<<"Header"<<std::endl;
        }
        else if(no==2) std::cout << line<<std::endl;
        else if(no==3) std::cout<<line<<std::endl;
        else if(no==5) std::cout<<line<<std::endl;
        else if(no==6) std::cout<<line<<std::endl<<std::endl;
        else if(no==4 || no==7) ;
        else{
            body=body+line+"\n";
        }
        no++;
    }
    cout<<"Body"<<endl;
    cout<<body;
    return 0;
}

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

