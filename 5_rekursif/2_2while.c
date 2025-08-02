#include <stdio.h>

void fibonanci(int n);

int main() {
    int n;

    printf("Masukkan jumlah deret : ");
    scanf("%d", &n);

    fibonanci(n);
}

void fibonanci(int n){
    int a = 0, b = 1, c, count = 0;

    while (count < n )
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
        count++;
    }
    printf("\n");
}