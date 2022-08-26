#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main() {

	//creating a socket and storing descriptor
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//having server address details in an inbuilt structure format
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//connecting socket with a server and ensuring connection
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if(connection_status == -1){
		printf("Connection failed\n");
		exit(0);
	}

	//storing server response and printing it
	char server_response[250];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	printf("Server sent : %s", server_response);

	//closing the socket
	close(network_socket);
	
	return 0;
}
