#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>					// For memcpy()
#include <sys/socket.h>
#include <netinet/in.h>				// IPPROTO_ICMP
#include <netinet/ip.h>				// struct ip
#include <netinet/ip_icmp.h>		// stuct icmp
#include <arpa/inet.h>				// inet_ntoa, inet_addr
#include <stdlib.h>
#include <math.h>

using namespace std;

class IP
{
	struct ip ip;
	
	public:

	IP()
	{
		ip.ip_v = 0x4;
		ip.ip_tos = 0x0;
		ip.ip_sum = 0x0;
	}
	
	IP(char * src_addr, char * dst_addr)
	{
		ip.ip_v   = 0x4;
		ip.ip_tos = 0x0;
		ip.ip_sum = 0x0;
		ip.ip_src.s_addr = inet_addr(src_addr);
		ip.ip_dst.s_addr = inet_addr(dst_addr);
	}

	void set_header_len(int hl) 	{ ip.ip_hl = hl; }

	void set_len(int len) 			{ ip.ip_len = htons(len); }

	unsigned short get_len() 		{ return ntohs(ip.ip_len); }

	struct ip * get_addr() 			{ return &ip; }

	void set_id(int id) 			{ ip.ip_id = htons(id); }

	void set_offset(int offset) 	{ ip.ip_off = offset; }

	void set_ttl(int ttl) 			{ ip.ip_ttl = ttl; }

	void set_proto(int p) 			{ ip.ip_p = p; }

	void set_sum(unsigned short sum){ ip.ip_sum = sum; }
	
};

class ICMP
{
	struct icmp icmp;

	public:

	ICMP()
	{
		icmp.icmp_id = 1234;			// Any arbitrary unsigned int
		icmp.icmp_seq = 0;
		icmp.icmp_cksum = 0x0;
	}

	struct icmp * get_addr() 			{ return &icmp; }
	
	void set_type(unsigned int type) 	{ icmp.icmp_type = type; }

	unsigned int get_type() 			{ return icmp.icmp_type; }

	void set_code(unsigned int code) 	{ icmp.icmp_code = code; }

	void set_cksum(unsigned short sum) 	{ icmp.icmp_cksum = sum; }

};

/*
Function to calculate the checksum required for the
ip_sum and icmp_cksum fields.
The checksum is the one's complement of the one's
complement sum of all the 16 bit words in the header.
*/

unsigned short checksum(unsigned short *addr, int len)
{   
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;
    
    while (nleft > 1)
    {   
        sum += *w++;
        nleft -= 2;
    }
    
    if (nleft == 1)
    {   
        *(unsigned char *) (&answer) = *(unsigned char *) w;
        sum += answer;
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;
    return (answer);
}


//char* itoa(int num)
//{ 
//    /* log10(num) gives the number of digits; + 1 for the null terminator */
//    int size = log10(num) + 1;
//    char *x = malloc(size);
//    snprintf(x, size, "%d", num);
//    return x;
//}


int main(int argc, char * argv[])
{
	unsigned char * packet;
	int sd;
	const int on = 1;
	struct sockaddr_in sockaddr;
	char* src;
	char * dst;

	//src = argv[1];
	dst = argv[1];
	int ipn = 0;
	//********************************************
	while(true) {
		/*ipn = rand() % 256;
		src = "172.16.132.";
		char end[3];
		//end = int_to_str(ip);
		sprintf(end,"%d",ipn);
		//end = itoa(ip);
		strcat(src,end);
		*/
		
		int ipn;
	ipn = rand() % 256;
	string ss = "172.16.132.";
	char* src = new char[ss.size() + 1];
	copy(ss.begin(),ss.end(),src);
	src[ss.size()] = '\0';
	//src = ss.c_str();
	char end[3];
	//end = int_to_str(ip);
	sprintf(end,"%d",ipn);
	//end = itoa(ip);
	strcat(src,end);
	// IP header
	
	IP ip_pkt(src, dst);
	ip_pkt.set_header_len(0x5);
	ip_pkt.set_id(12830);
	ip_pkt.set_offset(0x0);
	ip_pkt.set_ttl(64);
	ip_pkt.set_len(60);
	ip_pkt.set_proto(IPPROTO_ICMP);
	ip_pkt.set_sum(checksum((u_short *)ip_pkt.get_addr(), sizeof(struct ip)));

	// ICMP header

	ICMP icmp_pkt;
	icmp_pkt.set_type(ICMP_ECHO);
	icmp_pkt.set_code(0);
	icmp_pkt.set_cksum(checksum((u_short *)icmp_pkt.get_addr(), 8));

	/*
	Allocate memory for the packet and copy
	the IP header first, then the ICMP header
	after an offset of 20 bytes.
	*/

	packet = (unsigned char *) malloc(ip_pkt.get_len());
	memcpy(packet, ip_pkt.get_addr(), sizeof(struct ip));
	memcpy(packet + 20, icmp_pkt.get_addr(), 8);

	/*
	Create a raw socket so that kernel doesn't interfere
	with the headers of the custom packet.
	*/

    if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0)
    {
        cout<<"Couldn't create raw socket"<<endl;
        exit(1);
    }
	
    if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0)
    {
        cout<<"setsockopt() failed"<<endl;
        exit(1);
    }

    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(dst);

	// Send the packet

	if(sendto(sd, packet, ip_pkt.get_len(), 0, (struct sockaddr *)&sockaddr,
					sizeof(struct sockaddr)) < 0)
	{
		cout<<"Packet couldn't be sent"<<endl;
		exit(1);
	}

	cout<<"Packet sent!"<<endl;

	}
	return 0;

}

/*
char* int_to_str(int a) {
	char s[10];
	int i;
	while(a!=0) {
		s[i++] = a%10;
		a /= 10;
	}
	s[i] = '\0';
	return s;		
}
*/


