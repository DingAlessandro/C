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

void CandV(char str1[DIM]) {
    char t;
    for(int i=0; i<strlen(str1); i++) {
        for(int j=0; j<strlen(str1) - 1; j++) {
            if(str1[j] < str1[j+1]) 
            {
                t=str1[j];
                str1[j]=str1[j+1];
                str1[j+1]=t;
            }
        }
    }
}
 
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM], str1[DIM];
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
        
        printf("Stringa ricevuta: %s\n",str);
        strcpy(str1, str);
        CandV(str1);
        write(soa, str1, sizeof(str1));
        
        close(soa);

     }
      
   return 0;
    
}