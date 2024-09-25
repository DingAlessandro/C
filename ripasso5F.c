#include <stdio.h>
#include <stdlib.h>
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
void Visualizza(int numbers[], int* cont)
{
    for(int i = 0; i < *cont; i++)
    {
        printf("%d\n", numbers[i]);
    }
    printf("========\n");
}
void VisualizzaInv(int numbers[], int* cont)
{
    for(int i = *cont; i > 0; i--)
    {
        printf("%d\n", numbers[i - 1]);
    }
    printf("========\n");
}
void Sum(int numbers[], int* cont)
{
    int Sum = 0;
    double Mid;
    for(int i = 0; i < *cont; i++)
    {
        Sum += numbers[i];
    }
    Mid = Sum;
    Mid = Mid / *cont;
    printf("somma = %d, media = %.2f\n", Sum, Mid);
    printf("========\n");
}
void NumMod(int numbers[], int* cont, int mod)
{
    
    for(int i = 0; i < *cont; i++)
    {
        if ((mod == 1 && numbers[i] % 2 == 0) || (mod == 0 && numbers[i] % 2 != 0))
        {
            printf("%d\n", numbers[i]);
        }
    }
    printf("========\n");
}
void Search(int numbers[], int* cont, int num)
{
    int f = 0;
    for(int i = 0; i < *cont; i++)
    {
        if(numbers[i] == num)
        {
            printf("%d\n", numbers[i]); 
            f = 1;
        }
    }
    if(f == 0)
    {
        printf("numero non trovato");   
    }
    printf("========\n"); 
}
void Delete(int numbers[], int* cont, int num)
{
    int f = 0;
    for(int i = 0; i < *cont; i++)
    {
        if(numbers[i] == num || f == 1)
        {
            if(!(i == *cont - 1))
            {
                numbers[i] = numbers[i + 1];
            }
            f = 1;
        }
    }
    if(f == 0)
    {
        printf("numero non trovato");   
    }
    printf("========\n"); 
}
void Inverti(int numbers[], int* cont)
{
    if(*cont % 2 == 0)
    {
        for(int i = 0; i < *cont; i++)
        {
            if(i % 2 == 0)
            {
                printf("%d", numbers[i + 1]);
            }
            else
            {   
                printf("%d", numbers[i - 1]);
            }
        }
    }
    printf("========\n"); 
}
void Ordina(int numbers[], int* cont)
{
    for(int i = 0; i < *cont; i++)
    {
        for (int g = 0; g < *cont - 1 - i; g++)
        {
            if (numbers[g] > numbers[g + 1])
            {
                int num = numbers[g];
                numbers[g] = numbers[g + 1];
                numbers[g + 1] = num;
            }
        }
    }
    printf("========\n"); 
}
int main(int argc, char *argv[])
{
    int numbers [MAX];
    int cont;
    int num;
    int* contP = &cont;
    *contP = MAX;
    int choose;
    for (int i = 0; i < 10; i++) {
        printf("inserisci il %d numero\n", i + 1);
        scanf("%d", &numbers[i]);
    }
    do {
        choose = menu();
        switch (choose) {
            case 1:
            Visualizza(numbers, contP);
            break;
            case 2:
            VisualizzaInv(numbers, contP);
            break;
            case 3:
            Sum(numbers, contP);
            break;
            case 4:
            NumMod(numbers, contP, 1);
            break;
            case 5:
            NumMod(numbers, contP, 0);
            break;
            case 6:
            printf("inserisci un numero\n");
            scanf("%d", &num);
            Search(numbers, contP, num);
            break;
            case 7:
            printf("inserisci un numero\n");
            scanf("%d", &num);
            Delete(numbers, contP, num);
            break;
            case 8:
            Inverti(numbers, contP);
            break;
            case 9:
            Ordina(numbers, contP);
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
