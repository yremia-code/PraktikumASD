#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p;

void isidata();
void insertposition();
void tampil();

int main()
{
    char jwb;
    int pilihan;

    do
    {
        fflush(stdin);
        isidata();
        insertposition();
        printf("Masukkan data lagi (y/t) : ");
        fflush(stdin);
        jwb = getchar();
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    do
    {
        puts("\nOpsi : ");
        puts("1. Tambah data");
        puts("2. Keluar");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            isidata();
            insertposition();
            tampil();
        }
        else if (pilihan == 2)
        {
            break;
        }
        else
        {
            puts("Pilihan tidak valid");
        }

    } while (pilihan != 0);

    return 0;
}

void isidata()
{
    int isi;

    printf("Data yang akan disimpan : ");
    scanf("%d", &isi);

    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->data = isi;
        p->next = NULL;
    }
}

void insertposition()
{
    Node *cek;

    // insert awal
    if (head == NULL)
    {
        head = p;
        return;
    }

    // jika data baru kurang dari head data
    if (p->data < head->data)
    {
        p->next = head;
        head = p;
        return;
    }

    cek = head;

    // Menejelajahi node untuk menemukan tempat yang sesuai
    while (cek->next != NULL && cek->next->data < p->data)
    {
        cek = cek->next;
    }

    // cek data yang sama
    if (cek->data == p->data)
    {
        puts("Data sudah ada");
        free(p);
        return;
    }

    // Cek data yang sama pada akhir
    if (cek->next != NULL && cek->next->data == p->data)
    {
        puts("Data sudah ada");
        free(p);
        return;
    }

    // memasukkan data baru ke dalam linked list
    p->next = cek->next;
    cek->next = p;
}

void tampil()
{
    Node *baca = head;

    puts("\nDAFTAR DATA\n");

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
