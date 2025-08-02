#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef char itemType;
typedef struct
{
    itemType karkater[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType huruf, stack *s);
itemType pop(stack *s);
int polindrom(char *kal);

int main() {
    char kalimatt[MAX];

    printf("Masukkan kalimat : ");
    fgets(kalimatt, MAX, stdin);

    kalimatt[strcspn(kalimatt, "\n")] = 0;

    if (polindrom(kalimatt))
    {
        printf("Polindrom");
    } else
    {
        printf("Tidak polindrom");
    }
    
    

    return 0;
}

void inisialisasi(stack *s){
    s->count = 0;
}

int kosong(stack *s){
    return (s->count == 0);
}

int penuh(stack *s){
    return (s->count == MAX);
}

void push(itemType huruf, stack *s){
    if (!penuh(s))
    {
        s->karkater[s->count] = huruf;
        s->count++;
    }
}

itemType pop(stack *s){
    if (!kosong(s))
    {
        return s->karkater[--s->count];
    }
    return '\0';
}

int polindrom(char *kal){
    stack s;
    inisialisasi(&s);
    int len = strlen(kal);

    for (int i = 0; i < len; i++)
    {
        if ((kal[i] >= 'A' && kal[i] <= 'Z') && kal[i] != '\0')
        {
            kal[i] += 32;
        }
        push(kal[i], &s);
    }

    for (int i = 0; i < len; i++)
    {
        if ((kal[i] >= 'a' && kal[i] <= 'z') || (kal[i] >= 'A' && kal[i] <= 'Z') || (kal[i] >= '0' && kal[i] <= '9'))
        {
            char huruf = pop(&s);
            if (kal[i] != huruf)
            {
                return 0;
            }
            
        }
    }
    return 1;
}