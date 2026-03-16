#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p, *baca;

void isidata();
void insertawal();
void tampil();

int main () {

    char jwb;

    do
    {
        fflush(stdin);
        isidata();
        insertawal();
        fflush(stdin);
        printf("Masukkan data ? (y/t) ");
        scanf(" %c", &jwb);
        getchar();
    } while (jwb == 'y' || jwb == 'Y');
    
    tampil();

    return 0;
}

void isidata()
{
    int x;

    printf("Data yang mau disimpan? ");
    scanf("%d", &x);
    getchar();

    p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        printf("alokasi gagal\n");
        exit(0);
    }
    else
    {
        p->data = x;
        p->next = NULL;
    }
}

void insertawal() {
    if (head != NULL)
    {
        p->next = head;
    }

    head = p;
}

void tampil() {
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    
}