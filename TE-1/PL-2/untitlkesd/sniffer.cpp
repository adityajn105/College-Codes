#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <time.h>

int main(int argc, char **argv) {
	int i;
	pcap_t* descr;
	const u_char* packet;
	u_char* ptr;
	struct pcap_pkthdr hdr;
	struct ether_header *eptr;
	char errbuf[PCAP_ERRBUF_SIZE];
	
	char *dev;
	char *net;
	char *mask;
	int ret;	// ret code
	
	bpf_u_int32 netp;
	bpf_u_int32 maskp;
	struct in_addr addr;
	
	dev = "eth0";
	
	if (dev == NULL) {
		printf("%s\n", errbuf);
		exit(1);
	}
	
	printf("DEV: %s\n", dev);
	
	/* Open device for sniffing
	pcap_t* pcap_open_live(char* device, int snaplen, int prmisc, int to_ms, char* ebuf)
	*/
	
	descr = pcap_open_live(dev, BUFSIZ, 0, 1500, errbuf);
	
	if (descr == NULL) {
		printf("pcap_open_live(): %s\n", errbuf);
		exit(1);
	}
	
	packet = pcap_next(descr, &hdr);
	
	if(packet == NULL) {
		printf("Didn't grab\n");	
		exit(1);
	}
	
	printf("Grabbed packet of length %d\n",hdr.len);
    printf("Recieved at ..... %s\n",ctime((const time_t*)&hdr.ts.tv_sec)); 
    printf("Ethernet address length is %d\n",ETHER_HDR_LEN);
	
	eptr = (struct ether_header*) packet;
	
	if (ntohs (eptr->ether_type) == ETHERTYPE_IP) {
		printf("Ethernet type hex:%x dec:%d is an IP packet\n",
                ntohs(eptr->ether_type),
                ntohs(eptr->ether_type));
    }else  if (ntohs (eptr->ether_type) == ETHERTYPE_ARP)
    {
        printf("Ethernet type hex:%x dec:%d is an ARP packet\n",
                ntohs(eptr->ether_type),
                ntohs(eptr->ether_type));
    }else {
        printf("Ethernet type %x not IP", ntohs(eptr->ether_type));
        exit(1);
    }
    
    ptr = eptr->ether_dhost;
    i = ETHER_ADDR_LEN;
    printf("Destination Address: ");
    
    do {
     	printf("%s%x",(i == ETHER_ADDR_LEN) ? " " : ":",*ptr++);
    }while(--i>0);
    printf("\n");
    
    
    ptr = eptr->ether_shost;
    i = ETHER_ADDR_LEN;
    printf(" Source Address:  ");
    do{
        printf("%s%x",(i == ETHER_ADDR_LEN) ? " " : ":",*ptr++);
    }while(--i>0);
    printf("\n");
	
	
	/*
	
	ret = pcap_lookupnet(dev, &netp, &maskp, errbuf);
	
	if (ret == -1) {
		printf("%s\n", errbuf);
		exit(1);
	}
	
	addr.s_addr = netp;
	net = inet_ntoa(addr);
	
	printf("NET: %s\n", net);
	
	addr.s_addr = maskp;
	mask = inet_ntoa(addr);
	
	printf("MASK: %s\n", mask);
	
*/
	return 0;
	
}
