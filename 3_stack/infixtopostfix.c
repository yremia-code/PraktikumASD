#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef char itemType;
typedef struct
{
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
int precendence(char operator);
void infixtopostfix(char *infix, char *postfix);

int main()
{
    char jwb, infix[MAX], postfix[MAX];

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    puts(" ");

    do
    {
        printf("Masukkan ekspresi dalam notasi infix    : ");
        scanf("%s", infix);

        infixtopostfix(infix, postfix);

        printf("Ungkapan ekspresi dalam notasi postfix  : %s\n", postfix);
        puts(" ");

        printf("Mau mencoba lagi (y/t) ? ");
        scanf(" %c", &jwb);
        fflush(stdin);

    } while (jwb == 'y' || jwb == 'Y');

    return 0;
}

void inisialisasi(stack *s)
{
    s->count = 0;
}

int kosong(stack *s)
{
    return (s->count == 0);
}

int penuh(stack *s)
{
    return (s->count == MAX);
}

void push(itemType x, stack *s)
{
    if (!penuh(s))
    {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s)
{
    if (!kosong(s))
    {
        return s->data[--s->count];
    }
    return ' ';
}

int precendence(char operator)
{
    // switch (operator)
    // {
    // case '-':
    // case '+':
    //     return 1;

    // case '*':
    // case '/':
    //     return 2;

    // case '^':
    //     return 3;

    // default:
    //     return 0;
    // }

    if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator== '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void infixtopostfix(char *infix, char *postfix)
{
    stack s;
    inisialisasi(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char karakter = infix[i];

        // jika karakter/operand adalah huruf/angka langsung diisikan pada array
        if ((karakter >= 'a' && karakter <= 'z') || (karakter >= 'A' && karakter <= 'Z') || (karakter >= '0' && karakter <= '9'))
        {
            postfix[j++] = karakter;
        }
        // jika karakter adalah '(' akan melakukan push stack
        else if (karakter == '(')
        {
            push(karakter, &s);
        }
        // jika karakter adalah ')' akan melakukan pop semua data samapi menemukan karakter '('
        else if (karakter == ')')
        {
            while (!kosong(&s) && s.data[s.count - 1] != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // menghapus '(' dari stack
        }
        /*jika karakter adalah operator akan dilakukan push dan ketika ada operator yang lebih tinggi
        presendencenya akan dilakukan pop semua operator yang ada dalam stack*/
        else
        {
            while (!kosong(&s) && precendence(s.data[s.count - 1]) >= precendence(karakter))
            {
                postfix[j++] = pop(&s);
            }
            push(karakter, &s);
        }
    }

    // pop semua operator yang tersisa distack ketika tidak ada operand lagi
    while (!kosong(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}