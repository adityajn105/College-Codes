#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;


int main() {
    int serverSocket, clientSocket,WINDOW=4;                 //two socket for server and client
    char buffer[12];   //data will be sent in buffer
    char ack[1],data[1];
    struct sockaddr_in serverAddr,clientAddr;      //structure representing server
    socklen_t addr_size;                            //address size of client

    serverSocket = socket(AF_INET,SOCK_STREAM,0); //domain,type,protocol

    //AF_INET - ip4 Internet protocols
    //SOCK_STREAM - Provides sequenced, reliable, two-way, connection-based byte streams.
    //Default(0) - TCP in this case

    serverAddr.sin_family=AF_INET;  //sa_family_t
    serverAddr.sin_port =htons(7968); //in_port_t   //port to use for communications
    inet_aton("127.0.1.1", &serverAddr.sin_addr); //in_addr
    memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);   //memset- fill memory with constant byte
                                                                    //here fill serverAddr.sinzero with zeroes

    bind(serverSocket,(struct sockaddr *)&serverAddr, sizeof(serverAddr));  //bind the address struct to server socket

    listen(serverSocket,5);             //listen for max five connections

    clientSocket=accept(serverSocket,(struct sockaddr *)&clientAddr, &addr_size);   //accept connection
                                                                                    // and bind its address to clientAddr
    char *ip = inet_ntoa(clientAddr.sin_addr);
    cout<<"Connected to client@"<<ip<<endl;
    strcpy(buffer,"baca059d0bc");
    int len =strlen(buffer);
    int curr=0;int acurr=0;
    while(acurr<=len-1 || curr<=len-1) {
        if (acurr < len) {
            data[0] = buffer[acurr];
            send(clientSocket, data, 1, 0);
            cout << "Packet Sent : Seq - " << acurr+1 << " |  Data - " << data[0] << endl;
            acurr++;
        }
        if(acurr-curr==WINDOW || acurr>=len-4){
            recv(clientSocket,ack,1,0);
            cout<<"Ack- "<<ack[0]<<endl;
            int ak=ack[0]-'0';
            if(curr==ak){
                acurr=curr;
            }
            if(curr!=ak){
                curr=ak;
            }
        }
    }
    return 0;
}
