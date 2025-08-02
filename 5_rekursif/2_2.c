#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n);

int main() {

    int bnyk_deret;

    printf("Masukkan panjang deret fibonanci : ");
    scanf("%d", &bnyk_deret);

    fibonacci(bnyk_deret);

    return 0;
}

void fibonacci(int n){
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