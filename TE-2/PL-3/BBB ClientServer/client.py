import socket

def main():
	client = socket.socket()
	client.connect(("127.0.0.1",12335))
	print("Connection Established to {}".format("127.0.0.1"))
	
	fole=client.recv(1024)
	data = fole.split("\n")
	for i,v in enumerate(data):
		print("{} : {}".format(i,v))
	inp=int(input("enter file no to get"))
	client.send(data[inp])

	fname= open(data[inp],"w")
	content = client.recv(1024)

	fname.write(content)
	client.close()



if __name__ == '__main__':
	main()