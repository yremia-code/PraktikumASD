#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p, *after, *before, *baca, *tail;

void alokasi();
void insertawal();
void insertakhir();
void insertafter();
void insertbefore();
void tampil();

int main() {
    int jwb;

    do
    {
        printf("Menu Insert\n");
        printf("1. Insert Awal\n");
        printf("2. Insert Akhir\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &jwb);

        switch (jwb)
        {
        case 1:
            alokasi();
            insertawal();
            tampil();
            break;
        
        case 2:
            alokasi();
            insertakhir();
            tampil();
            break;
        
        case 3:
            alokasi();
            insertafter();
            tampil();
            break;
        
        case 4:
            alokasi();
            insertbefore();
            tampil();
            break;
        
        case 5:
            exit(0);
        
        default:
            exit(0);
            break;
        }
        
    } while (jwb != 0 || jwb < 6);
    
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

    if(after->next == NULL)
        insertakhir();

    p->next = after->next;
    p->prev = after;

    after->next->prev = p;
    after->next = p;
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