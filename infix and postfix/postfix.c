#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 2;
}

// empty =1
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull = 1
int isFull(struct Stack *s)
{
    if (s->top >= s->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// push  =1
void push(struct Stack *s, char newElement)
{
    if (!isFull(s))
    {
        s->arr[s->top + 1] = newElement;
        s->top++;
        // return 1;
    }
}

// return's 1 if +,- and 2 if /,*
int precedenceCheck(char a)
{
    // printf("~~~~~%c", a);
    if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(struct Stack *s)
{
    if (!isEmpty(s))
    {
        char c = s->arr[s->top];
        s->top--;
        return c;
    }
    else
    {
        printf("Stack is empty.\n");
        return '0';
    }
}

void infixToPostfix(char *infix)
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->size = 10;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (isEmpty(st))
            {
                push(st, infix[i]);
                i++;
            }
            else if (!isEmpty(st))
            {
                if (precedenceCheck(st->arr[st->top]) < precedenceCheck(infix[i]))
                {
                    push(st, infix[i]);
                    i++;
                }
                else if (precedenceCheck(st->arr[st->top]) >= precedenceCheck(infix[i]))
                {

                    postfix[j] = pop(st);
                    j++;
                }
            }
        }
    }

    // for gaining the remaining items in the stack
    while (!isEmpty(st))
    {
        postfix[j] = pop(st);
        j++;
    }

    postfix[j] = '\0';

    printf("The string is %s.\n", postfix);
}

int main(int argc, char const *argv[])
{
    char *infix = "x-y/z-k*d";

    infixToPostfix(infix);

    return 0;
}
