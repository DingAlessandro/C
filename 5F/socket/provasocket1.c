//SERVER
#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi 
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define DIM 50
#define SERVERPORT 1313

int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    // definizione dei dati del socket p.161
    //valorizazione della struttura
    servizio.sin_family=AF_INET; //sempre assegnato a AF_INET metodo di indirizzameto
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //indirizzo htonl converte l'indirizzo in 32 bit
    servizio.sin_port=htons(SERVERPORT); //numero di porta htons converte la porta in 16 bit
    int socketfd, soa, fromlen=sizeof(servizio); 
    char str[DIM];
    // impostazione del transport endpoint del server p.163-164
    socketfd=socket(AF_INET,SOCK_STREAM,0); //se la connession avviene con successo la scocketfd assumera un valore maggiore di 1 se non assumera -1
    // leghiamo l'indirizzo al transport endpoint p. 164
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)); //associa un ip locale alla socket facoltativo nel client il sistema operativo terra conto dei processi
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// può attendere fino a 10 client
    // ciclo infinito
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);//pulisce il canale socket
        //il server accetta la connessione pag. 165
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen); //server accetta la connesione
        //legge dal client
        read(soa,str,sizeof(str));
        printf("Stringa ricevuta: %s\n",str);
        close(soa);
    }
   return 0;   
}