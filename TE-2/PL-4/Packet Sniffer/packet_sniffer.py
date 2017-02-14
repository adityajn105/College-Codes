
#        By- Aditya Jain
#        Class - TE-1
#        Roll-no - 302029


from scapy.all import *
import os,sys
import threading

class Packet_Sniffer(threading.Thread):
	def __init__(self,filter,fname,core):
		threading.Thread.__init__(self)
		self.filter=filter
		self.fname=fname
		self.core=core

	def pkt_sniffer_callback(self,pkt):
		sys.stdout=open(self.fname,"w")
		pkt.show()

	def run(self):
		print "###### "+self.core+" ######"
		sniff(prn=self.pkt_sniffer_callback,filter=self.filter,count=2)

if __name__ == '__main__':
	dhcp= Packet_Sniffer("udp and portrange 67-68","DHCP","Core-1")
	dhcp.start()
	ftp = Packet_Sniffer("tcp and portrange 20-21","FTP","Core-2")
	ftp.start()
	smtp =Packet_Sniffer("tcp port 25","SMTP","Core-3")
	smtp.start()
	dns = Packet_Sniffer("udp port 53","DNS","Core-4")
	dns.start()
	telnet=Packet_Sniffer("tcp port 23","TELNET","Core-5")
	telnet.start()
	
