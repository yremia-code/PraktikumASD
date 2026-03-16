#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
typedef char itemType;
typedef struct simpul
{
    itemType data;
    Node *next;
};

typedef struct
{
    Node *head;
    Node *tail;
} queue;

Node *baru, *output, *baca;

void inisialisasi(queue *q);
void enqueue(queue *q);
void dequeue(queue *q);
void tampil(queue *q);
int kosong(queue *q);

int main()
{
    int pilihan;
    queue q;
    inisialisasi(&q);

    do
    {
        puts("MENU QUEUE using LINKED LIST");
        puts("1. Mengisi Queue <ENQUEUE>");
        puts("2. Mengambil isi Queue <DEQUEUE>");
        puts("3. Menampilkan isi Queue -> FIFO");
        puts("4. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            enqueue(&q);
            puts(" ");
            break;

        case 2:
            dequeue(&q);
            puts(" ");
            break;

        case 3:
            tampil(&q);
            puts(" ");
            break;

        case 4:
            exit(0);

        default:
            break;
        }
    } while (pilihan != 4);

    return 0;
}

void inisialisasi(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue *q)
{
    //MEMESAN MEMORI
    baru = (Node *)malloc(sizeof(Node));

    if (baru == NULL)
    {
        printf("Alokasi Gagal!!");
        return;
    }

    //MEMINTA USER MEMASUKKAN DATA KEMUDIAN MENYIMPAN PADA NODE BARU BAGIAN DATA
    printf("Masukkan data Anda : ");
    scanf(" %c", &baru->data);

    //MENGINISIALISASI NODE BARU BAGIAN NEXT MENJADI NULL
    baru->next = NULL;

    //MELAKUKAN PENGECEKKAN APAKAH LINKED LIST KOSONG
    if (kosong(q))
    {
        q->head = baru; //MENAUTKAN LINKED LIST QUEUE BAGIAN HEAD KEPADA NODE BARU
        q->tail = baru; //MENAUTKAN LINKED LIST QUEUE BAGIAN TAIL KEPADA NODE BARU
    }
    else
    {
        q->tail->next = baru; //MENAUTKAN DATA BARU DENGAN TAIL
        q->tail = baru; //MEMINDAHKAN TAIL
    }
}

void dequeue(queue *q)
{
    //MELAKUKAN PENGECEKKAN APAKAH LINKED LIST KOSONG
    if (kosong(q))
    {
        puts("Queue Kosong Tidak Ada Data!!!"); //JIKA KOSONG TIDAK BISA MELAKUKAN DEQUEUE
        return;
    }

    //MENGARAHKAN NODE OUTPUT KEPADA NODE AWAL YANG DITUNJUK HEAD
    output = q->head;
    char data = output->data; //MEMINDAHKAN DATA YANG ADA KE DALAM VARIABEL DATA

    q->head = q->head->next; //MELAKUKAN PENYELAMATAN AGAR LINKED LIST TIDAK TERPUTUS

    //JIKA LINKED LIST KOSONG TAIL AKAN DIISI NULL
    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    free(output);
    printf("Item yang Anda ambil adalah %c\n", data); //OUTPUT DATA
}

void tampil(queue *q)
{
    //NODE BACA DIARAHKA KEPADA HEAD
    baca = q->head;

    puts("ISI QUEUE");


    //MELAKUKAN PENGECEKAN LINKED LIST
    if (kosong(q))
    {
        puts("...KOSONG...");
    }

    //MELAKUKAN PERULANGAN UNTUK MENYISIR LINKED LIST
    while (baca != NULL)
    {
        printf("%c \n", baca->data); //MENAMPILKAN NODE BACA BAGIAN DATA
        baca = baca->next; //MELAKUAKN PEMINDAHAN NODE
    }
}

int kosong(queue *q)
{
    return (q->head == NULL);
}