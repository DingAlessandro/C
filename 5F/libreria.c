#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MAX_LIB 20
#define MAX_LI 10

typedef struct {
    char titolo[30];
    char autore[30];
    int anno;
    float prezzo;
} Libro;

typedef struct {
    Libro libri[MAX_LI];
    char categoria[30];
    int indice;
} Categoria;

int menu() {
    int choose;
    printf("Menu\n[1] Visualizza\n[2] Visualizza per Categoria\n[3] Inserimento manuale\n[4] Lettura da file (libreria_libri.csv)\n[5] Ricerca libro con titolo\n[0] Esci\n");
    scanf("%d", &choose);
    return choose;
}

void exits() {
    printf("Closing\n");
}

void AddLibro(int i, Libro *new, char token[]) {
    switch (i) {
    case 0:
        strcpy(new->titolo, token);
        break;
    case 1:
        strcpy(new->autore, token);
        break;
    case 2:
        new->anno = atoi(token);
        break;
    case 3:
        new->prezzo = atof(token);
        break;
    }
}

int ContCate(char cate[], Categoria libreria[], int* punt) {
    int indice = -1;
    for (int i = 0; i < *punt; i++) {
        if (strcmp(cate, libreria[i].categoria) == 0) {
            indice = i;
            return indice;
        }
    }
    return NewCate(cate, libreria, punt);
}

int NewCate(char cate[], Categoria libreria[], int* punt) {
    if(*punt + 1 != MAX_LIB)
    { 
        int k = 1;
        if(*punt != 0)
        {
            k = CateEs(cate, libreria, punt);
        }
        if(k == 1)
        {
            strcpy(libreria[*punt].categoria, cate);
            printf("Aggiunta nuova categoria: %s\n", cate);
            (*punt)++;
            return *punt - 1;
        }
        else
        {
            return k;
        }
    }
    else
    {
        printf("libreria con numero di categorie piene inserisci una gia esistente\n");
        return -1;
    }    
}

int CateEs(char cate[], Categoria libreria[], int* punt)
{
    for(int i = 0; i < *punt; i++)
    {
        if(strcmp(cate, libreria[i].categoria) == 0)
        {
            printf("categoria inserita gia esistente\n");
            return -1;
        }
    }
    return 1;
}
int NuovoLibro(Categoria libreria[], Libro new, int punt) {
    if(libreria[punt].indice + 1 != MAX_LI)
    {
        strcpy(libreria[punt].libri[libreria[punt].indice].titolo, new.titolo);
        strcpy(libreria[punt].libri[libreria[punt].indice].autore, new.autore);
        libreria[punt].libri[libreria[punt].indice].anno = new.anno;
        libreria[punt].libri[libreria[punt].indice].prezzo = new.prezzo;
        libreria[punt].indice++;
        return 1;
    }
    else
    {
        printf("Categoria con numero di libri pieno inseriscine in un'altra\n");
        return -1;
    }
}

void VisuaAll(Categoria libreria[], int punt) {
    for (int i = 0; i < punt; i++) {
        printf("Categoria: %s\n", libreria[i].categoria);
        for (int k = 0; k < libreria[i].indice; k++) {
            VisuaLB(libreria[i].libri[k]);
        }
        printf("///////////////////////////\n");
    }
}

void RicercaPerCategoria(Categoria libreria[], int punt) {
    char cate[30];
    printf("Inserisci la categoria da visualizzare:\n");
    scanf("%s", cate);
    if(VisuaPerCategoria(libreria, punt, cate) == -1)
    {
        printf("Categoria %s non trovata.\n", cate);
    }
}

int VisuaPerCategoria(Categoria libreria[], int punt, char cate[])
{
    for (int i = 0; i < punt; i++) {
        if (strcmp(cate, libreria[i].categoria) == 0) {
            printf("Libri nella categoria %s:\n", cate);
            for (int k = 0; k < libreria[i].indice; k++) {
                VisuaLB(libreria[i].libri[k]);
            }
            return 1;
        }
    }
    return -1;
}

void VisuaLB(Libro l) {
    printf("Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n", l.titolo, l.autore, l.anno, l.prezzo);
}

void LetturaFile(Categoria libreria[], int* punt) {
    char buffer[MAX_LEN];
    FILE *libriCSV = fopen("libreria_libri.csv", "r");
    if (libriCSV == NULL) {
        perror("Errore nell'aprire il file");
        return;
    }
    int k = -1; //non legge la prima volta perche leggerebe i parametro della colonna
    while (fgets(buffer, MAX_LEN, libriCSV) != NULL) {
        char *token = strtok(buffer, ",");
        Libro new;
        for (int i = 0; i < 4; i++) {
            if(i == 1)
            {
                k = ContTito(libreria, *punt, token);
            }
            if(k == 1)
            {    
                AddLibro(i, &new, token);
            }
            token = strtok(NULL, ",");
        }
        k = 1;
        int p;
        do
        {
            printf("Inserisci la categoria del libro:\n");
            char cate[30];
            scanf("%s", cate);
            p = ContCate(cate, libreria, punt);
            if(p != -1)
            {
                p = NuovoLibro(libreria, new, p);
            }
        }while(p == -1);
    }
    fclose(libriCSV);
}

void InsMan(Categoria libreria[], int* punt)
{
   Libro new;
   int k;
   do
   {
        printf("inserisci il titolo\n");
        scanf("%s", new.titolo);
        k = ContTito(libreria, *punt, new.titolo);
        if(k == -1)
        {
            printf("titolo gia esistente inserisci un'altra");
        }
   }while(k == -1);
   printf("inserisci l'autore\n");
   scanf("%s", new.autore);
   printf("inserisci l'anno\n");
   scanf("%d", &new.anno);
   printf("inserisci il prezzo\n");
   scanf("%f", &new.prezzo);
   int p;
   do
   {
        printf("Inserisci la categoria del libro:\n");
        char cate[30];
        scanf("%s", cate);
        p = ContCate(cate, libreria, punt);
        if(p != -1)
        {
            p = NuovoLibro(libreria, new, p);
        }
    }while(p == -1);
}
int ContTito(Categoria libreria[], int punt, char titolo[30])
{
    for(int i = 0; i < punt; i++)
    {
        for(int k = 0; k < libreria[i].indice; k++)
        {
            if(strcmp(libreria[i].libri[k].titolo, titolo) == 0)
            {
                return -1;
            }
        }
    }
    return 1;
}

char* RicercaConCategoria(Categoria libreria[], int punt, char titolo[])
{
    for(int i = 0; i < punt; i++)
    {
        for(int k = 0; k < libreria[i].indice; k++)
        {
            if(strcmp(libreria[i].libri[k].titolo, titolo) == 0)
            {
                return libreria[i].categoria;
            }
        }
    }
    return NULL;
}

void RicercaConTito(Categoria libreria[], int punt)
{
    char titolo[30];
    printf("inserisci il titolo del libro\n");
    scanf("%s", titolo);
    char* cate = RicercaConCategoria(libreria, punt, titolo);
    if(cate == NULL)
    {
        printf("libro non trovato\n");
    }
    else
    {
        VisuaPerCategoria(libreria, punt, cate);
    }   
}

int main() {
    Categoria libreria[MAX_LIB];
    int punt = 0;
    int choose;
    do {
        choose = menu();
        switch (choose) {
        case 1:
            if(punt == 0)
            {
                printf("libreria vuota\n");
            }
            else
            {
                VisuaAll(libreria, punt);
            }
            break;
        case 2:
            if(punt == 0)
            {
                printf("libreria vuota\n");
            }
            else
            {
                RicercaPerCategoria(libreria, punt);
            }
            break;
        case 3:
            InsMan(libreria, &punt);
            break;
        case 4:
            LetturaFile(libreria, &punt);
            break;
        case 5:
            if(punt == 0)
            {
                printf("libreria vuota\n");
            }
            else
            {
                RicercaConTito(libreria, punt);
            }
            break;
        case 0:
            exits();
            break;
        default:
            printf("Scelta non esiste, riprova\n");
            break;
        }
    } while (choose != 0);

    return 0;
}
