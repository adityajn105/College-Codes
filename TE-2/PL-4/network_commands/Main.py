from __future__ import print_function
from subprocess import call

def ping():
	ip = raw_input("Enter IP address: ")
	call(["ping", ip, "-c", "4"])

def ssh():
	username = raw_input("Enter username: ")
	ip 		= raw_input("Enter IP: ")
	call(["ssh", username+"@"+ip])

def netstat():
	call(["netstat"])

def traceroute():
	url = raw_input("Enter URL: ")
	call(["traceroute", url])	

def ifup():
	iface = raw_input("Enter interface: ")
	call(["ifup", iface])

def ifdown():
	iface = raw_input("Enter interface: ")
	call(["ifdown", iface])

def finger():
	username = raw_input("Enter username: ")
	call(["finger", username])


def main():

	commands = { '1': ping, '2': ssh, '3': netstat, '4': traceroute, '5': ifup, '6': ifdown, '7': finger }
	while True:

		ch = raw_input('''
1.ping
2.ssh
3.netstat
4.traceroute
5.ifup
6.ifdown
7.finger
> ''')

		if ch == 'q':
			break
		elif int(ch) < 7 and int(ch) > 0:
			commands[ch]()
		else:
			break
	

if __name__ == '__main__':
	main()