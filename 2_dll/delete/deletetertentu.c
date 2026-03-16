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
void deleteakhir();
void deletetertentu();
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

    puts("----Hapus Tertentu----");
    deletetertentu();
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
        printf("Tidak ada data yang akan dihapus");
        return;
    }
    else
    {
        head = hapus->next;
        hapus->next->prev = NULL;
        bebaskan(hapus);
    }
}

void deleteakhir()
{
    hapus = head;

    if (head->next == NULL)
    {
        deleteawal();
    }
    else
    {
        while (hapus->next != NULL)
        {
            hapus = hapus->next;
        }
        hapus->prev->next = NULL;
        bebaskan(hapus);
    }
}

void deletetertentu()
{
    hapus = head;

    if (head == NULL)
    {
        puts("\nTidak ada yang dihapus");
        return;
    }

    int key;
    printf("Mau hapus data ke ");
    scanf("%d", &key);

    if (head->data == key)
    {
        deleteawal();
    }
    else if (head->next == NULL)
    {
        head = NULL;
        bebaskan(hapus);
    }
    else
    {
        while (hapus->data != key)
        {
            if (hapus->next == NULL && hapus->data != key)
            {
                puts("Data tidak ditemukan");
                return;
            }
            hapus = hapus->next;
        }

        if (hapus->next == NULL)
        {
            deleteakhir();
        }
        else
        {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
            bebaskan(hapus);
        }
    }
}