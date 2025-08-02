#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char itemTYpe;
typedef struct
{
    itemTYpe data[MAX];
    int count;
    int front;
    int rear;
} queue;

void inisialisasi(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void enqueue(itemTYpe data, queue *q);
itemTYpe dequeue(queue *q);
void cari(itemTYpe data, queue *q);
void minmax(char *, char *, queue *p);
void tampil(queue *q);

int main()
{
    int pilihan;
    itemTYpe isi, data;
    queue q;
    inisialisasi(&q);
    itemTYpe min = CHAR_MAX, max = CHAR_MIN;

    do
    {
        puts("MENU QUEUE using ARRAY");
        puts("1. Tambah Data");
        puts("2. Hapus Data");
        puts("3. Tampil data min & max");
        puts("4. Cari data");
        puts("5. Cetak isi queue");
        puts("6. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan data Anda : ");
            scanf(" %c", &isi);
            enqueue(isi, &q);
            puts(" ");
            break;

        case 2:
            printf("Item yang Anda ambil adalah %c\n", dequeue(&q));
            puts(" ");
            break;

        case 3:
            minmax(&min, &max, &q);
            printf("Data terkecil = %c\n", min);
            printf("Data terbesar = %c\n", max);
            puts(" ");
            break;

        case 4:
            printf("Data yang dicari : ");
            scanf(" %c", &data);
            cari(data, &q);
            puts(" ");
            break;

        case 5:
            tampil(&q);
            puts(" ");
            break;

        case 6:
            exit(0);

        default:
            break;
        }
    } while (pilihan != 6);

    return 0;
}

void inisialisasi(queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int kosong(queue *q)
{
    return (q->count == 0);
}

int penuh(queue *q)
{
    return (q->count == MAX);
}

void enqueue(itemTYpe data, queue *q)
{
    if (!penuh(q))
    {
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
    else
    {
        puts("STOP!! PENUH");
    }
}

itemTYpe dequeue(queue *q)
{
    itemTYpe out;

    if (!kosong(q))
    {
        out = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return out;
    }
    else
    {
        puts("Queue kosong");
        return ' ';
    }
}

void cari(itemTYpe data, queue *q)
{
    int found;
    int i = q->front;

    for (int count = 0; count < q->count; count++)
    {
        if (q->data[i] == data)
        {
            found = 1;
            break;
        }
        i = (i + 1) % MAX;
    }

    if (found)
    {
        printf("%c data ditemukan\n", data);
    }
    else
    {
        printf("%c tidak ada dalam Queue\n", data);
    }
}

void minmax(char *min, char *max, queue *q)
{
    int i = q->front;

    for (int count = 0; count < q->count; count++)
    {
        if (q->data[i] < *min)
            *min = q->data[i];

        if (q->data[i] > *max)
            *max = q->data[i];

        i = (i + 1) % MAX;
    }
}

void tampil(queue *q)
{
    puts("ISI ANTRIAN SAAT INI");
    if (kosong(q))
    {
        puts("ANTRIAN KOSONG!");
        return;
    }

    int i = q->front;
    for (int count = 0; count < q->count; count++)
    {
        printf("%c\n", q->data[i]);
        i = (i + 1) % MAX;
    }
}