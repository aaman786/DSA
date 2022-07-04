#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int frontInd;
    int rearInd;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    if (q->frontInd == q->rearInd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct CircularQueue *q)
{
    if ((q->rearInd + 1) % q->size == q->frontInd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct CircularQueue *q, int newVal)
{
    if (!isFull(q))
    {
        q->rearInd = (q->rearInd + 1) % q->size;
        q->arr[q->rearInd] = newVal;

        printf("The element %d is enqueued.\n", newVal);
    }
    else
    {
        printf("The queue is Full.\n");
    }
}

void dequeue(struct CircularQueue *q)
{
    if (!isEmpty(q))
    {
        q->frontInd = (q->frontInd + 1) % q->size;
        int val = q->arr[q->frontInd];
        printf("The element %d is dequeued.\n", val);
    }
    else
    {
        printf("The queue is empty.\n");
    }
}

int main(int argc, char const *argv[])
{
    struct CircularQueue cq;
    cq.size = 5;
    cq.frontInd = cq.rearInd = 0;
    cq.arr = (int *)malloc(cq.size * sizeof(int));

    enqueue(&cq, 12);
    enqueue(&cq, 12);
    enqueue(&cq, 12);
    enqueue(&cq, 12);

    enqueue(&cq, 12);
    return 0;s
}
