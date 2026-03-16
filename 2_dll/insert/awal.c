#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p;
Tnode *baca;

void alokasi();
void insertawal();
void tampil();

int main()
{
    char jwb;

    printf("DLL Insert Awal\n");
    do
    {
        fflush(stdin);
        alokasi();
        insertawal();
        fflush(stdin);
        printf("Masukkan data lagi (y/t) : ");
        scanf(" %c", &jwb);
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    return 0;
}

void alokasi()
{
    p = (Tnode *)malloc(sizeof(Tnode));

    if (p == NULL)
    {
        printf("Alokasi Gagal\n");
        exit(0);
    }
    else
    {
        printf("Data yang akan disimpan ? ");
        scanf("%d", &p->data);
        p->next = NULL;
        p->prev = NULL;
    }
}

void insertawal()
{
    if (head == NULL)
    {
        head = p;
    } else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void tampil()
{
    baca = head;
    
    printf("Data Yang Tersedia\n");
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    
}