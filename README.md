# Lab 2

## Team Members
- team member 1
- team member 2

## Lab Question Answers

Answer for Question 1: 
When the 50% loss was added, approximately half of the messages sent from the UDP client never arrived at the server. This is because UDP is connectionless, best-effort protocol. It does not provide acknowledgments, retransmissions, or error correction. If a packet is dropped in the network, UDP does not attempt to resend it, so lost packets are never recovered.

Question 2:
TCP still delivered all the packets correctly. TCP is a connection-oriented protocol that guarantees reliable delivery by retransmitting lost packets and maintaining ordering. If a packet is dropped, TCP retransmits it after detecting the loss (via missing acknowledgments or timeouts).

Question 3:
TCP became slower under packet loss. Retransmissions and congestion-control mechanisms introduced delays, reducing overall speed.

...
...