#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//thread POSIX(LINUX)
void* stampaGiorno(void* par)
{
    //printf("buongiorno\n");
    printf("%s\n", (char*)par);
    return (void*)0;
}
void* stampaSera(void* par)
{
    printf("buonasera\n");
}
void* stampaNotte(void* par)
{
    printf("buonanotte\n");
}
int main() //compilando con gcc si usa anche -lpthread
{
    pthread_t threadGiorno, threadSera, threadNotte;
    char* msg1 ="buongiorno";
    printf("ciao\n");
    pthread_create(&threadGiorno, NULL, &stampaGiorno, msg1); // indirizzo thread, null, indirizzo della funzione con le istruzioni
    pthread_create(&threadSera, NULL, &stampaSera, NULL); 
    pthread_create(&threadNotte, NULL, &stampaNotte, NULL); 
    pthread_join(threadGiorno, NULL);
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);
    // printf("buongiorno\n");
    //printf("buonasera\n");
    //printf("buonanote\n");
    return 0;
}