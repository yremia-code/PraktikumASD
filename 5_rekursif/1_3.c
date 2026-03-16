#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS 50

void pembalik_kata(char *s, int panjang);

int main() {
    char kata[MAKS];
    int panjang;

    printf("Masukkan kata : ");
    fgets(kata, sizeof kata, stdin);

    kata[strcspn(kata, "\n")]=0;

    panjang = strlen(kata)-1;

    printf("Kata yang dibalik: ");
    pembalik_kata(kata, panjang);
    puts("\n");

    return 0;
}

void pembalik_kata(char *s, int panjang){
    if (panjang < 0)
    {
        return;
    }
    else
    {
        printf("%c", s[panjang]);
        pembalik_kata(s, panjang-1);
    }
}