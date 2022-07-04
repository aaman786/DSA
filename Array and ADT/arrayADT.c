#include <stdio.h>
#include <stdlib.h>

struct array
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createAnArray(struct array *a, int tSize, int uSize)
{
    a->totalSize = tSize;
    a->usedSize = uSize;
    a->ptr = (int *)malloc(tSize * (sizeof(int)));
}

void display(struct array *a)
{
    int i = 0;
    while (i < a->usedSize)
    {
        printf("The value at index %d is: %d\n", i, (a->ptr)[i]);
        i++;
    }
}

void settingValue(struct array *a)
{
    int i, n;
    while (i < a->usedSize)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    struct array arr;
    createAnArray(&arr, 5, 2);

    printf("The Insertion ~~~~~\n");
    settingValue(&arr);

    printf("The Traversal ~~~~~\n");
    display(&arr);

    // printf("HEllo");
    return 0;
}
