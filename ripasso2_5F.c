#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void cont(char stringa[]) {
  int t = 0;
  for (int i = 0; i < strlen(stringa); i++) {
    if (stringa[i] < 65 || stringa[i] > 90 && stringa[i] < 97 ||
        stringa[i] > 122) {
      t = 1;
    }
  }
  if (t == 0) {
    printf("la stringa contiene solo lettere\n");
  } else {
    printf("la stringa altri carratteri\n");
  }
}
void search(char stringa[], char c) {
  int t = 0;
  for (int i = 0; i < strlen(stringa); i++) {
    if (stringa[i] == c) {
      t = 1;
    }
  }
  if (t == 0) {
    printf("carratere non trovato\n");
  } else {
    printf("carratere trovato\n");
  }
}
void ParDis(char stringa[], char stringa1[], char stringa2[]) {
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++) {
        if (i % 2 == 0) {
            stringa1[idx1] = stringa[i];
            idx1++;
        } else {
            stringa2[idx2] = stringa[i];
            idx2++;
        }
    }
}
void doppie(char stringa[])
{
    int t = 0;
    char c;
    for (int i = 0; i < strlen(stringa); i++) {
        if(stringa[i]  == stringa[i + 1])
        {
            t = 1;
        }
    }
    if (t == 0) {
    printf("non ci sono doppie\n");
  } else {
    printf("ci sono doppie\n");
  }
}
void Lenght(char stringa[], char stringa2[])
{
  if(strlen(stringa) > strlen(stringa2))
  {
    printf("la prima stringa è più lunga della seconda\n");
  }
  else if(strlen(stringa) < strlen(stringa2))
  {
    printf("la seconda stringa è più lunga della prima\n");
  }
  else
  {
    printf("la lunghezza è uguale fra le due stringhe\n");
  }
}
int contaVocali(char stringa[]) {
    int count = 0;
    for (int i = 0; i < strlen(stringa); i++) {
        char c = toupper(stringa[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

void piuVocali(char stringa1[], char stringa2[]) {
    int vocali1 = contaVocali(stringa1);
    int vocali2 = contaVocali(stringa2);
    if (vocali1 > vocali2) {
        printf("La prima stringa contiene più vocali (%d)\n", vocali1);
    } else if (vocali2 > vocali1) {
        printf("La seconda stringa contiene più vocali (%d)\n", vocali2);
    } else {
        printf("Entrambe le stringhe contengono lo stesso numero di vocali (%d)\n", vocali1);
    }
}

int contaConsonanti(char stringa[]) {
    int count = 0;
    for (int i = 0; i < strlen(stringa); i++) {
        char c = toupper(stringa[i]);
        if (isalpha(c) && !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            count++;
        }
    }
    return count;
}

void piuConsonanti(char stringa1[], char stringa2[]) {
    int consonanti1 = contaConsonanti(stringa1);
    int consonanti2 = contaConsonanti(stringa2);
    if (consonanti1 > consonanti2) {
        printf("La prima stringa contiene più consonanti (%d)\n", consonanti1);
    } else if (consonanti2 > consonanti1) {
        printf("La seconda stringa contiene più consonanti (%d)\n", consonanti2);
    } else {
        printf("Entrambe le stringhe contengono lo stesso numero di consonanti (%d)\n", consonanti1);
    }
}
int main(int argc, char *argv[]) {
  char stringa[20];
  char stringa2[20];
  char stringa_1[20] = "";
  char stringa_2[20] = "";
  char c;
  printf("inserisci la prima stringa\n");
  scanf("%s", stringa);
  printf("controlla lettere");
  cont(stringa);
  printf("inserisci un carratere\n");
  scanf("%s", &c);
  search(stringa, c);
  printf("pari dispari\n");
  ParDis(stringa, stringa_1, stringa_2);
  printf("stringa1 = %s\n", stringa_1);
  printf("stringa2 = %s\n", stringa_2);
  printf("doppie\n");
  doppie(stringa);
  printf("inserisci la seconda stringa\n");
  scanf("%s", stringa2);
  printf("lunghezza\n");
  Lenght(stringa, stringa2);
  printf("vocali\n");
  piuVocali(stringa, stringa2);
  printf("consonanti\n");
  piuConsonanti(stringa, stringa2);
}
