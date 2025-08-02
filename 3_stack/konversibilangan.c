#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *p);
int kosong(stack *p);
int penuh(stack *p);
void push(itemType x, stack *p);
itemType pop(stack *p);
void destobin(int des);
void destooktal(int des);
void destoheksa(int des);

int main() {
    int des, pilihan;

    puts("KONVERSI BILANGAN DESIMAL");
    printf("Masukkan bil desimal yang akan dikonversi : ");
    scanf("%d", &des);

    do
    {
        puts(" ");
        puts("MENU KONVERSI");
        puts("1. BINER");
        puts("2. OKTAL");
        puts("3. HEKSADESIMAL");
        puts("4. Keluar");
        puts(" ");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Hasil Konversi %d ke BINER = ", des);
            destobin(des);
            break;
        
        case 2:
            printf("Hasil Konversi %d ke OKTAL = ", des);
            destooktal(des);
            break;

        case 3:
            printf("Hasil Konversi %d ke HEKSADESIMAL = ", des);
            destoheksa(des);
            break;
        
        case 4:
            exit(0);

        default:
            break;
        }
    } while (pilihan != 4);

    return 0;
}

void inisialisasi(stack *p){
    p->count = 0;
}

int kosong(stack *p){
    return (p->count == 0);
}

int penuh(stack *p){
    return (p->count == MAX);
}

void push(itemType x, stack *p){
    if (!penuh(p))
    {
        p->data[p->count] = x;
        p->count++;
    }
}

itemType pop(stack *p){
    if (!kosong(p))
    {
        return p->data[--p->count];
    }
    return ' ';
}

void destobin(int des) {
    stack s;
    inisialisasi(&s);

    if (des == 0)
    {
        printf("0");
        return;
    }

    while (des > 0)
    {
        push(des%2, &s);
        des /= 2;
    }
    
    while (!kosong(&s))
    {
        printf("%d", pop(&s));
    }
}

void destooktal(int des) {
    stack s;
    inisialisasi(&s);

    if (des == 0)
    {
        printf("0");
        return;
    }

    while (des > 0)
    {
        push(des%8, &s);
        des /= 8;
    }

    while (!kosong(&s))
    {
        printf("%d", pop(&s));
    }
}

void destoheksa(int des){
    stack s;
    inisialisasi(&s);

    if (des == 0)
    {
        printf("0");
        return;
    }
    
    while (des > 0)
    {
        int heksa = des % 16;
        
        if (heksa < 10)
        {
            push('0' + heksa, &s);
        }
        else
        {
            push('A' + (heksa-10), &s);
        }

        des /= 16;
    }

    while (!kosong(&s))
    {
        printf("%c", pop(&s));
    }
}