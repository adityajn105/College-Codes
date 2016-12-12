#include <iostream>
#include <string>
#include <crafter.h>

using namespace std;
using namespace Crafter;

int main() {
	string iface = "eth0";
	
	string MyIP = GetMyIP(iface);
	string DstIP = "172.16.132.134";
	
	cout << "My IP " << MyIP << endl;
	
	Ethernet etherHeader;
	
	etherHeader.SetDestinationMAC(GetMAC(DstIP, iface));
	etherHeader.SetSourceMAC(GetMyMAC(iface));
	
	IP ipHeader;
	
	ipHeader.SetSourceIP(MyIP);
	ipHeader.SetDestinationIP(DstIP);
	
	TCP tcpHeader;
	
	tcpHeader.SetSrcPort(10000);
	tcpHeader.SetDstPort(RNG16());
	
	tcpHeader.SetFlags(TCP::SYN | TCP::CWR | TCP::ECE);
	
	RawLayer rawHeader;
	rawHeader.SetPayload("Some TCP Payload\n");
	
	Packet packet = etherHeader / ipHeader / tcpHeader / rawHeader;
	
	cout << endl << "Before Sending" << endl;
	packet.Print();
	
	packet.Send(iface);
	
	cout << "--------------------------------------" << endl;
	cout << "After Sending" << endl;
	packet.Print();
	
	return 0;
}
