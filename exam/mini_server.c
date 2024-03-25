#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client {
  int id; // The unique ID of the client
  char msg[1024]; // The message buffer of the client
} t_client;

t_client clients[1024]; // Declare an array to hold all clients
fd_set read_set, write_set, current; // Declare file descriptor sets for select function
int maxfd, gid = 0; // Declare the maximum file descriptor number and a global id for clients
char send_buffer[200000], recv_buffer[200040]; // Declare buffers for sending and receiving data

// Error handling function
void err(char *msg) {
  if (msg) // If a message is provided
	write(2, msg, strlen(msg)); // Write the message to stderr
  else // If no message is provided
	write(2, "Fatal error", 11); // Write "Fatal error" to stderr
  write(2, "\n", 1); // Write a newline to stderr
  exit(1); // Exit the program with status code 1
}

// Function to send a message to all clients except one
void send_to_all(int except) {
  for (int fd = 0; fd <= maxfd; fd++) // Iterate over all file descriptors
	if (FD_ISSET(fd, &write_set) && fd != except) // If fd is in the write set and is not the exception
	  if (send(fd, send_buffer, strlen(send_buffer), 0) == -1) // Send the message in send_buffer to fd
		err(NULL); // If send fails, handle error
}

int main(int ac, char **av) {
  if (ac != 2) // If the number of arguments is not 2
	err("Wrong number of arguments"); // Handle error

  struct sockaddr_in servaddr; // Structure to store server address
  int servfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket and get its file descriptor
  if (servfd == -1) err(NULL); // If socket creation fails, handle error
  maxfd = servfd; // Set maxfd to servfd
  FD_ZERO(&current); // Clear the current set
  FD_SET(servfd, &current); // Add servfd to the current set

  bzero(clients, sizeof(clients)); // Initialize clients array to zero
  bzero(&servaddr, sizeof(servaddr)); // Initialize servaddr structure to zero

  servaddr.sin_family = AF_INET; // Set address family to AF_INET
  servaddr.sin_addr.s_addr = htonl(2130706433); // Set IP address to 127.0.0.1
  servaddr.sin_port = htons(atoi(av[1])); // Set port number to the first argument

  // Bind the socket to the server address and listen for connections
  if (bind(servfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) == -1 || listen(servfd, 100) == -1)
	err(NULL); // If bind or listen fails, handle error

  // Main loop
  while (1) {
	read_set = write_set = current; // Set read_set and write_set to current
	if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
	  continue; // Wait for activity on any file descriptor

	// Iterate over all file descriptors
	for (int fd = 0; fd <= maxfd; fd++) {

	  // If fd is in the read set
	  if (FD_ISSET(fd, &read_set)) {

		// If fd is servfd (a new connection is incoming)
		if (fd == servfd) {
		  // Accept the new connection
		  int clientfd = accept(servfd, NULL, NULL);
		  if (clientfd == -1) continue; // If accept fails, continue to the next iteration
		  if (clientfd > maxfd) maxfd = clientfd; // If clientfd is greater than maxfd, update maxfd
		  clients[clientfd].id = gid++; // Assign new client a unique ID
		  FD_SET(clientfd, &current); // Add clientfd to the current set
		  sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id); // Prepare welcome message
		  send_to_all(clientfd); // Send welcome message
		  break;

		  // If fd is not servfd (a client is sending data)
		} else {
		  int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0); // Receive data from fd
		  // If recv fails or the client has closed the connection
		  if (ret <= 0) {
			sprintf(send_buffer, "server: client %d just left\n", clients[fd].id); // Prepare farewell message
			send_to_all(fd); // Send farewell message
			FD_CLR(fd, &current); // Remove fd from current set
			close(fd); // Close connection

			// If data is received
		  } else {
			// Iterate over received data
			for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++) {
			  clients[fd].msg[j] = recv_buffer[i]; // Append  received data to client's message buffer
			  // If a newline character is found (a complete message is received)
			  if (clients[fd].msg[j] == '\n') {
				clients[fd].msg[j] = '\0'; // Null-terminate the message
				sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg); // Prepare the message
				send_to_all(fd); // Send message
				bzero(clients[fd].msg, strlen(clients[fd].msg)); // Clear the client's message buffer
				j = -1; // Reset j
			  }
			}
			bzero(clients[fd].msg, strlen(clients[fd].msg)); // Clear the client's message buffer
			break;
		  }
		}
	  }
	}
  }
}
