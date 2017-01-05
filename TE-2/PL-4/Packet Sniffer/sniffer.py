from scapy.all import *
import multiprocessing

def pkt_callback(pkt):
	pkt.show()

def sniffer(filt,cnt):
	sniff(prn=pkt_callback,filter=filt,count=cnt)
	
if __name__ == "__main__":
	udp=multiprocessing.Process(target=sniffer,args=("udp",10))
	tcp=multiprocessing.Process(target=sniffer,args=("tcp",10))
	tcp.start()
	http=multiprocessing.Process(target=sniffer,args=("dst port 80",10))
	http.start()
	dns=multiprocessing.Process(target=sniffer,args=("dst port 53",10))
	dns.start()
	arp=multiprocessing.Process(target=sniffer,args=("arp",10))
	arp.start()
	arp=multiprocessing.Process(target=sniffer,args=("icmp",10))
	arp.start()
