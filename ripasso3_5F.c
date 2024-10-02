#include <stdio.h>
#include <unistd.h>

#define MAX 3

typedef struct {
    char ModelloAuto[20];
    char marca[20];
    int cilindrata;
    int prezzo;
    int anno_immatricolazione;
} Auto;

void visualizza(Auto macchina) {
    printf("Modello: %s\n", macchina.ModelloAuto);
    printf("Marca: %s\n", macchina.marca);
    printf("Cilindrata: %d\n", macchina.cilindrata);
    printf("Prezzo: %d\n", macchina.prezzo);
    printf("Anno di immatricolazione: %d\n", macchina.anno_immatricolazione);
}

void inserimento(Auto *macchina) {
    printf("Inserisci i parametri\n");
    printf("Modello:\n");
    scanf("%s", macchina->ModelloAuto);
    printf("Marca\n");
    scanf("%s", macchina->marca);
    printf("Cilindrata\n");
    scanf("%d", &macchina->cilindrata);
    printf("Prezzo\n");
    scanf("%d", &macchina->prezzo);
    printf("Anno di immatricolazione\n");
    scanf("%d", &macchina->anno_immatricolazione);
}

Auto confrontoP(Auto macchine[], int t, int sortOrder) {
    Auto result = macchine[0];
    for(int i = 1; i < t; i++) {
        if ((sortOrder == 1 && macchine[i].prezzo > result.prezzo) ||
            (sortOrder == 0 && macchine[i].prezzo < result.prezzo)) {
            result = macchine[i];
        }
    }
    return result;
}

void ordina(Auto macchine[], int t) {
    Auto temp;
    for(int i = 0; i < t; i++) {
        for(int k = i + 1; k < t; k++) {
            if (macchine[i].anno_immatricolazione > macchine[k].anno_immatricolazione) {
                temp = macchine[i];
                macchine[i] = macchine[k];
                macchine[k] = temp;
            }
        }
    }
}

void visuaPrezzo(Auto macchine[], int t, int pp) {
    for(int i = 0; i < t; i++) {
        if (macchine[i].prezzo > pp) {
            visualizza(macchine[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    Auto macchine[MAX];
    for (int i = 0; i < MAX; i++) {
        printf("Inserisci l'auto %d\n", i + 1);
        inserimento(&macchine[i]);
    }
    for (int i = 0; i < MAX; i++) {
        visualizza(macchine[i]);
    }
    printf("Macchina con prezzo più alto:\n");
    visualizza(confrontoP(macchine, MAX, 1));
    printf("Macchina con prezzo più basso:\n");
    visualizza(confrontoP(macchine, MAX, 0));
    printf("Ordina:\n");
    ordina(macchine, MAX);
    for (int i = 0; i < MAX; i++) {
        visualizza(macchine[i]);
    }
    int prezzo;
    printf("Inserisci il prezzo da cui iniziare:\n");
    scanf("%d", &prezzo);
    visuaPrezzo(macchine, MAX, prezzo);  
    return 0;
}
