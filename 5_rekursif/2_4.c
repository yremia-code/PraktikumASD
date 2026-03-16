#include <stdio.h>
#include <stdlib.h>

void fibonacci_iterasi(int n);
void fibonacci_rekursi(int n, int m, int p);

int main() {
    int panjang, pilihan;

    do
    {
        puts(" ");
        puts("DAFTAR MENU");
        puts("1. Menggunakan rekursi");
        puts("2. Menggunakan iterasi");
        puts("3. Keluar");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);

        switch(pilihan)
        {
        case 1:
            puts(" ");
            printf("Masukkan panjang deret : ");
            scanf("%d", &panjang);

            printf("Deret Fibonaci : ");
            fibonacci_rekursi(0, 1, panjang);
            printf("\n");
            break;
        
        case 2 :
            puts(" ");
            printf("Masukkan panjang deret : ");
            scanf("%d", &panjang);

            fibonacci_iterasi(panjang);
            break;

        case 3:
            exit(0);
        
        default:
            break;
        }
    } while (pilihan != 3);

    return 0;
}

void fibonacci_rekursi(int n, int m, int p){
    if (p > 0)
    {
        printf("%d ", n);
        fibonacci_rekursi(m, n + m, p-1);
    }
}

void fibonacci_iterasi(int n){
    int a = 0, b = 1, c;

    printf("Deret Fibonaci : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = b + a;
        a = b;
        b = c;
    }
    printf("\n");
}