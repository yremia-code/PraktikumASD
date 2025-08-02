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

Node *baru, *output;

void inisialisasi(stack *s);
int kosong(stack *s);
void push(int data, stack *s);
int pop(stack *s);
void freestack(stack *s);

int main(){
    char jawab;
    stack s;
    inisialisasi(&s);
    int data;

    puts("Implemnetasi STACK using SLL");
    puts("Mengisi Stack");
    do
    {
        fflush(stdin);
        printf("Data yang akan dimasukkan : ");
        scanf("%d", &data);
        push(data, &s);
        fflush(stdin);
        printf("Masukkan data lagi? ");
        scanf(" %c", &jawab);
        getchar();
    } while (jawab == 'y' || jawab == 'Y');

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

void freestack(stack *s){
    while (!kosong(s))
    {
        pop(s);
    }
}