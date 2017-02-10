from scapy.all import *
import os,sys
import threading

class Packet_Sniffer(threading.Thread):
	def __init__(self,filter,fname):
		threading.Thread.__init__(self)
		self.filter=filter
		self.fname=fname

	def pkt_sniffer_callback(self,pkt):
		sys.stdout=open(self.fname,"w")
		pkt.show()

	def run(self):
		sniff(prn=self.pkt_sniffer_callback,filter=self.filter,count=5)

if __name__ == '__main__':
	dhcp= Packet_Sniffer("udp and portrange 67-68","DHCP")
	dhcp.start()
	ftp = Packet_Sniffer("tcp and portrange 20-21","FTP")
	ftp.start()
	smtp =Packet_Sniffer("tcp port 25","SMTP")
	smtp.start()
	dns = Packet_Sniffer("udp port 53","DNS")
	dns.start()
	telnet=Packet_Sniffer("tcp port 23","TELNET")
	telnet.start()
	
