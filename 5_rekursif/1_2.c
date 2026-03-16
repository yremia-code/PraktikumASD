#include <stdio.h>

void tulisnaik(int n, int i);

int main()
{

    int num, i = 0;

    printf("Masukkan batas angka : ");
    scanf("%d", &num);

    tulisnaik(num, i);

    return 0;
}

void tulisnaik(int n, int i)
{

    if (i > n)
    {
        return;
    }
    else
    {
        printf("%d ", i);
        tulisnaik(n, i + 1);
    }
}