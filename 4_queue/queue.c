#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char itempType;
typedef struct
{
    itempType data[MAX];
    int count;
    int front;
    int rear;
} queue;

void inisialisasi(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void enqueue(itempType x, queue *q);
itempType dequeue(queue *q);

int main() {
    char jwb, data;
    queue q;

    puts("QUEUE BERBASIS ARRAY");
    inisialisasi(&q);
    puts("MENGISI QUEUE");

    do
    {
        if (penuh(&q))
        {
            puts("ANTRIAN PENUH!");
            break;
        }

        fflush(stdin);
        printf("Data yang akan dimasukkan : ");
        scanf(" %c", &data);
        enqueue(data, &q);
        fflush(stdin);
        printf("Masukkan data lagi ? ");
        scanf(" %c", &jwb);
        getchar();
        puts(" ");
    } while (jwb == 'y' || jwb == 'Y');

    puts("ISI ANTRIAN");
    while (!kosong(&q))
    {
        printf("%c\n", dequeue(&q));
    }
    
    return 0;
}

void inisialisasi(queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int kosong(queue *q){
    return (q->count == 0);
}

int penuh(queue *q){
    return (q->count == MAX);
}

void enqueue(itempType x, queue *q){
    if (!penuh(q))
    {
        q->data[q->rear] = x;
        q->rear = (q->rear+1) % MAX;
        q->count++;
    }
    else
    {
        puts("Penuh!");
    }
}

itempType dequeue(queue *q){
    itempType item;
    if (!kosong(q))
    {
        item = q->data[q->front];
        q->front = (q->front+1) % MAX;
        q->count--;
        return (item);
    } else
    {
        printf("KOSONG!");
        return ' ';
    }
}