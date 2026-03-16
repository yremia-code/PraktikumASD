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
void insertawal();
void insertakhir();
void insertafter();
void insertbefore();
void tampil();
void bebaskan(Node *);
void hapusawal();
void hapusakhir();
void hapusafter();
void hapustertentu();

int main()
{
    int jwb;
    char optionins, optiondel;

    do
    {
        puts("\nMENU UTAMA");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &jwb);

        switch (jwb)
        {
        case 1:
            printf("\n");
            fflush(stdin);
            isidata();
            fflush(stdin);

            puts("\nMENU INSERT");
            puts("a. Insert awal");
            puts("b. Insert akhir");
            puts("c. Insert setelah node tertentu");
            puts("d. Insert sebelum node tertentu");
            printf("Masukkan pilihan Anda : ");
            optionins = getchar();
            getchar();
            if (optionins == 'a' || optionins == 'A')
            {
                insertawal();
                puts("Membentuk linked list dg insert di awal");
            }
            else if (optionins == 'b' || optionins == 'B')
            {
                insertakhir();
                puts("Membentuk linked list dg insert di akhir");
            }
            else if (optionins == 'c' || optionins == 'C')
            {
                insertafter();
                puts("Membentuk linked list dg insert setelah node tertentu");
            }
            else if (optionins == 'd' || optionins == 'D')
            {
                insertbefore();
                puts("Membentuk linked list dg insert sebelum node tertentu");
            }
            else
            {
                puts("Pilihan tidak valid");
            }

            printf("\n");
            tampil();
            break;

        case 2:
            puts("MENU DELETE");
            puts("a. Delete di awal");
            puts("b. Delete di akhir");
            puts("c. Delete node tertentu");
            printf("Masukkan pilihan Anda : ");
            scanf(" %c", &optiondel);
            getchar();

            if (optiondel == 'a' || optiondel == 'A')
            {
                hapusawal();
            }
            else if (optiondel == 'b' || optiondel == 'B')
            {
                hapusakhir();
            }
            else if (optiondel == 'c' || optiondel == 'C')
            {
                hapustertentu();
            }
            else
            {
                puts("Pilihan tidak valid");
            }

            printf("\n");
            tampil();
            break;

        case 3:
            exit(0);
            break;
        }
    } while (jwb == 1 || jwb == 2 || jwb == 3);

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

void insertawal()
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
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

void insertafter()
{
    Node *cek = head;
    int key;

    printf("Memasukkan node setelah node berapa ? ");
    scanf("%d", &key);

    if (head == NULL)
    {
        insertawal();
    }
    else
    {
        while (cek != NULL && cek->id != key)
        {
            cek = cek->next;
        } if (cek == NULL) {
            printf("Node dengan No %d tidak ditemukan.\n", key);
            return;
        }
        p->next = cek->next;
        cek->next = p;
    }
}

void insertbefore()
{
    Node *cek = head, *pcek = NULL;
    int key;

    printf("Memasukkan node sebelum node berapa ? ");
    scanf("%d", &key);

    if (head == NULL)
    {
        insertawal();
    }
    else
    {
        while (cek != NULL && cek->id != key)
        {
            pcek = cek;
            cek = cek->next;
        } if (cek == NULL) {
            printf("Node dengan No %d tidak ditemukan.\n", key);
            return;
        }
        p->next = cek;
        pcek->next = p;
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
        if(hapus->next == NULL)
        {
            head = NULL;
            bebaskan(hapus);
            hapus = NULL;
        }
        phapus->next = NULL;
        bebaskan(hapus);
    }
}

void hapusafter()
{
    Node *hapus = head, *phapus;
    int key;

    if (head == NULL)
    {
        printf("Data tidak ada.\n");
        return;
    }
    else
    {
        printf("Node yg akan dihapus setelah node berapa ? ");
        scanf("%d", &key);

        while (hapus != NULL && hapus->id != key)
        {
            phapus = hapus;
            hapus = hapus->next;
        }
        phapus = hapus;
        hapus = hapus->next;
        phapus->next = hapus->next;
        bebaskan(hapus);
    }
}

void hapustertentu()
{
    Node *hapus = head, *phapus;
    int key;

    printf("Node yg akan dihapus : ");
    scanf("%d", &key);

    if (hapus->id == key)
    {
        hapusawal();
        return;
    }
    else
    {
        while (hapus != NULL && hapus->id != key)
        {
            phapus = hapus;
            hapus = hapus->next;
        }

        phapus->next = hapus->next;
        bebaskan(hapus);
    }
}
