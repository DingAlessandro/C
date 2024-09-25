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
  for (int i = 0; i < strlen(stringa); i++) {
    if (stringa[i] % 2 == 0) {
      stringa1 += stringa[i];
    } else {
      stringa2 += stringa[i];
    }
  }
}
void doppie(char stringa[])
{
    int t = 0;
    char c;
    for (int i = 0; i < strlen(stringa) - 1; i++) {
        if(stringa[i]  == stringa[i + 1])
        {
            t = 1;
            printf("doppia %c\n", stringa[i]);
        }
    }
    if (t == 0) {
    printf("non ci sono doppie\n");
  } else {
    printf("ci sono doppie\n");
  }
}
int main(int argc, char *argv[]) {
  char stringa[20];
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
  printf("stringa1 = %s", stringa_1);
  printf("stringa2 = %s", stringa_2);
  printf("doppie\n");
  doppie(stringa);
}