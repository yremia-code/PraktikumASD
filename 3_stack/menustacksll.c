#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
typedef struct simpul{
    int data;
    Node *next;
};

typedef struct
{
    Node *head;
} stack;

Node *baru, *output, *baca;

void inisialisasi(stack *s);
int kosong(stack *s);
void push(int data, stack *s);
int pop(stack *s);
void tampil(stack *s);
void freestack(stack *s);

int main(){
    stack s;
    inisialisasi(&s);
    int data, pilihan;

    puts("Implemnetasi STACK using SLL\n");
    do
    {
        puts("MENU STACK using SLL");
        puts("1. Mengisi Stack (PUSH)");
        puts("2. Mengambil isi Stack (POP)");
        puts("3. Menampilkan isi Stack (FILO)");
        puts("4. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan data Anda : ");
                scanf("%d", &data);
                push(data, &s);
                puts(" ");
                break;
    
            case 2:
                printf("\nItem yang Anda ambil adalah %d\n", pop(&s));
                puts(" ");
                break;
    
            case 3:
                tampil(&s);
                puts(" ");
                break;
    
            case 4:
                exit(0);
                break;
    
            default:
                break;
            }
    } while (pilihan != 4);

    puts("ISI STACK");
    while (!kosong(&s))
    {
        printf("%d\n", pop(&s));
    }
    
    freestack(&s);

    return 0;
}

void inisialisasi(stack *s){
    s->head = NULL;
}

int kosong(stack *s){
    return s->head == NULL;
}

void push(int data, stack *s){
    baru = (Node *)malloc(sizeof(Node));

    if (baru == NULL)
    {
        printf("Alokasi gagal");
        exit(1);
    }
    baru->data = data;
    baru->next = s->head;
    s->head = baru;
}

int pop(stack *s){
    if (kosong(s))
    {
        printf("Tidak ada data\n");
        return ' ';
    }
    output = s->head;
    int dataoutput = output->data;
    s->head = s->head->next;
    free(output);
    output = NULL;
    return dataoutput;
}

void tampil(stack *s){
    baca = s->head;

    if (kosong(s))
    {
        printf("Tidak ada data");
    }
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

void freestack(stack *s){
    while (!kosong(s))
    {
        pop(s);
    }
}