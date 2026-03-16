#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head, *p, *baca, *tail, *after;

void alokasi();
void insertakhir();
void insertafter();
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
        printf("Masukkan data ? (y/t) ");
        scanf(" %c", &jwb);
        getchar();
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    puts("\nINSERT AFTER");
    fflush(stdin);
    alokasi();
    insertafter();
    fflush(stdin);

    tampil();

    return 0;
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        puts("Alokasi Gagal");
        return;
    }
    else
    {
        printf("Data yang akan dimasukkan ? ");
        scanf("%d", &p->data);
        p->next = NULL;
    }
}

void insertakhir()
{
    tail = head;

    if (head == NULL)
        head = p;
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

void insertafter()
{
    int key;

    printf("Insert setelah node ? ");
    scanf("%d", &key);

    after = head;
    while (after->data != key)
    {
        after = after->next;
    }

    if (after->next == NULL)
    {
        insertakhir();
    }
    else
    {
        p->next = after->next;
        after->next = p;
    }
}

void tampil(){
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}