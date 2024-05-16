#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SLICE_SIZE 64
#define BUFFER_SLICE 16

typedef struct
{
    unsigned char buffer[BUFFER_SLICE_SIZE];
    int size;
} Buffer;

Buffer buffer[BUFFER_SLICE];
int writeindex = 0;
int readindex = 0;
int N_SLICES = 0;
pthread_cond_t not_full, not_empty;
pthread_mutex_t critical;
int end = 0;

void *read_file(void *arg)
{
    FILE *fileorigine = (FILE *)arg;
    int n;
    while (!feof(fileorigine))
    {
        pthread_mutex_lock(&critical);
        if (N_SLICES >= BUFFER_SLICE)
        {
            pthread_cond_wait(&not_full, &critical);
        }
        n = fread(buffer[readindex].buffer, 1, BUFFER_SLICE_SIZE, fileorigine);
        if (n > 0)
        {
            buffer[readindex].size = n;
            readindex = (readindex + 1) % BUFFER_SLICE;
            N_SLICES++;
            pthread_cond_signal(&not_empty);
        }
        pthread_mutex_unlock(&critical);
    }
    end = 1;
    pthread_cond_signal(&not_empty);
}

void *write_file(void *arg)
{
    FILE *filedestinatario = (FILE *)arg;
    int n;
    while (1)
    {
        pthread_mutex_lock(&critical);
        if (N_SLICES == 0)
        {
            if(end)
            {
                return NULL;
            }
            pthread_cond_wait(&not_empty, &critical);
        }
        else
        {
            fwrite(buffer[writeindex].buffer, 1, buffer[writeindex].size, filedestinatario);
            writeindex = (writeindex + 1) % BUFFER_SLICE;
            N_SLICES--;
            pthread_cond_signal(&not_full);
        }
        pthread_mutex_unlock(&critical);
    }
}

int main()
{
    pthread_t writeTh, readTh;
    FILE *fileorigine = fopen("fileorigine.txt", "r");
    FILE *filedestinatario = fopen("filedestinatario", "w");
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_mutex_init(&critical, NULL);
    phtread_create(&readTh, NULL, &read_file, fileorigine);
    pthread_create(&writeTh, NULL, &write_file, NULL);
    pthread_join(readTh, NULL);
    pthread_join(writeTh, NULL);
    return 0;
}