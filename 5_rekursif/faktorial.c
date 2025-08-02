#include <stdio.h>
#include <stdlib.h>

int faktorial(int n);

int main() {
    int num, fact;

    printf("Masukkan bilangan integer : ");
    scanf("%d", &num);

    if (num < 0)
    {
        puts(" ");
        puts("Faktorial tidak didefinisikan untuk bilangan negatif");
    } else {
        fact = faktorial(num);
        printf("Faktorial dari %d : %d\n", num, fact);
    }
    
    return 0;
}

int faktorial(int n) {
    if(n==0) {
        return 1;
    } else {
        return n*faktorial(n-1);
    }
}