#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int frontInd; // deueue at
    int rareInd;  // enqueue at
    int *arr;
};

// isEmpty = 1
int isEmpty(struct Queue *q)
{
    if (q->rareInd == q->frontInd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull = 1
int isFull(struct Queue *q)
{
    if (q->rareInd >= q->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int newVal)
{
    if (!isFull(q))
    {
        q->arr[q->rareInd] = newVal;
        q->rareInd++;
        printf("The element %d is enqueued.\n", newVal);
    }
    else
    {
        printf("The queue is Full.\n");
    }
}

void dequeue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        int val = q->arr[q->frontInd];
        q->frontInd++;
        printf("The element %d is dequeued.\n", val);
    }
    else
    {
        printf("The queue is empty.\n");
    }
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    q.size = 5;
    q.frontInd = q.rareInd = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 6);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    printf("The Queue is Empty %d.\n", isEmpty(&q));

    return 0;
}
