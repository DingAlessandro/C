#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 10
int menu()
{
    int choose;
    printf("Menù\n[1] Visualizza\n[2] Visualizza inverso\n[3] Visualizza somma e media\n[4] Visualizza pari\n[5] Visualizza dispari\n[6] Cerca\n[7] Elimina\n[8] Alterna\n[9] Ordina crescente\n[0] Esci\n");
    scanf("%d", &choose);
    return choose;
}
void exits()
{
    printf("Closing");
    system("clear");
}
int main(int argc, char *argv[])
{
    int numbers [MAX];
    int choose;
    for (int i = 0; i < 10; i++) {
        srand(time(NULL));
        numbers[i] = rand() % 21;
    }
    do {
        choose = menu();
        switch (choose) {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 0:
            exits();
            break;
            default:
            printf("scelta non esiste, riprova\n");
            break;
        
        }
    }while (choose != 0);
}