#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int itemType;
typedef struct
{
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);

int main()
{
    stack tumpukan;
    char jwb;
    itemType x;

    puts("Implementasi STACK menggunakan ARRAY");
    inisialisasi(&tumpukan);
    puts("Mengisi Stack");
    do
    {
        if (penuh(&tumpukan))
        {
            puts("Stack penuh, tidak bisa menerima data\n");
            break;
        }
        
        fflush(stdin);
        printf("Data yang akan dimasukkan ? ");
        scanf("%d", &x);
        push(x, &tumpukan);
        fflush(stdin);
        printf("Masukkan data lagi ? ");
        scanf(" %c", &jwb);
        getchar();
        puts(" ");
    } while (jwb == 'y' || jwb == 'Y');

    puts("ISI STACK");
    while (!kosong(&tumpukan))
    {
        printf("%d\n", pop(&tumpukan));
    }

    return 0;
}

void inisialisasi(stack *s)
{
    s->count = 0;
}

int kosong(stack *s)
{
    if (s->count == 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int penuh(stack *s)
{
    if (s->count == MAX)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void push(itemType x, stack *s)
{
    if (penuh(s))
    {
        puts("Stack penuh, tidak bisa menerima data");
    }
    else
    {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s)
{
    itemType x;

    if (kosong(s))
    {
        puts("Stack kosong, tidak ada data");
        return (' ');
    }
    else
    {
        x = s->data[--s->count];
        return (x);
    }
}
