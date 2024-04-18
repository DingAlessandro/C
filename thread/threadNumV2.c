#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXRANGE 100
int array[MAXRANGE];
int position;
void *search(void *par)
{
    int *range = (int *)par;
    for (int i = range[0]; i < range[1]; ++i)
    {
        if (array[i] == 8)
        {
            position = i;
        }
    }
    return (void *)0;
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAXRANGE; i++)
    {
        array[i] = rand() % 101;
        for(int k = 0; k < i; k++)
        {
            if(array[k] == array[i])
            {
                i--;
            }
        }
    }
    pthread_t thread1, thread2, thread3, thread4;
    int range1[2] = {0, MAXRANGE/4-1};
    int range2[2] = {MAXRANGE/4, MAXRANGE/2-1};
    int range3[2] = {MAXRANGE/2, MAXRANGE/2 + MAXRANGE/4-1};
    int range4[2] = {MAXRANGE/2 + MAXRANGE/4, MAXRANGE};
    pthread_create(&thread1, NULL, &search, (void *)&range1);
    pthread_create(&thread2, NULL, &search, (void *)&range2);
    pthread_create(&thread3, NULL, &search, (void *)&range3);
    pthread_create(&thread4, NULL, &search, (void *)&range4);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    printf("Il numero otto si trova alla posizione: %d\n", position);
    return 0;
}
