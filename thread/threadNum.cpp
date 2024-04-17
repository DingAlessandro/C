#include <stdio.h>
#include <pthread.h>
int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int position;
void* search(void* par) 
{
    int* range = (int*[])par;
    for (int i = range[0]; i < range[1]; ++i) 
    {
        if (array[i] == 8) 
        {
            position = i;
        }
    }
    return (void*)0;
}

int main() {
    pthread_t thread1, thread2;
    int range1[2] = {0, 4};
    int range2[2] = {5, 9};
    pthread_create(&thread1, NULL, search, (void*)&range1);
    pthread_create(&thread2, NULL, search, (void*)&range2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Il numero otto si trova alla posizione: %d\n", found_index);
    return 0;
}
