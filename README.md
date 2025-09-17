# Lab 2

## Team Members
- Jasmine Gau
- Jenny Lin

## Lab Question Answers
**Question 4: If you used LLMs for any part of this lab, explain how you used it.**
Google and ChatGPT were used to refine my answers for precision.

Answer for Question 1: 
When the 50% loss was added, approximately half of the messages sent from the UDP client never arrived at the server. This is because UDP has no connection and no guarantee. However, it lacks error checking, so it does not provide acknowledgements and retransmissions. If a packet is dropped in the network, UDP does not attempt to resend it, so lost packets are never recovered.

Question 2:
TCP still delivered all the packets correctly. TCP is a connection-oriented protocol that guarantees reliable delivery by retransmitting lost packets and maintaining ordering. If a packet is dropped, TCP retransmits it after detecting the loss (via missing acknowledgments or timeouts).

Question 3:
TCP became slower under packet loss. Retransmissions and congestion-control mechanisms introduced delays, reducing the overall speed.

1. What is argc and *argv[]?
argc: argument count, argv: argument vector (array of strings)

2. What is a UNIX file descriptor and file descriptor table?
UNIX file descriptor: a non-negative integer that uniquely identifies an open file (or socket) within a process. 
File descriptor table: a data structure maintained by the kernel that maps file descriptors to the corresponding open file descriptions.

3. What is a struct? What's the structure of sockaddr_in?
struct: user-defined data type used to group related vars that are diff types. 
sockaddr_in structure: specify an endpoint address for the socket and contains:
- sin_family: address family like AF_INET
- sin_port: port number 
- sin_addr: IP address 

4. What are the input parameters and return value of socket()
Inputs: 
- domain: communication domain 
- type: communication semantics
- protocol: protocol to be used with the socket 
Return value: a file descriptor for the new socket; -1 if error

5. What are the input parameters of bind() and listen()?
bind(): 
- sockfd: socket file descriptor
- &serv_addr: pointer to sockaddr structure
- sizeof(serv_addr): size of address structure
listen(): 
sockfd: socket file descriptor
backlog: max num of pending connections

6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
while(1) creates a loop to accept new client connections continuously
Problems: The server handles connections sequentially, so they will block other clients until itself disconnects. Therefore, other clients must wait and this might lead to bottleneck.

7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
fork(): creates a child process that is the same copy of the parent process. It can be applied here by calling fork() after accept() to create a child process for each client connection. The child will then handle the client communication while the parent continues accepting new connections, this enables concurrent handling of multiple clients.

8. This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
system call: a way for a program to request a service from the operating system's kernel. IT provides the interface between user-space applications and the kernel, which allows programs to perform operations that requires kernel to do so, like network communication and memory allocation.


