#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p, *tail, *baca, *after;

void alokasi();
void insertakhir();
void insertafter();
void tampil();

int main()
{
    char jwb;

    printf("DLL Insert Akhir\n");
    do
    {
        fflush(stdin);
        alokasi();
        insertakhir();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        scanf(" %c", &jwb);
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    puts("");
    tampil();

    puts("");
    printf("Insert After\n");
    alokasi();
    insertafter();
    puts("");
    tampil();
    puts("");

    return 0;
}

void alokasi()
{
    p = (Tnode *)malloc(sizeof(Tnode));

    if (p == NULL)
    {
        printf("alokasi gagal\n");
        exit(0);
    }
    else
    {
        printf("Data yang mau disimpan? ");
        scanf("%d", &p->data);
        p->next = NULL;
        p->prev = NULL;
    }
}

void insertakhir()
{
    tail = head;

    if (head == NULL)
        head = p;
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void insertafter()
{
    int key;

    printf("Sisip after brp ? ");
    scanf("%d", &key);

    after = head;

    while (after->data != key)
    {
        after = after->next;
    }

    p->next = after->next;
    p->prev = after;

    after->next->prev = p;
    after->next = p;
}

void tampil()
{
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}