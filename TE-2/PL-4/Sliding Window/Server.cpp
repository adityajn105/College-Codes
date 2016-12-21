#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <string.h>

using namespace std;


int main() {
    int serverSocket, clientSocket;                 //two socket for server and client
    char buffer[1024];                              //data will be sent in buffer
    struct sockaddr_in serverAddr,clientAddr;      //structure representing server
    socklen_t addr_size;                            //address size of client

    serverSocket = socket(AF_INET,SOCK_STREAM,0); //domain,type,protocol

    //AF_INET - ip4 internet protocols
    //SOCK_STREAM - Provides sequenced, reliable, two-way, connection-based byte streams.
    //Default(0) - TCP in this case

    serverAddr.sin_family=AF_INET;  //sa_family_t
    serverAddr.sin_port =htons(7951); //in_port_t   //port to use for communications
    inet_aton("127.0.1.1", &serverAddr.sin_addr); //in_addr
    memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);   //memset- fill memory with constant byte
                                                                    //here fill serverAddr.sinzero with zeroes

    bind(serverSocket,(struct sockaddr *)&serverAddr, sizeof(serverAddr));  //bind the address struct to server socket

    listen(serverSocket,5);             //listen for max five connections

    clientSocket=accept(serverSocket,(struct sockaddr *)&clientAddr, &addr_size);   //accept connection
                                                                                    // and bind its address to clientAddr
    char *ip = inet_ntoa(clientAddr.sin_addr);
    cout<<"Connected to client@"<<ip<<endl;
    cout<<"Packet no to be send :";
    cin>>buffer;
    send(clientSocket,buffer,1024,0);       //send buffer to client(client,buffer,size,0)
    cout<<buffer<<" Sent";
    return 0;
}