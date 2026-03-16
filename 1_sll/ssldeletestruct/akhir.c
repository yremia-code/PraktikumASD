#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa
{
    int id;
    char name[20];
    float nilai;
    Node *next;
};

Node *head = NULL, *p;

void isidata();
void insertakhir();
void tampil();
void bebaskan(Node *);
void hapusawal();
void hapusakhir();
void hapusafter();
void hapustertentu();

int main()
{
    char jwb;

    puts("SSL DELETE AKHIR- data struct");
    puts("Linked List untuk aplikasi INSERT DI AKHIR");
    puts("Membentuk linked list dg Insert di akhir");
    do
    {
        printf("\n");
        isidata();
        insertakhir();
        printf("Ada data lagi (y/t) ?");
        scanf(" %c", &jwb);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    printf("Mau menghapus node terakhir ? (y/t) ");
    scanf(" %c", &jwb);
    if (jwb == 'y' || jwb == 'Y')
    {
        printf("\nMenghapus simpul terakhir dari list.......\n");
        hapusakhir();
        tampil();
    }

    return 0;
}

void isidata()
{
    int no;
    char nama[20];
    float score;

    printf("No      : ");
    scanf("%d", &no);
    printf("Nama    : ");
    getchar();
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0;
    printf("Nilai   : ");
    scanf("%f", &score);

    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->id = no;
        strcpy(p->name, nama);
        p->nilai = score;
        p->next = NULL;
    }
}

void insertakhir()
{
    Node *tail;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void tampil()
{
    Node *baca = head;

    puts("Data yang telah diinputkan : \n");
    printf("No \t Nama \t\t\t Nilai\n");
    while (baca != NULL)
    {
        printf("%d \t %-20s \t %.0f \n", baca->id, baca->name, baca->nilai);

        baca = baca->next;
    }
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}

void hapusawal()
{
    Node *hapus = head;

    if (head == NULL)
    {
        printf("Data tidak ada.\n");
        return;
    }
    else
    {
        head = hapus->next;
        bebaskan(hapus);
    }
}

void hapusakhir()
{
    Node *hapus = head, *phapus;

    if (head == NULL)
    {
        printf("Data tidak ada.\n");
        return;
    }
    else
    {
        while (hapus->next != NULL)
        {
            phapus = hapus;
            hapus = hapus->next;
        }
        phapus->next = NULL;
        bebaskan(hapus);
    }
}
