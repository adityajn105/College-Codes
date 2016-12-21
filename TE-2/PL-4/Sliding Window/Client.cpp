#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;
int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket=socket(AF_INET,SOCK_STREAM,0);     //create client socket

    serverAddr.sin_family=AF_INET;                  //address family
    serverAddr.sin_port=htons(7951);                //port in network
    serverAddr.sin_addr.s_addr=inet_addr("127.0.1.1");  //internet address
    memset(serverAddr.sin_zero, '\0',sizeof serverAddr.sin_zero);   //overwrite sinzero with zeroes

    addr_size=sizeof serverAddr;
    connect(clientSocket,(struct sockaddr *)&serverAddr,addr_size); //connect to server
    recv(clientSocket,buffer,1024,0);       //receive data in buffer

    cout<<"Packet No received is"<<buffer;

    return 0;
}