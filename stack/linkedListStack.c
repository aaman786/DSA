#include <stdio.h>
#include <stdlib.h>

struct NodeStack
{
    int data;
    struct NodeStack *next;
};

// for traversal of the linked stack
void traversal(struct NodeStack *ptr)
{
    while (ptr != NULL)
    {
        printf("Stack Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// checking Linked stack is empty or not.
int isEmpty(struct NodeStack *top)
{
    if (top->next == NULL)
    {
        printf("The stack is Empty.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// checking Linked stack is full or not.
int isFull()
{
    struct NodeStack *ptr = (struct NodeStack *)malloc(sizeof(struct NodeStack));

    if (ptr == NULL)
    {
        printf("The stack is Full...\n");
        return 1;
    }
    else
    {
        printf("The stack is not Full...\n");
        return 0;
    }
}

// push operation in Linked stack
struct NodeStack *pushAtBegining(struct NodeStack *top, int newElement)
{
    if (isFull)
    {
        struct NodeStack *ptr = (struct NodeStack *)malloc(sizeof(struct NodeStack));
        ptr->data = newElement;

        ptr->next = top;

        top = ptr;
        return top;
    }
    else
    {
        return top;
    }
}

// pop operation in linked list
int popAtBegining(struct NodeStack **top)
{
    if (isEmpty(*top))
    {
        return -1;
    }
    else
    {
        struct NodeStack **ptr = top;
        int element = (*ptr)->data;

        *top = (*top)->next;
        free(ptr);
        return element;
    }
}

// peek function for the stack.
int peek(struct NodeStack *top, int index);

int main(int argc, char const *argv[])
{
    struct NodeStack *top = (struct NodeStack *)malloc(sizeof(struct NodeStack));
    struct NodeStack *second = (struct NodeStack *)malloc(sizeof(struct NodeStack));
    struct NodeStack *third = (struct NodeStack *)malloc(sizeof(struct NodeStack));
    struct NodeStack *fourth = (struct NodeStack *)malloc(sizeof(struct NodeStack));

    top->data = 2;
    top->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    // top = push(top, 11); //push operation in linked stack.
    // int returnTypePopAtBegining = popAtBegining(&top); // passing address for real changes.

    /* if (returnTypePopAtBegining != -1)
    {
        printf("The %d element is popped from the stack.\n", returnTypePopAtBegining);
    } */

    traversal(top); // traversal of stack

    // use of peek operation.
    for (int i = 0; i <= 3; i++)
    {
        printf("Peek at index %d, the element got is: %d\n", i, peek(top, i));
    }

    return 0;
}

// StackTop but only work with when pushing is done.
/*
int stackTop(){
    return top->data;
}
 */

// peek operation of stack
int peek(struct NodeStack *top, int index)
{
    struct NodeStack *ptr = top;
    for (int i = 0; i < index && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
