#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h> // for struct to store things

int main()
{
  // Create the socket FD save as int
  int client_socket;
  // AF_INET means 'address family: internet (IPv4)'
  // SOCK_STREAM indicates we're using TCP
  // '0' means use default protocol - TCP
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    printf("Error creating socket. Exiting.\n");
    return 1;
  }

  // Specify an address for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  // htons converts port to appropriate data format
  server_address.sin_port = htons(9002); // Listen on port 9002
  // server_address.sin_addr is a struct with a specific 
  // field 's_addr'
  server_address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY = 0.0.0.0
  
  int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  // check for connection error
  if (connection_status == -1) {
    printf("Error creating connection. Exiting.\n");
  }
  
  // Buffer for response
  char server_response[256];
  // Get response                                               optional flags
  recv(client_socket, &server_response, sizeof(server_response), 0);

  printf("\nresponse:%s\n", server_response);

  // Close the socket
  close(client_socket);
  return 0;
}
