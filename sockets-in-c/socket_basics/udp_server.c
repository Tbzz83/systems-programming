#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <netinet/in.h> // for struct to store things

int main()
{
    // Message to send back to client
    //char server_messages[256] = "You have reached the server!";

    int server_socket;

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket. Exiting.\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); // Listen on port 9002
    server_address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY = 0.0.0.0

    // Bind the socket to our specified IP and port
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) != 0) {
        printf("bind failed.\n");
        exit(errno);
    }

    char client_message[256];

    recvfrom(server_socket, client_message, sizeof(client_message), 0, NULL, NULL);

    printf("Client message: %s\n", client_message);

    close(server_socket);

    return 0;
}
