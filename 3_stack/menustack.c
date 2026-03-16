#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
void tampil(stack *s);

int main() {
    stack tumpukan;
    int pilihan;
    itemType x;

    inisialisasi(&tumpukan);

    do {
        if (penuh(&tumpukan)) {
            puts("Stack Penuh Program akan Melakukan POP");
            printf("Mengeluarkan data %d", pop(&tumpukan));
        }

        puts("MENU STACK using ARRAY");
        puts("1. Mengisi Stack (PUSH)");
        puts("2. Mengambil isi Stack (POP)");
        puts("3. Menampilkan isi Stack");
        puts("4. Keluar");
        puts(" ");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            printf("Masukkan data Anda : ");
            scanf("%d", &x);
            push(x, &tumpukan);
            puts(" ");
            break;

        case 2:
            printf("\nItem yang Anda ambil adalah %d\n", pop(&tumpukan));
            puts(" ");
            break;

        case 3:
            tampil(&tumpukan);
            puts(" ");
            break;

        case 4:
            exit(0);
            break;

        default:
            break;
        }
    } while (pilihan != 4);

    return 0;
}

void inisialisasi(stack *s) {
    s->count = 0;
}

int kosong(stack *s) {
    if (s->count == 0) {
        return (1);
    } else {
        return (0);
    }
}

int penuh(stack *s) {
    if (s->count == MAX) {
        return (1);
    } else {
        return (0);
    }
}

void push(itemType x, stack *s) {
    if (!penuh(s)) {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s) {
    if (!kosong(s)) {
        return s->data[--s->count];
    } else {
        return ' ';
    }
}

void tampil(stack *s) {
    puts("\nIsi stack saat ini adalah : ");
    for (int i = s->count-1; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}