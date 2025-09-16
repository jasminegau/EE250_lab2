/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     * argc is the argument count, and argv is the argument vector (array of strings).
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     * A UNIX file descriptor is a non-negative integer that uniquely identifies an open file (or socket) within a process. The file descriptor table is a data structure maintained by the kernel that maps file descriptors to their corresponding open file descriptions.
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     * A struct is a user-defined data type in C that allows the grouping of related variables of different types. The sockaddr_in structure is used to specify an endpoint address for the socket and contains the following members:
     * - sin_family: Address family (e.g., AF_INET for IPv4)
     * - sin_port: Port number (in network byte order)
     * - sin_addr: IP address (in network byte order)
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     * The input parameters of socket() are:
     * - domain: Specifies the communication domain (e.g., AF_INET for IPv4)
     * - type: Specifies the communication semantics (e.g., SOCK_STREAM for TCP)
     * - protocol: Specifies a particular protocol to be used with the socket (0 for default)
     * The return value is a file descriptor for the new socket, or -1 on error
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     * bind() parameters: socket file descriptor, pointer to sockaddr structure, size of address structure
     * listen() parameters: socket file descriptor, backlog (maximum number of pending connections)
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        * while(1) creates an infinite loop to continuously accept new client connections. 
        * Problems with multiple simultaneous connections: The server handles connections sequentially, blocking on each client until it disconnects. This means other clients must wait, creating a bottleneck and poor performance under load.
        *
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * fork() creates a child process that is an exact copy of the parent process. It can be applied here by calling fork() after accept() to create a child process for each client connection. The child handles the client communication while the parent continues accepting new connections, enabling concurrent handling of multiple clients.
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        //printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 * A system call is a programmatic way for a program to request a service from the operating system's kernel. System calls provide the interface between user-space applications and the kernel, allowing programs to perform operations like file I/O, network communication, process management, and memory allocation that require kernel privileges.
 */