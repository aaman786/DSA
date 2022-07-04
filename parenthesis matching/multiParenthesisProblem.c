#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

// return 0 with msg
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("The stack is Empty.\n");
        return 0;
    }
    else
    {
        printf("The stack is not Empty.\n");
        return 1;
    }
}

// return 0 with msg
int isFull(struct Stack *s)
{
    if (s->top >= s->size)
    {
        return 0;
    }
    else
    {

        return 1;
    }
}

// push operation
void push(struct Stack *s, char newElement)
{
    if (isFull(s))
    {
        s->arr[s->top + 1] = newElement;
        s->top++;
    }
    else
    {
        printf("Can't push element %c, stack is full!\n", newElement);
    }
}

// pop operation.
void pop(struct Stack *s)
{
    // char c = s->arr[s->top];
    if (isEmpty)
    {
        s->top--;
        // return c;
    }
    else
    {
        // printf("Can't pop element %c, stack is already empty.\n",c);
    }
}

int matchingParenthesis(char a[], int size)
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->size = (int)(size / 2) + 2; // type casting
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    // printf("%d", st->size);
    for (int i = 0; i < size; i++)
    {
        if (a[i] == '[' || a[i] == '(' || a[i] == '{')
        {
            push(st, a[i]);
        }
        else if (a[i] == ']' || a[i] == ')' || a[i] == '}')
        {
            pop(st);
        }
    }

    return st->top;

    // printf("%d", st->top);

    // int i = 0;
    // while (i <= st->top)
    // {
    //     printf("The stack is: %c\n", st->arr[i]);
    //     i++;
    // }
}

int main(int argc, char const *argv[])
{
    char *exp = "((8){(9-8)})"; // size = 12

    // finding size
    int i = 0;
    while (exp[i] != '\0')
    {
        // printf("%c", exp[i]);
        i++;
    }

    int ans = matchingParenthesis(exp, i + 1);

    if (ans == -1)
    {
        printf("The expression passed is balanced.\n");
    }
    else
    {
        printf("The expression passed is not balanced.\n");
    }

    return 0;
}
