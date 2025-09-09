"""
Server receiver buffer is char[256]
If correct, the server will send a message back to you saying "I got your message"
Write your socket client code here in python
Establish a socket connection -> send a short message -> get a message back -> ternimate
use python "input->" function, enter a line of a few letters, such as "abcd"
"""
import socket

def main():
    HOST = 'localhost'
    PORT = 8888
    
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        client_socket.connect((HOST, PORT))
        print(f"Connected to server at {HOST}:{PORT}")
        
        message = input("Enter a message to send to the server: ")
        
        client_socket.send(message.encode('utf-8'))
        
        response = client_socket.recv(256)
        print(f"Server response: {response.decode('utf-8')}")
        
    except ConnectionRefusedError:
        print(f"Could not connect to server at {HOST}:{PORT}")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        client_socket.close()
        print("Connection closed")


if __name__ == '__main__':
    main()