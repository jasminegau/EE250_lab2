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

Question 4: What are the input parameters and return value of socket()
The input parameters of socket() are:
- **domain:** Specifies the communication domain 
- **type:** Specifies the communication semantics 
- **protocol:** Specifies a particular protocol to be used with the socket
The **return value is a file descriptor** for the new socket, or -1 on error.

Question 5: What are the input parameters of bind() and listen()?
**bind() parameters:** socket file descriptor, pointer to sockaddr structure, size of address structure
**listen() parameters:** socket file descriptor, backlog (An integer that defines the maximum length for the queue of pending connections)

Question 6:
Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
while(1) creates an infinite loop to accept new client connections continuously. During multiple simultaneous connections, the server handles connections sequentially, thus blocking on each client until it disconnects. This means other clients must wait which will create a bottleneck and poor performance under load.

Question 7: Research how the command fork() works. How can it be applied here to better handle multiple connections?
**fork()** creates a child process that is an exact copy of the parent process. This can be applied here by calling **fork()** after **accept()**, which creates a child process for each client connection. The child handles the client communication while the parent continues accepting new connections, enabling concurrent handling of multiple clients.

Question 8: This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
**A system call** is a programmatic way for a program to request a service from the operating system's kernel. System calls will provide the interface between user-space applications and the kernel, allowing programs to perform operations like file I/O, network communication, process management, and memory allocation that require kernel privileges.


