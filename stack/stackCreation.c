#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// push operation in stack
void push(struct stack *ptr, int val)
{
    if (ptr->top >= ptr->size - 1) // condition for checking the stack is full or not.
    {
        printf("\n~~~~~~The stack is Full. So can't push %d element.\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("The element %d is succesfully pushed in the stack.\n", val);
    }
}

// pop operation in stack
void pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack Underflow!... can't pop element %d \n", ptr->arr[ptr->top]);
    }
    else
    {
        printf("The %d element is succesfully popped...\n", ptr->arr[ptr->top]);
        ptr->top--;
    }
}

// traversal of stack
void traversalOfStack(struct stack *ptr, int size)
{
    if (size == -1)
    {
        printf("\nThe stack is Empty.\n");
    }
    else
    {
        printf("\nDisplaying the whole stack. \n");

        int i = 0;
        while (i <= size)
        {
            printf("The %d element of stack is: %d\n", i + 1, ptr->arr[i]);

            i++;
        }
    }
}

// gives topmost element
void stackTop(struct stack *);

// gives bottom most element
void stackBottom(struct stack *);

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("The stack is created sucessfully.\n");

    // push operation
    printf("\n\nPerforming push operation\n");
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    // push(s, 11); //out of index(size) for checking the range msg.

    traversalOfStack(s, s->top); // here 2nd argument is a size of stack

    // // pop operation
    // printf("\n\nPerforming pop operation\n");
    // pop(s);
    // pop(s);

    stackTop(s);
    stackBottom(s);

    return 0;
}

void stackTop(struct stack *ptr)
{
    printf("The top most element of the stack is: %d\n", ptr->arr[ptr->top]);
}

void stackBottom(struct stack *ptr)
{
    printf("The bottom most element of the stack is: %d\n", ptr->arr[0]);
}
