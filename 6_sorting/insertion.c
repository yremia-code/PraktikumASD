#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;

    int deret_bil[10] = {84, 55, 20, 35, 48, 39, 25, 68, 30, 72};

    printf("Deret Bilangan : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", deret_bil[i]);
    }
    puts(" ");
    puts(" ");

    for (int i = 1; i <= n; i++)
    {
        int key = deret_bil[i];
        int j = i - 1;

        while (j >= 0 && deret_bil[j] > key)
        {
            deret_bil[j + 1] = deret_bil[j];
            j = j - 1;
        }
        deret_bil[j + 1] = key;

        printf("Sorting ke-%d : ", i);
        for (int k = 0; k < 10; k++)
        {
            printf("%d ", deret_bil[k]);
        }
        puts(" ");
    }

    return 0;
}