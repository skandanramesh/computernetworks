#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

int main() {

	//creating a server socket and storing descriptor
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//having server address details in an inbuilt structure format and binding them
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	//listen for connections with atmost 5 sockets in queue
	listen(server_socket, 5);

	//accept a connection and store descriptor
	int client_socket = accept(server_socket, NULL, NULL);

	//send a message to the client socket
	char server_message[256] = "You've reached the server\n";	
	send(client_socket, server_message, sizeof(server_message), 0);

	//close the server socket
	close(server_socket);

	return 0;
}
