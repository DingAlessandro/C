#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *functionCiao(void *ptr)
{
    char *nome = (char *)ptr;
    printf("ciao %s\n", nome);
    pthread_exit(NULL);
}
int main()
{
    char nome[30];
    printf("inserisci il nome\n");
    scanf("%s", nome);
    pthread_t thraeadCiao[20];
    for (int i = 0; i < 20; i++)
    {
        pthread_create(&thraeadCiao[i], NULL, &functionCiao, (void *)nome);
        pthread_join(thraeadCiao[i], NULL);
    }
}