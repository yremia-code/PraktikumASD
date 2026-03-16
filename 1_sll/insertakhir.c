#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p, *baca, *tail;

void alokasi();
void insertakhir();
void tampil();

int main() {
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
    } while (jwb == 'Y' || jwb == 'y');
    
    tampil();

    return 0;
}

void alokasi(){
    p = (Node *)malloc(sizeof(Node));

    if(p == NULL)
    {
        printf("Alokasi Gagal\n");
        return;
    } else
    {
        printf("Masukkan Data : ");
        scanf("%d", &p->data);
        p->next = NULL;
    }
}

void insertakhir() {
    tail = head;

    if (head == NULL)
    {
        head = p;
    } else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
        tail = p;
    }
}

void tampil() {
    baca = head;

    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    
}