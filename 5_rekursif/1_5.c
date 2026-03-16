#include <stdio.h>
#include <stdlib.h>

int faktorial(int n);

int main()
{
    int bil1, bil2, pilihan, hasil;

    do
    {
        puts("Daftar Menu");
        puts("1. Permutasi");
        puts("2. Kombinasi");
        puts("3. Keluar");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            puts(" ");
            puts("PERMUTASI");
            printf("Masukkan Bilangan Pertama : ");
            scanf("%d", &bil1);
            printf("Masukkan Bilangan Kedua : ");
            scanf("%d", &bil2);

            hasil = faktorial(bil1) / faktorial(bil1 - bil2);

            printf("Permutasi dari %d dan %d : %d\n", bil1, bil2, hasil);
            puts(" ");
            break;

        case 2:
            puts(" ");
            puts("KOMBINASI");
            printf("Masukkan Bilangan Pertama : ");
            scanf("%d", &bil1);
            printf("Masukkan Bilangan Kedua : ");
            scanf("%d", &bil2);

            hasil = faktorial(bil1) / (faktorial(bil2) * faktorial(bil1 - bil2));
            printf("Kombinasi dari %d dan %d : %d\n", bil1, bil2, hasil);
            puts(" ");
            break;

        default:
            break;
        }
    } while (pilihan != 3);

    return 0;
}

int faktorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1);
    }
}