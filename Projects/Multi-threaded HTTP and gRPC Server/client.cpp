#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

int main()
{
    int socketClient = socket(AF_INET, SOCK_STREAM, 0); 

    sockaddr_in clientAddress; 
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(8080);
    clientAddress.sin_addr.s_addr = INADDR_ANY; 

    connect(socketClient, (struct sockaddr*)&clientAddress, 
            sizeof(clientAddress)) ; 

    const char* message = "Hello, server!"; 
    send(socketClient, message, strlen(message), 0); 

    close(socketClient); 

    return 0;


}