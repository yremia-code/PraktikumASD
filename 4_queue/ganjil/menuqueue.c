#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char itemType;
typedef struct
{
    itemType data[MAX];
    int count;
    int front;
    int rear;
} queue; 

void inisialisasi(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void enqueue(itemType x, queue *q);
itemType dequeue(queue *q);
void tampil(queue *q);

int main()
{
    int pilihan;
    itemType isi;
    queue q;
    inisialisasi(&q);

    do
    {
        puts("MENU QUEUE using ARRAY");
        puts("1. Mengisi Queue <ENQUEUE>");
        puts("2. Mengambil isi Queue <DEQUEUE>");
        puts("3. Menampilkan isi Queue -> FIFO");
        puts("4. Keluar");
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

void enqueue(itemType x, queue *q)
{
    if (!penuh(q))
    {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
    else
    {
        puts("\nSTOP!!!");
        puts("Queue Penuh! Data terakhir gk bs masuk!");
    }
}

itemType dequeue(queue *q)
{
    itemType out;

    if (!kosong(q))
    {
        out = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return out;
    }
    else
    {
        puts("ANTRIAN KOSONG!");
        return ' ';
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