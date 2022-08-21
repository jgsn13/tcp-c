#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void clientServerChat(int connfd) {
    char buff[MAX];
    int n;

    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));

        // print buffer which contains the the client contents
        printf("From client: %s\t To client: ", buff);
        bzero(buff, MAX);
        n = 0;

        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;
        // and send that buffer to client
        write(connfd, buff, sizeof(buff));

        // if msg contains "Exit" then the server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server exit...\n");
            break;
        }
    }
}

int main() { return 0; }
