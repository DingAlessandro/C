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

void CandV(char str[DIM], int num[2]) {
    num[0] = 0;  
    num[1] = 0;  

    for (int i = 0; i < strlen(str); i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || 
            tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || 
            tolower(str[i]) == 'u') {
            num[0]++;  
        } else if (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') {
            num[1]++; 
        }
    }
}
 
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    int num[2];
    char str[DIM];
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
        
        CandV(str, num);
        write(soa, num, sizeof(num));
        
        close(soa);

     }
      
   return 0;
    
}