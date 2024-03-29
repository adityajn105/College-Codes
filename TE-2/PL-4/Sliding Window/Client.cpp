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
using namespace std;
int main() {
    int clientSocket;
    char data[2],ack[3],ldata;
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
    int choice;
    cout<<"1. Go Back N\t2.Selective Repeat\tYour Choice  :";cin>>choice;
    if(choice==1) {
        int curr = 0;
        ldata = '\0';
        int lindex = -1;
        while (curr <= 21) {
            recv(clientSocket, data, 1, 0);
            if (data[0] == '0' && ldata != '0' && lindex == -1) {
            	ack[0] = '0'+curr%10;
            	ack[1] = '0'+curr/10;
            	send(clientSocket, ack, 2, 0);
                cout << "Packet Lost" << endl;
                ldata = '0';
                lindex = curr;
            }
            else if (ldata == '0' && data[0] == '0' && lindex != -1) {
                curr = lindex;
                ack[0] = '0'+(curr+1)%10;
            	ack[1] = '0'+(curr+1)/10;
            	send(clientSocket, ack, 2, 0);
                buffer[curr] = '0';
                cout << "Packet Recieved : Seq  " << curr + 1 << " | Data : 0" << endl;
                lindex = -1;
                ldata = '\0';
                curr++;
            }
            else if (lindex == -1) {
                ack[0] = '0'+(curr+1)%10;
            	ack[1] = '0'+(curr+1)/10;
            	send(clientSocket, ack, 2, 0);
                buffer[curr] = data[0];
                cout << "Packet Recieved : Seq  " << curr + 1 << " | Data : " << data[0] << endl;
                curr++;
            }
        }
        cout<<"Data Recieved is : "<<buffer;
    }
    else{
        int curr = 0;
        int lindex=-1;
        while (curr < 22) {
            recv(clientSocket, data, 2, 0);
            if (data[0] == '0') {
                ack[0] = '0'+curr%10;
                ack[1] = '0'+curr/10;
                send(clientSocket, ack, 3, 0);
                cout <<"Packet Lost" << endl;
                lindex=curr;
                curr++;
            }
            else if (data[0] == 'E' && lindex!=-1) {
                ack[0] = 'E';
                buffer[lindex] = '0'+0;
                cout <<"Packet Recieved : Seq  " << lindex + 1 << " | Data : "<<0<< endl;
                ack[1] = '0' + (lindex+1)%10;
                ack[2] = '0' + (lindex+1)/10;
                send(clientSocket, ack, 3, 0);
                lindex = -1;
            }
            else {
                ack[0] = '0' + (curr + 1)%10;
                ack[1] = '0' + (curr + 1)/10;
                buffer[curr] = data[0];
                cout <<"Packet Recieved : Seq  " << curr + 1 << " | Data : " << data[0] << endl;
                send(clientSocket, ack, 3, 0);
                curr++;
            }
        }
        cout<<"Data Recieved is : "<<buffer<<endl;
    }
    return 0;
}
