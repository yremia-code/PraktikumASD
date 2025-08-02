#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p, *tail, *before, *pbef, *baca;

void alokasi();
void insertakhir();
void insertbefore();
void tampil();

int main()
{
    char jwb;

    puts("INSERT AKHIR");

    do
    {
        fflush(stdin);
        alokasi();
        insertakhir();
        fflush(stdin);
        printf("Masukkan data lagi ? (y/t) ");
        jwb = getchar();
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    puts("INSERT BEFORE");
    fflush(stdin);
    alokasi();
    insertbefore();
    fflush(stdin);
    tampil();

    return 0;
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi Gagal!");
        return;
    }
    else
    {
        printf("Masukkan data : ");
        scanf("%d", &p->data);
        p->next = NULL;
    }
}

void insertakhir()
{
    tail = head;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        tail = p;
    }
}

void insertbefore()
{
    int key;

    printf("Masukkan data sebelum ? ");
    scanf("%d", &key);

    before = head;
    while (before->data != key)
    {
        pbef = before;
        before = before->next;
    }

    p->next = before;
    pbef->next = p;
}

void tampil()
{
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}