#include <stdio.h>
#include <stdlib.h>

typedef char itemType;

typedef struct simpul Node;
struct simpul
{
    itemType data;
    int priority;
    Node *next;
};

typedef struct
{
    Node *head;
    Node *tail;
} queue;

void inisialisasi(queue *q);
void enqueue(queue *q);
void dequeue(queue *q);
void tampil(queue *q);
int kosong(queue *q);

int main()
{
    queue q;
    inisialisasi(&q);
    int pilihan;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue (Tambah data)\n");
        printf("2. Dequeue (Hapus data)\n");
        printf("3. Tampilkan data\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            tampil(&q);
            break;
        case 4:
            printf("Keluar...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
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
    Node *baru = (Node *)malloc(sizeof(Node));
    if (baru == NULL)
    {
        puts("Alokasi memori gagal");
        return;
    }

    printf("Masukkan data: ");
    scanf(" %c", &baru->data);
    printf("Masukkan prioritas : ");
    scanf("%d", &baru->priority);

    baru->next = NULL;

    // Jika queue kosong atau prioritas baru lebih tinggi dari head
    if (kosong(q) || baru->priority < q->head->priority)
    {
        baru->next = q->head;
        q->head = baru;
        if (q->tail == NULL)
        {
            q->tail = baru;
        }
    }
    else
    {
        // Cari posisi yang tepat untuk insert
        Node *current = q->head;
        while (current->next != NULL && current->next->priority <= baru->priority)
        {
            current = current->next;
        }
        baru->next = current->next;
        current->next = baru;

        // Update tail jika insert di akhir
        if (baru->next == NULL)
        {
            q->tail = baru;
        }
    }
}

void dequeue(queue *q)
{
    if (kosong(q))
    {
        puts("Queue kosong");
        return;
    }
    Node *temp = q->head;
    printf("Data '%c' dengan prioritas %d dihapus\n", temp->data, temp->priority);
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(temp);
}

void tampil(queue *q)
{
    if (kosong(q))
    {
        puts("Queue kosong");
        return;
    }
    printf("\nIsi Queue (Prioritas 1 = tertinggi):\n");
    Node *current = q->head;
    while (current != NULL)
    {
        printf("Data: %c \tPrioritas: %d\n", current->data, current->priority);
        current = current->next;
    }
}

int kosong(queue *q)
{
    return (q->head == NULL);
}