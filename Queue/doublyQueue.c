#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
};

struct Node *frontInd = NULL;
struct Node *rearInd = NULL;

// inserting element from last
void enqueueRear(int val)
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
        ptr->previous = NULL;

        if (frontInd == NULL)
        {
            frontInd = rearInd = ptr;
        }
        else
        {

            ptr->previous = rearInd;
            rearInd->next = ptr;
            rearInd = ptr;
        }
        printf("The element %d is successfully enqueued from rear.\n", val);
    }
}

// removing element from last
void dequeueFront()
{
    if (frontInd == NULL)
    {
        printf("The queue is Empty.\n");
    }
    else
    {
        struct Node *ptr = frontInd;
        int val = ptr->data;
        frontInd->previous = ptr->previous;
        frontInd = frontInd->next;
        free(ptr);
        printf("The element %d is successfully dequeued.\n", val);
    }
}

void traversalOfDoublyQueue()
{

    struct Node *ptr = frontInd;

    while (ptr != NULL)
    {
        printf("Element: %d.\n", ptr->data);
        ptr = ptr->next;
    }
}

// inserting element from start
void enqueueFront(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("The queue is full becaue heap is exhuast.\n");
    }
    else
    {
        if (frontInd->previous == NULL)
        {
            printf("Can't fill element because front of queue is already occupied.\n");
        }
        else
        {
            ptr->data = val;
            ptr->next = frontInd->next;
            frontInd->next = ptr;
            ptr->previous = frontInd;
        }
    }
}

// removing from rear
void dequeueRear()
{
    if (rearInd == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        struct Node *ptr = rearInd->previous;
        struct Node *temp = rearInd;
        ptr->next = temp->next;
        int val = temp->data;
        free(temp);
        rearInd = ptr;
        printf("The value %d is dequeued from the rear.\n", val);
    }
}

int main(int argc, char const *argv[])
{
    enqueueRear(2);
    enqueueRear(4);
    enqueueRear(6);

    traversalOfDoublyQueue();

    // dequeueFront();
    // enqueueFront(11);
    // enqueueFront(13);
    // enqueueFront(15);

    dequeueRear();
    enqueueRear(7);

    traversalOfDoublyQueue();
    return 0;
}