#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <fstream>
using namespace std;

void help(){
	cout<<"Usage:\n"
			"1. get arg1 arg2 -Get file (arg1 - file to be copied  arg2- file to be created)\n"
			"2. pwd -Current path\n"
			"3. help -Show help\n"
            "4. ls -list files\n"<<endl;
}
void ls(char cmd[],int cc,int cd){
	send(cc, cmd, 10, 0);
    char buff[100];
    recv(cd,buff,100,0);
    while(strcmp(buff,"\0")!=0){
        cout<<buff<<endl;
        recv(cd,buff,100,0);
    }
}
void get(char cmd[],int cc,int cd){
    send(cc,cmd,10,0);
    char file[20];cin>>file;
    char filel[20];cin>>filel;
    send(cc,file,20,0);
    ofstream outfile;
    outfile.open(filel);
    char buffer[1024];
    bool dat=false;
    recv(cd,buffer,1024,0);
    while(strcmp(buffer,"eof")!=0){
    	dat=true;
    	outfile << buffer<<"\n";
    	recv(cd,buffer,1024,0);
    }
    if(!dat){
    	cout<<"File not found!!"<<endl;
    }
    outfile.close();
}


int main() {
    int clientSocketcontrol,clientSocketdata;
    char cmd[10];
    char user[20];
    char pass[20],ack[1];
    struct sockaddr_in serverAddrctl,serverAddrdata;
    socklen_t addr_size;

    clientSocketcontrol=socket(AF_INET,SOCK_STREAM,0);
    serverAddrctl.sin_family=AF_INET;
    serverAddrctl.sin_port=htons(7968);
    serverAddrctl.sin_addr.s_addr=inet_addr("127.0.1.1");
    addr_size=sizeof serverAddrctl;
    connect(clientSocketcontrol,(struct sockaddr *)&serverAddrctl,addr_size);

    cout<<"Please Login\nUsername : ";cin>>user;
    send(clientSocketcontrol, user, 20, 0);
    cout<<"Password :";cin>>pass;
    send(clientSocketcontrol, pass, 20, 0);

    recv(clientSocketcontrol,ack,1,0);
    bool islogin;
    if(ack[0]=='s'){
      	cout<<"Login Successful"<<endl;
      	islogin=true;
        clientSocketdata=socket(AF_INET,SOCK_STREAM,0);
        serverAddrdata.sin_family=AF_INET;
        serverAddrdata.sin_port=htons(8892);
        serverAddrdata.sin_addr.s_addr=inet_addr("127.0.1.1");
        addr_size=sizeof serverAddrdata;
        connect(clientSocketdata,(struct sockaddr *)&serverAddrdata,addr_size);
    }
    else{
    	cout<<"Login Failure"<<endl;
    	islogin=false;
    }

    while(islogin){
    	cout<<"ftp>>";cin>>cmd;
    	if(strcmp(cmd,"help")==0){
    		help();
    	}else if(strcmp(cmd,"ls")==0){
    		ls(cmd,clientSocketcontrol,clientSocketdata);
    	}else if(strcmp(cmd,"get")==0){
            get(cmd,clientSocketcontrol,clientSocketdata);
        }

    }

    return 0;
}
