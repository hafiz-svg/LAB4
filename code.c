<<<<<<< HEAD
#include <stdio.h>
#include <string.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>
int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char message[1000] , server_reply[1000];
=======
#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write

int main(int argc , char *argv[])
{
	int socket_desc , new_socket , c;
	struct sockaddr_in server , client;
	char message[1000],client_msg[1000];
>>>>>>> commit
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
<<<<<<< HEAD
		
	server.sin_addr.s_addr = inet_addr("192.168.56.105");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("Connected\n");

	while(1){	
	// Client  message
	printf("Client: ");
        bzero(message,1000);
        fgets(message,1000,stdin);	

	//Send some data
	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	
	//Receive a reply from the server
	if( recv(socket_desc, server_reply , 1000 , 0) < 0)
	{
		puts("recv failed");
	}
	printf("Server Reply: %s \n",server_reply);
	}
	close(socket_desc);	
=======
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("bind failed");
		return 1;
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 5);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
	{
		puts("Connection accepted");
		int n;
		//recieve msg from client
		while((n=recv(new_socket, client_msg,1000,0))>0){
		printf("Client: %s",client_msg);
		bzero(client_msg,1000);
		//Reply to the client
		printf("Server :\n");
		bzero(message,1000);
		fgets( message,1000,stdin);
		send(new_socket , message , strlen(message),0);}
	}
	
	if (new_socket<0)
	{
		perror("accept failed");
		return 1;
	}
	
	close(new_socket);
>>>>>>> commit
	return 0;
}
