#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *frontInd = NULL;
struct Node *rareInd = NULL;

void enqueue(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL)
    {
        printf("The queue is full.\n");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (frontInd == NULL)
        {
            frontInd = rareInd = ptr;
        }
        else
        {
            rareInd->next = ptr;
            rareInd = ptr;
        }
        printf("The element %d is sucessfully enqueued.\n", val);
    }
}

void dequeue()
{
    if (frontInd == NULL)
    {
        printf("The is Empty.\n");
    }
    else
    {
        struct Node *ptr = frontInd;
        int val = ptr->data;
        frontInd = frontInd->next;
        free(ptr);
        printf("The element %d is successfully dequeued.\n", val);
    }
}

void traversalOfLinkedQueue()
{
    struct Node *ptr = frontInd;

    while (ptr != NULL)
    {
        printf("The element of the queue is: %d.\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    enqueue(2);
    enqueue(4);
    enqueue(6);

    // dequeue();

    traversalOfLinkedQueue();

    return 0;
}
