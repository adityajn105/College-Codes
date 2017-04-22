import socket
import os

def main():
	server=socket.socket();
	server.bind(("127.0.0.1",12335))
	server.listen(5)
	client,addr=server.accept()
	print("Client Connected :{}".format(addr))
	ls = os.listdir('server_data/')
	client.send("\n".join(ls))
	fname = client.recv(1024)

	content = open("server_data/{}".format(fname))
	client.send(content.read())

	client.close()

if __name__ == '__main__':
	main()