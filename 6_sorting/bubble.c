#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;

    int deret_bil[] = {84, 55, 20, 35, 48, 39, 25, 68, 30, 72};

    printf("Deret Bilangan : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", deret_bil[i]);
    }
    puts(" ");
    puts(" ");
    int i, j;
    // Mengontrol jumlah perulangan sebanyak banyak data
    for (i = 0; i < n - 1; i++)
    {
        // Pengulangan untuk membandingkan elemen bersebelahan
        // jml - i - 1 karena elemen terbesar sudah di posisi terakhir
        for (j = 0; j < n - i - 1; j++)
        {
            // Jika elemen saat ini lebih besar dari elemen berikutnya
            if (deret_bil[j] > deret_bil[j + 1])
            {
                // Tukar posisi elemen
                int temp = deret_bil[j];
                deret_bil[j] = deret_bil[j + 1];
                deret_bil[j + 1] = temp;
            }
        }
    }
    printf("Sorting ke-%d : ", i + 1);
    for (int k = 0; k < n; k++)
    {
        printf("%d ", deret_bil[k]);
    }
    puts(" ");


return 0;
}