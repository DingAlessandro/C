#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_DIM 1024
#define BUFFER_SIZE 64
typedef struct
{
    unsigned char buffer[BUFFER_DIM]
} BUFF;
BUFF buff[BUFFER_SIZE];
int ins;
int ins2;
void *scrivi(void *arg)
{
    FILE *file = (FILE *)arg;
}
void *leggi(void *arg)
{
    FILE *file = (FILE *)arg;
    if (ins2 % BUFFER_SIZE == ins % BUFFER_SIZE)
    {
        pthread_exit(1);
    }
    else
    {
    }
}
int main(int argc, char *argv[])
{
}