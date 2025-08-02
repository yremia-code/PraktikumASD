#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p, *tail, *baca, *hapus;

void alokasi();
void insertakhir();
void tampil();
void deleteawal();
void bebaskan(Tnode *);

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

    puts("----Hapus Awal----");
    deleteawal();
    tampil();

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

void tampil()
{
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

void bebaskan(Tnode *x)
{
    free(x);
    x = NULL;
}

void deleteawal()
{
    hapus = head;

    if (head == NULL)
    {
        puts("\nTidak ada data yang akan dihapus");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = hapus->next;
        hapus->next->prev = NULL;
    }
    bebaskan(hapus);
}