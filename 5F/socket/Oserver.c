#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int OC(char str[DIM], char c) {
    int n = 0;
    for(int i = 0; i < strlen(str); i++) 
    {
        if(tolower(str[i]) == tolower(c)) {
            n++;
        }
    }
    return n;
}


int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM], c;
    int n = 0;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    for (; ;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        
        read(soa,str,sizeof(str));
        read(soa,&c,sizeof(c));
        n = OC(str, c);
        write(soa, &n, sizeof(n));
        close(soa);

     }
      
   return 0;
    
}