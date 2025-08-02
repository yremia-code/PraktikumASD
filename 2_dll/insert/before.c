#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p, *tail, *baca, *before;

void alokasi();
void insertakhir();
void insertbefore();
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
    printf("Insert Before\n");
    alokasi();
    insertbefore();
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

void insertbefore()
{
    int key;

    printf("Sisip before brp ? ");
    scanf("%d", &key);

    before = head;

    while (before->data != key)
    {
        before = before->next;
    }

    p->prev = before->prev;
    p->next = before;

    before->prev->next = p;
    before->prev = p;
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