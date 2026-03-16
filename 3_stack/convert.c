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

void inisialisasi(stack *S);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *S);
int precendence(char op);
void infixtopostfix(char *infix, char *postfix);

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Masukkan ekspresi infix : ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);

    printf("Ekspresi postfix        : %s\n", postfix);

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

int precendence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
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
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') || (token >= '0' && token <= '9'))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(token, &s);
        }
        else if (token == ')')
        {
            while (!kosong(&s) && s.data[s.count - 1] != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (!kosong(&s) && precendence(s.data[s.count - 1]) >= precendence(token))
            {
                postfix[j++] = pop(&s);
            }
            push(token, &s);
        }
    }
    while (!kosong(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}