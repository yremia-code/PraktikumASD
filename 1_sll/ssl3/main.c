#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct isi
{
    char nrp[15];
    char name[50];
    char kelas[20];
} data;

typedef struct simpul Node;
struct simpul
{
    data mahasiswa;
    Node *next;
};

Node *head = NULL, *p;

void isidata();
void akhir();
void tampil();
void bebaskan(Node *);
void hapusawal();
void hapus();
void update();

int main()
{
    char jwb;
    int pilihan;

    do
    {
        fflush(stdin);
        isidata(); // isi data
        akhir();   // insert akhir
        fflush(stdin);
        printf("Data lain (y/t) : ");
        jwb = getchar();
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    do
    {
        printf("\nPilih Opsi : \n");
        printf("1. Update Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampil\n");
        printf("4. Tambah\n");
        printf("5. Keluar\n");

        printf("Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
            update();
        else if (pilihan == 2)
            hapus();
        else if (pilihan == 3)
            tampil();
        else if (pilihan == 4)
        {
            fflush(stdin);
            isidata();
            akhir();
        }
        else if (pilihan == 5)
            break;
        else
            printf("Pilihan tidak valid.\n");
    } while (pilihan != 0);

    return 0;
}

void isidata()
{
    data mhs;

    printf("\nData yang akan disimpan : \n");
    printf("NRP     : ");
    scanf("%s", mhs.nrp);
    getchar();
    printf("Nama    : ");
    fgets(mhs.name, sizeof(mhs.name), stdin);
    mhs.name[strcspn(mhs.name, "\n")] = 0;
    printf("Kelas   : ");
    fgets(mhs.kelas, sizeof(mhs.kelas), stdin);
    mhs.kelas[strcspn(mhs.kelas, "\n")] = 0;

    // Alokasi memori
    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->mahasiswa = mhs; // Data yang diinputkan disimpan di dalam p
        p->next = NULL;
    }
}

void akhir()
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

    puts("\n\nDAFTAR MAHASISWA\n");

    while (baca != NULL)
    {
        printf("NRP     : %s\n", baca->mahasiswa.nrp);
        printf("Nama    : %s\n", baca->mahasiswa.name);
        printf("Kelas   : %s\n\n", baca->mahasiswa.kelas);

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

    if (hapus->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = hapus->next;
        bebaskan(hapus);
    }
}

void hapus()
{
    Node *hapus, *phapus = NULL;
    data hpsmhs;

    printf("\nData yang akan dihapus : \n");
    printf("NRP     : ");
    scanf("%s", hpsmhs.nrp);
    getchar();

    hapus = head;

    // hapus awal node
    if (hapus != NULL && strcmp(hapus->mahasiswa.nrp, hpsmhs.nrp) == 0)
    {
        hapusawal();
    }
    else
    {
        while (hapus != NULL && strcmp(hapus->mahasiswa.nrp, hpsmhs.nrp) != 0)
        {
            phapus = hapus;
            hapus = hapus->next;

            if (hapus->next == NULL)
            {
                printf("Data tidak ditemukan.\n");
                return;
            }
        }
        phapus->next = hapus->next;
        bebaskan(hapus);
    }
}

void update()
{
    Node *update = head;
    data updatemhs;

    printf("\nData yang akan diupdate : \n");
    printf("NRP     : ");
    scanf("%s", updatemhs.nrp);
    getchar();

    update = head;

    if (head == NULL)
    {
        printf("Data kosong.\n");
        return;
    }
    else
    {
        while (update != NULL && strcmp(update->mahasiswa.nrp, updatemhs.nrp) != 0)
        {
            update = update->next;
        }
        if (update == NULL)
        {
            printf("Data tidak ditemukan.\n");
        }

        puts("\nData yang diupdate  : \n");
        printf("Nama    : %s\n", update->mahasiswa.name);
        printf("Kelas   : %s\n", update->mahasiswa.kelas);

        puts("\nPerubahan Data      : \n");
        printf("Nama    : ");
        fgets(update->mahasiswa.name, sizeof(update->mahasiswa.name), stdin);
        update->mahasiswa.name[strcspn(update->mahasiswa.name, "\n")] = 0;
        printf("Kelas   : ");
        fgets(update->mahasiswa.kelas, sizeof(update->mahasiswa.kelas), stdin);
        update->mahasiswa.kelas[strcspn(update->mahasiswa.kelas, "\n")] = 0;
    }
}
