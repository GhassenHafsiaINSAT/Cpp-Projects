#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

int main()
{
// Creating the server socket , the file descriptor

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    /* 
        - AF_INET specifies the address family, IPv4 protocol family
        - SOCK_STREAM defines the type of socket, TCP type socket 
        - 0 specifies the protocol , o is the default protocol for the family address 
    */


// Defining Server Address

    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080); 
    serverAddress.sin_addr.s_addr  = INADDR_ANY; 

    /* 
        - sockaddr_in is a datatype used to store the address of a socket
        - htons() used to convert the unsigned int from machine byte order to network byte order
        - INADDR_ANY : make it listen to all available IPs 
    */



// Allocating a port number to a socket 

    bind(serverSocket, (struct sockaddr*)&serverAddress, 
            sizeof(serverAddress)); 

// Listening for connections, preparing the socket to accept incomming client connections

    listen(serverSocket, 5);

    /* 
        - 5 specifies the maximum number of pending connections that can be queued up before the server starts rejecting new connections.
    */

// Accepting a client connection

    int clientSocket = accept(serverSocket, nullptr, nullptr); 

// Receiving Data from the client

    char buffer[1024] = { 0 }; 
    recv(clientSocket, buffer, sizeof(buffer), 0); 
    std::cout <<"message from the client: " << buffer 
            << std::endl; 

// Closing the Server Socket
    close(serverSocket); 


}