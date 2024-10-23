#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main(int argc,char** argv)
{
       
    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM];
    int num;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    printf("Inserisci la stringa\n");
    scanf("%s",str1);
    write(socketfd,str1,sizeof(str1));
    read(socketfd,num,sizeof(num));
    if(num == 0)
    {
        printf("la stringa è palidroma\n");
    }else
    {
        printf("la stringa non è palidroma\n");
    }
    close(socketfd);
    return 0;
}




