#include <stdio.h>

void tulismundur(int n);

int main() {
    int num;

    printf("Masukkan angka : ");
    scanf("%d", &num);

    puts("Hasil : ");
    tulismundur(num);
    puts(" ");

    return 0;
}

void tulismundur(int n){
    if (n < 0)
    {
        return;
    } else
    {
        printf("%d ", n);
        tulismundur(n-1);
    }
}