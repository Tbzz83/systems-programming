#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h> // for struct to store things
#include <unistd.h>

int main()
{
    // Create the socket FD save as int
    int client_socket;
    // AF_INET means 'address family: internet (IPv4)'
    // SOCK_STREAM indicates we're using TCP
    // '0' means use default protocol - TCP
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket. Exiting.\n");
        return 1;
    }

    // Specify an address for the socket
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    // htons converts port to appropriate data format
    server_address.sin_port = htons(9002); // Connect to port 9002 on server
    // htons = host to network short (converts to network byte order - Big Endian)
    // server_address.sin_addr is a struct with a specific 
    // field 's_addr'
    server_address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY = 0.0.0.0


    //int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    char client_message[] = "Hello from client";
    if (sendto(client_socket, client_message, sizeof(client_message), 0, (const struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        printf("sendto error.\n");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(client_socket);
    return 0;
    }
