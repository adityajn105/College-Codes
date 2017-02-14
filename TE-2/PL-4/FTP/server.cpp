/*
	By- Aditya Jain
	Class - TE-1
	Roll-no - 302029
*/

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void ls(int clientSocketData){
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char buff[100];
    mydir = opendir(".");
    while((myfile = readdir(mydir)) != NULL){
        stat(myfile->d_name, &mystat);
        strcpy(buff,myfile->d_name);
        send(clientSocketData,buff,100,0);
    }
    strcpy(buff,"\0");
    send(clientSocketData,buff,100,0);
    closedir(mydir);
}

void pwd(int cd){
	char buff[100];
	char *path=NULL;
	size_t size;
	path=getcwd(path,size);
	strcpy(buff,path);
	send(cd,buff,100,0);
}

void put(int cc,int cd){
	char file[20];
    recv(cc,file,20,0);
    ofstream outfile;
    outfile.open(file);
    char buffer[1024];
    bool dat=false;
    recv(cd,buffer,1024,0);
    while(strcmp(buffer,"eof")!=0){
    	dat=true;
    	outfile<<buffer<<"\n";
    	recv(cd,buffer,1024,0);
    }
    outfile.close();
}

void get(int cc,int cd){
    char file[20];
    recv(cc,file,20,0);
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char buff[20];
    mydir = opendir(".");
    bool done=false;
    char buffer[1024];
    while((myfile = readdir(mydir)) != NULL){
        stat(myfile->d_name, &mystat);
        strcpy(buff,myfile->d_name);
        if(strcmp(buff,file)==0){
            done=true;
            ifstream fileBuffer(buff, ios::in);
            if (fileBuffer.is_open())
            {
                int i=0;
                while(!fileBuffer.eof()){
                    fileBuffer.getline(buffer, 1024);
                    send(cd,buffer,1024,0);
                }
            }
            break;
        }
    }
    strcpy(buffer,"eof");
    send(cd,buffer,1024,0);
}

void cat(int cc,int cd){
    char file[20];
    recv(cc,file,20,0);
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char buff[20];
    mydir = opendir(".");
    bool done=false;
    char buffer[1024];
    while((myfile = readdir(mydir)) != NULL){
        stat(myfile->d_name, &mystat);
        strcpy(buff,myfile->d_name);
        if(strcmp(buff,file)==0){
            done=true;
            ifstream fileBuffer(buff, ios::in);
            if (fileBuffer.is_open())
            {
                int i=0;
                while(!fileBuffer.eof()){
                    fileBuffer.getline(buffer, 1024);
                    send(cd,buffer,1024,0);
                }
            }
            break;
        }
    }
    strcpy(buffer,"eof");
    send(cd,buffer,1024,0);
}

int main() {
    socklen_t addr_size;
    char user[20];
    char pass[20];
    char cmd[10];

    //for control info
    int serverSocketcontrol, clientSocketcontrol;
    struct sockaddr_in serverAddrctl,clientAddrctl;
    serverSocketcontrol = socket(AF_INET,SOCK_STREAM,0);
    serverAddrctl.sin_family=AF_INET;  //sa_family_t
    serverAddrctl.sin_port =htons(7967); //in_port_t   //port to use for communications
    inet_aton("127.0.1.1", &serverAddrctl.sin_addr); //in_addr
    bind(serverSocketcontrol,(struct sockaddr *)&serverAddrctl, sizeof(serverAddrctl));  //bind the address struct to server socket
    listen(serverSocketcontrol,1);             //listen for max five connections
    clientSocketcontrol=accept(serverSocketcontrol,(struct sockaddr *)&clientAddrctl, &addr_size);

    //for data info
    int serverSocketdata,clientSocketdata;
    struct sockaddr_in serverAddrdata,clientAddrdata;


    char *ip = inet_ntoa(clientAddrctl.sin_addr);
    cout<<"Control info port with client@"<<ip<<endl;

    recv(clientSocketcontrol, user, 20, 0);
    recv(clientSocketcontrol,pass,20,0);
    bool loggedin;
    if(strcmp(user,"admin")==0 && strcmp(pass,"admin")==0) {
        send(clientSocketcontrol, "s", 1, 0);
        loggedin = true;
        struct sockaddr_in serverAddrdata, clientAddrdata;
        serverSocketdata = socket(AF_INET, SOCK_STREAM, 0);
        serverAddrdata.sin_family = AF_INET;  //sa_family_t
        serverAddrdata.sin_port = htons(8891); //in_port_t   //port to use for communications
        inet_aton("127.0.1.1", &serverAddrdata.sin_addr); //in_addr
        bind(serverSocketdata, (struct sockaddr *) &serverAddrdata,
             sizeof(serverAddrdata));  //bind the address struct to server socket
        listen(serverSocketdata, 5);             //listen for max five connections
        clientSocketdata = accept(serverSocketdata, (struct sockaddr *) &clientAddrdata, &addr_size);
        char *ip = inet_ntoa(clientAddrdata.sin_addr);
        cout << "Data port with client@" << ip << endl;
    }
    else{
    	send(clientSocketcontrol,"f",1,0);
    	loggedin=false;
    }

    while(loggedin){
    	recv(clientSocketcontrol,cmd,10,0);
    	if(strcmp(cmd,"ls")==0){
    		ls(clientSocketdata);
    	}else if(strcmp(cmd,"get")==0){
        	get(clientSocketcontrol,clientSocketdata);
        }else if(strcmp(cmd,"pwd")==0){
        	pwd(clientSocketdata);
        }else if(strcmp(cmd,"cat")==0){
        	cat(clientSocketcontrol,clientSocketdata);
        }else if(strcmp(cmd,"put")==0){
        	put(clientSocketcontrol,clientSocketdata);
        }
    }

    return 0;
}
