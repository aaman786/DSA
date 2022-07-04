#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

// return 0 with msg stack is empty
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("The given stack is Empty.\n");
        return 0;
    }
    else
    {
        printf("The stack is not Empty.\n");
        return 1;
    }
}

// return 0 with msg that stack is full
int isFull(struct Stack *s)
{
    if (s->top >= s->size)
    {
        printf("The stack is Full.\n");
        return 0;
    }
    else
    {
        printf("The stack is not Full.\n");
        return 1;
    }
}

// for pushing the elements of an stack
void push(struct Stack *s, char c)
{
    if (isFull)
    {
        s->arr[s->top + 1] = c;
        s->top++;
    }
}

// for poping the elements of a stack
void pop(struct Stack *s)
{
    char temp[1];
    if (isEmpty)
    {
        s->top--;
    }
}

int parenthesisMatching(char str[])
{
    int len = strlen(str);

    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->size = len / 2;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    // code for parenthesis check
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            push(st, '(');
        }
        else if (str[i] == ')')
        {
            pop(st);
        }
    }
    printf("The value of Top is: %d\n", st->top);

    return st->top;
}

int main(int argc, char const *argv[])
{

    char *exp = "((8)(*--$$9))";

    int n = parenthesisMatching(exp);
    if (n == -1)
    {
        printf("There is not any problem in expression.\n");
    }
    else
    {
        printf("There is a problem in expression.\n");
        printf("The element we get in stack are: %d \n", n);
    }

    return 0;
}
