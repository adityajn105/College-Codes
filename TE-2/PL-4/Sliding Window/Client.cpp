#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
using namespace std;
int main() {
    int clientSocket;
    char data[1],ack[1],ldata;
    char buffer[1024];
    
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    clientSocket=socket(AF_INET,SOCK_STREAM,0);     //create client socket

    serverAddr.sin_family=AF_INET;                  //address family
    serverAddr.sin_port=htons(7968);                //port in network
    serverAddr.sin_addr.s_addr=inet_addr("127.0.1.1");  //internet address
    memset(serverAddr.sin_zero, '\0',sizeof serverAddr.sin_zero);   //overwrite sinzero with zeroes
    addr_size=sizeof serverAddr;
    connect(clientSocket,(struct sockaddr *)&serverAddr,addr_size); //connect to server
    int curr=0;
    ldata ='\0';
    int lindex=-1;
    while(curr<=10){
        recv(clientSocket,data,1,0);
        if(data[0]=='0' && ldata!='0' && lindex==-1){
            ack[0]='0'+curr;
            ldata='0';
            send(clientSocket,ack,1,0);
            cout<<"Packet Lost"<<endl;
            lindex=curr;
        }
        else if(ldata=='0' && data[0]=='0' && lindex!=-1 ){
            curr=lindex;
            ack[0]='0'+(curr+1);
            ldata='\0';
            buffer[curr]='0';
            cout << "Packet Recieved : Seq  " << curr+1 << " | Data : 0"<<endl;
            send(clientSocket,ack,1,0);
            lindex=-1;
            curr++;
        }
        else if(lindex==-1){
            ack[0]='0'+(curr+1);
            buffer[curr]=data[0];
            cout << "Packet Recieved : Seq  " << curr+1 << " | Data : " << data[0]<<endl;
            send(clientSocket,ack,1,0);
            curr++;
        }
    }
    return 0;
}