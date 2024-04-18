#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct 
{
    char nome[20];
    char cognome[20];
    float media;
} Studente;

void* stampa(void* par) 
{
    Studente studente = *(Studente*)par;
    printf("Nome: %s\nCognome: %s\nMedia: %.2f\n", studente.nome, studente.cognome, studente.media);
    return NULL;
}

void* stampaF(void* par) 
{
    Studente studente = *(Studente*)par;
    FILE* file = fopen("file.txt", "w");
    if (file != NULL) 
    {
        fprintf(file, "Nome: %s\nCognome: %s\nMedia: %.2f\n", studente.nome, studente.cognome, studente.media);
        fclose(file);
    } else 
    {
        printf("Errore nell'apertura del file.");
    }
    return NULL;
}

int main() {
    pthread_t threadStampa, threadStampaF;
    Studente studente;
    printf("Inserisci il nome: ");
    scanf("%s", studente.nome);
    printf("Inserisci il cognome: ");
    scanf("%s", studente.cognome);
    printf("Inserisci la media: ");
    scanf("%f", &studente.media);
    pthread_create(&threadStampa, NULL, &stampa, (void*)&studente);
    pthread_create(&threadStampaF, NULL, &stampaF, (void*)&studente);
    pthread_join(threadStampa, NULL);
    pthread_join(threadStampaF, NULL);
    return 0;
}
