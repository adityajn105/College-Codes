all : Server Client

Server : shm_server.c
	gcc shm_server.c -o Server

Client : shm_client.c
	gcc shm_client.c -o Client

clean : 
	rm -f Server Client
	
