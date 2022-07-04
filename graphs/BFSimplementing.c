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
    }
    else
    {
        printf("The queue is Full.\n");
    }
}

int dequeue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        int val = q->arr[q->frontInd];
        q->frontInd++;
        return val;
    }
    else
    {
        printf("The queue is empty.\n");
    }
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    q.size = 10;
    q.frontInd = q.rareInd = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS implementation.
    int node;
    int i = 4; // starting node
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);

        for (int j = 0; j < 7; j++)
        {

            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}
