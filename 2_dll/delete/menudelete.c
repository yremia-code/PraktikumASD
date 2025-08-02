#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Tnode;
struct simpul
{
    int data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head = NULL, *p, *tail, *baca, *hapus, *after, *before;

void alokasi();
void insertawal();
void insertakhir();
void insertafter();
void insertbefore();
void tampil();
void deleteawal();
void deleteakhir();
void deletetertentu();
void bebaskan(Tnode *);

int main()
{
    int menu, pilihan;

    do
    {
        puts("\nMENU UTAMA");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan pilihan : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            puts("\nMENU INSERT");
            puts("1. Insert Awal");
            puts("2. insert Akhir");
            puts("3. Insert After");
            puts("4. Insert Before");
            printf("Masukkan pilihan : ");
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                fflush(stdin);
                alokasi();
                insertawal();
                fflush(stdin);
                tampil();
                break;

            case 2:
                fflush(stdin);
                alokasi();
                insertakhir();
                fflush(stdin);
                tampil();
                break;

            case 3:
                fflush(stdin);
                alokasi();
                insertafter();
                fflush(stdin);
                tampil();
                break;

            case 4:
                fflush(stdin);
                alokasi();
                insertbefore();
                fflush(stdin);
                tampil();
                break;

            default:
                break;
            }
            break;

        case 2:
            puts("\nMENU DELETE");
            puts("1. Delete Awal");
            puts("2. Delete Akhir");
            puts("3. Delete Tertentu");
            printf("Masukkan pilihan : ");
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                deleteawal();
                tampil();
                break;

            case 2:
                deleteakhir();
                tampil();
                break;

            case 3:
                deletetertentu();
                tampil();
                break;

            default:
                break;
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            break;
        }

    } while (menu != 0);

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

void insertawal()
{
    if (head == NULL)
    {
        head = p;
    }
    else
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

    puts("\nIsi DLL");

    if (head == NULL)
    {
        puts("Tidak ada data");
    }

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

void deleteakhir()
{
    hapus = head;

    if (head == NULL)
    {
        puts("\nTidak ada yang dihapus");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (hapus->next != NULL)
        {
            hapus = hapus->next;
        }
        hapus->prev->next = NULL;
    }
    bebaskan(hapus);
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